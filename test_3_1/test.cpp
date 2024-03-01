//#include <iostream>
//using namespace std;
//
//// 求约数之和
//int func(int x)
//{
//    int ret = 0;
//    for (int i = 1; i < x; i++)
//    {
//        if (x % i == 0)
//        {
//            ret += i;
//        }
//    }
//    return ret;
//}
//
//int main()
//{
//    int n = 0;
//    while (cin >> n)
//    {
//        int count = 0;
//        for (int i = 1; i < n; i++)
//        {
//            if (func(i) == i)
//            {
//                count++;
//            }
//        }
//
//        cout << count;
//    }
//
//    return 0;
//}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    if (str.find("joker JOKER") != string::npos)
    {
        cout << "joker JOKER" << endl;
        return 0;
    }

    int pos = str.find('-');
    string poker1 = str.substr(0, pos);
    string poker2 = str.substr(pos + 1);

    string poker1_first = poker1.substr(0, 1);
    string poker2_first = poker2.substr(0, 1);

    int poker1_cnt = count(poker1.begin(), poker1.end(), ' ') + 1;
    int poker2_cnt = count(poker2.begin(), poker2.end(), ' ') + 1;

    

    if (poker1_cnt == poker2_cnt)
    {
        string tmp = "345678910JQKA2";
        if (tmp.find(poker1_first) > tmp.find(poker1_first))
        {
            cout << poker1;
        }
        else
        {
            cout << poker2;
        }
    }
    else if (poker1_cnt == 4 || poker2_cnt == 4)
    {

    }

    return 0;
}