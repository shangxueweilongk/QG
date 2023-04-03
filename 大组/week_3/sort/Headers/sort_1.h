#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int arr_1[200005] = { 0 };
int temp_1[200005] = { 0 }, temp_2[200005] = { 0 };


//��������
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

//�鲢����
void merge(int arr[], int left, int mid, int right)
{
	int i = left, j = mid + 1, flag = left;
	while (j <= right && i <= mid)//(���鲻Խ�磬i��ȥ������һ������)
	{
		if (arr[j] < arr[i])
			temp_2[flag++] = arr[j++];
		else
			temp_2[flag++] = arr[i++];
	}
	while (i <= mid)//jָ�����⣬��iûָ����һ������
		temp_2[flag++] = arr[i++];
	while (j <= right)//iֱ����һ�����飬��jδָ������
		temp_2[flag++] = arr[j++];
	for (int d = left; d <= right; d++)//�ٽ�temp��ֵ����ȥ
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


//����
void quick_sort(int arr[], int left, int right)
{
	if (left >= right)//���ݹ�
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
	quick_sort(arr, left, i - 1);//i����Ҫ����
	quick_sort(arr, i + 1, right);
}


//��������
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
			/*printf("%d ", i);*///�����д�ӡ��Ҫ��ʱ
			count++;
		}
	}
}

//������������()
int max_digits(int arr[], int len)//�ҵ�����������λ��
{
	int max = arr[0], digits = 0;
	//maxΪ��������(max����ȡ0�����и���),digitsΪ���λ��
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
		int bucket[15] = { 0 };//ͳ��

		for (int j = 0; j < len; j++)
		{
			int num = (arr[j] / radix) % 10;//num����Ϊ��λ��ʮλ...
			bucket[num]++;
		}
		//��bucket��ֵ��Ӧ���ǵڼ�������bucketֵΪ5�������Ǿ��������ĵ��������
		for (int j = 1; j < 10; j++)
			bucket[j] = bucket[j - 1] + bucket[j];

		for (int j = len - 1; j >= 0; j--)
			//�Ӻ���ǰ��Ϊ�Ѿ��ź����ˣ����ϴ󡱵��Ѿ��ں���
		{
			int num = (arr[j] / radix) % 10;
			temp_1[bucket[num] - 1] = arr[j];
			bucket[num]--;//���λ��Ϊ1������������һ����λ����Ҫ-1
		}

		for (int j = 0; j < len; j++)//���������
			arr[j] = temp_1[j];

		radix *= 10;
	}
}




