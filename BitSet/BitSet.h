#pragma once
#include <assert.h>

namespace tjq
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_bits.resize(N / 32 + 1, 0);
		}

		// 把 x 映射的位标记成 1
		void set(size_t x)
		{
			assert(x <= N);

			size_t i = x / 32;
			size_t j = x % 32;

			_bits[i] |= (1 << j);
		}

		void reset(size_t x)
		{
			assert(x <= N);

			size_t i = x / 32;
			size_t j = x % 32;

			_bits[i] &= ~(1 << j);
		}

		bool test(size_t x)
		{
			assert(x <= N);

			size_t i = x / 32;
			size_t j = x % 32;

			return _bits[i] & (1 << j);
		}

	private:
		vector<int> _bits;
	};

	template<size_t N>
	class two_bit_set
	{
	public:
		void set(size_t x)
		{
			// 00 -> 01
			if (_bs1.test(x) == false &&
				_bs2.test(x) == false)
			{
				_bs2.set(x);
			}
			else if (_bs1.test(x) == false
				&& _bs2.test(x) == true)
			{
				// 01 -> 10
				_bs1.set(x);
				_bs2.reset(x);
			}
		}

		bool test(size_t x)
		{
			if (_bs1.test(x) == false &&
				_bs2.test(x) == true)
			{
				return true;
			}

			return false;
		}

	private:
		bitset<N> _bs1;
		bitset<N> _bs2;
	};
}