#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkStack_show.h"
#include"LinkQueue_show.h"

int main()
{
	char box[200] = { 0 };
	int flag;
	while (1)
	{
		while (1)
		{
			flag = 0;
			system("cls");
			printf("�����ʵ�����¹���\n");
			printf("1.��ջ���в���\n");
			printf("2.�Զ��н��в���\n");
			printf("3.�˳�����\n");
			printf("����������ʵ����Ӧ����\n");
			scanf("%s", box);
			while (getchar() != '\n');
			if (strlen(box) != 1)
			{
				printf("��������ȷ������!");
				system("pause");
			}
			else if (box[0] < '1' || box[0]>'3')
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
			show_1();
			break;
		case(2):
			show_2();
			break;
		case(3):
			return;

		}
	}
	return 0;
}