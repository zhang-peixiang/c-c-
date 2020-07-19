#include "sort.h"
#include "stack.h"

void PrintArray(int* array, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void Swap(int* left, int* right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}

//插入排序
void InsertSort(int* array, int size)
{
	// 注意：i从1开始--->原因:从0开始没有意义
	int i = 0;
	for (i = 1; i < size; i++)
	{
		//模拟单个元素插入过程
		int key = array[i];
		int end = i - 1;

		//找待插入元素在区间中的位置
		while (end >= 0 && key<array[end])
		{
			array[end + 1] = array[end];
			end--;
		}

		//插入元素
		array[end + 1] = key;
	}
}


//希尔排序----对插入排序的改进
/*
方法一：gap以1递减
void ShellSort(int* array, int size)
{
	int gap = 3;
	int i = 0;
	while (gap>0)
	{
		for (i = gap; i < size; i++)
		{
			int key = array[i];
			int end = i - gap;
			while (end >= 0 && key<array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
		gap--;
	}
}
*/

//方法二：gap=gap/3+1;-----研究表明，效率较高
void ShellSort(int* array, int size)
{
	int i = 0;
	int gap = size;
	while (gap>1)
	{
		gap = gap / 3 + 1;
		for (i = gap; i < size; i++)
		{
			int key = array[i];
			int end = i - gap;
			while (end >= 0 && key<array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}
}

//选择排序
void SelectSort(int* array, int size)
{
	int i = 0;
	int j = 0;
	int maxpos = 0;//标记最大值的位置
	int end = size - 1;//把最大值放到end位置
	for (i = 0; i < size-1; i++)
	{
		maxpos = 0;
		for (j = 1; j < size - i; j++)
		{
			//找当前区间中最大元素的位置
			if (array[j]>array[maxpos])
				maxpos = j;
		}
		if (maxpos != end)
		{
			Swap(&array[maxpos], &array[end]);
		}
		end--;
	}
}

//选择排序改进
void SelectSortOP(int* array, int size)
{
	int j = 0;
	int maxpos = 0;
	int minpos = 0;	
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		maxpos = begin;
		minpos = begin;
		for (j = begin+1; j <= end; j++)
		{
			if (array[j]>array[maxpos])
				maxpos = j;
			if (array[j] < array[minpos])
				minpos = j;
		}
		if (maxpos != end)
		{
			Swap(&array[maxpos], &array[end]);
		}
		if (minpos == end)
		{
			minpos = maxpos;
		}
		if (minpos != begin)
		{
			Swap(&array[minpos], &array[begin]);
		}
		begin++;
		end--;
	}
}

void AdjustDown(int* array, int size, int parent)
{
	//用child标记parent较大的孩子，默认左孩子
	//先标记左孩子的原因是：如果parent有孩子，parent一定先有左孩子。

	int child = parent * 2 + 1;

	while (child < size)
	{
		//找parent中较大的孩子，用parent的左右孩子比较
		// 必须先保证parent的右孩子存在
		if (child + 1 < size && array[child] < array[child + 1])
			child += 1;

		// 检测parent是否满足堆的性质
		if (array[parent] < array[child])
		{
			Swap(&array[parent], &array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

//堆排序
void HeapSort(int* array, int size)
{
	int end = size - 1;
	//建堆--大堆
	//注意从倒数第一个非叶子节点的位置开始使用堆调整，一直调整到根节点的位置
	int root = (size - 2) / 2;
	for (root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDown(array, size, root);
	}

	//排序--利用堆删除的思想进行排序
	while (end)
	{
		Swap(&array[end], &array[0]);
		AdjustDown(array, end, 0);
		end--;
	}
}


//冒泡排序
void BubbleSort(int* array, int size)
{
	int i = 0;
	int j = 0;
	//控制冒泡的趟数
	for (i = 0; i < size - 1; i++) //-1的目的是可以少冒泡一趟，因为最后一次冒泡区间中只剩余一个元素
	{
		//具体冒泡方式：用相邻位置的元素进行比较，如果不满足条件，就进行交换
		//j：表示前一个元素的下标
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j]>array[j + 1])
				Swap(&array[j], &array[j + 1]);
		}
	}
}

//冒泡法改进
//设置一个flag ：当数组只需要交换一次就可以有序时，标记flag就可以直接跳出
//--例如：0，1，2，3，4，5，6，7，9，8  只需要一次交换就可以变为有序数组，当有了flag时，第二次循环结束即可返回
void BubbleSortOP(int* array, int size)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	//控制冒泡的趟数
	for (i = 0; i < size - 1; i++) //-1的目的是可以少冒泡一趟，因为最后一次冒泡区间中只剩余一个元素
	{
		flag = 0;
		//具体冒泡方式：用相邻位置的元素进行比较，如果不满足条件，就进行交换
		//j：表示前一个元素的下标
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j]>array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			return;
	}
}


//三数取中法-----快排里面的基准值取三数中最中间的数
int GetMiddleIndex(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (array[left] < array[right - 1])
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid]>array[right - 1])
			return right - 1;
		else
			return mid;
	}
	else
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right - 1;
		else
			return mid;

	}
}

//常规法
int Partion1(int* array, int left, int right)
{
	int keyofindex = GetMiddleIndex(array, left, right);
	if (keyofindex != right-1)
		Swap(&array[keyofindex], &array[right - 1]);
	int key = array[keyofindex];
	int begin = left;
	int end = right - 1;
	while (begin<end)
	{
		while (begin<end && array[begin] <= key)
		{
			begin++;
		}
		while (begin<end && array[end]>=key)
		{
			end--;
		}
		if (begin<end)
		{
			Swap(&array[begin], &array[end]);
			begin++;
			end--;
		}
	}
	if (begin!=right-1)
	{
		Swap(&array[begin], &array[right-1]);
	}
	return begin;
}

