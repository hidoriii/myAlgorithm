#include "Solution.h"

vector<vector<int>> Solution::generateMatrix(int n)
{
	vector<vector<int>> ans(n, vector<int>(n, 0)); // ʹ��vector����һ����ά����
	int startX = 0, startY = 0; // ����ÿѭ��һ��Ȧ����ʼλ��
	int loop = n / 2; // ÿ��Ȧѭ�����Σ�����nΪ����3����ôloop = 1 ֻ��ѭ��һȦ�������м��ֵ��Ҫ��������
	int mid = n / 2; // �����м��λ�ã����磺nΪ3�� �м��λ�þ���(1��1)��nΪ5���м�λ��Ϊ(2, 2)
	int count = 1; // ������������ÿһ���ո�ֵ
	int offset = 1; // ��Ҫ����ÿһ���߱����ĳ��ȣ�ÿ��ѭ���ұ߽�����һλ
	int i, j;
	while (loop--) {
		i = startX;
		j = startY;

		// ���濪ʼ���ĸ�for����ģ��ת��һȦ
		// ģ��������д�����(����ҿ�)
		for (j = startY; j < n - offset; j++) {
			ans[startX][j] = count++;
		}
		// ģ��������д��ϵ���(����ҿ�)
		for (i = startX; i < n - offset; i++) {
			ans[i][j] = count++;
		}
		// ģ��������д��ҵ���(����ҿ�)
		for (; j > startY; j--) {
			ans[i][j] = count++;
		}
		// ģ��������д��µ���(����ҿ�)
		for (; i > startX; i--) {
			ans[i][j] = count++;
		}

		// �ڶ�Ȧ��ʼ��ʱ����ʼλ��Ҫ���Լ�1�� ���磺��һȦ��ʼλ����(0, 0)���ڶ�Ȧ��ʼλ����(1, 1)
		startX++;
		startY++;
		// offset ����ÿһȦ��ÿһ���߱����ĳ���
		offset += 1;
	}
	// ���nΪ�����Ļ�����Ҫ�������������м��λ�ø�ֵ
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
		for (i = left; i <= right; ++i) ans.push_back(matrix[top][i]); //�����ƶ�ֱ������
		if (++top > bottom) break; //�����趨�ϱ߽磬���ϱ߽�����±߽磬�����������ɣ���ͬ
		for (i = top; i <= bottom; ++i) ans.push_back(matrix[i][right]); // ����
		if (--right < left) break; //�����趨�ұ߽�
		for (i = right; i >= left; --i) ans.push_back(matrix[bottom][i]); // ����
		if (--bottom < top) break; //�����趨�±߽�
		for (i = bottom; i >= top; --i) ans.push_back(matrix[i][left]); // ����
		if (++left > right) break; //�����趨��߽�
	}
	return ans;
}
