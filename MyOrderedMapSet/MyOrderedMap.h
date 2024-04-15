#pragma once
#include "HashTable.h"

namespace tjq
{
	template<class K, class V, class Hash = HashFunc<K>>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash>::iterator iterator;
		
		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		bool insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

	private:
		hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash> _ht;
	};
}