#include <iostream>
#include <string>

#include "Solution.h"

int main0()
{
    Solution sln;
    vector<int> nums{ 1,2,4,6,8,9,10 };
    std::cout << sln.search_1(nums, 4) << std::endl;
    std::cout << sln.search_2(nums, 4) << std::endl;

    std::cin.get();
    return 0;
}
