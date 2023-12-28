#include <iostream>
using namespace std;

bool isPalindrome(string s)
{
    string newStr = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }

        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            newStr.push_back(s[i]);
        }
    }

    int left = 0;
    int right = newStr.size() - 1;
    while (left++ < right--)
    {
        if (newStr[left] != newStr[right])
        {
            return false;
        }
    }
    return true;
}

class Solution
{
public:
    string reverseWords(string s)
    {
        int size = s.size();
        int begin = 0;
        int end = 0;
        for (int i = 0; i < size; i++)
        {
            if (s[i] == ' ')
            {
                end = i;
                reverse(s.begin() + begin, s.begin() + end);
                begin = end + 1;
            }
        }
        reverse(s.begin() + begin, s.end());

        return s;
    }
};

string multiply(string num1, string num2)
{
    int size1 = num1.size();
    int size2 = num2.size();
    int arr[500] = { 0 };
    int k = 0;  // 用来维护数组下标
    string ret = "";

    // 把未进位的乘积存入数组
    for (int j = size2 - 1; j >= 0; j--)
    {
        int tmp = k;
        for (int i = size1 - 1; i >= j; i--)
        {
            arr[k] += (num2[j] - '0') * (num1[i] - '0');
            k++;
        }
        k = tmp + 1;
    }
    // 开始进位
    for (int i = 0; i < size1 + size2 - 1; i++)
    {
        arr[i + 1] += arr[i] / 10;
        arr[i] %= 10;
    }
    // 把数组中（倒序）的数字转为字符串
    for (int i = size1 + size2 - 1; i >= 0; i--)
    {
        if (arr[i] == 0)
            continue;
        else
            ret.push_back(arr[i] + '0');
    }

    return ret;
}

//int main()
//{
//    string ret = multiply("123", "456");
//    cout << ret << endl;
//
//    //string s = "abb";
//    //if (isPalindrome(s))
//    //    printf("true");
//    //else
//    //    printf("false");
//    return 0;
//}

int main()
{
    string str = "";
    cin >> str;

    int begin = 0;
    int end = str.size();
    for (int i = 0; i < end; i++)
    {
        if (str[i] == ' ')
        {
            begin = i + 1;
        }
    }

    cout << end - begin;
}