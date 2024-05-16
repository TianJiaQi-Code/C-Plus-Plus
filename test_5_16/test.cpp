// 2024-5-16

// 1.
//#include <iostream>
//#include <list>
//using namespace std;
//
//void Reverse(int& n, list<int>& lst, int& left, int& right)
//{
//    list<int> rlst;
//
//    auto it = lst.begin();
//    for (int i = 0; i < right; i++)
//    {
//        // 使用临时变量避免迭代器失效：如果迭代器指向元素被删除，迭代器就会失效
//        auto tmpit = it;
//        ++it;
//
//        if (i >= left - 1)
//        {
//            // void splice (iterator position, list& x, iterator i);
//            rlst.splice(rlst.begin(), lst, tmpit);
//        }
//    }
//
//    // 把反转后的子链表拼接回主链表
//    it = lst.begin();
//    for (int i = 0; i < left - 1; i++)
//    {
//        ++it;
//    }
//    // void splice (iterator position, list& x);
//    lst.splice(it, rlst);
//}
//
//int main()
//{
//    int n = 0;
//    while (cin >> n)
//    {
//        list<int> lst;
//        int left = 0, right = 0;
//        for (int i = 0; i < n; i++)
//        {
//            int tmp = 0;
//            cin >> tmp;
//            lst.push_back(tmp);
//        }
//        cin >> left >> right;
//
//        Reverse(n, lst, left, right);
//        for (auto& e : lst)
//        {
//            cout << e << ' ';
//        }
//        cout << endl;
//    }
//
//    return 0;
//}

// 2. 猴子分桃
