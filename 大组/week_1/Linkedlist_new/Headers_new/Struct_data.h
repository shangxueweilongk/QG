#pragma once
typedef struct NODE1//������
{
	char data[1000];//������
	struct NODE1* next;//ָ����
}node1;

typedef struct NODE2//˫������
{
	char data[1000];//������
	struct NODE2* next;//ǰָ��
	struct NODE2* back;//��ָ��
}node2;

int len;//ѭ������ڵ���
int j = 1;//ѭ���������ʹ��
