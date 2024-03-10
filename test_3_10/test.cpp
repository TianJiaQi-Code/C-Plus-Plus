//class Bonus
//{
//public:
//    int getMost(vector<vector<int> > board)
//    {
//        int len = board.size();
//        int wid = board[0].size();
//        vector<vector<int>> tmp(len, vector<int>(wid, 0));
//
//        tmp[0][0] = board[0][0];
//
//        for (int i = 0; i < len; i++)
//        {
//            for (int j = 0; j < wid; j++)
//            {
//                if (i == 0 && j == 0)
//                {
//                    continue;
//                }
//                else if (i == 0)
//                {
//                    tmp[i][j] = tmp[i][j - 1] + board[i][j];
//                }
//                else if (j == 0)
//                {
//                    tmp[i][j] = tmp[i - 1][j] + board[i][j];
//                }
//                else
//                {
//                    tmp[i][j] = max(tmp[i - 1][j], tmp[i][j - 1]) + board[i][j];
//                }
//            }
//        }
//        return tmp[len - 1][wid - 1];
//    }
//};