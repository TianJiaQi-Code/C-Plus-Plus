#pragma once

template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

// �ػ�
template<>
struct HashFunc<string>
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto e : s)
		{
			hash += e;
			hash *= 131;
		}
		return hash;
	}
};

namespace open_address
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;	// ���
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable(size_t size = 10)
		{
			_tables.resize(size);
		}

		HashData<K, V>* Find(const K& key)
		{
			Hash hs;
			// ����̽��
			size_t hashi = hs(key) % _tables.size();
			while (_tables[hashi]._state != EMPTY)
			{
				if (key == _tables[hashi]._kv.first &&
					_tables[hashi]._state == EXIST)
				{
					return &_tables[hashi];
				}

				++hashi;
				hashi %= _tables.size();
			}

			return nullptr;
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;

			// ���ݵ�����
			if (_n * 10 / _tables.size() >= 7)
			{
				HashTable<K, V, Hash> newHT(_tables.size() * 2);
				// �����ɱ������뵽�±�
				for (auto e : _tables)
				{
					if (e._state == EXIST)
					{
						newHT.Insert(e._kv);
					}
				}
				_tables.swap(newHT._tables);
			}

			Hash hs;
			// ����̽��
			size_t hashi = hs(kv.first) % _tables.size();
			while (_tables[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _tables.size();
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_n;

			return true;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				_n--;
				ret->_state = DELETE;
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0;	// ʵ�ʴ洢�����ݸ���
	};
}

namespace hash_bucket
{
	// T -> K
	// T -> pair<K, V>
	template<class T>
	struct HashNode
	{
		HashNode<T>* _next;
		T _data;

		HashNode(const T& data)
			: _next(nullptr)
			, _data(data)
		{}
	};

	// ǰ������
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	template<class K, class T, class KeyOfT, class Hash>
	struct __HTIterator
	{
		typedef HashNode<T> Node;
		typedef HashTable<K, T, KeyOfT, Hash> HT;
		typedef __HTIterator<K, T, KeyOfT, Hash> Self;

		Node* _node;
		HT* _ht;

		__HTIterator(Node* node, HT* ht)
			: _node(node)
			, _ht(ht)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		Self& operator++()
		{
			if (_node->_next)
			{
				// ��ǰͰ���ǽڵ�
				_node = _node->_next;
			}
			else
			{
				// ��ǰͰ�����ˣ�����һ��Ͱ
				KeyOfT kot;
				Hash hs;
				size_t hashi = hs(kot(_node->_data)) % _ht->_tables.size();
				
				// ����һ��Ͱ
				hashi++;
				while (hashi < _ht->_tables.size())
				{
					if (_ht->_tables[hashi])
					{
						_node = _ht->_tables[hashi];
						break;
					}
					hashi++;
				}

				// ����û��Ͱ��
				if (hashi == _ht->_tables.size())
				{
					_node = nullptr;
				}
			}
			return *this;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
	};

	template<class K, class T, class KeyOfT, class Hash>
	class HashTable
	{
		template<class K, class T, class KeyOfT, class Hash>
		friend struct __HTIterator;

		typedef HashNode<T> Node;

	public:
		typedef __HTIterator<K, T, KeyOfT, Hash> iterator;

		iterator begin()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				// �ҵ���һ��Ͱ�ĵ�һ���ڵ�
				if (_tables[i])
				{
					return iterator(_tables[i], this);
				}
			}
			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		HashTable()
		{
			_tables.resize(10, nullptr);
			_n = 0;
		}

		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;

					cur = next;
				}
				_tables[i] = nullptr;
			}
		}

		bool Insert(const T& data)
		{
			KeyOfT kot;

			if (Find(kot(data)))
				return false;

			Hash hs;

			// �������ӵ�1������
			if (_n == _tables.size())
			{
				vector<Node*> newTables(_tables.size() * 2, nullptr);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					// ȡ���ɱ��нڵ㣬���¼���ҵ��±�Ͱ��
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						// ͷ�嵽�±�
						size_t hashi = hs(kot(cur->_data)) % newTables.size();
						cur->_next = newTables[hashi];
						newTables[hashi] = cur;

						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newTables);
			}

			size_t hashi = hs(kot(data)) % _tables.size();
			Node* newnode = new Node(data);

			// ͷ��
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;

			++_n;
			return true;
		}

		Node* Find(const K& key)
		{
			KeyOfT kot;
			Hash hs;
			size_t hashi = hs(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			KeyOfT kot;
			Hash hs;
			size_t hashi = hs(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					// ɾ��
					if (prev)
					{
						prev->_next = cur->_next;
					}
					else
					{
						_tables[hashi] = cur->_next;
					}

					delete cur;

					--_n;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}

	private:
		vector<Node*> _tables;	// ָ������
		size_t _n;
	};
}