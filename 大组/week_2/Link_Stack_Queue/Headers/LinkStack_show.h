#pragma once
#include"LinkStack_calculate.h"

void show_1()
{
	LinkStack s;
	initLStack(&s);
	int flag;
	char box[200] = { 0 },data_1[200]={0}, data, c;//data_1ֻ����������ݣ�data������ջԪ�����ݣ�cΪ��ջԪ������
	while (1)
	{
		while (1)
		{
			flag = 0;
			system("cls");
			printf("�����ʵ�����¹���\n");
			printf("1.�ж�ջ�Ƿ�Ϊ��\n");
			printf("2.��ȡջ���ڵ������\n");
			printf("3.ѹջ\n");
			printf("4.��ջ\n");
			printf("5.��������ջ\n");
			printf("6.��ȡջ�ĳ���\n");
			printf("7.���ջ\n");
			printf("8.ջ������������\n");
			printf("9.����ջ���˳�\n");
			printf("����������ʵ����Ӧ����\n");
			scanf("%s", box);
			while (getchar() != '\n');
			if (strlen(box) != 1)
			{
				printf("��������ȷ������!");
				system("pause");
			}
			else if (box[0] < '1' || box[0]>'9')
			{
				printf("��������ȷ������!");
				system("pause");
			}
			else
			{
				flag = box[0] - 48;
				break;
			}
		}
		system("cls");
		switch (flag)
		{
		case(1):
			if (isEmptyLStack(&s))
				printf("ջΪ��!\n");
			else
				printf("ջ��Ϊ��.\n");
			system("pause");
			break;
		case(2):
			if (getTopLStack(&s) != NULL)
			{
				printf("ջ���ڵ������Ϊ��%c",s.top->data);
			}
			else
				printf("����Ϊ��!\n");
			system("pause");
			break;

		case(3):
			printf("����������(������һ���ַ���Ϊ�ַ�����ֻ�Ե�һ���ַ����в���)\n");
			scanf("%s", data_1);
			data = data_1[0];
			pushLStack(&s,data);
			printf("ѹջ�ɹ�!\n");
			system("pause");
			break;

		case(4):
			c = popLStack(&s);
			if (c==0)
				printf("ջΪ��\n");
			else
				printf("��ջ�ɹ�����ջ�ڵ������Ϊ��%c\n",c);
			system("pause");
			break;
		case(5):
			if (traverseLSueue(&s) == false)
				printf("ջΪ��!\n");
			system("pause");
			break;

		case(6):
			if (LStackLength(&s) >= 0)
				printf("���г����ǣ�%d.\n", LStackLength(&s));
			else
			{
				printf("ջ����!!!\n");
				exit(0);
			}
			system("pause");
			break;

		case(7):
			clearLStack(&s);
			printf("ջ�Ѿ����\n");
			system("pause");
			break;

		case(8):
			calculate();
			system("pause");
			break;

		case(9):
			destroyLStack(&s);
			system("pause");
			return;
		}

	}
}