#pragma once

namespace tjq
{
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			: _ptr(ptr)
		{}
		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "delete: " << _ptr << endl;
				delete _ptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}

		unique_ptr(const unique_ptr<T>& sp) = delete;
		unique_ptr& operator=(const unique_ptr<T>& sp) = delete;

	private:
		T* _ptr;
	};
}