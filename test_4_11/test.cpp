//// 哈希表每个空间给个标记
//// EMPTY此位置空， EXIST此位置已经有元素， DELETE元素已经删除
//enum State
//{
//	EMPTY,
//	EXIST,
//	DELETE
//};


#include <iostream>
using namespace std;

// 注意：假如实现的哈希表中元素唯一，即key相同的元素不再进行插入
// 为了实现简单，此哈希表中我们将比较直接与元素绑定在一起
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
		// 检测哈希表底层空间是否充足
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
			// 转一圈也没有找到，注意：动态哈希表，该种情况可以不用考虑，哈希表中元
			素个数到达一定的数量，哈希冲突概率会增大，需要扩容来降低哈希冲突，因此哈希表中元素是
			不会存满的
			if(hashAddr == startAddr)
			return false;
			*/
		}
		// 插入元素
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
// 本文所实现的哈希桶中key是唯一的
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
	// 哈希桶中的元素不能重复
	PNode* Insert(const V& data)
	{
		// 确认是否需要扩容。。。
		// _CheckCapacity();
// 1. 计算元素所在的桶号
		size_t bucketNo = HashFunc(data);
		// 2. 检测该元素是否在桶中
		PNode pCur = _ht[bucketNo];
		while (pCur)
		{
			if (pCur->_data == data)
				return pCur;
			pCur = pCur->_pNext;
		}
		// 3. 插入新元素
		pCur = new Node(data);
		pCur->_pNext = _ht[bucketNo];
		_ht[bucketNo] = pCur;
		_size++;
		return pCur;
	}
	// 删除哈希桶中为data的元素(data不会重复)，返回删除元素的下一个节点
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
					// 将该节点从原哈希表中拆出来
					_ht[bucketIdx] = pCur->_pNext;
					// 将该节点插入到新哈希表中
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
	size_t _size; // 哈希表中有效元素的个数
};


// 哈希函数采用处理余数法，被模的key必须要为整形才可以处理，此处提供将key转化为整形的方法
// 整形数据不需要转化
template<class T>
class DefHashF
{
public:
	size_t operator()(const T& val)
	{
		return val;
	}
};
// key为字符串类型，需要将其转化为整形
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
// 为了实现简单，此哈希表中我们将比较直接与元素绑定在一起
template<class V, class HF>
class HashBucket
{
	// ……
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