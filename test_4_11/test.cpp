//// ��ϣ��ÿ���ռ�������
//// EMPTY��λ�ÿգ� EXIST��λ���Ѿ���Ԫ�أ� DELETEԪ���Ѿ�ɾ��
//enum State
//{
//	EMPTY,
//	EXIST,
//	DELETE
//};


#include <iostream>
using namespace std;

// ע�⣺����ʵ�ֵĹ�ϣ����Ԫ��Ψһ����key��ͬ��Ԫ�ز��ٽ��в���
// Ϊ��ʵ�ּ򵥣��˹�ϣ�������ǽ��Ƚ�ֱ����Ԫ�ذ���һ��
template<class K, class V>
class HashTable
{
	struct Elem
	{
		pair<K, V> _val;
		State _state;
	};
public:
	HashTable(size_t capacity = 3)
		: _ht(capacity), _size(0)
	{
		for (size_t i = 0; i < capacity; ++i)
			_ht[i]._state = EMPTY;
	}
	bool Insert(const pair<K, V>& val)
	{
		// ����ϣ��ײ�ռ��Ƿ����
		// _CheckCapacity();
		size_t hashAddr = HashFunc(key);
		// size_t startAddr = hashAddr;
		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first
				== key)
				return false;
			hashAddr++;
			if (hashAddr == _ht.capacity())
				hashAddr = 0;
			/*
			// תһȦҲû���ҵ���ע�⣺��̬��ϣ������������Բ��ÿ��ǣ���ϣ����Ԫ
			�ظ�������һ������������ϣ��ͻ���ʻ�������Ҫ���������͹�ϣ��ͻ����˹�ϣ����Ԫ����
			���������
			if(hashAddr == startAddr)
			return false;
			*/
		}
		// ����Ԫ��
		_ht[hashAddr]._state = EXIST;
		_ht[hashAddr]._val = val;
		_size++;
		return true;
	}
	int Find(const K& key)
	{
		size_t hashAddr = HashFunc(key);
		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first
				== key)
				return hashAddr;
			hashAddr++;
		}
		return hashAddr;
	}
	bool Erase(const K & key)
	{
		int index = Find(key);
		if (-1 != index)
		{
			_ht[index]._state = DELETE;
			_size++;
			return true;
		}
		return false;
	}
	size_t Size()const;
	bool Empty() const;
	void Swap(HashTable<K, V, HF>&ht);


	void CheckCapacity()
	{
		if (_size * 10 / _ht.capacity() >= 7)
		{
			HashTable<K, V, HF> newHt(GetNextPrime(ht.capacity));
			for (size_t i = 0; i < _ht.capacity(); ++i)
			{
				if (_ht[i]._state == EXIST)
					newHt.Insert(_ht[i]._val);
			}
			Swap(newHt);
		}
	}


private:
	size_t HashFunc(const K & key)
	{
		return key % _ht.capacity();
	}
private:
	vector<Elem> _ht;
	size_t _size;
};




