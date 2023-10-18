// 我们看看这个函数，是不是很僵硬？
class Date
{
public:
	void Init(int year)
	{
		// 这里的year到底是成员变量，还是函数形参？
		year = year;
	}
private:
	int year;
};

// 所以一般都建议这样
class Date
{
public:
	void Init(int year)
	{
		_year = year;
	}
private:
	int _year;
};

// 或者这样
class Date
{
public:
	void Init(int year)
	{
		mYear = year;
	}
private:
	int mYear;
};

// 其他方式也可以的，主要看公司要求。一般都是加个前缀或者后缀标识区分就行。