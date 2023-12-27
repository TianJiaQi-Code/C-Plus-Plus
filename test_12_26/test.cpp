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

int main()
{
    string s = "abb";
    if (isPalindrome(s))
        printf("true");
    else
        printf("false");
    return 0;
}