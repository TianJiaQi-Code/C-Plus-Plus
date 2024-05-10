#pragma once
#include <functional>

template<class T>
class SmartPtr
{
public:
	// RAII
	SmartPtr(T* ptr)
		: _ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "delete: " << _ptr << endl;
		delete _ptr;
	}

	// 像指针一样
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};

namespace tjq
{
	template<class T>
	class auto_ptr
	{
	public:
		// RAII
		auto_ptr(T* ptr)
			: _ptr(ptr)
		{}

		// ap2(ap1)
		auto_ptr(auto_ptr<T>& ap)
		{
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}

		~auto_ptr()
		{
			cout << "delete: " << _ptr << endl;
			delete _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};

	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			: _ptr(ptr)
		{}

		unique_ptr(const unique_ptr<T>& ap) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& ap) = delete;

		~unique_ptr()
		{
			cout << "delete: " << _ptr << endl;
			delete _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};

	template<class T>
	class shared_ptr
	{
	public:
		template<class D>
		shared_ptr(T* ptr, D del)
			: _ptr(ptr)
			, _pcount(new int(1))
			, _del(del)
		{}

		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _pcount(new int(1))
		{}

		shared_ptr(const shared_ptr<T>& sp)
		{
			_ptr = sp._ptr;
			_pcount = sp._pcount;

			// 拷贝时++计数
			++(*_pcount);
		}

	private:
		T* _ptr;
		int* _pcount;
		function<void(T*)> _del = [](T* ptr) { delete ptr; };
	};
}