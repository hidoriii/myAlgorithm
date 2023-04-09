#include <iostream>
#include <string>
#include "Solution.h"

int main()
{
	Solution sln;
	vector<int> nums{ 1,2,2,3,3,3,4,4,5 };
	auto ans = sln.removeDuplicates(nums);
	std::cout << ans << "\n";
	for (int i = 0; i < ans; i++)
		std::cout << nums[i] << " ";

	std::cin.get();
	return 0;
}
