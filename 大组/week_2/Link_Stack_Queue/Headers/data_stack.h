#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
//ifndef���Ա������´���:�����.h�ļ��ж�����ȫ�ֱ���, һ��C�ļ�������.h�ļ����,
//�������#ifndef�궨��, ����ֱ����ظ�����Ĵ���; �������#ifndef�򲻻�������ִ���
#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>


typedef  struct Stack_Node
{
	int result;//���ڴ洢��������ÿ������Ľ��             
	char data;//ֻ�洢һ���ַ�
	struct Stack_Node* next;
}StackNode, * LinkStackPtr;

typedef  struct  Link_Stack
{
	LinkStackPtr top;//ջ��
	int	count;//�ڵ���
}LinkStack;


#endif 
