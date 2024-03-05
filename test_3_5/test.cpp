#include <iostream>
#include <string>
using namespace std;

int str_str(string longs, string shorts)
{
    if (longs.size() < shorts.size())
    {
        swap(longs, shorts);
    }

    string ret = "";
    for (int i = 0; i < shorts.size(); i++)
    {
        string tmp;
        for (int j = 0; j < longs.size(); j++)
        {
            if (shorts[i] == longs[j])
            {
                tmp.push_back(shorts[i]);
            }
            else
            {
                if (tmp.size() > ret.size())
                {
                    ret = tmp;
                    tmp = "";
                }
            }
        }
    }

    return ret.size();
}

int main()
{
    string str1;
    string str2;
    while (cin >> str1)
    {
        cin >> str2;
        int ret = str_str(str1, str2);
        cout << ret << endl;
    }
    return 0;
}