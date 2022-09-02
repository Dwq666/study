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
 *
 *  归并排序
 *
 *
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

/**
 *  堆排序
 *
 // 思想：
	// 在原始序列上直接操作.
	// 利用二叉堆的数据结构来实现排序,二叉堆是一个完全二叉数.
	// 二叉堆的特点是堆顶元素是一个最值(大顶堆的堆顶为最大值,小顶堆的堆顶为最小值);
	// 大顶堆：任意节点的元素都要大于他的子节点元素,小顶堆：任意节点的元素都要小于他的子节点元素.
	// 排序方法是将堆顶元素和最后一个元素交换,然后恢复大/小顶堆;再将堆顶元素和最后第二个元素交换,以此类推.
	// 排序第一步是需要将原始数据构建乘二叉堆(升序排序构建大顶堆,降序排序构建小顶堆),我们升序排序所以构建大顶堆;
	// 第二步是调整使之重新成为大顶堆,我们使用从最后一个非叶子节点往上进行下沉处理(down_adjust()).
	// 此处我们提供了二叉堆的插入元素后维护二叉堆的操作,采用上浮处理(up_adjust).
 *
 */
void Sort_Algorithm::sort_heap(vector<int> &data)
{
	int length = data.size();
	// 对每一个非叶结点进行堆调整(从最后一个非叶结点(最后一个节点的父节点)开始)
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		down_adjust(data, i, length);
	}

	for (int i = length - 1; i > 0; i--)
	{
		// 将当前最大的放置到数组末尾
		swap(data.at(0), data.at(i));
		// 将未完成排序的部分继续进行堆排序
		down_adjust(data, 0, i);
	}
}

void Sort_Algorithm::down_adjust(vector<int> &data, int parent, int length)
{
	//获取左子节点下标
	int lson = 2 * parent + 1;
	//获取右子节点下标
	int rson = 2 * parent + 2;
	int maxId = parent;
	if (lson < length && data.at(maxId) < data.at(lson))
		maxId = lson;
	if (rson < length && data.at(maxId) < data.at(rson))
		maxId = rson;
	// 如果maxIdx的值有更新
	if (maxId != parent)
	{
		//交换父子节点元素
		swap(data.at(parent), data.at(maxId));
		// 递归调整其他不满足堆性质的部分
		down_adjust(data, maxId, length);
	}
}

/**
 * @brief
 *
 * // 思想：
	// 计数排序的思想比较新颖,不再是基于元素之间的比较,而是将待排序序列的元素当作容器的索引,记录索引出现的次数;
	// 比如临时容器的a[i] = n,表示元素i出现n次;
	// 记录玩出现次数之后,将临时容器从小到大将元素汇总起来,则变为有序;
	// 我的方法是有所改进,临时容器记录的不是元素出现的次数,而是记录小于等于该元素的元素个数;
	// 这样做的优点是可以保证稳定排序.
	// 计数排序的缺点：只能对整数序列进行排序,而且不适合最大元素和最小元素差得很大的情况（为什么呢）.

 */
void Sort_Algorithm::sort_count(vector<int> &data)
{
	int length = data.size();
	//取最大值和最小值
	int max = data.at(0);
	int min = data.at(0);
	for (int i = 0; i < length; i++)
	{
		if (data.at(i) > max)
			max = data.at(i);
		if (data.at(i) < min)
			min = data.at(i);
	}
	//取最大值和最小值的差值
	int difference = max - min;

	// 2.创建统计容器,并遍历待排序序列进行统计元素出现的次数.
	// 容器元素默认值为0.
	vector<int> iCountData;
	iCountData.resize(difference + 1);
	for (int i = 0; i < length; i++)
	{
		// min值作为一个偏移量的角色.
		++iCountData.at(data.at(i) - min);
	}

	// 3.改进以实现稳定排序,对统计容器做变形,统计容器元素存的不再是待排序元素出现的次数,
	// 而是记录小于等于该索引的元素个数.
	int sum = 0;
	for (auto &value : iCountData)
	{
		sum += value;
		value = sum;
	}

	// 4.倒序遍历原始待排序序列,从统计容器中找到正确位置输出到结果容器,
	vector<int> sorted_data;
	sorted_data.resize(data.size());
	for (int i = data.size() - 1; i >= 0; i--)
	{
		// data.at(i)-min是当前元素与最小值的差值,
		// 以差值作为count_data的索引值,则count_data.at(data.at(i)-min)代表小于等于当前元素data.at(i)的个数,
		// 所以count_data(data.at(i)-min)-1表示当前元素data.at(i)的升序序号.
		// 将当前元素data.at(i)放入sorted_data的正确的位置上.
		sorted_data.at(iCountData.at(data.at(i) - min) - 1) = data.at(i);
		// 随后更新统计容器的元素值,这和倒序遍历是实现稳定排序的关键.
		--iCountData.at(data.at(i) - min);
	}
	// 5.最后将已排序容器赋给原始序列,排序结束.
	data = sorted_data;
}

