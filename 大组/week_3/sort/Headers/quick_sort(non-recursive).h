#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>

int count = 0;
typedef  struct Stack_Node
{
	int data;//只存储一个字符
	struct Stack_Node* next;
}StackNode, * LinkStackPtr;

typedef  struct  Link_Stack
{
	LinkStackPtr top;//栈顶
	int	count;//节点数
}LinkStack;


//初始化栈
bool initLStack(LinkStack* s)
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));//创造头结点
	if (s->top == NULL)
	{
		printf("动态内存分配失败，将退出程序\n");
		exit(0);
	}
	s->count = 0;
	s->top->next = NULL;
	return true;
}

//判断栈是否为空
bool isEmptyLStack(LinkStack* s)
{
	if (s->count <= 0)
		return true;//为空
	else
		return false;//不为空
}


// 入栈
bool pushLStack(LinkStack* s, char data)
{
	LinkStackPtr p_new = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p_new == NULL)
	{
		printf("内存分配失败，将退出程序\n");
		exit(0);
	}
	p_new->data = data;
	p_new->next = s->top;//链接下一个栈
	s->top = p_new;//移动top指针
	(s->count)++;//长度加1
	return true;
}

//出栈
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

//销毁栈
void destroyLStack(LinkStack* s)
{
	if (isEmptyLStack(s))//为空即已经销毁了
		return;
	LinkStackPtr p = s->top;
	LinkStackPtr q = NULL;
	while (p != NULL)//将头结点也销毁
	{
		q = p;
		p = p->next;
		free(q);
	}
	s->top = NULL;
	s->count = 0;
}

int quick_sort_once(int arr[], int left, int right)//单趟快排
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

void quick_sort_1(int arr[], int left, int right)//非递归快排
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
