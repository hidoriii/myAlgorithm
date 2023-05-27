#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using std::map;
using std::string;
using std::unordered_map;
using std::vector;

/**
 * @brief 37. 解数独
 * @see https://leetcode-cn.com/problems/sudoku-solver/
 *
 * @param board 数独
 * @return 是否成功解数独
 * @note 1. 数独的解法需遵循如下规则：
 *       2. 数字 1-9 在每一行只能出现一次。
 *       3. 数字 1-9 在每一列只能出现一次。
 *       4. 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 *       5. 空白格用 '.' 表示。
 *       6. 给定的数独序列只包含数字 1-9 和字符 '.' 。
 *       7. 你可以假设给定的数独只有唯一解。
 *       8. 给定数独永远是 9x9 形式的。
 */
class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        backtracking(board);
    }

private:
    bool backtracking(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++) // 遍历行
        {
            for (int j = 0; j < board[0].size(); j++) // 遍历列
            {
                if (board[i][j] != '.') // 如果不是空白格，就跳过
                {
                    continue;
                }
                for (char k = '1'; k <= '9'; k++) // (i, j) 这个位置放 k 是否合适
                {
                    if (isValid(i, j, k, board)) // 如果合适，放入棋盘
                    {
                        board[i][j] = k;         // 放置k
                        if (backtracking(board)) // 如果找到合适一组立刻返回
                        {
                            return true;
                        }
                        board[i][j] = '.'; // 回溯，撤销k
                    }
                }
                return false; // 1-9 试完都不行，那么就返回 false
            }
        }
        return true; // 遍历完没有返回 false，说明找到了合适棋盘位置了
    }
    bool isValid(int row, int col, char val, vector<vector<char>> &board)
    {
        // 判断行里是否重复
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == val)
            {
                return false;
            }
        }
        // 判断列里是否重复
        for (int j = 0; j < 9; j++)
        {
            if (board[j][col] == val)
            {
                return false;
            }
        }
        // 判断9方格里是否重复
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++)
        {
            for (int j = startCol; j < startCol + 3; j++)
            {
                if (board[i][j] == val)
                {
                    return false;
                }
            }
        }
        return true;
    }
};