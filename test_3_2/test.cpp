#include <iostream>
#include <vector>
using namespace std;

int func(int n)
{
    // 构建前n行杨辉三角
    vector<vector<int>> vvi;
    // n行
    vvi.resize(n);
    vvi[0].push_back(1);
    vvi[0].push_back(0);
    vvi[0].push_back(0);
    for (int i = 1; i < n; i++)
    {
        // 每行i*2+1个数字，末尾补两个0
        vvi[i].resize(i * 2 + 1);
        // 初始化前两个数
        vvi[i][0] = 1;
        vvi[i][1] = i;
        // 计算后面的数
        for (int j = 2; j < i * 2 + 1; j++)
        {
            vvi[i][j] = vvi[i - 1][j] + vvi[i - 1][j - 1] + vvi[i - 1][j - 2];
        }
        // 尾插两个0
        vvi[i].push_back(0);
        vvi[i].push_back(0);

        if (i == n - 1)
        {
            // 找第n行的偶数
            for (int k = 0; k < vvi[i].size() - 2; k++)
            {
                if (vvi[i][k] % 2 == 0)
                {
                    return k + 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    int input;
    while (cin >> input)
    {
        int ret = func(input);
        cout << ret << endl;
    }
    return 0;
}