//// 两种排序方法
//#include <iostream>
//#include <string>
//#include <vector>
//#include <string.h>
//using namespace std;
//
//// 比较两个字符串的长度
//int lencmp(string str1, string str2)
//{
//    return str1.size() - str2.size();
//}
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//
//    vector<string> vs;
//    vs.resize(n);
//    for (int i = 0; i < n; i++)
//    {
//        cin >> vs[i];
//    }
//
//    int isdic = 1;  // 假设是字典序
//    int islen = 1;  // 假设是长度序
//    for (int i = 0; i < n - 1; i++)
//    {
//        if (strcmp(vs[i].c_str(), vs[i + 1].c_str()) > 0)
//        {
//            isdic = 0;
//        }
//        if (lencmp(vs[i], vs[i + 1]) > 0)
//        {
//            islen = 0;
//        }
//    }
//
//    if (isdic == 1 && islen == 0)
//        cout << "lexicographically";
//    else if (isdic == 0 && islen == 1)
//        cout << "lengths";
//    else if (isdic == 1 && islen == 1)
//        cout << "both";
//    else
//        cout << "none";
//
//    return 0;
//}

// 求最小公倍数
