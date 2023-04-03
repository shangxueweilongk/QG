#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble_sort_1(int arr[], int len)//ð�������Ż�1
{
	for (int i = 0; i < len - 1; i++)
	{
		int flag = 0;//����Ƿ���н���
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				//����
				int box = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = box;
				flag = 1;//���
			}
		}
		if (flag == 0)//���û�н�����Ԫ�أ����Ѿ�����
			return;
	}
}

void bubble_sort_2(int arr[], int len)//ð�������Ż�2
{

	int k = len - 1;
	for (int i = 0; i < k; i++)
	{
		int pos = 0;//������¼���һ�ν�����λ��
		for (int j = 0; j < k; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int box = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = box;
				pos = j;//��¼���һ�ν�����λ��
			}
		}
		if (pos == 0)//���û�н�����Ԫ�أ����Ѿ�����
			return;
		k = pos;//��һ�αȽϵ���¼λ�ü���,k�������Ϊû�н��н����ʾ�����
	}
}


void bubble_sort_3(int arr[], int len)//ð�������Ż�3
{
	int n = 0;//ͬʱ�����ֵ����С��Ҫ�����±����
	int k = len - 1;
	for (int i = 0; i < k; i++)//ȷ����������
	{
		int pos = 0;//������¼���һ�ν�����λ��
		//����Ѱ�����ֵ
		for (int j = n; j < k; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int box = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = box;
				pos = j;//��¼���һ�ν�����λ��
			}
		}

		if (pos == 0)//���û�н�����Ԫ�أ����Ѿ�����
			return;

		k = pos;//��һ�αȽϵ���¼λ�ü���,k�������Ϊû�н��н����ʾ�����

		//����Ѱ����Сֵ(����Сֵ�ں���ʱ�Ͽ��������)
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
		if (pos == 0)//���û�н�����Ԫ�أ����Ѿ�����
			return;
	}
}

void random_quick_sort(int arr[], int left, int right)
{
	if (left >= right)//���ݹ�
		return;

	int i = left, j = right;
	int pos = rand() % (right - left + 1) + left;//������ɷ�Χ�ڵ��±�
	int temp = arr[left]; arr[left] = arr[pos]; arr[pos] = temp;//�����ֵ�������׼ֵ����
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

//����ȡ�п���
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
	if (left >= right)//���ݹ�
		return;

	int i = left, j = right;
	int pos = get_mid(left, right, (left + right) / 2);//������ֵ
	int temp = arr[left]; arr[left] = arr[pos]; arr[pos] = temp;//�����ֵ�������׼ֵ����
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