//挖坑法
int Partion2(int* array, int left, int right)
{
	int keyofindex = GetMiddleIndex(array, left, right);
	if (keyofindex != right - 1)
		Swap(&array[keyofindex], &array[right - 1]);
	int begin = left;
	int end = right - 1;
	int key = array[keyofindex];
	while (begin < end)
	{
		//end位置形成了一个新的坑
		// 让begin从前往后找比基准值大的元素
		while (begin < end && array[begin] <= key)
			begin++;
		// 让begin位置大的元素填end位置的坑
		if (begin < end)
			array[end--] = array[begin];

		//begin位置形成了一个新的坑
		// 让end从后往前找比基准值小的元素，填begin位置的坑
		// 让end从后往前找，找比基准值小的元素，找到了就停下来
		while (begin < end && array[end] >= key)
			end--;
		if (begin < end)
			array[begin++] = array[end];
	}
	//用基准值填最后的一个坑
	if (begin != right-1)
		array[begin] = key;
	return begin;
}

//双指针法
int Partion3(int* array, int left, int right)
{
	//采用三数取中法降低取到极值的概率
	int keyofindex = GetMiddleIndex(array, left, right);
	if (keyofindex != right - 1)
		Swap(&array[keyofindex], &array[right - 1]);
	int cur = left;
	int prev = left - 1;
	int key = array[keyofindex];
	
	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur) //++prev 标记的是比key大的数  cur标记的是比key小的数
			Swap(&array[cur], &array[prev]);
		cur++;
	}
	
	if (++prev != right - 1)
		Swap(&array[right - 1], &array[prev]);
	return prev;
}

//快速排序
//[left,right] 表示待排序元素的区间
void QuickSort(int* array, int left, int right)
{
	if (right - left < 16)//当数据量较少时，用插入排序效率高
	{
		InsertSort(array, right - left);
	}
	else
	{
		//Partion按照基准值（就是区间中的某个元素）对区间进行划分成两部分，左部分元素比基准值小，右侧部分比基准值大
		//该函数返回基准值在区间中的位置
		//[left,right] 区间中的基准值位置已经存放好了，基准值左侧和右侧不一定有序
		int div = Partion3(array, left, right);

		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}

//快速排序--递归变循环
void QuickSortNor(int* array, int size)
{
	Stack s;
	
	int left = 0;
	int right = size;
	StackInit(&s);

	StackPush(&s, right);
	StackPush(&s, left);

	while (StackEmpty(&s)==0)
	{
		//先按照基准值来进行划分
		left = StackTop(&s);
		StackPop(&s);

		right = StackTop(&s);
		StackPop(&s);

		if (right - left > 1)
		{
			int div = Partion1(array, left, right);

			//排基准值左半侧--将右半部分入栈[div+1,right)
			StackPush(&s, right);
			StackPush(&s, div + 1);

			// 排基准值的右半侧--将左部分的区间入栈[left,div)
			StackPush(&s, div);
			StackPush(&s, left);
		}
	}
	StackDestroy(&s);
}

void MergeData(int* array, int left,int mid, int right, int* tmp)
{
	int index1 = left;
	int index2 = mid;
	int index = left;
	while (index1 < mid && index2 < right)
	{
		if (array[index1]>array[index2])
			tmp[index++] = array[index2++];
		else
			tmp[index++] = array[index1++];
	}
	while (index1<mid)
		tmp[index++] = array[index1++];
	while (index2<right)
		tmp[index++] = array[index2++];
}

void _MergeSort(int* array, int left, int right,int* tmp)
{
	if (right - left>1)
	{
		int mid = left + ((right - left) >> 1);

		_MergeSort(array, left, mid, tmp);

		_MergeSort(array, mid, right, tmp);
		
		MergeData(array, left, mid, right, tmp);

		memcpy(array + left, tmp + left, (right - left)*sizeof(array[left]));
	}

}
//归并排序
void MergeSort(int* array, int size)
{
	int* tmp = (int*)malloc(sizeof(array[0])*size);
	if (tmp == NULL)
		return;

	_MergeSort(array, 0, size, tmp);
	free(tmp);
}

///////////////////////////////////////////////////////
void test()
{
	int array[] = { 0, 1, 3, 6, 5, 8, 9, 4, 2, 7 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	//InsertSort(array, sizeof(array) / sizeof(array[0]));
	//PrintArray(array, sizeof(array) / sizeof(array[0]));
	//ShellSort(array, sizeof(array) / sizeof(array[0]));
	//PrintArray(array, sizeof(array) / sizeof(array[0]));
	//SelectSort(array, sizeof(array) / sizeof(array[0]));
	//PrintArray(array, sizeof(array) / sizeof(array[0]));
	//SelectSortOP(array, sizeof(array) / sizeof(array[0]));
	//PrintArray(array, sizeof(array) / sizeof(array[0]));
	//HeapSort(array, sizeof(array) / sizeof(array[0]));
	//PrintArray(array, sizeof(array) / sizeof(array[0]));
	//BubbleSort(array, sizeof(array) / sizeof(array[0]));
	//PrintArray(array, sizeof(array) / sizeof(array[0]));
	//QuickSort(array, 0, sizeof(array) / sizeof(array[0]));
	//PrintArray(array, sizeof(array) / sizeof(array[0]));
	//BubbleSortOP(array, sizeof(array) / sizeof(array[0]));
	//PrintArray(array, sizeof(array) / sizeof(array[0]));
	//QuickSortNor(array, sizeof(array) / sizeof(array[0]));
	//PrintArray(array, sizeof(array) / sizeof(array[0]));
	MergeSort(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));

}