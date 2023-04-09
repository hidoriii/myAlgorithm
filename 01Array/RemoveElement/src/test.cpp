#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

#include "Solution.h"
Solution sln;

void test1()
{
	vector<int> nums{ 1,2,3,5,0,6,0 };
	sln.moveZeroes(nums);
	for (const auto& i : nums)
		std::cout << i << " ";
}

void test2()
{
    string s("a#c"), t("b");
	if (sln.backspaceCompare(s, t))
		std::cout << "yes\n";
	else
		std::cout << "no\n";
}

int main()
{
	test2();

    std::cin.get();
    return 0;
}
