#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int arr_1[200005] = { 0 };
int temp_1[200005] = { 0 }, temp_2[200005] = { 0 };


//插入排序
void insert_sort(int arr[], int len)
{
	for (int i = 0, j; i < len; i++)
	{
		int temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = temp;
	}
}

//归并排序
void merge(int arr[], int left, int mid, int right)
{
	int i = left, j = mid + 1, flag = left;
	while (j <= right && i <= mid)//(数组不越界，i不去到另外一个数组)
	{
		if (arr[j] < arr[i])
			temp_2[flag++] = arr[j++];
		else
			temp_2[flag++] = arr[i++];
	}
	while (i <= mid)//j指出界外，但i没指到另一个数组
		temp_2[flag++] = arr[i++];
	while (j <= right)//i直到另一个数组，但j未指出界外
		temp_2[flag++] = arr[j++];
	for (int d = left; d <= right; d++)//再将temp的值赋回去
		arr[d] = temp_2[d];
}

void merge_sort(int arr[], int left, int right)
{
	int mid = (left + right) / 2;
	if (left < right)
	{
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}


//快排
void quick_sort(int arr[], int left, int right)
{
	if (left >= right)//出递归
		return;

	int i = left, j = right;
	int temp = arr[left];

	while (i < j)
	{
		while (arr[j] >= temp && j > i)
			j--;
		while (arr[i] <= temp && j > i)
			i++;
		if (i < j)
		{
			int box = arr[i];
			arr[i] = arr[j];
			arr[j] = box;
		}
	}
	arr[left] = arr[i];
	arr[i] = temp;
	quick_sort(arr, left, i - 1);//i不需要排序
	quick_sort(arr, i + 1, right);
}


//计数排序
void count_sort(int arr[], int len)
{
	int max = arr[0], min = arr[0],count=0;
	for (int i = 1; i < len; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	for (int i = 0; i < len; i++)
		arr_1[arr[i]]++;
	for (int i = min; i <= max; i++)
	{
		for (int j = 1; j <= arr_1[i]; j++)
		{ 	
			/*printf("%d ", i);*///不进行打印但要计时
			count++;
		}
	}
}

//基数计数排序()
int max_digits(int arr[], int len)//找到数组中最大的位数
{
	int max = arr[0], digits = 0;
	//max为最大的整数(max不能取0可能有负数),digits为最大位数
	for (int i = 1; i < len; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	while (max > 0)
	{
		digits++;
		max = max / 10;
	}
	return digits;
}

void radix_count_sort(int arr[], int len)
{
	int digits = max_digits(arr, len), radix = 1;

	for (int i = 1; i <= digits; i++)
	{
		int bucket[15] = { 0 };//统计

		for (int j = 0; j < len; j++)
		{
			int num = (arr[j] / radix) % 10;//num依次为个位、十位...
			bucket[num]++;
		}
		//让bucket的值对应这是第几个数（bucket值为5代表这是经过排序后的第五个数）
		for (int j = 1; j < 10; j++)
			bucket[j] = bucket[j - 1] + bucket[j];

		for (int j = len - 1; j >= 0; j--)
			//从后往前因为已经排好序了，“较大”的已经在后面
		{
			int num = (arr[j] / radix) % 10;
			temp_1[bucket[num] - 1] = arr[j];
			bucket[num]--;//如个位数为1的有两个，下一个的位置需要-1
		}

		for (int j = 0; j < len; j++)//将数组更新
			arr[j] = temp_1[j];

		radix *= 10;
	}
}




