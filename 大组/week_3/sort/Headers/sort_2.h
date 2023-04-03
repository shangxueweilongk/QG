#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble_sort_1(int arr[], int len)//冒泡排序优化1
{
	for (int i = 0; i < len - 1; i++)
	{
		int flag = 0;//标记是否进行交换
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				//交换
				int box = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = box;
				flag = 1;//标记
			}
		}
		if (flag == 0)//如果没有交换过元素，则已经有序
			return;
	}
}

void bubble_sort_2(int arr[], int len)//冒泡排序优化2
{

	int k = len - 1;
	for (int i = 0; i < k; i++)
	{
		int pos = 0;//用来记录最后一次交换的位置
		for (int j = 0; j < k; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int box = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = box;
				pos = j;//记录最后一次交换的位置
			}
		}
		if (pos == 0)//如果没有交换过元素，则已经有序
			return;
		k = pos;//下一次比较到记录位置即可,k后面的因为没有进行交换故均有序
	}
}


void bubble_sort_3(int arr[], int len)//冒泡排序优化3
{
	int n = 0;//同时找最大值的最小需要两个下标遍历
	int k = len - 1;
	for (int i = 0; i < k; i++)//确定排序趟数
	{
		int pos = 0;//用来记录最后一次交换的位置
		//正向寻找最大值
		for (int j = n; j < k; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int box = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = box;
				pos = j;//记录最后一次交换的位置
			}
		}

		if (pos == 0)//如果没有交换过元素，则已经有序
			return;

		k = pos;//下一次比较到记录位置即可,k后面的因为没有进行交换故均有序

		//反向寻找最小值(当较小值在后面时较快完成排序)
		for (int j = k; j > n; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				int box = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = box;
			}
		}
		n++;
		if (pos == 0)//如果没有交换过元素，则已经有序
			return;
	}
}

void random_quick_sort(int arr[], int left, int right)
{
	if (left >= right)//出递归
		return;

	int i = left, j = right;
	int pos = rand() % (right - left + 1) + left;//随机生成范围内的下标
	int temp = arr[left]; arr[left] = arr[pos]; arr[pos] = temp;//将随机值与最左基准值交换
	temp = arr[left];

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
	random_quick_sort(arr, left, i - 1);
	random_quick_sort(arr, i + 1, right);
}

//三数取中快排
int get_mid(int x, int y, int z)
{
	if ((x >= y && x <= z) || (x <= y && x >= z))
		return x;
	if ((y >= x && y <= z) || (y <= x && y >= z))
		return y;
	if ((z >= y && z <= x) || (z <= y && z >= x))
		return z;
}

void mid_quick_sort(int arr[], int left, int right)
{
	if (left >= right)//出递归
		return;

	int i = left, j = right;
	int pos = get_mid(left, right, (left + right) / 2);//三数中值
	int temp = arr[left]; arr[left] = arr[pos]; arr[pos] = temp;//将随机值与最左基准值交换
	temp = arr[left];

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
	mid_quick_sort(arr, left, i - 1);
	mid_quick_sort(arr, i + 1, right);

}
