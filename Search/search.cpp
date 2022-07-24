#include "search.h"
using namespace std;

/*
* 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
* 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出重复的数字。.
*/
vector<int> search_Algorithm::findRepeatNumber(vector<int>& nums)
{	
	//定义一个存放值的哈希表imap
	map<int, bool> imap;
	int num;
	//存放重复数字的数组sum
	vector<int> sum;
	for (int i = 0; i < nums.size(); i++)
	{	
		//获取nums数组的元素
		num = nums[i];
		//判断获取到的元素是否在哈希表，有的话就是重复数字，加入数组sum
		if (imap[num])
			sum.push_back(num);
		//往哈希表存放数据元素
		imap[num] = true;
	}
	return sum;
}


/*
* 统计一个数字在排序数组中出现的次数
*/

int search_Algorithm::search(vector<int>& nums, int target)
{	
	//获取出现次数
	return helper(nums, target) - helper(nums, target - 1);
}
int search_Algorithm::helper(vector<int>& nums, int tar) 
{	
	//i(左边界)  j(右边界)
	int i = 0, j = nums.size() - 1;
	while (i <= j)
	{	
		//找到数组的中位数
		int m = (i + j) / 2;
		//如果数组中位数索引的元素小于要找的值，更改左边界，如果大于，更改右边界
		if (nums[m] <= tar)
			i = m + 1;
		else
			j = m - 1;

	}
	return i;
}

/*
* 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字
*/

int search_Algorithm::missingNumber(vector<int>& nums)
{	
	//i(左边界)  j(右边界)
	int i = 0, j = nums.size() - 1;
	while (i <= j)
	{	
		//找到数组的中位数
		int m = (i + j) / 2;

		if (nums[m] == m)
			i = m + 1;
		else
			j = m - 1;
	}

	return i;
}


/*
* 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

bool search_Algorithm::findNumberIn2DArray(vector<vector<int>>& matrix, int target)
{	
	//获取索引值 i  , j
	int i = matrix.size() - 1, j = 0;
	while (i >= 0 && j < matrix[0].size())
	{	
		//判断二维数组索引到的元素是否大于要查找的元素,是的话就消去第i行元素，
		if (matrix[i][j] > target)
		{
			
			i--;
		}
		//判断二维数组索引到的元素是否小于要查找的元素,是的话就消去第j列元素，
		else if (matrix[i][j] < target)
		{
			j++;
		}
		else
		{
			return true;
		}
	}

	return false;


}