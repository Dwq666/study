#include "SortMain.h"
using namespace std;

/**
 * 选择排序
 *
 * 思想：
 * 在原始待排序列上做修改;
 * 首先找出待排序列中最小的数,然后用这个数和原序列中的第一个数交换位置;
 * 其次,找出第二小的和原第二个数交换位置;
 * 依次顺序直到找到第二大的数,之后原数列完全变成有序数列
 */

void Sort_Algorithm::sort_select(vector<int> &data)
{

	if (data.size() < 2)
		return;
	//定义最小值下标
	int min;

	//开始选择
	for (int i = 0; i < data.size() - 1; i++)
	{
		min = i;
		//开始循环找到无序序列中最小的数的下标.
		for (int j = i + 1; j < data.size(); j++)
		{
			if (data.at(min) > data.at(j))
				min = j;
		}
	
		//替换
		swap(data.at(i), data.at(min));
	}
}

/**
	* 插入排序
	*
	* 思想：
	// 在原始待排序列上做修改;
	// 将待排序序列分为有序区和无序区;
	// 最开始的待排序列只有第一个元素是有序的;
	// 从第二个元素开始,向有序区往前查找合适的位置插入;
	// 直到最后一个元素找到了合适的位置插入时原待排序列变为有序序列.
	*/

void Sort_Algorithm::sort_insert(vector<int> &data)
{
	if (data.size() < 2)
		return;
	// 从序列中第二个元素开始遍历
	for (int i = 1; i < data.size(); i++)
	{ // 本轮要插入的元素.
		int key = data.at(i);
		// j从最后一个有序元素（i前一个)往前遍历查找插入位置.
		int j = i - 1;
		while (j >= 0 && data.at(j) > key)
		{
			// 将大于key的元素往后移,给key腾出位置插入
			data.at(j + 1) = data.at(j);
			j--;
		}
		// 已经找到要插入的位置为j+1,将key插入.
		data.at(j + 1) = key;
	}
}

/**
	* 冒泡排序
	*
	*
	* // 思想：
	// 在原始待排序序列上操作;
	// 将原始待排序序列分成无序区和有序区两部分;
	// 初始状态下整个原始序列为无序区,每遍历一遍就浮现出无序区最大的元素放在有序区;
	// 随着遍历,最终无序区长度变为0,整个原始序列变为有序序列
	*/

void Sort_Algorithm::sort_bubble(vector<int> &data)
{
	if (data.size() < 2)
		return;

	for (int i = 0; i < data.size(); i++)
	{
		//设定⼀个标记，若为false，则表示此次循环没有进⾏交换，也就是待排序列已经有序，排序已经完成。
		bool bIsSwap = false;
		for (int j = 0; j < data.size() - i - 1; j++)
		{
			// 无序区前一个元素大于它的后一个元素,交换位置
			if (data.at(j) > data.at(j + 1))
			{
				swap(data.at(j), data.at(j + 1));
				bIsSwap = true;
			}
		}

		//没有数据交集，提前退出
		if (!bIsSwap)
			break;
	}
}

/**
 * 递归快速排序
 *
 *  // 思想：
	// 在元素序列上直接操作;
	// 每次在无序序列中选取一个数,一般称之为中轴数,
	// 将元素序列分成两个部分,使得一部分的元素全都小于等于另一部分的所有元素;
	// 也就是说将序列分成小于等于中轴数和大于等于中轴数的两部分,使得中轴数变为有序;
	// 再递归的对分成的两部分进行划分操作.
 *
 */

void Sort_Algorithm::sort_quick_recursive(vector<int> &data, int left, int right)
{
	if (left < right)
	{
		// 找到中轴数的索引.
		int p = partition(data, left, right);
		//排序小于元素值的分区
		sort_quick_recursive(data, left, p - 1);
		//排序大于元素值的分区
		sort_quick_recursive(data, p + 1, right);
	}
}
int Sort_Algorithm::partition(vector<int> &data, int left, int right)
{
	// 找到中轴数的正确位置,同时将序列划分为两部分
	//取序列最后一个元素为中轴数
	int key = data.at(right);
	// 此处设置两个索引i和j,区间[left,i]为小于中轴数的序列,
	// 区间[j,right-1]为大于中轴数的序列.
	int i = left - 1;
	for (int j = left; j < right; j++)
	{
		if (data.at(j) <= key)
		{
			// 大于中轴数的元素让它继续待在[j,right-1]区间什么也不做;
			// 小于中轴数的元素全部从[j,right-1]区间放到[left,i]区间去.
			i++;
			swap(data.at(i), data.at(j));
		}
	}

	// 此时中轴数的正确位置应该在i+1,将其归位.
	swap(data.at(i + 1), data.at(right));
	// 返回中轴数的正确索引.
	return i + 1;
}

/**
 *   非递归利用栈来实现.
	 利用栈来存储子序列的起点后终点(其实递归也是通过调用系统堆栈来保护调用现场的)
 */
void Sort_Algorithm::sort_quick_Norecursive(std::vector<int> &data, int left, int right)
{
	if (left < right)
	{
		// 找到中轴数的索引.
		int index = partition(data, left, right);

		// 如果中轴数索引两个分区存在,则将起点和终点入栈.
		stack<int> ista;
		if (index - 1 > left)
		{
			// 下面的入栈顺序要和此处一致.
			ista.push(left);
			ista.push(index - 1);
		}
		if (index + 1 < right)
		{
			ista.push(index + 1);
			ista.push(right);
		}
		// 从栈里面取出序列并找到该序列中轴数的正确索引.
		while (!ista.empty())
		{
			// 注意顺序.
			int r = ista.top();
			ista.pop();
			int l = ista.top();
			ista.pop();
			index = partition(data, l, r);
			// 将新的序列区间入栈.
			if (index - 1 > l)
			{
				ista.push(l);
				ista.push(index - 1);
			}
			if (index + 1 < r)
			{
				ista.push(index + 1);
				ista.push(r);
			}
		}
	}
}

