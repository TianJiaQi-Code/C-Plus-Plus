//#include <iostream>
//#include <vector>
//using namespace std;
//
//int rabbit(int n)
//{
//    vector<int> rabbit_age(1, 1);
//
//    for (int i = 2; i <= n; i++)
//    {
//        int size = rabbit_age.size();
//        for (int j = 0; j < size; j++)
//        {
//            rabbit_age[j]++;
//            if (rabbit_age[j] > 2)
//            {
//                rabbit_age.push_back(1);
//            }
//        }
//    }
//
//    return rabbit_age.size();
//}
//
//int main()
//{
//    int n;
//    while (cin >> n)
//    {
//        int ret = rabbit(n);
//        cout << ret << endl;
//    }
//    return 0;
//}