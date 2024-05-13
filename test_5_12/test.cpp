// 2024.5.31

// 1.�Ǽ�����
#include <iostream>
#include <vector>
using namespace std;

void Fibonacci(vector<int>& fib)
{
    for (int i = 2; i <= 10000; i++)
    {
        fib.push_back((fib[i - 1] + fib[i - 2]) % 10000);
    }
}

int main()
{
    // �ҹ��ɷ����������о���һ��쳲���������
    vector<int> fib = { 1, 1 };
    Fibonacci(fib);

    int n = 0;
    while (cin >> n)
    {
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            printf("%04d", fib[num]);
        }
        printf("\n");
    }

    return 0;
}

// 2.����
//#include <iostream>
//#include <string>
//using namespace std;
//
//int numRoot(int num)
//{
//    while (true)
//    {
//        int ret = 0;
//        while (num)
//        {
//            ret += num % 10;
//            num /= 10;
//        }
//
//        if (ret < 10)
//        {
//            return ret;
//        }
//        else
//        {
//            num = ret;
//        }
//    }
//}
//
//int main()
//{
//    // ʹ��string�����������ݣ��������
//    string str = "";
//    while (cin >> str)  // ��������
//    {
//        int num = 0;
//        for (auto& ch : str)
//        {
//            num += ch - '0';
//        }
//
//        cout << numRoot(num) << endl;
//    }
//
//    return 0;
//}