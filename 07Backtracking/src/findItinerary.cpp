#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using std::map;
using std::string;
using std::unordered_map;
using std::vector;

/**
 * @brief 332. 重新安排行程
 * @see https://leetcode-cn.com/problems/reconstruct-itinerary/
 *
 * @param tickets 机票
 * @return 重新安排的行程
 * @note 1. 机票数量范围 [1, 3000]
 *       2. 机票的格式 [出发机场, 到达机场]
 *       3. 机票的格式 [出发机场, 到达机场]
 *       4. 所有机票的出发机场都不同
 *       5. 所有机票的到达机场都不同
 *       6. 假定所有机票都能够成功使用
 *
 */
class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        targets.clear();
        vector<string> result;
        for (const auto &v : tickets)
        {
            targets[v[0]][v[1]]++; // 记录映射关系
        }
        result.push_back("JFK"); // 起始机场
        backtracking(tickets.size(), result);
        return result;
    }

private:
    // unordered_map<出发机场, map<到达机场, 航班次数>> targets
    unordered_map<string, map<string, int>> targets;
    bool backtracking(int ticketNum, vector<string> &result)
    {
        if (result.size() == ticketNum + 1) // 找到一条路径
        {
            return true;
        }
        // 遍历所有可能的航班
        for (std::pair<const string, int> &target : targets[result.back()]) // targets[result.back()] 表示当前机场的所有航班
        {
            if (target.second > 0) // 有航班
            {
                result.push_back(target.first);      // 选择
                target.second--;                     // 使用
                if (backtracking(ticketNum, result)) // 回溯
                {
                    return true;
                }
                result.pop_back(); // 撤销选择
                target.second++;   // 撤销使用
            }
        }
        return false;
    }
};