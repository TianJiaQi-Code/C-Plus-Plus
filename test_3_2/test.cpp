#include <iostream>
#include <vector>
using namespace std;

int func(int n)
{
    // ����ǰn���������
    vector<vector<int>> vvi;
    // n��
    vvi.resize(n);
    vvi[0].push_back(1);
    vvi[0].push_back(0);
    vvi[0].push_back(0);
    for (int i = 1; i < n; i++)
    {
        // ÿ��i*2+1�����֣�ĩβ������0
        vvi[i].resize(i * 2 + 1);
        // ��ʼ��ǰ������
        vvi[i][0] = 1;
        vvi[i][1] = i;
        // ����������
        for (int j = 2; j < i * 2 + 1; j++)
        {
            vvi[i][j] = vvi[i - 1][j] + vvi[i - 1][j - 1] + vvi[i - 1][j - 2];
        }
        // β������0
        vvi[i].push_back(0);
        vvi[i].push_back(0);

        if (i == n - 1)
        {
            // �ҵ�n�е�ż��
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