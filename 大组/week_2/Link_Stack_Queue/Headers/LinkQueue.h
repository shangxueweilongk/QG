#pragma once
#include "data_queue.h" 

//初始化
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
	printf("销毁队列完成\n");
}

//判断队列是否为空
bool IsEmptyLQueue(const LQueue* Q)
{
	if (Q->length > 0)
		return false;
	return true;
}

//返回首节点地址
void* GetHeadLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
		return NULL;
	return Q->front->next->data;
}

//返回队列长度
int LengthLQueue(LQueue* Q)
{
	return Q->length;
}

//入队
void EnLQueue(LQueue* Q, void* data)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("动态内存分配失败，将退出程序\n");
		exit(0);
	}
	p->data = data;//存储数据指针
	Q->rear->next = p;
	Q->rear = p;
	p->next = NULL;
	Q->length++;
}

//出队
bool DeLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
		return false;
	Node* p = Q->front->next;//存储出队节点的地址
	Q->front->next = p->next;//指向新节点
	if (Q->front == NULL)//出队后头结点指向NULL的话，front与rear重合
		Q->rear = Q->front;
	free(p);//释放空间
	Q->length--;
	return true;
}

//清空队列
void ClearLQueue(LQueue* Q)
{
	Node* p = Q->front->next;//保留头结点
	Node* q = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	Q->front->next = NULL;
	Q->rear = Q->front;
	Q->length = 0;
	printf("清空队列完成\n");
}

//打印
void LPrint(void* q, char c)
{
	if (c == 'i')
		printf("%d ", *(int*)q);
	if (c == 'f')
		printf("%f ", *(float*)q);
	if (c == 'c')
		printf("%c ", *(char*)q);

}


//遍历(从头到尾)
bool TraverseLQueue(const LQueue* Q, char c)
{
	if (IsEmptyLQueue(Q))
		return false;
	Node* p = Q->front->next;
	while (p != NULL)
	{
		LPrint(p->data, c);
		p = p->next;
	}
	return true;
}



