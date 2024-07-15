#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int ret = 0;
    unordered_set<char> hash;
    for (int left = 0, right = 0; right < s.size(); right++)
    {
        while (hash.count(s[right]))
        {
            ret = max(right - left, ret);
            hash.erase(s[left]);
            left++;
        }
        hash.insert(s[right]);
    }
    return ret;
}

int main()
{
    cout << lengthOfLongestSubstring("abcabcbb");
    return 0;
}