#pragma once
#include "HashTable.h"

namespace tjq
{
	template<class K, class Hash = HashFunc<K>>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		typedef typename hash_bucket::HashTable<K, const K, SetKeyOfT, Hash>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		bool insert(const K& key)
		{
			return _ht.Insert(key);
		}

	private:
		hash_bucket::HashTable<K, const K, SetKeyOfT, Hash> _ht;
	};
}