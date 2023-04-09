#include <iostream>

#include "Solution.h"
Solution sln;

int main()
{
	int n = 4;
	auto ans = sln.generateMatrix(n);

	for (const auto& row : ans) {
		for (const auto& num : row)
			std::cout << num << " ";
		std::cout << "\n";
	}

	std::cout << "\n\n";
	vector<vector<int>> matrix{ {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	auto ans2 = sln.spiralOrder(matrix);
	for (const auto i : ans2)
		std::cout << i << " ";

	return 0;
}