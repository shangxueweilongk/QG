#pragma once
#include"LinkQueue.h"

char type;

//ȷ����������
void get_type()
{
	while (1)
	{
		type = '\0';
		printf("��������Ҫ��������ݵ�����:\n");
		printf("����'i'��洢����, ����'f'��洢�����ͣ�����'c'��洢�ַ�\n");
		scanf("%c", &type);
		while (getchar() != '\n');
		if (type == 'i' || type == 'f' || type == 'c')
			break;
		else
		{
			printf("�����������������룡\n");
			system("pause");
			system("cls");
		}
	}
}


//��������
void get_int(void** data)
{
	int* p = (int*)malloc(sizeof(int));
	if (p == NULL)
	{
		printf("�ڴ����ʧ�ܣ����˳�����\n");
		exit(0);
	}
	char s[50];
	int flag = 1;
	while (1)
	{
		flag = 1;//����
		system("cls");
		printf("������һ��������:\n");
		gets(s);
		if (*s == '-')
		{
			if (strlen(s) < 7 && strlen(s) > 0)//���ϸ���
			{
				int i;
				for (i = 1; i < 7 && s[i] != '\0'; i++)
				{
					if (s[i] < '0' || s[i]>'9')
					{
						flag = 0;
						printf("����������������������\n");
						break;
					}
				}
				if (flag == 1)
				{
					*p = 0;
					for (i = 1; i < 7 && s[i] != '\0'; i++)
						*p = (*p) * 10 + s[i] - '0';
					(*p) *= -1;
					*data = (void*)p;
					return;
				}
			}
		}
		else if (strlen(s) < 6 && strlen(s) > 0)
		{
			int i;
			for (i = 0; i < 6 && s[i] != '\0'; i++)
			{
				if (s[i] < '0' || s[i]>'9')
				{
					flag = 0;
					printf("����������������������\n");
					break;
				}
			}
			if (flag == 1)
			{
				*p = 0;
				for (i = 0; i < 6 && s[i] != '\0'; i++)
					*p = (*p) * 10 + s[i] - '0';
				*data = (void*)p;
				return;
			}
		}
		printf("������һ������-10000.0��С��10000.0����;\n");
		system("pause");
	}
}

//����������
void get_float(void** data)
{
	float* p = (float*)malloc(sizeof(float));
	if (p == NULL)
	{
		printf("�ڴ����ʧ�ܣ����˳�����\n");
		exit(0);
	}
	*p = 0.0;
	char s[50];
	int flag = 1,times=0;//times��¼С�������
	while (1)
	{
		times = 0;
		flag = 1;//����
		system("cls");
		printf("������һ��������\n");
		gets(s);
		if (*s == '-')
		{
			if (strlen(s) < 7 && strlen(s) > 0)//���ϸ���
			{
				int i, j = 0;
				for (i = 1; i < 7 && s[i] != '\0'; i++)
				{
					if (s[i] == '.')//����С��������
					{
						times++;
						if (times > 1)
						{
							flag = 0;
							printf("����������������������!\n");
							break;
						}
					}
					if ((s[i] < '0' || s[i]>'9') && (s[i] != '.'))
					{
						flag = 0;
						printf("����������������������!\n");
						break;
					}
					if (s[i] == '.' && (i == 0 || i == strlen(s) - 1))//.123��213,�ȴ������
					{
						flag = 0;
						printf("����������������������!\n");
						break;
					}
					if (s[i] == '.' && s[i + 1] == '.')//1..23��2.13�ȴ������
					{
						flag = 0;
						printf("����������������������!\n");
						break;
					}

				}
				if (flag == 1)
				{
					*p = 0;
					for (i = 1; i < 7 && s[i] != '\0' && s[i] != '.'; i++)
						*p = (*p) * 10 + s[i] - '0';

					if (s[i] == '.')//����С����
					{
						i++;
						j = i;
					}

					for (; i < 7 && s[i] != '\0'; i++)
						*p = (*p) * 10 + s[i] - '0';

					if (j > 0)//ת����С��
					{
						for (; j < 7 && s[j] != '\0'; j++)
							*p = (*p) / 10;
					}

					(*p) *= -1;
					*data = (void*)p;
					return;
				}
			}
		}
		else if (strlen(s) < 6 && strlen(s) > 0)
		{
			int i, j = 0;
			for (i = 0; i < 6 && s[i] != '\0'; i++)
			{
				if (s[i] == '.')//����С��������
				{
					times++;
					if (times > 1)
					{
						flag = 0;
						printf("����������������������!\n");
						break;
					}
				}
				if ((s[i] < '0' || s[i]>'9') && (s[i] != '.'))
				{
					flag = 0;
					printf("����������������������!\n");
					break;
				}
				if (s[i] == '.' && (i == 0 || i == strlen(s) - 1))//.123��213,�ȴ������
				{
					flag = 0;
					printf("����������������������!\n");
					break;
				}
				if (s[i] == '.' && s[i + 1] == '.')//1..23��2.13�ȴ������
				{
					flag = 0;
					printf("����������������������!\n");
					break;
				}
			}
			if (flag == 1)
			{
				*p = 0;
				for (i = 0; i < 6 && s[i] != '\0' && s[i] != '.'; i++)
					*p = (*p) * 10 + s[i] - '0';

				if (s[i] == '.')//����С����
				{
					i++;
					j = i;
				}

				for (; i < 6 && s[i] != '\0'; i++)
					*p = (*p) * 10 + s[i] - '0';

				if (j > 0)
				{
					for (; j < 6 && s[j] != '\0'; j++)
					{
						*p = (*p) / 10;
					}
				}

				*data = (void*)p;
				return;
			}
		}
		printf("������һ������-10000.0С��10000.0��������λ��(��������λ��С��λ�Լ�С����)������5λ;\n");
		system("pause");
	}
}

