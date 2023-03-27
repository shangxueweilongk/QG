#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node
{
    void* data;                   //数据域指针
    struct node* next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node* front;                   //队头
    Node* rear;                    //队尾
    int length;            //队列长度
} LQueue;

#endif // LQUEUE_H_INCLUDED
