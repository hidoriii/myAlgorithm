#include <iostream>
#include "Solution.h"
Solution sln;

int main()
{
	string s1("anagram"), s2("nagaram");
	if (sln.isAnagram(s1, s2)) {
		std::cout << "yes\n";
	}
	else {
		std::cout << "no\n";
	}

	std::cin.get();
	return 0;
}