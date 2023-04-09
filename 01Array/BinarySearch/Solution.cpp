#include <iostream>
#include "Solution.h"

inline int Solution::mySqrt(int x)
{
	int left = 0, right = x;
	int ans = -1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if ((long long)mid * mid <= x) {
			ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return ans;
}

inline bool Solution::isPerfectSquare(int num)
{
	int left = 0, right = num;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if ((long long)mid * mid < num) 
			left = mid + 1;
		else if ((long long)mid * mid > num) 
			right = mid - 1;
		else 
			return true;
	}
	return false;
}
