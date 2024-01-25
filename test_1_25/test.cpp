#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    vector<vector<int>> vv;
    vv.resize(10);

    int i = 0;
    int vsi = 0;
    while (str[i] != '\0')
    {
        if ((str[i] != '\0') && ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
        {
            i++;
            continue;
        }
        else if ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
        {
            int vsj = 0;
            while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
            {
                vv[vsi].resize(vsj + 1);
                vv[vsi][vsj] = str[i] - '0';

                i++;
                vsj++;
            }
            vsi++;
        }
    }

    vector<int> sizeV;
    sizeV.resize(10);
    int max = 0;
    for (i = 0; i < vv.size(); i++)
    {
        sizeV[i] = vv[i].size();
        if (sizeV[i] > sizeV[max])
        {
            max = i;
        }
    }

    for (i = 0; i < vv[max].size(); i++)
    {
        cout << vv[max][i];
    }
}