// 2024.5.17

// 1. �������������С������ɺ�
// [��̬�滮][��������]

// 2. �мٱ�
#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    while (cin >> n && n != 0)
    {
        // �ҷ�Ϊ3��: a, b, c
        // �趨aһ������b, ���ǲ�һ������c
        // ÿ�γ��ؿ����ų�2��: ����ٱ���a, b��, ���ų�c��a, b�бȽ��ص��Ƿ�
        //                    ����ٱ���c��, ���ų�a, b
        // �����������: ���a, b������c, ��ȡ�ϴ���Ƿݼ�����
        // ����a == b, д�������ʡ��b
        int ret = 0;
        int a = 0, c = 0;
        while (n != 1)  // n == 1 �Ͳ����ٳ���
        {
            if (n % 3 == 1)
            {
                a = n / 3;
                c = a + 1;
            }
            else if (n % 3 == 2)
            {
                c = n / 3;
                a = (n - c) / 2;
            }
            else
            {
                a = n / 3;
                c = a;
            }

            n = a > c ? a : c;
            ++ret;
        }

        cout << ret << endl;
    }

    return 0;
}