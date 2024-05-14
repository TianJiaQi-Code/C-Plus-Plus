// 2024-5-14

// 1. ��̨����չ����
class Solution
{
public:
    int jumpFloorII(int number)
    {
        // F(n) = F(n-1) + F(n-2) + ... + F(1) + 1
        //      = 2^(n-1)
        return pow(2, number - 1);
    }
};

// 2. �쵽������
#include <iostream>
using namespace std;

// C = 2 * pi * r
double circumference(double& radius)
{
    return 2 * 3.14 * radius;
}

int main()
{
    double n = 0;  // è��
    double r = 0;  // ��뾶
    while (cin >> n >> r)
    {
        if (circumference(r) >= n)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}