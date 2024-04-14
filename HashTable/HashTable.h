#pragma once

template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

// 特化
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
		State _state = EMPTY;	// 标记
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
			// 线性探测
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

			// 扩容的问题
			if (_n * 10 / _tables.size() >= 7)
			{
				HashTable<K, V, Hash> newHT(_tables.size() * 2);
				// 遍历旧表，插入到新表
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
			// 线性探测
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
		size_t _n = 0;	// 实际存储的数据个数
	};
}

namespace hash_bucket
{
	template<class K, class V>
	struct HashNode
	{
		HashNode<K, V>* _next;
		pair<K, V> _kv;

		HashNode(const pair<K, V>& kv)
			: _next(nullptr)
			, _kv(kv)
		{}
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
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

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;

			Hash hs;

			// 负载因子到1就扩容
			if (_n == _tables.size())
			{
				vector<Node*> newTables(_tables.size() * 2, nullptr);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					// 取出旧表中节点，重新计算挂到新表桶中
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						// 头插到新表
						size_t hashi = hs(cur->_kv.first) % newTables.size();
						cur->_next = newTables[hashi];
						newTables[hashi] = cur;

						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newTables);
			}

			size_t hashi = hs(kv.first) % _tables.size();
			Node* newnode = new Node(kv);

			// 头插
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;

			++_n;
			return true;
		}

		Node* Find(const K& key)
		{
			Hash hs;
			size_t hashi = hs(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			Hash hs;
			size_t hashi = hs(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					// 删除
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

		void Some()
		{
			size_t bucketSize = 0;
			size_t maxBucketLen = 0;
			size_t sum = 0;
			double averageBucketLen = 0;

			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				if (cur)
				{
					++bucketSize;
				}

				size_t bucketLen = 0;
				while (cur)
				{
					++bucketLen;
					cur = cur->_next;
				}

				sum += bucketLen;

				if (bucketLen > maxBucketLen)
				{
					maxBucketLen = bucketLen;
				}
			}

			averageBucketLen = (double)sum / (double)bucketSize;

			printf("load factor:%lf\n", (double)_n / _tables.size());
			printf("all bucketSize:%zd\n", _tables.size());
			printf("bucketSize:%zd\n", bucketSize);
			printf("maxBucketLen:%zd\n", maxBucketLen);
			printf("averageBucketLen:%lf\n", averageBucketLen);
		}

	private:
		vector<Node*> _tables;	// 指针数组
		size_t _n;
	};
}