void Sort_Algorithm::sort_bucket(vector<int> &data)
{
	// 1.遍历待排序序列获取其中最大值和最小值,并计算他们的差值d
	int max = data.at(0);
	int min = data.at(0);
	for (int i = 1; i < static_cast<int>(data.size()); i++)
	{
		if (max < data.at(i))
		{
			max = data.at(i);
		}
		if (min > data.at(i))
		{
			min = data.at(i);
		}
	}
	//取最大值和最小值的差值
	int difference = max - min;
	// 2.初始化桶,桶因为要频繁插入元素,所以用List数据结构,然后所有的桶放在vector容器中.
	vector<list<int>> iBucketList;
	// 我们将桶的个数设置为原序列元素个数.
	int iBucketNum = data.size();
	iBucketList.resize(iBucketNum);
	// 3.遍历原序列,将元素放到合适的桶中.
	for (int value : data)
	{
		// 定位元素所属的桶的索引.
		// 桶所有的桶平均划分最大值和最小值d的区间,value-min是当前元素与最小值的差值(区间).
		// bucket_num-1是总的区间个数,则d/(bucket_num-1)代表一个区间的长度.
		// 那么整个表达式得到的index则为当前元素value所跨越的区间个数,也就是当前元素所在的桶的索引
		int index = (value - min) / (difference / (iBucketNum - 1));
		iBucketList.at(index).push_back(value);
	}

	// 4.对每个桶进行排序,我们采用快速排序.
	// 依次将每个桶里的元素排好序后放入sorted_sequence中.
	vector<int> iSorted_sequence;
	for (auto bucket : iBucketList)
	{
		// 因为我们之前写的快排是对vector<int>进行排序,所以我们使用一个辅助容器.
		// 我们完全可以重新写一个针对list<int>的快排算法,这样会提高时间和空间复杂度,此处我们就使用现成的（非递归快排）
		vector<int> auxiliary;
		auxiliary.assign(bucket.begin(), bucket.end());
		sort_quick_Norecursive(auxiliary, 0, auxiliary.size() - 1);
		// 将当前桶内元素排好序后放入sorted_sequence容器尾部.
		iSorted_sequence.insert(iSorted_sequence.end(), auxiliary.begin(), auxiliary.end());
	}
	// 5.将有序序列赋给data.
	data = iSorted_sequence;
}

/**
 * @brief 
 * 
 *  // 思想：
    // 使用了桶排序中桶的思想,但它比桶排序更精明,它只需要十个桶,因为他的排序思想是分别对元素中的个位,十位,百位....进行排序.
    // 也就是说,首先对所有数以个位数的大小进行排序,然后再对所有数以他们的十位数进行排序,依次类推.
    // 在整个过程中会使得原始序列逐渐趋近有序,待将最高位排完之后完全有序.
    // 想想为什么是从个位开始而不是从最高位开始呢,按道理从最高位开始的话每次都能得出一部分数的正确大小关系.
    // 确实可以从最高位开始,而且可以减少比较次数,但是从最高位开始会有一个致命缺点,那就是在如果从高位开始,在对高位相同的
    // 数继续排序时,又需要另外创建十个桶对他们排序,其实也就是说最终的结果就是真多每一个不同的元素都会为它创建一个桶,
    // 如果待排序序列有10000个不同的元素,那么从高位开始比较的方法就需要创建10000个桶,而从个位开始比较的方法可以重复使用
    // 那10个桶,如果序列个数更多那么这样的性能差异就更明显,所以虽然减少了比较次数但浪费了非常多的空间,得不偿失.
    // 所以我们说基数排序的话都默认的是从个位开始比较的.
 */


void Sort_Algorithm::sort_radix(vector<int> &data)
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
	// int left = 0;
	// int right = ivec.size() - 1;
	// sortTest.sort_merge_recursive(ivec, left, right);

	//堆排序
	// sortTest.sort_heap(ivec);

	//计数排序
	// sortTest.sort_count(ivec);

	//桶排序
	sortTest.sort_bucket(ivec);

	cout << "排序后" << endl;
	//遍历数组排序后
	for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); it++)
	{

		cout << *it << " ";
	}

	cout << endl;
}