/**
	* 希尔排序
	*
	*
	*
	* 思想：
	// 还是在原待排序序列上进行操作;
	// 该算法是插入排序的变种和优化,当无序序列不理想,简单的插入排序会有很多的交换操作,影响效率;
	// 希尔排序做的改进是将原始待排序序列以一个偏移量h进行逻辑上的分组,对组内的元素采用插入排序,使得原始序列基本有序;
	// 偏移量逐渐减小,每减小一次进行组内插入排序,最后一轮则以1为偏移量,也就是将原书待排序列分为同一组进行组内排序,也就是简单的插入排序;
	// 该排序算法对于无序序列很不理想的情况有利.
	// 注：一般将h初始值设为length/2,h逐倍递减直至1,其实还有更理性的分组方法,对最终效率也有所优化.
	*/

void Sort_Algorithm::sort_shell(vector<int> &data)
{
	if (data.size() < 2)
		return;

	for (int h = data.size() / 2; h > 0; h /= 2)
	{
		// i=h.i是第一个分组的第二个元素，i++ i就是下一个分组的第二个元素
		for (int i = h; i < data.size(); i++)
		{
			//下面就是对每个分组进行插入排序
			int key = data.at(i);
			int j = i - h;
			while (j >= 0 && data.at(j) > key)
			{
				data.at(j + h) = data.at(j);
				j = j - h;
			}

			data.at(j + h) = key;
		}
	}
}

/**
 *   // 思想：
	// 归并排序这里不再是直接在原始序列上进行操作;
	// 归并排序利用的是分而治之的思想,将序列分成两个子序列,将两个子序列排好序后合并为有序的序列;
	// 而对两个子序列进行排序同样用分而治之,如此递归下去;
	// 归并分为三步：分,治,合;治是关键,而治又是最简单的,将序列分为只有一个元素的两个子序列后自然变得有序;
	// 所以归并可以分为两步：将序列一直分成只有一个元素的子序列,然后将这些有序的子序列合并.
 *
 */
void Sort_Algorithm::sort_merge_recursive(vector<int> &data, int left, int right)
{
	if (left < right)
	{
		// 将序列一分为二并获取中间位置.
		int mid = (left + right) / 2;
		// 递归处理两个子序列使之有序.
		sort_merge_recursive(data, left, mid);
		sort_merge_recursive(data, mid + 1, right);
		// 合并两个有序子序列后结束归并排序.
		merge(data, left, mid, right);
	}
}

void Sort_Algorithm::merge(vector<int> &data, int left, int mid, int right)
{
	// 将有序的两个子序列合并.
	// 获取两个子序列的第一个元素.
	int i = left;
	int j = mid + 1;
	// 创建临时容器来保存合并结果,同时指定容器大小.
	vector<int> ivec;
	ivec.resize(right - left + 1);
	// 开始合并.
	int k = 0;
	while (i <= mid && j <= right)
	{
		if (data.at(i) <= data.at(j))
		{
			ivec.at(k++) = data.at(i++);
		}
		else
		{
			ivec.at(k++) = data.at(j++);
		}
	}
	// 到此为止肯定有一个子序列已经完全放到临时容器里,现在将另子序列的元素放入临时容器.
	while (i <= mid)
	{
		ivec.at(k++) = data.at(i++);
	}

	while (j <= right)
	{
		ivec.at(k++) = data.at(j++);
	}

	// 最后将临时容器里的元素复制到原容器完成合并.
	for (int n = 0; n < k; n++)
	{
		data.at(left++) = ivec.at(n);
	}
}




void Sort_Algorithm::sort_heap(vector<int> &data)
{
	
}






void Sort_Algorithm::functionTest()
{

	Sort_Algorithm sortTest;

	//定义一个数组
	vector<int> ivec;
	ivec.push_back(2);
	ivec.push_back(70);
	ivec.push_back(73);
	ivec.push_back(59);
	ivec.push_back(13);
	ivec.push_back(11);
	ivec.push_back(96);
	ivec.push_back(47);
	ivec.push_back(36);
	ivec.push_back(56);

	cout << "排序前" << endl;
	//遍历数组排序前
	for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); it++)
	{

		cout << *it << " ";
	}

	cout << endl;

	//选择排序
	// sortTest.sort_select(ivec);

	//冒泡排序
	// sortTest.sort_bubble(ivec);

	//递归快速排序
	// int left = 0;
	// int right = ivec.size() - 1;
	// sortTest.sort_quick_recursive(ivec, left, right);
	//非递归快速排序
	// sortTest.sort_quick_Norecursive(ivec, left, right);

	//插入排序
	// sortTest.sort_insert(ivec);

	//希尔排序
	// sortTest.sort_select(ivec);

	//归并排序-递归
	int left = 0;
	int right = ivec.size() - 1;
	sortTest.sort_merge_recursive(ivec, left, right);

	cout << "排序后" << endl;
	//遍历数组排序后
	for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); it++)
	{

		cout << *it << " ";
	}

	cout << endl;
}