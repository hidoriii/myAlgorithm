#include "../include/leetcode.h"

/**
 * @brief 406. 根据身高重建队列
 * @see https://leetcode.cn/problems/queue-reconstruction-by-height/
 */
class Solution
{
public:
    // 版本一：使用vector（动态数组）
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) -> bool
             { if(a[0] == b[0]) return a[1] < b[1]; return a[0] > b[0]; }); // 身高从大到小排（身高相同k小的站前面）
        vector<vector<int>> que;
        for (int i = 0; i < people.size(); i++)
        {
            que.insert(que.begin() + people[i][1], people[i]); // 插入到下标为 k 的位置
        }
        return que;
    }

    // 版本二：使用list（链表）
    vector<vector<int>> reconstructQueue_2(vector<vector<int>> &people)
    {
        // 身高从大到小排（身高相同k小的站前面）
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) -> bool
             { if(a[0] == b[0]) return a[1] < b[1]; return a[0] > b[0]; });
        list<vector<int>> que; // list底层是链表实现，插入效率比 vector高的多
        for (int i = 0; i < people.size(); i++)
        {
            int pos = people[i][1]; // 插入到下标为 pos的位置
            auto iter = que.begin();
            while (pos--) // 寻找在插入位置
            {
                iter++;
            }
            que.insert(iter, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }

    // 版本三：使用vector，但不让它动态扩容
    vector<vector<int>> reconstructQueue_2(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) -> bool
             { if(a[0] == b[0]) return a[1] < b[1]; return a[0] > b[0]; });
        vector<vector<int>> que(people.size(), vector<int>(2, -1));
        for (int i = 0; i < people.size(); i++)
        {
            int pos = people[i][1];
            if (pos == que.size() - 1)
            {
                que[pos] = people[i];
            }
            else
            {
                for (int j = que.size() - 2; j >= pos; j--)
                {
                    que[j + 1] = que[j];
                }
                que[pos] = people[i];
            }
        }
        return que;
    }
};