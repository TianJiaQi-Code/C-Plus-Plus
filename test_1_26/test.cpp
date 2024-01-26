#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    vector<int> ret;

    while (M != 0)
    {
        ret.push_back(M % N);
        M /= N;
    }

    for (int i = ret.size() - 1; i >= 0; i--)
    {
        if (N < 10)
        {
            cout << ret[i];
        }
        else if (N >= 10 && N <= 15)
        {
            char tmp = ret[i] + 55;
            cout << tmp;
        }
    }
}