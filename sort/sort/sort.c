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

//��������
void InsertSort(int* array, int size)
{
	// ע�⣺i��1��ʼ--->ԭ��:��0��ʼû������
	int i = 0;
	for (i = 1; i < size; i++)
	{
		//ģ�ⵥ��Ԫ�ز������
		int key = array[i];
		int end = i - 1;

		//�Ҵ�����Ԫ���������е�λ��
		while (end >= 0 && key<array[end])
		{
			array[end + 1] = array[end];
			end--;
		}

		//����Ԫ��
		array[end + 1] = key;
	}
}


//ϣ������----�Բ�������ĸĽ�
/*
����һ��gap��1�ݼ�
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

//��������gap=gap/3+1;-----�о�������Ч�ʽϸ�
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

//ѡ������
void SelectSort(int* array, int size)
{
	int i = 0;
	int j = 0;
	int maxpos = 0;//������ֵ��λ��
	int end = size - 1;//�����ֵ�ŵ�endλ��
	for (i = 0; i < size-1; i++)
	{
		maxpos = 0;
		for (j = 1; j < size - i; j++)
		{
			//�ҵ�ǰ���������Ԫ�ص�λ��
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

//ѡ������Ľ�
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
	//��child���parent�ϴ�ĺ��ӣ�Ĭ������
	//�ȱ�����ӵ�ԭ���ǣ����parent�к��ӣ�parentһ���������ӡ�

	int child = parent * 2 + 1;

	while (child < size)
	{
		//��parent�нϴ�ĺ��ӣ���parent�����Һ��ӱȽ�
		// �����ȱ�֤parent���Һ��Ӵ���
		if (child + 1 < size && array[child] < array[child + 1])
			child += 1;

		// ���parent�Ƿ�����ѵ�����
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

//������
void HeapSort(int* array, int size)
{
	int end = size - 1;
	//����--���
	//ע��ӵ�����һ����Ҷ�ӽڵ��λ�ÿ�ʼʹ�öѵ�����һֱ���������ڵ��λ��
	int root = (size - 2) / 2;
	for (root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDown(array, size, root);
	}

	//����--���ö�ɾ����˼���������
	while (end)
	{
		Swap(&array[end], &array[0]);
		AdjustDown(array, end, 0);
		end--;
	}
}


//ð������
void BubbleSort(int* array, int size)
{
	int i = 0;
	int j = 0;
	//����ð�ݵ�����
	for (i = 0; i < size - 1; i++) //-1��Ŀ���ǿ�����ð��һ�ˣ���Ϊ���һ��ð��������ֻʣ��һ��Ԫ��
	{
		//����ð�ݷ�ʽ��������λ�õ�Ԫ�ؽ��бȽϣ�����������������ͽ��н���
		//j����ʾǰһ��Ԫ�ص��±�
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j]>array[j + 1])
				Swap(&array[j], &array[j + 1]);
		}
	}
}

//ð�ݷ��Ľ�
//����һ��flag ��������ֻ��Ҫ����һ�ξͿ�������ʱ�����flag�Ϳ���ֱ������
//--���磺0��1��2��3��4��5��6��7��9��8  ֻ��Ҫһ�ν����Ϳ��Ա�Ϊ�������飬������flagʱ���ڶ���ѭ���������ɷ���
void BubbleSortOP(int* array, int size)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	//����ð�ݵ�����
	for (i = 0; i < size - 1; i++) //-1��Ŀ���ǿ�����ð��һ�ˣ���Ϊ���һ��ð��������ֻʣ��һ��Ԫ��
	{
		flag = 0;
		//����ð�ݷ�ʽ��������λ�õ�Ԫ�ؽ��бȽϣ�����������������ͽ��н���
		//j����ʾǰһ��Ԫ�ص��±�
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


//����ȡ�з�-----��������Ļ�׼ֵȡ���������м����
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

//���淨
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

//�ڿӷ�
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
		//endλ���γ���һ���µĿ�
		// ��begin��ǰ�����ұȻ�׼ֵ���Ԫ��
		while (begin < end && array[begin] <= key)
			begin++;
		// ��beginλ�ô��Ԫ����endλ�õĿ�
		if (begin < end)
			array[end--] = array[begin];

		//beginλ���γ���һ���µĿ�
		// ��end�Ӻ���ǰ�ұȻ�׼ֵС��Ԫ�أ���beginλ�õĿ�
		// ��end�Ӻ���ǰ�ң��ұȻ�׼ֵС��Ԫ�أ��ҵ��˾�ͣ����
		while (begin < end && array[end] >= key)
			end--;
		if (begin < end)
			array[begin++] = array[end];
	}
	//�û�׼ֵ������һ����
	if (begin != right-1)
		array[begin] = key;
	return begin;
}

//˫ָ�뷨
int Partion3(int* array, int left, int right)
{
	//��������ȡ�з�����ȡ����ֵ�ĸ���
	int keyofindex = GetMiddleIndex(array, left, right);
	if (keyofindex != right - 1)
		Swap(&array[keyofindex], &array[right - 1]);
	int cur = left;
	int prev = left - 1;
	int key = array[keyofindex];
	
	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur) //++prev ��ǵ��Ǳ�key�����  cur��ǵ��Ǳ�keyС����
			Swap(&array[cur], &array[prev]);
		cur++;
	}
	
	if (++prev != right - 1)
		Swap(&array[right - 1], &array[prev]);
	return prev;
}

//��������
//[left,right] ��ʾ������Ԫ�ص�����
void QuickSort(int* array, int left, int right)
{
	if (right - left < 16)//������������ʱ���ò�������Ч�ʸ�
	{
		InsertSort(array, right - left);
	}
	else
	{
		//Partion���ջ�׼ֵ�����������е�ĳ��Ԫ�أ���������л��ֳ������֣��󲿷�Ԫ�رȻ�׼ֵС���Ҳಿ�ֱȻ�׼ֵ��
		//�ú������ػ�׼ֵ�������е�λ��
		//[left,right] �����еĻ�׼ֵλ���Ѿ���ź��ˣ���׼ֵ�����Ҳ಻һ������
		int div = Partion3(array, left, right);

		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}

//��������--�ݹ��ѭ��
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
		//�Ȱ��ջ�׼ֵ�����л���
		left = StackTop(&s);
		StackPop(&s);

		right = StackTop(&s);
		StackPop(&s);

		if (right - left > 1)
		{
			int div = Partion1(array, left, right);

			//�Ż�׼ֵ����--���Ұ벿����ջ[div+1,right)
			StackPush(&s, right);
			StackPush(&s, div + 1);

			// �Ż�׼ֵ���Ұ��--���󲿷ֵ�������ջ[left,div)
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
//�鲢����
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