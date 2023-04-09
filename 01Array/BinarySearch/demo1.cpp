#include <iostream>
#include <string>

#include "Solution.h"

int main1()
{
    Solution s;
    vector<int> nums{ 1,2,3,4,6,8,9,10 };
    std::cout << s.searchInsert(nums, 11);

    std::cin.get();
    return 0;
}
