#pragma once
typedef struct NODE1//单链表
{
	char data[1000];//数据域
	struct NODE1* next;//指针域
}node1;

typedef struct NODE2//双向链表
{
	char data[1000];//数据域
	struct NODE2* next;//前指针
	struct NODE2* back;//后指针
}node2;

int len;//循环链表节点数
int j = 1;//循环链表遍历使用
