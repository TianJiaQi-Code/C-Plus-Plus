class Date
{
public:
	// 1.�޲ι��캯��
	Date()
	{}
	// 2.���ι��캯��
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d1; // �����޲ι��캯��
	Date d2(2015, 1, 1); // ���ô��εĹ��캯��

	// ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
	// ���´���ĺ�����������d3�������ú����޲Σ�����һ���������͵Ķ���
	// warning C4930: ��Date d3(void)��: δ����ԭ�ͺ���(�Ƿ��������ñ��������?)
	Date d3();
}