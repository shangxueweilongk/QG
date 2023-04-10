#pragma once
#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

//二叉排序树
typedef struct BTNode
{
	int data;
	struct BTNode* pLchid;
	struct BTNode* pRchid;
}bst;
///////////////////////////////////////////
//栈
typedef  struct Stack_Node
{
	bst* p;
	struct Stack_Node* next;
}StackNode, * LinkStackPtr;

typedef  struct  Link_Stack
{
	LinkStackPtr top;//栈顶
	int	count;//节点数
}LinkStack;
//////////////////////////////////////////
//队列
typedef struct node
{
	bst* p1;                   //数据域指针
	struct node* next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
	Node* front;                   //队头
	Node* rear;                    //队尾
	int length;            //队列长度
} LQueue;

/////////////////////////////////////////////////

//栈的初始化
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
bst* getTopLStack(LinkStack* s)
{
	if (isEmptyLStack(s))//为空
		return NULL;
	return s->top->p;
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

//压栈
bool pushLStack(LinkStack* s, bst* t)
{
	LinkStackPtr p_new = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p_new == NULL)
	{
		printf("内存分配失败，将退出程序\n");
		exit(0);
	}
	p_new->p = t;
	p_new->next = s->top;//链接下一个栈
	s->top = p_new;//移动top指针
	(s->count)++;//长度加1
	return true;
}

//出栈
bst* popLStack(LinkStack* s)
{
	bst* c;
	if (isEmptyLStack(s))
		return 0;
	LinkStackPtr p = s->top;
	c = s->top->p;
	s->top = s->top->next;
	free(p);
	s->count--;
	return c;
}

///////////////////////////////////////////////

//队列初始化
void InitLQueue(LQueue* Q)
{
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));//创建头结点
	if (Q->front == NULL)
	{
		printf("动态空间创建失败，程序将退出\n");
		exit(0);
	}
	Q->rear->next = NULL;
	Q->length = 0;
}

//判断队列是否为空
bool IsEmptyLQueue(const LQueue* Q)
{
	if (Q->length > 0)
		return false;
	return true;
}

//返回队列首节点地址
bst* GetHeadLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
		return NULL;
	return Q->front->next->p1;
}

//入队
void EnLQueue(LQueue* Q, bst* data)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("动态内存分配失败，将退出程序\n");
		exit(0);
	}
	p->p1 = data;//存储数据指针
	Q->rear->next = p;
	Q->rear = p;
	p->next = NULL;
	Q->length++;
}

//出队
void DeLQueue(LQueue* Q)
{
	Node* p = Q->front->next;//存储出队节点的地址
	Q->front->next = p->next;//指向新节点
	if (Q->front->next == NULL)//出队后头结点指向NULL的话，front与rear重合
		Q->rear = Q->front;
	free(p);//释放空间
	Q->length--;
}

//销毁队列
void DestoryLQueue(LQueue* Q)
{
	Node* p = Q->front;
	Node* q = NULL;
	while (p == NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	Q->length = 0;
}