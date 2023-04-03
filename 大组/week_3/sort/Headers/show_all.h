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
	printf("1����������\n");
	printf("2������С����\n");
	printf("3�����ɲ������ݲ���������\n");
	printf("4����ɫ����\n");
	printf("5��Ѱ�����������е�k�����\n");
	printf("6���˳�\n");
	printf("���������ֽ�����Ӧ����\n");
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
				printf("��������ȷ������!");
				system("pause");
			}
			else if (str[0] < '1' || str[0]>'9')
			{
				printf("��������ȷ������!");
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
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			insert_sort(data_1, 10000);
			diff = clock() - start;
			printf("��������(1w)��ʱ��%dms\n", diff);


			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			merge_sort(data_1, 0, 9999);
			diff = clock() - start;
			printf("�鲢����(1w)��ʱ��%dms\n", diff);


			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			quick_sort(data_1, 0, 9999);
			diff = clock() - start;
			printf("��������(1w)��ʱ��%dms\n", diff);


			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			count_sort(data_1, 10000);
			diff = clock() - start;
			printf("��������(1w)��ʱ��%dms\n", diff);

			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			radix_count_sort(data_1, 10000);
			diff = clock() - start;
			printf("������������(1w)��ʱ��%dms\n", diff);

			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			quick_sort_1(data_1, 0,9999);
			diff = clock() - start;
			printf("���ŷǵݹ�(1w)��ʱ��%dms\n", diff);


			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			bubble_sort_1(data_1, 10000);
			diff = clock() - start;
			printf("ð�������Ż�1(1w)��ʱ��%dms\n", diff);

			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			bubble_sort_2(data_1, 10000);
			diff = clock() - start;
			printf("ð�������Ż�2(1w)��ʱ��%dms\n", diff);

			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_1, "%d", &data_1[d]) != EOF)
				d++;
			fclose(fp_1);
			start = clock();
			bubble_sort_3(data_1, 10000);
			diff = clock() - start;
			printf("ð�������Ż�3(1w)��ʱ��%dms\n", diff);

			printf("##################################################\n");

			if ((fp_2 = fopen("data_2.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_2, "%d", &data_2[d]) != EOF)
				d++;
			fclose(fp_2);
			start = clock();
			insert_sort(data_2, 50000);
			diff = clock() - start;
			printf("��������(5w)��ʱ��%dms\n", diff);


			if ((fp_2 = fopen("data_2.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_2, "%d", &data_2[d]) != EOF)
				d++;
			fclose(fp_2);
			start = clock();
			merge_sort(data_2, 0, 49999);
			diff = clock() - start;
			printf("�鲢����(5w)��ʱ��%dms\n", diff);


			if ((fp_2 = fopen("data_2.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_2, "%d", &data_2[d]) != EOF)
				d++;
			fclose(fp_2);
			start = clock();
			quick_sort(data_2, 0, 49999);
			diff = clock() - start;
			printf("��������(5w)��ʱ��%dms\n", diff);

			if ((fp_2 = fopen("data_2.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_2, "%d", &data_2[d]) != EOF)
				d++;
			fclose(fp_2);
			start = clock();
			count_sort(data_2, 50000);
			diff = clock() - start;
			printf("��������(5w)��ʱ��%dms\n", diff);

			if ((fp_2 = fopen("data_2.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_2, "%d", &data_2[d]) != EOF)
				d++;
			fclose(fp_2);
			start = clock();
			radix_count_sort(data_2, 50000);
			diff = clock() - start;
			printf("������������(5w)��ʱ��%dms\n", diff);

			printf("##################################################\n");


			if ((fp_3 = fopen("data_3.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_3, "%d", &data_3[d]) != EOF)
				d++;
			fclose(fp_3);
			start = clock();
			insert_sort(data_3, 200000);
			diff = clock() - start;
			printf("��������(20w)��ʱ��%dms\n", diff);


			if ((fp_3 = fopen("data_3.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_3, "%d", &data_3[d]) != EOF)
				d++;
			fclose(fp_3);
			start = clock();
			merge_sort(data_3, 0, 199999);
			diff = clock() - start;
			printf("�鲢����(20w)��ʱ��%dms\n", diff);


			if ((fp_3 = fopen("data_3.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_3, "%d", &data_3[d]) != EOF)
				d++;
			fclose(fp_3);
			start = clock();
			quick_sort(data_3, 0, 199999);
			diff = clock() - start;
			printf("��������(20w)��ʱ��%dms\n", diff);

			if ((fp_3 = fopen("data_3.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_3, "%d", &data_3[d]) != EOF)
				d++;
			fclose(fp_3);
			start = clock();
			count_sort(data_3, 200000);
			diff = clock() - start;
			printf("��������(20w)��ʱ��%dms\n", diff);

			if ((fp_3 = fopen("data_3.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_3, "%d", &data_3[d]) != EOF)
				d++;
			fclose(fp_3);
			start = clock();
			radix_count_sort(data_3, 200000);
			diff = clock() - start;
			printf("������������(20w)��ʱ��%dms\n", diff);

			if ((fp_3 = fopen("data_3.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_3, "%d", &data_3[d]) != EOF)
				d++;
			fclose(fp_3);
			start = clock();
			random_quick_sort(data_3, 0, 199999);
			diff = clock() - start;
			printf("�����������(20w)��ʱ��%dms\n", diff);

			if ((fp_3 = fopen("data_3.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			d = 0;
			while (fscanf(fp_3, "%d", &data_3[d]) != EOF)
				d++;
			fclose(fp_3);
			start = clock();
			mid_quick_sort(data_3, 0, 199999);
			diff = clock() - start;
			printf("����ȡ�п���(20w)��ʱ��%dms\n", diff);

			printf("##################################################\n");
		case(2):
			start = clock();
			for (int i = 1; i <= 100000; i++)//����С������
			{
				int data_4[105] = { 0 };
				srand(time(0));//���������
				for (int j = 0; j < 100; j++)//������ɺ���һ�ٸ�Ԫ�ص�����
					data_4[j] = rand() % 100;
				insert_sort(data_4, 100);
			}
			diff = clock() - start;
			printf("��������(����С����)��ʱ��%dms\n", diff);

			start = clock();
			for (int i = 1; i <= 100000; i++)//����С������
			{
				int data_4[105] = { 0 };
				srand(time(0));//���������
				for (int j = 0; j < 100; j++)//������ɺ���һ�ٸ�Ԫ�ص�����
					data_4[j] = rand() % 100;
				merge_sort(data_4, 0, 99);
			}
			diff = clock() - start;
			printf("�鲢����(����С����)��ʱ��%dms\n", diff);

			start = clock();
			for (int i = 1; i <= 100000; i++)//����С������
			{
				int data_4[105] = { 0 };
				srand(time(0));//���������
				for (int j = 0; j < 100; j++)//������ɺ���һ�ٸ�Ԫ�ص�����
					data_4[j] = rand() % 100;
				quick_sort(data_4, 0, 99);
			}
			diff = clock() - start;
			printf("����(����С����)��ʱ��%dms\n", diff);

			start = clock();
			for (int i = 1; i <= 100000; i++)//����С������
			{
				int data_4[105] = { 0 };
				srand(time(0));//���������
				for (int j = 0; j < 100; j++)//������ɺ���һ�ٸ�Ԫ�ص�����
					data_4[j] = rand() % 100;
				insert_sort(data_4, 100);
			}
			diff = clock() - start;
			printf("��������(����С����)��ʱ��%dms\n", diff);

			start = clock();
			for (int i = 1; i <= 10000; i++)//����С������
			{
				int data_4[105] = { 0 };
				srand(time(0));//���������
				for (int j = 0; j < 100; j++)//������ɺ���һ�ٸ�Ԫ�ص�����
					data_4[j] = rand() % 100;
				count_sort(data_4, 100);
			}
			diff = clock() - start;
			printf("��������(����С���ݣ����������������������ʮ����ֻ����10*k��)��ʱ��%dms\n", diff);

			start = clock();
			for (int i = 1; i <= 100000; i++)//����С������
			{
				int data_4[105] = { 0 };
				srand(time(0));//���������
				for (int j = 0; j < 100; j++)//������ɺ���һ�ٸ�Ԫ�ص�����
					data_4[j] = rand() % 100;
				radix_count_sort(data_4, 100);
			}
			diff = clock() - start;
			printf("������������(����С����)��ʱ��%dms\n", diff);
			system("pause");
			break;

		case(3):
			printf("��5w������������뵽data.txt�ļ���\n");
			FILE* fp;
			if ((fp = fopen("data.txt", "w+")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
				exit(0);
			}
			srand(time(0));
			for (int i = 1; i <= 50; i++)//����5w�������������
			{
				int random = rand() % 1001;
				fprintf(fp, "%d ", random);
			}
			printf("�Ѿ������ݶ���data.txt�ļ���\n");
			fclose(fp);
			FILE* fp_1;
			if ((fp_1 = fopen("data.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
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
			printf("�鲢����(5w)��ʱ��%dms\n", diff);

			system("pause");
			break;

		case(4):
			color_sort();
			system("pause");
			break;

		case(5):
			if ((fp_1 = fopen("data_1.txt", "r")) == NULL)
			{
				printf("�޷��򿪸��ļ�,���˳�����\n");
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