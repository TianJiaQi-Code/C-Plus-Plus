#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> fib;
    fib.resize(2);
    fib[0] = 0;
    fib[1] = 1;

    int n = 0;
    cin >> n;

    int i = 2;
    int min = n - fib[1];
    while (1)
    {
        fib.resize(i + 1);
        fib[i] = fib[i - 1] + fib[i - 2];

        if (fib[i] < n)
        {
            if (min > n - fib[i])
            {
                min = n - fib[i];
            }
        }
        else if (fib[i] == n)
        {
            return 0;
        }
        else if (fib[i] > n)
        {
            if (min > fib[i] - n)
            {
                min = fib[i] - n;
            }
            else
            {
                return min;
            }
        }

        i++;
    }

    return 0;
}