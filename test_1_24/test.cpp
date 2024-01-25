//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    // ����
//    int n = 0;
//    cin >> n;
//
//    vector<int> v;
//    v.resize(n);
//    for (int i = 0; i < n; i++)
//    {
//        cin >> v[i];
//    }
//
//    // ����
//    int cur = 0;
//    int next = cur + 1;
//    int count = 0;
//    while (next < n)
//    {
//        if (v[cur] > v[next])
//        {
//            while (v[cur] > v[next] || v[cur] == v[next]) // ����
//            {
//                cur++;
//                next++;
//            }
//            count++;
//            cur = next;
//        }
//        else if (v[cur] < v[next])
//        {
//            while (v[cur] < v[next] || v[cur] == v[next]) // ����
//            {
//                cur++;
//                next++;
//            }
//            count++;
//            cur = next;
//        }
//        else
//        {
//            cur++;
//            next++;
//        }
//    }
//
//    // ���
//    cout << count;
//}

// ����������
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ����
    int n = 0;
    cin >> n;

    vector<int> v;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // ����
    int count = 0;
    int i = 0;
    while (i < n) {
        if (v[i] < v[i + 1]) {
            while (i + 1 < n && v[i] <= v[i + 1]) {
                i++;
            }
            count++;
            i++;
        }
        else if (v[i] == v[i + 1]) {
            i++;
        }
        else if (v[i] > v[i + 1]) {
            while (i + 1 < n && v[i] >= v[i + 1]) {
                i++;
            }
            count++;
            i++;
        }
    }

    // ���
    cout << count;
}


//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    string str;
//    getline(cin, str);
//
//    reverse(str.begin(), str.end());
//
//    int left = 0;
//    int right = 0;
//    while (1)
//    {
//        right = str.find(' ', left);
//        if (right == -1)
//            break;
//
//        reverse(str.begin() + left, str.begin() + right);
//
//        left = right + 1;
//    }
//
//    cout << str;
//}