// 2024.5.17

// 1. 求正数数组的最小不可组成和
// [动态规划][背包问题]

// 2. 有假币
#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    while (cin >> n && n != 0)
    {
        // 币分为3份: a, b, c
        // 设定a一定等于b, 但是不一定等于c
        // 每次称重可以排除2份: 如果假币在a, b中, 则排除c和a, b中比较重的那份
        //                    如果假币在c中, 则排除a, b
        // 考虑最差的情况: 如果a, b不等于c, 则取较大的那份继续称
        // 由于a == b, 写代码可以省略b
        int ret = 0;
        int a = 0, c = 0;
        while (n != 1)  // n == 1 就不用再称了
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