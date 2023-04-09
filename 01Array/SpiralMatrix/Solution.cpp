#include "Solution.h"

vector<vector<int>> Solution::generateMatrix(int n)
{
	vector<vector<int>> ans(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
	int startX = 0, startY = 0; // 定义每循环一个圈的起始位置
	int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
	int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
	int count = 1; // 用来给矩阵中每一个空格赋值
	int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
	int i, j;
	while (loop--) {
		i = startX;
		j = startY;

		// 下面开始的四个for就是模拟转了一圈
		// 模拟填充上行从左到右(左闭右开)
		for (j = startY; j < n - offset; j++) {
			ans[startX][j] = count++;
		}
		// 模拟填充右列从上到下(左闭右开)
		for (i = startX; i < n - offset; i++) {
			ans[i][j] = count++;
		}
		// 模拟填充下行从右到左(左闭右开)
		for (; j > startY; j--) {
			ans[i][j] = count++;
		}
		// 模拟填充左列从下到上(左闭右开)
		for (; i > startX; i--) {
			ans[i][j] = count++;
		}

		// 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
		startX++;
		startY++;
		// offset 控制每一圈里每一条边遍历的长度
		offset += 1;
	}
	// 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
	if (n % 2) {
		ans[mid][mid] = count;
	}
	return ans;
}

vector<int> Solution::spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> ans;
	if (matrix.empty())
		return ans;
	int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
	int i;
	while (true) {
		for (i = left; i <= right; ++i) ans.push_back(matrix[top][i]); //向右移动直到最右
		if (++top > bottom) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
		for (i = top; i <= bottom; ++i) ans.push_back(matrix[i][right]); // 向下
		if (--right < left) break; //重新设定右边界
		for (i = right; i >= left; --i) ans.push_back(matrix[bottom][i]); // 向左
		if (--bottom < top) break; //重新设定下边界
		for (i = bottom; i >= top; --i) ans.push_back(matrix[i][left]); // 向上
		if (++left > right) break; //重新设定左边界
	}
	return ans;
}
