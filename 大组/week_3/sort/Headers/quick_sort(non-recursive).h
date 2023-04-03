#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>

int count = 0;
typedef  struct Stack_Node
{
	int data;//ֻ�洢һ���ַ�
	struct Stack_Node* next;
}StackNode, * LinkStackPtr;

typedef  struct  Link_Stack
{
	LinkStackPtr top;//ջ��
	int	count;//�ڵ���
}LinkStack;


//��ʼ��ջ
bool initLStack(LinkStack* s)
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));//����ͷ���
	if (s->top == NULL)
	{
		printf("��̬�ڴ����ʧ�ܣ����˳�����\n");
		exit(0);
	}
	s->count = 0;
	s->top->next = NULL;
	return true;
}

//�ж�ջ�Ƿ�Ϊ��
bool isEmptyLStack(LinkStack* s)
{
	if (s->count <= 0)
		return true;//Ϊ��
	else
		return false;//��Ϊ��
}


// ��ջ
bool pushLStack(LinkStack* s, char data)
{
	LinkStackPtr p_new = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p_new == NULL)
	{
		printf("�ڴ����ʧ�ܣ����˳�����\n");
		exit(0);
	}
	p_new->data = data;
	p_new->next = s->top;//������һ��ջ
	s->top = p_new;//�ƶ�topָ��
	(s->count)++;//���ȼ�1
	return true;
}

//��ջ
int popLStack(LinkStack* s)
{
	int c;
	if (isEmptyLStack(s))
		return 0;
	LinkStackPtr p = s->top;
	c = s->top->data;
	s->top = s->top->next;
	free(p);
	s->count--;
	return c;
}

//����ջ
void destroyLStack(LinkStack* s)
{
	if (isEmptyLStack(s))//Ϊ�ռ��Ѿ�������
		return;
	LinkStackPtr p = s->top;
	LinkStackPtr q = NULL;
	while (p != NULL)//��ͷ���Ҳ����
	{
		q = p;
		p = p->next;
		free(q);
	}
	s->top = NULL;
	s->count = 0;
}

int quick_sort_once(int arr[], int left, int right)//���˿���
{

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
	return i;
}

void quick_sort_1(int arr[], int left, int right)//�ǵݹ����
{
	LinkStack s;
	initLStack(&s);
	pushLStack(&s, left);
	pushLStack(&s, right);
	while (isEmptyLStack(&s) == false)
	{
		int j = popLStack(&s);
		int i = popLStack(&s);
		int key = quick_sort_once(arr, i, j);
		if (i < key - 1)
		{
			pushLStack(&s, i);
			pushLStack(&s, key - 1);
		}
		if (j > key + 1)
		{
			pushLStack(&s, key + 1);
			pushLStack(&s, j);
		}
	}
	destroyLStack(&s);
}
