#include <iostream>
#include <string>
#include "Solution.h"

int main()
{
	Solution s;
	vector<int> nums{ 1,2,3,5,6,7,7,7,8,9,10 };
	auto ans = s.searchRange(nums, 7);
	for (const auto i : ans)
		std::cout << i << " ";

	std::cin.get();
	return 0;
}