#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#include<string.h>

int final = 0;//第k大的数

//颜色排序
void color_sort()
{
	int arr[1005] = { 0 };
	printf("随机生成含有1k个元素的数组且元素的值为大于等于0小于3的整数\n");
	srand(time(0));
	for (int j = 0; j < 1000; j++)
		arr[j] = rand() % 3;
	int  p1 = 0, p2 = 999;

	printf("原来的数组\n");
	for (int j = 0; j < 1000; j++)
		printf("%d ", arr[j]);
	printf("\n");
	for (int p0 = 0; p0 <= p2; p0++)
	{
		if (arr[p0] == 0)
		{
			int box = arr[p0];
			arr[p0] = arr[p1];
			arr[p1] = box;
			p1++;//p1向前一步
		}
		else if (arr[p0] == 2)
		{
			int box = arr[p0];
			arr[p0] = arr[p2];
			arr[p2] = box;
			p2--;//p2向后一步
			p0--;//p0退回去一步检查交换后是否为0或2
		}
	}
	printf("排序后的的数组\n");
	for (int j = 0; j < 1000; j++)
		printf("%d ", arr[j]);
}


//快排（找到第k大的数）
void quick_sort_k1(int arr[], int left, int right, int k)
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
	if (i > k)
		quick_sort_k1(arr, left, i - 1, k);
	if (i < k)
		quick_sort_k1(arr, i + 1, right, k);
	final = arr[k];
}


void quick_sort_k(int arr[], int left, int right)
{
	int k = 0;
	while (1)
	{
		system("cls");
		char str[1000] = { 0 };
		int flag = 1;
		k = 0;
		printf("请输入一个大于等于0且小于10000的非负整数\n");
		scanf("%s", str);
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] < '0' || str[i]>'9')
			{
				flag = 0;
				printf("输入有误，请重新输入\n");
				system("pause");
				break;
			}

			k = (str[i] - 48) + k*10;

			if (k >= 10000)
			{
				flag = 0;
				printf("输入有误，请重新输入\n");
				system("pause");
				break;
			}
		}
		if (flag == 1)
			break;
	}
	quick_sort_k1(arr, left, right, k);
	printf("第%d大的数为：%d\n", k,final);
}