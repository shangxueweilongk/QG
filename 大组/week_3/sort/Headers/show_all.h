#pragma once
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data.h"
#include"sort_1.h"
#include"sort_2.h"
#include"sort_application.h"
#include"quick_sort(non-recursive).h"

int* a;
clock_t start, diff;
FILE* fp_1, * fp_2, * fp_3;
int d = 0;
int data_3[200005] = { 0 };
int data_1[10005] = { 0 }, data_2[50005] = { 0 }, data_4[105] = { 0 };

void menu()
{
	printf("1、大量数据\n");
	printf("2、大量小数据\n");
	printf("3、生成测试数据并进行排序\n");
	printf("4、颜色排序\n");
	printf("5、寻找无序数列中第k大的数\n");
	printf("6、退出\n");
	printf("请输入数字进行相应操作\n");
}


void show()
{
	while (1)
	{
		char str[10000] = { 0 };
		int flag = 0;

		system("cls");
		menu();

		while (1)
		{
			scanf("%s", str);
			if (strlen(str) != 1)
			{
				printf("请输入正确的数字!");
				system("pause");
			}
			else if (str[0] < '1' || str[0]>'9')
			{
				printf("请输入正确的数字!");
				system("pause");
			}
			else
			{
				flag = str[0] - 48;
				break;
			}
		}

		switch (flag)
		{
		case(1):
			
			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			insert_sort(data_1, 10000);
			diff = clock() - start;
			printf("插入排序(1w)耗时：%dms\n", diff);


			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			merge_sort(data_1, 0, 9999);
			diff = clock() - start;
			printf("归并排序(1w)耗时：%dms\n", diff);


			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			quick_sort(data_1, 0, 9999);
			diff = clock() - start;
			printf("快速排序(1w)耗时：%dms\n", diff);


			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			count_sort(data_1, 10000);
			diff = clock() - start;
			printf("计数排序(1w)耗时：%dms\n", diff);

			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			radix_count_sort(data_1, 10000);
			diff = clock() - start;
			printf("基数计数排序(1w)耗时：%dms\n", diff);

			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			quick_sort_1(data_1, 0,9999);
			diff = clock() - start;
			printf("快排非递归(1w)耗时：%dms\n", diff);


			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			bubble_sort_1(data_1, 10000);
			diff = clock() - start;
			printf("冒泡排序优化1(1w)耗时：%dms\n", diff);

			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			bubble_sort_2(data_1, 10000);
			diff = clock() - start;
			printf("冒泡排序优化2(1w)耗时：%dms\n", diff);

			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			bubble_sort_3(data_1, 10000);
			diff = clock() - start;
			printf("冒泡排序优化3(1w)耗时：%dms\n", diff);

			printf("##################################################\n");

			if ((fp_2 = fopen("data_2.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_2, "%d", &data_2[d]) != EOF)
				d++;
			fclose(fp_2);
			start = clock();
			insert_sort(data_2, 50000);
			diff = clock() - start;
			printf("插入排序(5w)耗时：%dms\n", diff);


			if ((fp_2 = fopen("data_2.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_2, "%d", &data_2[d]) != EOF)
				d++;
			fclose(fp_2);
			start = clock();
			merge_sort(data_2, 0, 49999);
			diff = clock() - start;
			printf("归并排序(5w)耗时：%dms\n", diff);


			if ((fp_2 = fopen("data_2.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_2, "%d", &data_2[d]) != EOF)
				d++;
			fclose(fp_2);
			start = clock();
			quick_sort(data_2, 0, 49999);
			diff = clock() - start;
			printf("快速排序(5w)耗时：%dms\n", diff);

			if ((fp_2 = fopen("data_2.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_2, "%d", &data_2[d]) != EOF)
				d++;
			fclose(fp_2);
			start = clock();
			count_sort(data_2, 50000);
			diff = clock() - start;
			printf("计数排序(5w)耗时：%dms\n", diff);

			if ((fp_2 = fopen("data_2.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_2, "%d", &data_2[d]) != EOF)
				d++;
			fclose(fp_2);
			start = clock();
			radix_count_sort(data_2, 50000);
			diff = clock() - start;
			printf("基数计数排序(5w)耗时：%dms\n", diff);

			printf("##################################################\n");


			if ((fp_3 = fopen("data_3.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_3, "%d", &data_3[d]) != EOF)
				d++;
			fclose(fp_3);
			start = clock();
			insert_sort(data_3, 200000);
			diff = clock() - start;
			printf("插入排序(20w)耗时：%dms\n", diff);


			if ((fp_3 = fopen("data_3.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_3, "%d", &data_3[d]) != EOF)
				d++;
			fclose(fp_3);
			start = clock();
			merge_sort(data_3, 0, 199999);
			diff = clock() - start;
			printf("归并排序(20w)耗时：%dms\n", diff);


			if ((fp_3 = fopen("data_3.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_3, "%d", &data_3[d]) != EOF)
				d++;
			fclose(fp_3);
			start = clock();
			quick_sort(data_3, 0, 199999);
			diff = clock() - start;
			printf("快速排序(20w)耗时：%dms\n", diff);

			if ((fp_3 = fopen("data_3.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_3, "%d", &data_3[d]) != EOF)
				d++;
			fclose(fp_3);
			start = clock();
			count_sort(data_3, 200000);
			diff = clock() - start;
			printf("计数排序(20w)耗时：%dms\n", diff);

			if ((fp_3 = fopen("data_3.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_3, "%d", &data_3[d]) != EOF)
				d++;
			fclose(fp_3);
			start = clock();
			radix_count_sort(data_3, 200000);
			diff = clock() - start;
			printf("基数计数排序(20w)耗时：%dms\n", diff);

			if ((fp_3 = fopen("data_3.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_3, "%d", &data_3[d]) != EOF)
				d++;
			fclose(fp_3);
			start = clock();
			random_quick_sort(data_3, 0, 199999);
			diff = clock() - start;
			printf("随机快速排序(20w)耗时：%dms\n", diff);

			if ((fp_3 = fopen("data_3.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_3, "%d", &data_3[d]) != EOF)
				d++;
			fclose(fp_3);
			start = clock();
			mid_quick_sort(data_3, 0, 199999);
			diff = clock() - start;
			printf("三数取中快排(20w)耗时：%dms\n", diff);

			printf("##################################################\n");
		case(2):
			start = clock();
			for (int i = 1; i <= 100000; i++)//大量小数据量
			{
				int data_4[105] = { 0 };
				srand(time(0));//随机数种子
				for (int j = 0; j < 100; j++)//随机生成含有一百个元素的数组
					data_4[j] = rand() % 100;
				insert_sort(data_4, 100);
			}
			diff = clock() - start;
			printf("插入排序(大量小数据)耗时：%dms\n", diff);

			start = clock();
			for (int i = 1; i <= 100000; i++)//大量小数据量
			{
				int data_4[105] = { 0 };
				srand(time(0));//随机数种子
				for (int j = 0; j < 100; j++)//随机生成含有一百个元素的数组
					data_4[j] = rand() % 100;
				merge_sort(data_4, 0, 99);
			}
			diff = clock() - start;
			printf("归并排序(大量小数据)耗时：%dms\n", diff);

			start = clock();
			for (int i = 1; i <= 100000; i++)//大量小数据量
			{
				int data_4[105] = { 0 };
				srand(time(0));//随机数种子
				for (int j = 0; j < 100; j++)//随机生成含有一百个元素的数组
					data_4[j] = rand() % 100;
				quick_sort(data_4, 0, 99);
			}
			diff = clock() - start;
			printf("快排(大量小数据)耗时：%dms\n", diff);

			start = clock();
			for (int i = 1; i <= 100000; i++)//大量小数据量
			{
				int data_4[105] = { 0 };
				srand(time(0));//随机数种子
				for (int j = 0; j < 100; j++)//随机生成含有一百个元素的数组
					data_4[j] = rand() % 100;
				insert_sort(data_4, 100);
			}
			diff = clock() - start;
			printf("插入排序(大量小数据)耗时：%dms\n", diff);

			start = clock();
			for (int i = 1; i <= 10000; i++)//大量小数据量
			{
				int data_4[105] = { 0 };
				srand(time(0));//随机数种子
				for (int j = 0; j < 100; j++)//随机生成含有一百个元素的数组
					data_4[j] = rand() % 100;
				count_sort(data_4, 100);
			}
			diff = clock() - start;
			printf("计数排序(大量小数据，该排序次数少于其他排序十倍即只进行10*k次)耗时：%dms\n", diff);

			start = clock();
			for (int i = 1; i <= 100000; i++)//大量小数据量
			{
				int data_4[105] = { 0 };
				srand(time(0));//随机数种子
				for (int j = 0; j < 100; j++)//随机生成含有一百个元素的数组
					data_4[j] = rand() % 100;
				radix_count_sort(data_4, 100);
			}
			diff = clock() - start;
			printf("基数计数排序(大量小数据)耗时：%dms\n", diff);
			system("pause");
			break;

		case(3):
			printf("将5w个随机整数读入到data.txt文件中\n");
			FILE* fp;
			if ((fp = fopen("data.txt", "w+")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			srand(time(0));
			for (int i = 1; i <= 50; i++)//读入5w个随机整数数据
			{
				int random = rand() % 1001;
				fprintf(fp, "%d ", random);
			}
			printf("已经将数据读入data.txt文件中\n");
			fclose(fp);
			FILE* fp_1;
			if ((fp_1 = fopen("data.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			int a[50005] = { 0 };
			int d = 0;
			while (fscanf(fp_1, "%d", &a[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			merge_sort(a, 0, 49999);
			diff = clock() - start;
			printf("归并排序(5w)耗时：%dms\n", diff);

			system("pause");
			break;

		case(4):
			color_sort();
			system("pause");
			break;

		case(5):
			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("无法打开该文件,将退出程序\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			quick_sort_k(data_1, 0, 9999);
			system("pause");
			break;

		case(6):
			return;
		}
	}
}