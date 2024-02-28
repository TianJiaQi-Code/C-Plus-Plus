//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	const int a = 10;
//	int* p = (int*)(&a);
//	*p = 20;
//	cout << "a = " << a << ", *p = " << *p << endl;
//	return 0;//}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int count = 0;
    string input;
    getline(cin, input);

    vector<string> vs;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '"')
        {
            int pos = input.find('"', i + 1);
            if (pos == string::npos)
            {
                break;
            }

            vs.push_back(input.substr(i + 1, pos - i - 1));
            count++;
            i = pos + 1;
        }
        else
        {
            int pos = input.find(' ', i);
            if (pos == string::npos)
            {
                vs.push_back(input.substr(i));
                count++;
                break;
            }
            else
            {
                vs.push_back(input.substr(i, pos - i));
                count++;
                i = pos;
            }
        }
    }
    cout << count << endl;
    for (int i = 0; i < vs.size(); i++)
    {
        cout << vs[i] << endl;
    }
}