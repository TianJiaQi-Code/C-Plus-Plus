// 2024.5.31

// 1.星际密码
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
    // 找规律发现密码数列就是一个斐波那契数列
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

// 2.数根
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
//    // 使用string保存输入数据，避免溢出
//    string str = "";
//    while (cin >> str)  // 多组输入
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