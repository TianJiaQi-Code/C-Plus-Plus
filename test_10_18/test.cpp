// ���ǿ�������������ǲ��Ǻܽ�Ӳ��
class Date
{
public:
	void Init(int year)
	{
		// �����year�����ǳ�Ա���������Ǻ����βΣ�
		year = year;
	}
private:
	int year;
};

// ����һ�㶼��������
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

// ��������
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

// ������ʽҲ���Եģ���Ҫ����˾Ҫ��һ�㶼�ǼӸ�ǰ׺���ߺ�׺��ʶ���־��С