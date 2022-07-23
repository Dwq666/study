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

void Sort_Algorithm::sort_select(vector<int>& data)
{
	
	if (data.size() < 2)
		return;
	//定义最小值下标
	int min;

	//开始选择
	for (int i = 0; i < data.size() -1; i++)
	{
		min = i;
		//开始循环找到无序序列中最小的数的下标.
		for (int j = i + 1; j < data.size(); j++)
		{
			if (data.at(min) > data.at(j))
				min = j;
		}
		//替换
		int temp = data.at(i);
		data.at(i) = data.at(min);
		data.at(min) = temp;
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

void Sort_Algorithm::sort_insert(vector<int>& data)
{
	if (data.size() < 2)
		return;
	// 从序列中第二个元素开始遍历
	for (int i = 1; i < data.size(); i++)
	{   // 本轮要插入的元素.
		int key = data.at(i);
		// j从最后一个有序元素（i前一个)往前遍历查找插入位置.
		int j = i - 1;
		while (j >= 0 && data.at(j) > key)
		{
			// 将大于key的元素往后移,给key腾出位置插入
			data.at(j+ 1) = data.at(j);
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

void Sort_Algorithm::sort_bubble(vector<int>& data)
{
	if (data.size() < 2)
		return;

	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data.size() - i - 1; j++)
		{
			// 无序区前一个元素大于它的后一个元素,交换位置
			if (data.at(j) > data.at(j + 1))
			{
				int temp = data.at(j + 1);
				data.at(j + 1) = data.at(j);
				data.at(j) = temp;
			}
		
		}
	
	}

}

/**
	* 递归快速排序
	*
	*/

void Sort_Algorithm::sort_quick(vector<int>& data, int start, int end)
{
	if (start < end)
	{
		//给数组分区，然后获得一个元素值
		int p = partition(data, start, end);
		//排序小于元素值的分区
		sort_quick(data, start, p - 1);
		//排序大于元素值的分区
		sort_quick(data, p + 1, end);
	}
}
int Sort_Algorithm::partition(vector<int>& data, int start, int end)
{
	//釆用要分区的子范围中的第一个元素作为基准元素
	int pivotValue = data.at(start);
	int pivotPosition = start;
	//重新排列分区子范围中除基准元素之外的从start到end的兀素
	for (int pos = start + 1; pos <= end; pos++)
	{
		if (data.at(pos) < pivotValue)
		{
			// arr [pos]是当前循环数组元素值 //使用这个当前数组元素值和刚好位于基准元素右侧的元素交换
			swap(data.at(pivotPosition + 1), data.at(pos));
			//基准元素和当前循环数组元素值交换
			swap(data.at(pivotPosition), data.at(pivotPosition + 1));
			//调整基准元素的位置使基准元素项目保持不变
			pivotPosition++;
		}
	}
	return pivotPosition;
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


void Sort_Algorithm::sort_shell(vector<int>& data)
{
	if (data.size() < 2)
		return;

	for (int h = data.size() / 2; h > 0; h /= 2)
	{
		//i=h.i是第一个分组的第二个元素，i++ i就是下一个分组的第二个元素
		for (int i = h; i < data.size(); i++)
		{
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


void Sort_Algorithm::functionTest()
{	
	
	Sort_Algorithm sortTest;


	//定义一个数组
	vector<int> ivec;
	ivec.push_back(30);
	ivec.push_back(25);
	ivec.push_back(66);
	ivec.push_back(56);
	ivec.push_back(19);
	ivec.push_back(22);
	ivec.push_back(99);
	ivec.push_back(34);
	ivec.push_back(76);


	cout << "排序前" << endl;
	//遍历数组排序前
	for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); it++)
	{
		
		cout << *it << " ";
	
	}
	
	cout << endl;



	//选择排序
	//sortTest.sort_select(ivec);

	//冒泡排序
	//sortTest.sort_bubble(ivec);

	//快速排序
	//int start = 0;
	//int end = ivec.size() - 1;
	//sortTest.sort_quick(ivec,start,end);

	//插入排序
	//sortTest.sort_insert(ivec);

	//希尔排序
	sortTest.sort_select(ivec);



	cout << "排序后" << endl;
	//遍历数组排序后
	for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); it++)
	{

		cout << *it << " ";

	}

	cout << endl;
	

}