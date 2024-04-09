#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


vector<string> uncommonFromSentences(string s1, string s2)
{
    string str = s1 + " " + s2 + " ";
    unordered_map<string, int> um;

    // 分割字符串入哈希表
    int begin = 0, end = 0;
    while (begin < str.size())
    {
        // size_t find (const string& str, size_t pos = 0) const;
        end = str.find(" ", begin);

        // string (const string& str, size_t pos, size_t len = npos);
        int npos = end - begin;
        string key(str, begin, npos);
        ++um[key];

        begin = end + 1;
    }

    // 找到出现次数为 1 的单词
    vector<string> ret;
    for (auto& e : um)
    {
        if (e.second == 1)
        {
            ret.push_back(e.first);
        }
    }

    return ret;
}


int main()
{
    string str1 = "this apple is sweet";
    string str2 = "this apple is sour";
    
    
    vector<string> out = uncommonFromSentences(str1, str2);

    return 0;
}