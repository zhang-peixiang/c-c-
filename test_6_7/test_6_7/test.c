#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//ц╟ещеепР
void BubbleSort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		for (i = 0; i < sz-j-1; i++)
		{
			int ret = 0;
			if (arr[i] > arr[i + 1])
			{
				ret = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = ret;
			}
		}
	}
}


int main()
{
	int i = 0;
	int arr[] = { 2, 4, 5, 6, 8, 9, 3, 0, 1, 7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


