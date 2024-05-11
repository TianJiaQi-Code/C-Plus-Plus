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

		void release()
		{
			// 说明最后一个管理对象析构了，可以释放资源了
			if (--(*_pcount) == 0)
			{
				cout << "delete: " << _ptr << endl;
				_del(_ptr);
				delete _pcount;
			}
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				release();

				_ptr = sp._ptr;
				_pcount = sp._pcount;

				// 拷贝时++引用计数
				++(*_pcount);
			}

			return *this;
		}

		~shared_ptr()
		{
			release();
		}

		int use_count()
		{
			return *_pcount;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get() const
		{
			return _ptr;
		}

	private:
		T* _ptr;
		int* _pcount;
		function<void(T*)> _del = [](T* ptr) { delete ptr; };
	};

	// 不支持RAII，不参与资源管理
	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			: _ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& sp)
		{
			_ptr = sp.get();
		}

		weak_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			_ptr = sp.get();
			return *this;
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
}