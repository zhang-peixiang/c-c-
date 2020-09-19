#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 给定一个非空整数数组，除了某个元素只出现一次以外，
// 其余每个元素均出现两次。找出那个只出现了一次的元素。

// 说明：
// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？


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