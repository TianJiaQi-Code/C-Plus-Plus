//#include <iostream>
//#include <string>
//using namespace std;
//
//// 判断字符串是否为回文串
//int func(string str)
//{
//    int left = 0;
//    int right = str.size() - 1;
//
//    while (left < right)
//    {
//        if (str[left] != str[right])
//        {
//            return 0;
//        }
//        left++;
//        right--;
//    }
//
//    return 1;
//}
//
//int main()
//{
//    string str1;
//    string str2;
//    getline(cin, str1);
//    getline(cin, str2);
//
//    int count = 0;
//    for (int i = 0; i <= str1.size(); i++)
//    {
//        string tmp = str1;
//        tmp.insert(i, str2);
//        if (func(tmp) == 1)
//        {
//            count++;
//        }
//    }
//
//    cout << count;
//
//    return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    vector<int> input;
    input.resize(n + 1);
    input[n] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    long long sum = 0;
    long long ret = 0;
    for (int i = 0; i <= n; i++)
    {
        if (input[i] > 0)
        {
            sum += input[i];
        }
        else
        {
            if (ret < sum)
            {
                ret = sum;
            }
            sum = 0;
        }
    }

    cout << ret;
    return 0;
}