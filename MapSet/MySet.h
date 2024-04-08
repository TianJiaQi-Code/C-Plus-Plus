#pragma once

#include "RBTree.h"

namespace tjq
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		typedef typename RBTree<K, const K, SetKeyOfT>::iterator iterator;
		typedef typename RBTree<K, const K, SetKeyOfT>::const_iterator const_iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _t.Insert(key);
		}

		iterator find(const K& key)
		{
			return _t.Find(key);
		}

	private:
		RBTree<K, const K, SetKeyOfT> _t;
	};
}