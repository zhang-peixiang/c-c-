#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// ����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬
// ����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

// ˵����
// ����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����


int cmp(const int* left, const int* right)
{
	return *left - *right;
}
int singleNumber(int* nums, int numsSize)
{
	int i = 0;
	qsort(nums, numsSize, sizeof(int), cmp);
	int key = nums[0];
	int count = 0;
	for (i = 1; i < numsSize; i++)
	{
		if (key == nums[i])
		{
			count++;
			
		}
		else if (key != nums[i] && count==0)
		{
			return key;
		}
		else
		{
			count = 0;
			key = nums[i];
		}
	}

	return nums[numsSize-1];
}