#define _CRT_SECURE_NO_WARNINGS 1
#include"bst_1.h"


int turn()//���ַ���תΪ����
{
	printf("��������Ӧ����������(1000���ڵ�������)\n");
	while (1)
	{
		int num = 0,flag=1;
		char str[1000] = { 0 };
		scanf("%s", str);
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] < '0' || str[i]>'9')
			{
				flag = 0;
				break;
			}
			num = num * 10 + str[i] - 48;
		}
		if (flag == 1 && num<=1000 && num>=0)
			return num;
		printf("�����ʽ��������������\n");
	}
}

int main()
{
	int flag,num;
	char box[200] = { 0 };
	bst* t = NULL;//�����������ĳ�ʼ��
	while (1)
	{
		while (1)
		{
			flag = 0;
			system("cls");
			printf("1.�����������Ĳ���\n");
			printf("2.������������ɾ��\n");
			printf("3.�����������Ĳ���\n");
			printf("4.������������ǰ�����\n");
			printf("5.�������������������\n");
			printf("6.�����������ĺ������\n");
			printf("7.�����������Ĳ������\n");
			printf("8.�˳�\n");
			printf("���������������Ӧ����\n");
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
			num = turn();
			bst_insert(&t, num);
			system("pause");
			break;
		case(2):
			num = turn();
			bst_delete(&t, num);
			system("pause");
			break;

		case(3):
			num = turn();
			bst_search(t, num);
			system("pause");
			break;

		case(4):
			printf("ǰ�����(�ݹ�)��\n");
			bst_pretraverse_1(t);
			printf("\n");
			printf("ǰ�����(�ǵݹ�)��\n");
			bst_pretraverse_2(t);
			system("pause");
			break;
		case(5):
			printf("�������(�ݹ�)��\n");
			bst_intraverse_1(t);
			printf("\n");
			printf("�������(�ǵݹ�)��\n");
			bst_intraverse_2(t);
			system("pause");
			break;

		case(6):
			printf("�������(�ݹ�)��\n");
			bst_posttraverse_1(t);
			printf("\n");
			printf("�������(�ǵݹ�)��\n");
			bst_posttraverse_2(t);
			system("pause");
			break;

		case(7):
			printf("���������\n");
			bst_leveltraverse(t);
			system("pause");
			break;

		case(8):
			return;
		}
	}
	return 0;
}