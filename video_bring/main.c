#include <stdio.h>
#include "video.h"


void main()
{
	Video *videolist = NULL;//������ ����� ���� ���
	User *userlist = NULL;//������ ����� ���� ���
	Bring *bringlist = NULL;//������ ������ �޾Ƶ� ���
	int op;
	int count_vd = 0, count_user = 0;

	printf("���� �뿩���α׷��Դϴ�. ���Ͻô� ����� �Է��ϼ���.\n\n");
	for (; 1;) 
	{
		printf("1.�˻�\n2.�뿩\n3.�ݳ�\n4.���\n5.������ �߰�\n6.���� �߰�\n7.����\n8.�ҷ�����\n9.�ܾ��߰�\n0.����\n");
		scanf_s("%d", &op);
		while (getchar() != '\n');//���ڵ� ������ �ִ� ������ scanf�� �Է°�+\n�� ���� ���� �Ǵµ� getchar�� \n�� ���ۿ��� ���������ν� �ٽ� scanf�� ����Ҷ� ��ĭ���ν� ����Ҽ��ְ� ���༭ ���ѷ����� �����ʰ� ���������� �۵��ϰ� �ȴ�.
			switch (op)
			{

			case 0:
				printf("���α׷��� �����մϴ�");
				return;

			case 1:
				search(&videolist, &userlist, &bringlist);
				break;

			case 2:
				if (count_vd >= 1 && count_user >= 1)
					video_trade(&videolist, &userlist, &bringlist);
				else
					printf("�뿩�Ҽ� �ִ� ������ ������ �����ϴ�.\n\n");
				break;

			case 3:
				if (bringlist)
					return_vd(&videolist, &userlist, &bringlist);
				else
					printf("�뿩�� ������ �����ϴ�.\n\n");
				break;

			case 4:
				allprint(&videolist, &userlist, &bringlist);
				break;

			case 5:
				user_add(&userlist);
				printf("����� ����� �Ϸ�Ǿ����ϴ�.\n\n");
				count_user++;
				break;

			case 6:
				video_add(&videolist);
				printf("���� ����� �Ϸ�Ǿ����ϴ�.\n\n");
				count_vd++;
				break;

			case 7:
				save(&videolist, &userlist, &bringlist);
				break;

			case 8:
				op=load(&videolist, &userlist, &bringlist);//������ ���� �������� 1�� �̻����� üũ�ϱ� ���� ���ϰ�
				if (op == 1)
				{
					count_vd++;
					count_user++;
				}
				if (op == 2)
					count_user++;

				if (op == 3)
					count_vd++;
					
				break;

			case 9:
				if(count_user!=0)
				moneyplus(&userlist);
				else
				printf("���� ����ڸ� �߰����ּ���\n");
				break;
			
			

			default:
				printf("�߸��� ���Դϴ� �ٽ� �Է����ּ���\n");
				continue;
		}
	}
}
