#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Struct_data.h"
#include"CREAT.h"
#include"EXCHANGE.h"
#include"SEARCH.h"
#include"JUDGE.h"
#include"TURN_1.h"
#include"TURN_2.h"
#include"TRAVERSE.h"

node1* head1 = NULL;
node2* head2 = NULL;

int flag = 0;//flag=0û��������flag=1����flag=2˫��flag=3ѭ��


void menu()
{
	printf("A.����������\n");
	printf("B.����˫������\n");
	printf("C.����ѭ������\n");
	printf("D.��������ż����\n");
	printf("E.Ѱ�ҵ������е�\n");
	printf("F.�ж��б��Ƿ�ɻ�\n");
	printf("G.��ת�б�(�ǵݹ�)\n");
	printf("H.��ת�б�(�ݹ�)\n");
	printf("I.��������\n");
	printf("J.��������\n");
}

void menucontrol()
{
	char a[200]={0};
	while (1)
	{
		system("cls");//����
		menu();
		printf("�����(С)д��ĸ������Ӧ����\n");
		scanf("%s", a);
		if(strlen(a)>1)
		{
			system("cls");
			printf("���밴����������������\n");
			system("pause");
			getchar();
			continue;
		}

		else if (a[0] == 65 || a[0] == 97)//A.����������
		{
			system("cls");
			head1=creat_list1();
			if (head1 != NULL)//�����ؿ�ָ������flag=1(����Ǵ�����һ��������)
				flag = 1;
			else
				flag = 0;
			system("pause");
			continue;
		}

		else if (a[0] == 66 || a[0] == 98)//B.����˫������
		{
			system("cls");
			head2=creat_list2();
			if (head2 != NULL)//�����ؿ�ָ������flag=2(����Ǵ�����һ��˫������)
				flag = 2;
			else
				flag = 0;
			system("pause");
			continue;
		}

		else if (a[0] == 67 || a[0] == 99)//C.����ѭ������
		{
			system("cls");
			head1=creat_list3();
			if (head1 != NULL)//�����ؿ�ָ������flag=3(����Ǵ�����һ��ѭ������)
				flag = 3;
			else
				flag = 0;
			system("pause");
			continue;
		}

		else if (a[0] == 68 || a[0] == 100)//D.��������ż����
		{
			system("cls");

			if (flag == 1)
				exchange(head1);
			else if(flag==0)
				printf("������ʧ���޷����в��������˳�\n");
			else
				printf("��֧�ָ�����������в��������˳�\n");
			system("pause");
			continue;
		}

		else if (a[0] == 69 || a[0] == 101)//E.Ѱ�ҵ������е�
		{
			system("cls");

			if (flag == 1)
				printf("�е�����Ϊ��%s ", mid_search(head1)->data);

			else if (flag == 0)
				printf("������ʧ���޷����в��������˳�\n");
			else
				printf("��֧�ָ�����������в��������˳�\n");
			system("pause");
			continue;
		}

		else if (a[0] == 70 || a[0] == 102)//F.�ж��б��Ƿ�ɻ�
		{

			system("cls");
			if (flag == 1)
				circle_judge1(head1);
			else if (flag == 2)
				circle_judge2(head2);
			else if (flag == 3)
				circle_judge1(head1);
			else
				printf("������ʧ���޷����в��������˳�\n");
			system("pause");
			continue;
		}

		else if (a[0] == 71 || a[0] == 103)//G.��ת�б�(�ǵݹ�)
		{
			system("cls");
			if (flag == 1)
				turn_1(head1);
			else if (flag == 2)
				turn_2(head2);
			else if (flag == 3)
				turn_circle(head1,len);
			else
				printf("������ʧ���޷����в��������˳�\n");
			system("pause");
			continue;
		}

		else if (a[0] == 72 || a[0] == 104)//H.��ת�б�(�ݹ�)
		{
			system("cls");
			node1* head = (node1*)malloc(sizeof(node1));//���������׽ڵ�ĵ�ַ(�ݹ�)
			if (flag == 1)
			{
				head->next = turn_new_1(head1->next);
				head1 = head;
			}
			else if (flag == 2)
			{
				head->next = turn_new_2(head2->next);
				head2 = head;
			}
			else if (flag == 3)
			{
				head->next = turn_new_circle(head1->next);
				head1 = head;
			}
			else
				printf("������ʧ���޷����в��������˳�\n");
			system("pause");
			continue;
		}

		else if (a[0] == 73 || a[0] == 105)//I.�����б�
		{
		    system("cls");
			if (flag == 1)
				traverse_1(head1);
			else if (flag == 2)
				traverse_2(head2);
			else if (flag == 3)
				traverse_3(head1);
			else
				printf("������ʧ���޷����в��������˳�\n");
			system("pause");
			continue;
		}

		else if (a[0] == 74 || a[0] == 106)//J.��������
		{
			system("cls");
			exit(0);
		}

		else
		{
			system("cls");
			printf("���밴����������������\n");
			system("pause");
			continue;
		}
	}
}
