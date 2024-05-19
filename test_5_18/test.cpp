// 2024.5.18

// 1. 最难的问题
#include <iostream>
#include <string>
using namespace std;

string password(const string& str)
{
    string decode = "VWXYZABCDEFGHIJKLMNOPQRSTU";
    string ret = "";
    for (const auto& ch : str)
    {
        if (ch == ' ')
        {
            ret += ' ';
        }
        else
        {
            ret += decode[ch - 'A'];
        }
    }
    return ret;
}

int main()
{
    string str;
    while (getline(cin, str))
    {
        cout << password(str) << endl;
    }
    return 0;
}

// 2. 因子个数
#include <iostream>
#include <cmath>
using namespace std;

int PrimeFactor(int& n)
{
    int ret = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) // 是因子
        {
            while (n % i == 0)
            {
                n = n / i;
            }

            ++ret;
        }
    }

    if (n != 1)
    {
        ++ret;
    }

    return ret;
}

int main()
{
    int n = 0;
    while (cin >> n)
    {
        // 本质是求质因子的个数
        cout << PrimeFactor(n) << endl;
    }
    return 0;
}