//�ַ�����
void get_char(void** data)
{
	printf("������һ���ַ�(��֧�ֵ����ַ����룬�������ַ�����ֻ�Ե�һ���ַ����в���)\n");
	char* p = (char*)malloc(sizeof(char));
	if (p == NULL)
	{
		printf("�ڴ����ʧ�ܣ����˳�����\n");
		exit(0);
	}
	*p = 0;
	scanf("%c", p);
	while (getchar() != '\n');
	*data = (void*)(p);
}


//���ݴ���
void get_data(void** data)
{
	if (type == 'i')
		get_int(data);
	else if (type == 'f')
		get_float(data);
	else if (type == 'c')
		get_char(data);
}


//�˵�
void show()
{
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	void* add_data = NULL;
	int flag;
	char box[200] = { 0 };
	InitLQueue(Q);
	while (1)
	{
		while (1)
		{
			flag = 0;
			system("cls");
			printf("�����ʵ�����¹���\n");
			printf("1.�ж϶����Ƿ�Ϊ��\n");
			printf("2.��ȡ�׽ڵ������\n");
			printf("3.�룡�ӣ�\n");
			printf("4.�����ӣ�\n");
			printf("5.������������\n");
			printf("6.��ȡ���г���\n");
			printf("7.��ն���\n");
			printf("8.���ٶ��в��˳�\n");
			printf("����������ʵ����Ӧ����\n");
			scanf("%s", box);
			while (getchar() != '\n');
			if (strlen(box) != 1)
			{
				printf("��������ȷ������!");
				system("pause");
			}
			else if (box[0] < '1' || box[0]>'8')
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
			if (IsEmptyLQueue(Q))
				printf("����Ϊ��!\n");
			else
				printf("���в�Ϊ��.\n");
			system("pause");
			break;
		case(2):
			if (GetHeadLQueue(Q) != NULL)
			{
				printf("�׽ڵ������Ϊ��");
				LPrint(GetHeadLQueue(Q), type);
			}
			else
				printf("����Ϊ��!\n");
			system("pause");
			break;

		case(3):
			if (type == 'i')
				get_int(&add_data);
			else if (type == 'f')
				get_float(&add_data);
			else
				get_char(&add_data);

			EnLQueue(Q, add_data);
			printf("��ӳɹ�!\n");
			system("pause");
			break;

		case(4):
			if (DeLQueue(Q))
				printf("���ӳɹ�\n");
			else
				printf("����Ϊ��!\n");
			system("pause");
			break;
		case(5):
			if (TraverseLQueue(Q, type) == false)
				printf("����Ϊ��!\n");
			system("pause");
			break;

		case(6):
			if (LengthLQueue(Q) >= 0)
				printf("���г����ǣ�%d.\n", LengthLQueue(Q));
			else
			{
				printf("���г���!!!\n");
				exit(-1);
			}
			system("pause");
			break;

		case(7):
			ClearLQueue(Q);
			system("pause");
			break;

		case(8):
			DestoryLQueue(Q);
			free(Q);
			system("pause");
			return;
		}
	}
}


void show_2()
{
	get_type();
	show();
	return ;
}
