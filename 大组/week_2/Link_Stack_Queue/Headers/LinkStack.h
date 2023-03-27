#pragma once
#include "data_stack.h" 

//链栈的基本操作

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

//得到栈顶元素
LinkStackPtr getTopLStack(LinkStack* s)
{
	if (isEmptyLStack(s))//为空
		return NULL;
	return s->top;
}

//清空栈
void clearLStack(LinkStack* s)
{
	if (isEmptyLStack(s))//为空即已经清空了
		return ;
	LinkStackPtr p = s->top;
	LinkStackPtr q = NULL;

	while (p->next != NULL)//到头结点停止(保留头结点)
	{
		q = p;
		p = p->next;
		free(q);
	}

	s->top = p;
	s->count = 0;
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

//检测栈长度
int LStackLength(LinkStack* s)
{
	return s->count;
}

//入栈
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
char popLStack(LinkStack* s)
{
	char c;
	if (isEmptyLStack(s))
		return 0;
	LinkStackPtr p = s->top;
	c = s->top->data;
	s->top = s->top->next;
	free(p);
	s->count--;
	return c;
}

//入栈_1
bool pushLStack_1(LinkStack* s, int n)
{
	LinkStackPtr p_new = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p_new == NULL)
	{
		printf("内存分配失败，将退出程序\n");
		exit(0);
	}
	p_new->result = n;
	p_new->next = s->top;//链接下一个栈
	s->top = p_new;//移动top指针
	(s->count)++;//长度加1
	return true;
}

//出栈_1(用于四则运算)
int popLStack_1(LinkStack* s)
{
	int n;
	if (isEmptyLStack(s))
		return NULL;
	LinkStackPtr p = s->top;
	n = s->top->result;
	s->top = s->top->next;
	free(p);
	s->count--;
	return n;
}

//遍历栈
bool traverseLSueue(LinkStack* s)
{
	LinkStackPtr p = s->top;
	if (isEmptyLStack(s))
		return false;
	while (p->next != NULL)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	return true;
}