template<class V>
struct HashBucketNode
{
	HashBucketNode(const V& data)
		: _pNext(nullptr), _data(data)
	{}
	HashBucketNode<V>* _pNext;
	V _data;
};
// ������ʵ�ֵĹ�ϣͰ��key��Ψһ��
template<class V>
class HashBucket
{
	typedef HashBucketNode<V> Node;
	typedef Node* PNode;
public:
	HashBucket(size_t capacity = 3) : _size(0)
	{
		_ht.resize(GetNextPrime(capacity), nullptr);
	}
	// ��ϣͰ�е�Ԫ�ز����ظ�
	PNode* Insert(const V& data)
	{
		// ȷ���Ƿ���Ҫ���ݡ�����
		// _CheckCapacity();
// 1. ����Ԫ�����ڵ�Ͱ��
		size_t bucketNo = HashFunc(data);
		// 2. ����Ԫ���Ƿ���Ͱ��
		PNode pCur = _ht[bucketNo];
		while (pCur)
		{
			if (pCur->_data == data)
				return pCur;
			pCur = pCur->_pNext;
		}
		// 3. ������Ԫ��
		pCur = new Node(data);
		pCur->_pNext = _ht[bucketNo];
		_ht[bucketNo] = pCur;
		_size++;
		return pCur;
	}
	// ɾ����ϣͰ��Ϊdata��Ԫ��(data�����ظ�)������ɾ��Ԫ�ص���һ���ڵ�
	PNode* Erase(const V& data)
	{
		size_t bucketNo = HashFunc(data);
		PNode pCur = _ht[bucketNo];
		PNode pPrev = nullptr, pRet = nullptr;
		while (pCur)
		{
			if (pCur->_data == data)
			{
				if (pCur == _ht[bucketNo])
					_ht[bucketNo] = pCur->_pNext;
				else
					pPrev->_pNext = pCur->_pNext;
				pRet = pCur->_pNext;
				delete pCur;
				_size--;
				return pRet;
			}
		}
		return nullptr;
	}
	PNode* Find(const V& data);
	size_t Size()const;
	bool Empty()const;
	void Clear();
	bool BucketCount()const;
	void Swap(HashBucket<V, HF>& ht;
	~HashBucket();


	void _CheckCapacity()
	{
		size_t bucketCount = BucketCount();
		if (_size == bucketCount)
		{
			HashBucket<V, HF> newHt(bucketCount);
			for (size_t bucketIdx = 0; bucketIdx < bucketCount; ++bucketIdx)
			{
				PNode pCur = _ht[bucketIdx];
				while (pCur)
				{
					// ���ýڵ��ԭ��ϣ���в����
					_ht[bucketIdx] = pCur->_pNext;
					// ���ýڵ���뵽�¹�ϣ����
					size_t bucketNo = newHt.HashFunc(pCur->_data);
					pCur->_pNext = newHt._ht[bucketNo];
					newHt._ht[bucketNo] = pCur;
					pCur = _ht[bucketIdx];
				}
			}
			newHt._size = _size;
			this->Swap(newHt);
		}
	}


private:
	size_t HashFunc(const V& data)
	{
		return data % _ht.capacity();
	}
private:
	vector<PNode*> _ht;
	size_t _size; // ��ϣ������ЧԪ�صĸ���
};


// ��ϣ�������ô�������������ģ��key����ҪΪ���βſ��Դ����˴��ṩ��keyת��Ϊ���εķ���
// �������ݲ���Ҫת��
template<class T>
class DefHashF
{
public:
	size_t operator()(const T& val)
	{
		return val;
	}
};
// keyΪ�ַ������ͣ���Ҫ����ת��Ϊ����
class Str2Int
{
public:
	size_t operator()(const string& s)
	{
		const char* str = s.c_str();
		unsigned int seed = 131; // 31 131 1313 13131 131313
		unsigned int hash = 0;
		while (*str)
		{
			hash = hash * seed + (*str++);
		}
		return (hash & 0x7FFFFFFF);
	}
};
// Ϊ��ʵ�ּ򵥣��˹�ϣ�������ǽ��Ƚ�ֱ����Ԫ�ذ���һ��
template<class V, class HF>
class HashBucket
{
	// ����
private:
	size_t HashFunc(const V& data)
	{
		return HF()(data.first) % _ht.capacity();
	}
};

size_t GetNextPrime(size_t prime)
{
	const int PRIMECOUNT = 28;
	static const size_t primeList[PRIMECOUNT] =
	{
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul,
	25165843ul,
	50331653ul, 100663319ul, 201326611ul, 402653189ul,
	805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
	};
	size_t i = 0;
	for (; i < PRIMECOUNT; ++i)
	{
		if (primeList[i] > prime)
			return primeList[i];
	}
	return primeList[i];
}