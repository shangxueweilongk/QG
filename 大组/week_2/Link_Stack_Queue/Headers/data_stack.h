#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
//ifndef可以避免以下错误:如果在.h文件中定义了全局变量, 一个C文件包含了.h文件多次,
//如果不加#ifndef宏定义, 会出现变量重复定义的错误; 如果加了#ifndef则不会出现这种错误
#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>


typedef  struct Stack_Node
{
	int result;//用于存储四则运算每次运算的结果             
	char data;//只存储一个字符
	struct Stack_Node* next;
}StackNode, * LinkStackPtr;

typedef  struct  Link_Stack
{
	LinkStackPtr top;//栈顶
	int	count;//节点数
}LinkStack;


#endif 
