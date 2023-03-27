#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node
{
    void* data;                   //������ָ��
    struct node* next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node* front;                   //��ͷ
    Node* rear;                    //��β
    int length;            //���г���
} LQueue;

#endif // LQUEUE_H_INCLUDED
