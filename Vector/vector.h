#pragma once
#include <assert.h>

namespace tjq
{
	template<class T>
	class vector
	{
	public:
		// Vector的迭代器是一个原生指针
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
		{}

		vector(const vector<T>& v)
		{
			reserve(v.capacity());
			for (const auto& e : v)
			{
				push_back(e);
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endOfStorage, v._endOfStorage);
		}

		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		_vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endOfStorage = nullptr;
			}
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old = size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, old * sizeof(T));
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + old;
				_endOfStorage = _start + n;
			}
		}

		void resize(size_t n, T val = T());

		void push_back(const T& x)
		{
			if (_finish == _endOfStorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}

			*_finish = x;
			++_finish;
		}

		void pop_back()
		{
			assert(size() > 0);
			--_finish;
		}

		void insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);

			if (_finish == _endOfStorage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}
			memmove(pos + 1, pos, sizeof(T) * (_finish - pos));
			*pos = x;

			++_finish;
		}

		void erase(iterator pos);

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endOfStorage - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

	private:
		iterator _start = nullptr;			// 指向数据块的开始
		iterator _finish = nullptr;			// 指向有效数据的尾
		iterator _endOfStorage = nullptr;	// 指向存储容量的尾
	};
}