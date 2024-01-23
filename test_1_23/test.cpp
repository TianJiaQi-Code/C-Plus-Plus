//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    vector<int> v1;
//    int n = 0;
//    cin >> n;
//
//    // ÊäÈë
//    for (int i = 0; i < n * 3; i++)
//    {
//        int tmp = 0;
//        cin >> tmp;
//        v1.push_back(tmp);
//    }
//    sort(v1.begin(), v1.end()); // Ä¬ÈÏÉıĞò
//
//    vector<int> v2(v1.begin() + n, v1.end());
//
//    int sum = 0;
//    for (int i = 0; i < v2.size(); i += 2)
//    {
//        sum += v2[i];
//    }
//
//    cout << sum;
//}

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1;    // They are students. 
    getline(cin, str1);

    string del;     // aeiou
    getline(cin, del);

    for (int i = 0; i < del.size(); i++)
    {
        while (1)
        {
            int pos = str1.find(del[i]);
            if (pos == -1)
                break;
            str1.erase(pos);
        }
    }

    cout << str1;
}