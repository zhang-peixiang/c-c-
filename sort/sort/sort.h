#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//插入排序
void InsertSort(int* array, int size);


//希尔排序
void ShellSort(int* array, int size);

//选择排序
void SelectSort(int* array, int size);

//选择排序改进
void SelectSortOP(int* array, int size);

//堆排序
void HeapSort(int* array, int size);

//冒泡排序
void BubbleSort(int* array, int size);

//冒泡法改进
void BubbleSortOP(int* array, int size);

//快速排序
void QuickSort(int* array, int left, int right);

//快速排序--递归变循环
void QuickSortNor(int* array, int size);

//归并排序
void MergeSort(int* array, int size);

//////////////////////////////

void test();