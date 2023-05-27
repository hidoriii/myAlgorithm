#include <string>
#include <vector>
using std::string;
using std::vector;

/**
 * @brief 51. N皇后
 * @see https://leetcode.cn/problems/n-queens/
 */
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        result.clear();
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }

private:
    vector<vector<string>> result;
    // n 为输入的棋盘大小
    // row 是当前递归到棋盘的第几行了
    void backtracking(int n, int row, vector<string> &chessboard)
    {
        if (row == n)
        {
            result.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isValid(row, col, chessboard, n)) // 验证合法就可以放
            {
                chessboard[row][col] = 'Q'; // 放置皇后
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.'; // 回溯，撤销皇后
            }
        }
    }

    bool isValid(int row, int col, vector<string> &chessboard, int n)
    {
        // 检查列
        for (int i = 0; i < row; i++) // 这是一个剪枝
        {
            if (chessboard[i][col] == 'Q')
            {
                return false;
            }
        }
        // 检查右斜线
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        // 检查左斜线
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
};