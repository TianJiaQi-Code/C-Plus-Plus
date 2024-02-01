//#include <iostream>
//#include <vector>
//using namespace std;
//
//// 井字棋
//class Board
//{
//public:
//    bool checkWon(vector<vector<int> > board)
//    {
//        // write code here
//        if ((board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == 1) ||
//            (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == 1) ||
//            (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == 1) ||
//            (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == 1) ||
//            (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == 1) ||
//            (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == 1) ||
//            (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 1) ||
//            (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 1))
//        {
//            return true;
//        }
//        return false;
//    }
//};

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int score = 0;

    // 一、密码长度:
    if (str.size() <= 4)
        score += 5;
    else if (str.size() >= 5 && str.size() <= 7)
        score += 10;
    else if (str.size() >= 8)
        score += 25;

    // 二、字母:
    int big = 0;
    int small = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            small++;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            big++;
    }

    if (big && small)
        score += 20;
    else if (big || small)
        score += 10;

    // 三、数字:
    int numsum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            numsum++;
    }

    if (numsum == 1)
        score += 10;
    else if (numsum > 1)
        score += 20;

    // 四、符号:
    int symsum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if ((str[i] >= 0x21 && str[i] <= 0x2F) ||
            (str[i] >= 0x3A && str[i] <= 0x40) ||
            (str[i] >= 0x5B && str[i] <= 0x60) ||
            (str[i] >= 0x7B && str[i] <= 0x7E))
            symsum++;
    }

    if (symsum == 1)
        score += 10;
    else if (symsum > 1)
        score += 25;

    // 五、奖励（只能选符合最多的那一种奖励）:
    if (big && small && numsum && symsum)
        score += 5;
    else if ((big || small) && numsum && symsum)
        score += 3;
    else if ((big || small) && numsum)
        score += 2;


    if (score >= 90)
        cout << "VERY_SECURE";
    else if (score >= 80)
        cout << "SECURE";
    else if (score >= 70)
        cout << "VERY_STRONG";
    else if (score >= 60)
        cout << "STRONG";
    else if (score >= 50)
        cout << "AVERAGE";
    else if (score >= 25)
        cout << "WEAK";
    else if (score >= 0)
        cout << "VERY_WEAK";

    return 0;
}