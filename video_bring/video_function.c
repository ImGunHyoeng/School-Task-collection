#define _CRT_SECURE_NO_WARNINGS//�������ſ�
#include <stdio.h>
#include<string.h>
#include<stdlib.h>//strtok�� ����ϱ� ���ؼ� ������
#include "video.h"

int usersearch(User* user,char *temp,int c)
{
	int jungbok = 0;
	User *userflash = user;
	int thing = c;
	while (userflash)
	{
		if (thing == 0)
		{
		
		if (strcmp(userflash->id, temp) == 0)
			jungbok++;
		userflash = userflash->link;
		}
		if (thing == 1)
		{
			if (strcmp(userflash->name, temp) == 0)
				jungbok++;
			userflash = userflash->link;
		}
	}
	return(jungbok);
}

void search(Video **video,User **user,Bring **bring)
{
	Video *videosearch = *video;
	User *usersearch = *user;
	Bring *bringsearch = *bring;
	int count = 0;
	int op;
	char temp[1024];
	
	for (;1;)
	{
		printf("���Ͻô� �˻������ �����ϼ���.\n1. �����˻�\n2. �����˻�\n3. �뿩���\n");//����ġ������ ���ؼ� �˻������ ��ȭ�ߴ�.
		scanf_s("%d", &op);
		while (getchar() != '\n');
		switch (op)
		{
		case 1:
			printf("�˻��ϰ����ϴ� ���������� �Է����ּ���.\n");
			scanf_s("%s", temp, 1024);
			while (videosearch)
			{
				if (strcmp(videosearch->videoname, temp) == 0)//������ ����� �Է��Ѱ��� ���Ѵ�
				{
					count++;
				}
				videosearch = videosearch->link;
			}
			videosearch = *video;//�տ��� videosearch�� ������ ���ȱ⿡ ó���� ���� �Է����־ �����Ѵ�.
			if (count == 0)
			{
				printf("ã���ô� ������ �������� �ʽ��ϴ�.\n\n");
				return;
			}
			if (count == 1)
			{
				while (videosearch)
				{
					if (strcmp(videosearch->videoname, temp) == 0)
					{
						printf("���� ����:%s\n", videosearch->videoname);
						printf("���� ����:%s\n", videosearch->year);
						printf("�˻��� �Ϸ�Ǿ����ϴ�.\n\n");
						return;
					}
					videosearch = videosearch->link;
				}
			}
			if (count >= 2)//�������� �ִ°�쿡�� �ٸ��Ӽ����� �Է¹޴´�.
			{
				printf("���������� ������ �ֽ��ϴ�.\n");
				printf("ã���ô� ������ ���ۿ����� �Է����ּ���\n");
				scanf_s("%s", temp, 1024);
				while (videosearch)
				{
					if (strcmp(videosearch->year, temp) == 0)
					{
						printf("���� ����:%s\n", videosearch->videoname);
						printf("���� ����:%s\n", videosearch->year);
						printf("�˻��� �Ϸ�Ǿ����ϴ�.\n\n");
						return;
					}
					videosearch = videosearch->link;
				}
			}
			return;

		case 2:
			printf("�˻��ϰ����ϴ� ������ �̸��� �Է����ּ���.\n");
			scanf_s("%s", temp, 1024);
			while (usersearch)
			{
				if (strcmp(usersearch->name, temp) == 0)
				{
					count++;
				}
				usersearch = usersearch->link;
			}
			usersearch = *user;
			if (count == 0)
			{
				printf("ã���ô� ������ �������� �ʽ��ϴ�.\n\n");
				return;
			}
			if (count == 1)
			{
				while (usersearch)
				{
					if (strcmp(usersearch->name, temp) == 0)
					{
						printf("������ �̸�:%s\n", usersearch->name);
						printf("������ ���̵�:%s\n", usersearch->id);
						printf("������ �ڵ�����ȣ:%s\n", usersearch->phonennum);
						printf("������ �ܾ�:%s\n", usersearch->money);
						printf("�˻��� �Ϸ�Ǿ����ϴ�.\n\n");
						return;
					}
					usersearch = usersearch->link;
				}
			}
			if (count >= 2)
			{
				printf("���������� �ֽ��ϴ�.\n");
				printf("ã���ô� ������ id�� �Է����ּ���\n");
				scanf_s("%s", temp, 1024);
				while (usersearch)
				{
					if (strcmp(usersearch->id, temp) == 0)
					{
						printf("������ �̸�:%s\n", usersearch->name);
						printf("������ ���̵�:%s\n", usersearch->id);
						printf("������ �ڵ�����ȣ:%s\n", usersearch->phonennum);
						printf("������ �ܾ�:%s\n", usersearch->money);
						printf("�˻��� �Ϸ�Ǿ����ϴ�.\n\n");
						return;
					}
					usersearch = usersearch->link;
				}
			}
			return;

		case 3:
			printf("�뿩������ �˰���� ������ �Է��ϼ���.\n");
			scanf_s("%s", temp, 1024);
			while (bringsearch)
			{
				if (strcmp(bringsearch->title->videoname, temp) == 0)//�˻��ϰ����ϴ� ������ ���� ���Ѵ�
				{
					count++;
				}
				bringsearch = bringsearch->link;
			}
			bringsearch = *bring;//�տ��� videosearch�� ������ ���ȱ⿡ ó���� ���� �Է����־ �����Ѵ�.
			if (count == 0)
			{
				printf("���� �뿩������ �ʽ��ϴ�.\n\n");
				return;
			}
			if (count == 1)
			{
				while (bringsearch)
				{
					if (strcmp(bringsearch->title->videoname, temp) == 0)
					{
						printf("���� ����:%s\n", bringsearch->title->videoname);
						printf("���� ����:%s\n", bringsearch->title->year);
						printf("���������:%s\n", bringsearch->name);
						printf("�˻��� �Ϸ�Ǿ����ϴ�.\n\n");
						return;
					}
					bringsearch= bringsearch->link;
				}
			}
			if (count >= 2)//�������� �ִ°�쿡�� �ٸ��Ӽ����� �Է¹޴´�.
			{
				printf("���������� ������ �ֽ��ϴ�.\n");
				printf("ã���ô� ������ ���ۿ����� �Է����ּ���\n");
				scanf_s("%s", temp, 1024);
				while (bringsearch)
				{
					if (strcmp(bringsearch->title->year, temp) == 0)
					{
						printf("���� ����:%s\n", bringsearch->title->videoname);
						printf("���� ����:%s\n", bringsearch->title->year);
						printf("���������:%s\n", bringsearch->name);
						printf("�˻��� �Ϸ�Ǿ����ϴ�.\n\n");
						return;
					}
					bringsearch = bringsearch->link;
				}
			}
			return;

		default:
			printf("�߸����Է��Դϴ�. �ٽ��Է����ּ���.\n");
			break;
		}
	}
}

void allprint(Video **videolist, User ** userlist, Bring **bringlist)
{
	Video *videoprint = *videolist;
	User *userprint = *userlist;
	Bring *bringprint = *bringlist;
	printf("---------------------�������------------------------\n");
	while (videoprint)
	{
		printf("���� ���� : %s\n", videoprint->videoname);
		printf("���� ���� : %s\n", videoprint->year);
		videoprint = videoprint->link;
	}
	printf("\n\n");
	printf("---------------------����ڸ��------------------------\n");
	while (userprint)
	{
		printf("������ �̸� : %s\n", userprint->name);
		printf("������ ���̵� : %s\n", userprint->id);
		printf("������ �ڵ��� ��ȣ : %s\n", userprint->phonennum);
		printf("������ �ܾ� : %s\n", userprint->money);
		userprint = userprint->link;
	}
	printf("\n\n");
	printf("---------------------�뿩ǰ���------------------------\n");
	while (bringprint)
	{
		printf("�뿩 �������� : %s\n", bringprint->title->videoname);
		printf("�뿩 �������� : %s\n", bringprint->title->year);
		printf("�뿩�� ����� �̸� : %s\n\n", bringprint->name);
		bringprint = bringprint->link;
	}
	printf("\n\n");
	printf("����� �Ϸ�Ǿ����ϴ�.\n\n");
}

void user_add(User ** user)
{

	char temp[1024];
	User *userflash = (User*)malloc(sizeof(User));//�ӽ÷� ������ ����� �޾��� ����ü ���� NULL�� ����ÿ� ����Ǳ⿡ �ʱ�ȭ ��������
	int str_len;
	printf("����� �̸��� �Է��ϼ���.\n");
	scanf_s("%s", temp, 1024);//������ ����
	str_len = strlen(temp) + 1;//������ ���̺��� �ϳ� �������Ѽ� �ΰ��� ����
	userflash->name = (char*)malloc(strlen(temp));//temp�� ���̸�ŭ ����ü ����� ������ �Ҵ����ش�.
	strcpy_s(userflash->name, str_len, temp);//������ ������ �����Ѵ�.

	printf("����� ���̵� �Է��ϼ���.(�ߺ��Ұ���)\n");
	for (; 1;)//���̵� �ߺ��Ǿ����� �˾Ƴ��� ���� �Լ��̴�
	{
		int jung = 0;
		scanf_s("%s", temp, 1024);
		jung=usersearch(*user,temp,0);//�ߺ��Ǿ����� �ߺ��� ���� ���Ϲ޾Ƽ� if������ ��Ƴ���. user����ü�� ���� id�Է°��� �־��ش�.
		if (jung == 1)
			printf("�ߺ��� ���̵��Դϴ�.�ٽ� �Է����ּ���.\n");
		else
			printf("��밡���� ���̵��Դϴ�.\n");
			break;
	}
	str_len = strlen(temp) + 1;
	userflash->id = (char*)malloc(strlen(temp));
	strcpy_s(userflash->id, str_len, temp);

	printf("��ȭ��ȣ�� �Է��ϼ���.\n");
	scanf_s("%s", temp, 1024);
	str_len = strlen(temp) + 1;
	userflash->phonennum = (char*)malloc(strlen(temp));
	strcpy_s(userflash->phonennum, str_len, temp);
	
	userflash->money = (char*)malloc(1024);
	userflash->money = "10000";

	if (*user == NULL)//ó���� ������ NULL������ �س��⿡ ó���̶�� ��츦 ���� if���̴�
	{
		*user = userflash;//������ �Է��� ���� �־��ش�
		(*user)->link = NULL;//�׸��� ��ũ�� NULL�� �ٲپ��ش�
	}
	else {
		userflash->link = *user;//�ι�° �̻� �� ���̱⿡ flash�� ��ũ�� ���� ����ü�� �����ϰ�
		*user = userflash;//ó����尪�� ����ģ��
	}
}

void video_add(Video **video)
{
	char temp[1024];
	Video *videoflash=(Video*)malloc(sizeof(Video));//�ӽ÷� ������ ����� �޾��� ����ü ���� NULL�� ����ÿ� ����Ǳ⿡ �ʱ�ȭ ��������
	int str_len;
	printf("�Է��Ͻ� ���������� �Է��ϼ���.\n");
	scanf_s("%s", temp, 1024);//������ ����
	str_len = strlen(temp) + 1;//������ ���̺��� �ϳ� �������Ѽ� �ΰ��� ����
	videoflash->videoname = (char*)malloc(strlen(temp));//temp�� ���̸�ŭ ����ü ����� ������ �Ҵ����ش�.
	strcpy_s(videoflash->videoname, str_len, temp);//������ ������ �����Ѵ�.

	printf("������ ���ۿ����� �Է��ϼ���.\n");
	scanf_s("%s", temp, 1024);
	str_len = strlen(temp) + 1;
	videoflash->year = (char*)malloc(strlen(temp));
	strcpy_s(videoflash->year, str_len, temp);
	
	if (*video == NULL)//ó���� ������ NULL������ �س��⿡ ó���̶�� ��츦 ���� if���̴�
	{
		*video = videoflash;//������ �Է��� ���� �־��ش�
		(*video)->link = NULL;//�׸��� ��ũ�� NULL�� �ٲپ��ش�
	}
	else {
		videoflash->link = *video;//�ι�° �̻� �� ���̱⿡ flash�� ��ũ�� ���� ����ü�� �����ϰ�
		*video = videoflash;//������ ���� videoflash�� �������ν� video�� �Ǿ� ��带 ����ġ�� �ȴ�.
	}

}

void return_vd(Video **video, User **user, Bring **bring)
{
	Bring *temp_bring = *bring;
	Video *temp_video = *video;
	User *temp_user = *user;
	Bring *pre = *bring;
	char temp[1024];
	int count = 0,count_link=0;
	printf("�ݳ��Ͻ� ���������� �Է����ּ���.\n");
	scanf_s("%s", temp, 1024);
	while (temp_bring)
	{
		if (strcmp(temp_bring->title->videoname, temp) == 0)
			count++;
		temp_bring = temp_bring->link;
	}
	temp_bring = *bring;
	if (count == 0)
	{
		printf("�ش��ϴ� ������ �뿩���� �ʾҽ��ϴ�.\n");
		return;
	}
	if (count == 1)
	{
		while (temp_bring)
		{
			if (strcmp(temp_bring->title->videoname, temp)==0)
			{
				temp_video = temp_bring->title;
				break;
			}
			count_link++;
			temp_bring = temp_bring->link;
		}
	}
	if (count >= 2)
	{
		while (temp_bring)
		{
			printf("������ ������ ������ �����մϴ�. ������ ���ۿ����� �Է����ּ���\n");
			scanf_s("%s", temp, 1024);
			if (strcmp(temp_bring->title->year, temp)==0)
			{
				temp_video = temp_bring->title;
				break;
			}
			count_link++;
			temp_bring = temp_bring->link;
		}
	}
	printf("%s���� %s������ �ݳ��Ǿ����ϴ�.!\n\n", temp_bring->name, temp_bring->title->videoname);
	

	for (int i = 0; i < count_link-1 ; i++)//��ũ�� �Ѹ�ŭ�� �Ѵܰ� ���� �������ν� ����带 ����Ų��.
		pre = pre->link;

	if (count_link  == 0)
		(*bring) = (*bring)->link;//ù��° ��带 �̵��ϴ� ���
	
	if (count_link != 0)//��ũ�� �ѹ��̶� ����Ǿ��ٸ� �̷��� ����
	{
		pre->link = pre->link->link;
		(*bring) = pre;
	}


	if (*video == NULL)
	{
		*video = temp_video;
		(*video)->link = NULL;
	}
	else
	{
		temp_video->link = *video;
		*video = temp_video;
	}

	
}

void video_trade(Video **video, User **user, Bring **bring)
{
	int count = 0, count_link = 0;//link�� ��� ����Ǿ����� ���� ���� �ο� ���������� ã������ int
	char temp[1024];
	char *tempmoney;
	Video *videosearch = *video;
	Video *pre = *video;//������� ��ġ�� ã������
	User *usersearch = *user;
	Bring *bringlist = (Bring*)malloc(sizeof(Bring));//bring�� �ʱ�ȭ�� ������ NULL���� ũ�⸦ �޾ƿ´�.
	printf("!!!!!!!!!�뿩�� �ʵ����� ::� ������ �뿩�� �ܾ׿��� 1000���� �����ȴ�.!!!!!!!!!\n\n");
	printf("�뿩�ϰ����ϴ� ������ �̸��� �Է��ϼ���.\n");

	scanf_s("%s", temp, 1024);
	while (videosearch)
	{
		if (strcmp(videosearch->videoname, temp) == 0)//������ ����� �Է��Ѱ��� ���Ѵ�
		{
			count++;
		}
		videosearch = videosearch->link;
	}
	videosearch = *video;//�տ��� videosearch�� ������ ���ȱ⿡ ó���� ���� �Է����־ �����Ѵ�.

	if (count == 0)
	{
		printf("ã���ô� ������ �������� �ʽ��ϴ�.\n\n");
		return;
	}
	if (count == 1)
	{

		while (videosearch)
		{
			if (strcmp(videosearch->videoname, temp) == 0)
			{
				bringlist->title = videosearch;
				break;
			}
			videosearch = videosearch->link;
			count_link++;//������� ��ũ�� ã�� ���� �۾�
		}
	}

	if (count >= 2)//�������� �ִ°�쿡�� �ٸ��Ӽ����� �Է¹޴´�.
	{

		printf("���������� ������ �ֽ��ϴ�.\n");
		printf("ã���ô� ������ ���ۿ����� �Է����ּ���\n");
		scanf_s("%s", temp, 1024);
		while (videosearch)
		{
			if (strcmp(videosearch->year, temp) == 0)
			{
				bringlist->title = videosearch;
				break;
			}
			videosearch = videosearch->link;
			count_link++;
		}
	}

	count = 0;//ī��Ʈ �ʱ�ȭ ��������ã��
	printf("�뿩�ϰ��� �ϴ� ����� �̸��� �Է����ּ���.\n");
	scanf_s("%s", temp, 1024);
	while (usersearch)
	{
		if (strcmp(usersearch->name, temp) == 0)
		{
			count++;
		}
		usersearch = usersearch->link;
	}
	usersearch = *user;
	if (count == 0)
	{
		printf("ã���ô� ������ �������� �ʽ��ϴ�.\n\n");
		return;
	}
	if (count == 1)
	{

		while (usersearch)
		{
			if (strcmp(usersearch->name, temp) == 0)
			{
				bringlist->name = usersearch->name;
				tempmoney=moneycheck(usersearch->money);
				if (tempmoney == "x")
					return;
				else
				{
					int count = 0;
					count = strlen(tempmoney)+1;
					usersearch->money = (char*)malloc(sizeof(count));//�����Ҵ��̱⿡ ũ�⸦ �ٽ� �������ش�
					strcpy_s(usersearch->money, count, tempmoney);//���ڿ��� �ٽ� �޾���
					printf("�뿩�� �Ϸ�Ǿ����ϴ�\n\n");
				}
				break;
			}
			usersearch = usersearch->link;

		}
	}
	if (count >= 2)
	{

		printf("���������� �ֽ��ϴ�.\n");
		printf("ã���ô� ������ id�� �Է����ּ���\n");
		scanf_s("%s", temp, 1024);
		while (usersearch)
		{
			if (strcmp(usersearch->id, temp) == 0)
			{
				bringlist->name = usersearch->name;
				tempmoney = moneycheck(usersearch->money);
				if (tempmoney == "x")
					return;
				else
				{
					int count = 0;
					count = strlen(tempmoney) + 1;
					usersearch->money = (char*)malloc(sizeof(count));//�����Ҵ��̱⿡ ũ�⸦ �ٽ� �������ش�
					strcpy_s(usersearch->money, count, tempmoney);//���ڿ��� �ٽ� �޾���
					printf("�뿩�� �Ϸ�Ǿ����ϴ�\n\n");
				}
				break;
			}
			usersearch = usersearch->link;


		}
	}

	for (int i = 0; i < count_link - 1; i++)
			pre = pre->link;

	if (count_link  == 0)//��ũ�� �ϳ��� �̵����� �ʾҴٸ�
			(*video) = (*video)->link;//ù��° ��带 �̵��ϴ� ���
	if (count_link != 0)//��ũ�� �ϳ��� �������ٸ�
	{
		pre->link = pre->link->link;
		(*video) = pre;
	}

	if (*bring == NULL)
	{
		*bring = bringlist;
		(*bring)->link = NULL;
		(*bring)->title->link = NULL;//������忡 ����� ���� ���ֱ� ����
	}
	else
	{
		bringlist->link = *bring;
		*bring = bringlist;
		(*bring)->title->link = NULL;
	}
	
}

void save(Video **video,User **user,Bring **bring)
{
	char f_n[1024];
	Video *vd_flesh = *video;//������ ����ü�� ���� �޾��� ����ü �����͸� �����Ѵ�.
	User *us_flesh = *user;
	Bring *br_flesh = *bring;
	FILE *fp = NULL;//������ �޾ƿ� ������ ����
	printf("������ �����̸��� �Է��ϼ���\n");
	scanf_s("%s", f_n, 1024);
	fp = fopen(f_n, "w");//������ ���ϴ� �̸����� ����� ������� ��
	while (vd_flesh)
	{
		fputs("V\n", fp);
		fputs(vd_flesh->videoname, fp);//�� ����ü�� �Ӽ��� �ȿ� �־��
		fputs(" ", fp);//��ĭ�� ���ؼ� ���� �����ϱ� ���� ���۾�
		fputs(vd_flesh->year, fp);
		fputs(" \n", fp);//fgets�� ����ϸ� ������ ������ �ڵ����� ��ĭ �پ����⿡ ������ ���߱����ؼ� ��ĭ �ٰ� ��ĭ�� ������ �۵��ȵǰ� �߱⿡ �̷��� ��
		vd_flesh = vd_flesh->link;
	}
	while (us_flesh)
	{
		fputs("U\n", fp);
		fputs(us_flesh->name, fp);//�� ����ü�� �Ӽ��� �ȿ� �־��
		fputs(" ", fp);//��ĭ�� ���ؼ� ���� �����ϱ� ���� ���۾�
		fputs(us_flesh->id, fp);
		fputs(" ", fp);
		fputs(us_flesh->phonennum, fp);
		fputs(" ", fp);
		fputs(us_flesh->money, fp);
		fputs(" \n", fp);
		us_flesh = us_flesh->link;
	}
	while (br_flesh)
	{
		fputs("B\n", fp);
		fputs(br_flesh->name, fp);//�� ����ü�� �Ӽ��� �ȿ� �־��
		fputs(" ", fp);//��ĭ�� ���ؼ� ���� �����ϱ� ���� ���۾�
		fputs(br_flesh->title->videoname, fp);
		fputs(" ", fp);//��ĭ�� ���ؼ� ���� �����ϱ� ���� ���۾�
		fputs(br_flesh->title->year, fp);
		fputs(" ", fp);//��ĭ�� ���ؼ� ���� �����ϱ� ���� ���۾�
		fputs(" \n", fp);
		br_flesh = br_flesh->link;
	}
	fclose(fp);//���Ͽ������� �ݱ�
	printf("����Ǿ����ϴ�.\n\n");
}

char* moneycheck(char *money)//�����Ҵ��� �ϸ��� �޸𸮻� �����ϱ� ������ ���� �����ֱ⿡ �Լ����� ���������� ���� �����Ҽ� �ֱ⿡ char*�� �ؼ� �����Ҵ��� ��ȯ�Ѵٴ� ������ ����ߵ�
{
	char *tradefee = (char*)malloc(7);
	tradefee = "1000\n";
	int diffrent = 0;
	int str_len,str_len1;//���� �󸶳� ���̸� ���� �뵵
	int tradefee_i = 0;
	char temp_money[1024] = { "\n", };
	char temp[1024] = { "\n" }, zero = 0;//���� ���� ���� ����ϰ� �������ٰ�
	
	for(int i=0;money[i];i++)//char�� ���� �����ͷ� �����鼭 strlen�� temp�迭�ν� �����ؼ� �ֱ����ؼ� �ӽ������� �迭�� ũ�⸦ �̿���
	temp_money[i] = money[i];
	str_len=strlen(temp_money)+1;//NULL���� �ޱ� ����
	str_len1 = strlen(tradefee);
	diffrent = str_len - str_len1;
	if (diffrent == 0)
	{
		for (int i = 0; temp_money[i+1]; i++)
		{
			temp[i] = temp_money[i] - tradefee[i];
			if ((int)temp[0] < 0)
			{
				printf("�ܾ׺����Դϴ�.\n");
				return "x";
			}
			else
				temp[i] = temp[i] + 48;	
		}
		tradefee = temp;
		return tradefee;
	}
	else
	{
		if (str_len1 > str_len)
		{
			printf("�ܾ׺����Դϴ�.\n");
			return "x";
		}
		else
		for (int i = diffrent; i < str_len; i++)//���̸�ŭ ���� �ڸ������� �����ؼ� ������
		{
			temp[i] = temp_money[i] - tradefee[tradefee_i];
			if (temp[i] <= -1)//�����׳��� ����ϴٰ� ���� -1���ϰ� ���ð�쿡 ������ �Ǹ� ������ ������Ű�����ؼ� �Ʒ� ���ǵ��� ������
			{
				/*if (diffrent == 0)//���� �ڸ��� ���̰� �ȳ��µ� ������ ���ð�쿡 �����Ѵ�.
				{
					printf("�ܾ׺����Դϴ�.\n");
					return "x";
				}*/
				for (int j = diffrent -i+1; j > 0; j--)//�ΰ����� ���̰� ��� 1�̻�
				{
					if ((temp_money[j-i] - 49) < 0)//������ i-j���� ���� -1�� ������ �װ��� 0������������ �������� i-j�� ���̰��� �Ȱ��������� �ΰ��� ������ ��������� ����
					{
						printf("�ܾ׺������� �뿩�� �Ұ����մϴ�.\n");//�ܾ׺����ÿ� �뿩�Ұ� ���
						return "x";
					}
					else
					{
						temp_money[j-i] = (temp_money[j-i] - 49) + 48;//i-j���� ���� -1�� �Ѱ��� �������ش�
						temp_money[i] = (10 + (int)temp[i]) + 48;//������ ���� �ϳ� �������⿡ 10���� ���� �ݾ׸�ŭ ����ϰ� �ٽ� ������ ũ��� �����ش�.
					}
				}
			}
			//temp[i]=
			tradefee_i++;
		}

		if (temp_money[0] == 48)//ù��° ���� 0�ΰ�쿡�� �ι�° ���� ������ temp�� �ְ� �ƴϸ� �״�� �� �־��ش�.
			for (int i = 1; temp_money[i]; i++)
			{
				temp[i - 1] = temp_money[i];
			}
		else
			for (int i = 0; temp_money[i]; i++)
			{
				temp[i] = temp_money[i];
			}
		tradefee = temp;
		return tradefee;//�����Ҵ�� ������ �ּڰ��� �����⿡ �������� �ʰ� �����Ҽ� �ִ�
	}
	
}

int load(Video **video, User **user, Bring **bring)
{
	char f_n[1024];
	int vd_count = 0, user_count = 0;
	Video *vd_flesh = (Video*)malloc(sizeof(Video));//������ ����ü�� ���� �޾��� ����ü �����͸� �����Ѵ�.
	User *us_flesh = (User*)malloc(sizeof(User));
	Bring *br_flesh = (Bring*)malloc(sizeof(Bring));
	vd_flesh->link = NULL;//�տ� headó�� NULL���� ���������� �����س���
	us_flesh->link = NULL;
	br_flesh->link = NULL;
	
	FILE *fp = NULL;//������ �޾ƿ� ������ ����
	char *ptr;//���� ����������� ©�� �ޱ����ؼ� ���
	char line[1024];//���ٴ� �ҷ���������
	int str_len = 0;
	printf("�ҷ��� �����̸��� �Է��ϼ���\n");
	scanf_s("%s", f_n, 1024);
	
	fp = fopen(f_n, "r");//������ ���ϴ� �̸����� ����� ������� ��
	if (fp == NULL)//�����̸��� ���ٸ� ���
	{
		printf("�Է��Ͻ� ������ ã���� �����ϴ�.\n");
		return 0;
	}
	else
	{
		while (fgets(line, 1024, fp) != NULL)//����Ұ��� �����ִٸ��� line�����ϰ� 1024������ ������������ �ּҸ� �����´�
		{
			if (strcmp(line,"V\n")==0)//������ �������� �������� ������ ���ؼ� �����Ҷ� �Ǿ����� �ٸ��� �س���
			{
				fgets(line, 1024, fp);
				
				ptr = strtok(line, " ");//������ ���ؼ� ĭ�� ������ 

				str_len = strlen(ptr) + 1;//�����Ҵ翡 NULLũ�⸦ �߰������ν� ���� �������� �˰��ϱ����ؼ� �ϳ� �߰�
				vd_flesh->videoname = (char*)malloc(strlen(ptr));//�����Ҵ��̱⿡ �ٽ� ũ�⸦ �����Ѵ�.
				strcpy_s(vd_flesh->videoname, str_len, ptr);
				ptr = strtok(NULL, " ");//�����ϰ����� ��ĭ�� \n����� �ϱ⿡ NULL���������� �ٽ� " "���� ������ �ش޶�� ������ ���δ�.


				str_len = strlen(ptr) + 1;
				vd_flesh->year = (char*)malloc(strlen(ptr));
				strcpy_s(vd_flesh->year, str_len, ptr);
				vd_fresh(&vd_flesh);//��ũ ������ ����
				vd_count++;
			}

			if (strcmp(line, "U\n") == 0)
			{
				fgets(line, 1024, fp);

				ptr = strtok(line, " ");//������ ���ؼ� ĭ�� ������ 

				str_len = strlen(ptr) + 1;//�����Ҵ翡 NULLũ�⸦ �߰������ν� ���� �������� �˰��ϱ����ؼ� �ϳ� �߰�
				us_flesh->name = (char*)malloc(strlen(ptr));//�����Ҵ��̱⿡ �ٽ� ũ�⸦ �����Ѵ�.
				strcpy_s(us_flesh->name, str_len, ptr);
				ptr = strtok(NULL, " ");//�����ϰ����� ��ĭ�� \n����� �ϱ⿡ NULL���������� �ٽ� " "���� ������ �ش޶�� ������ ���δ�.


				str_len = strlen(ptr) + 1;
				us_flesh->id = (char*)malloc(strlen(ptr));
				strcpy_s(us_flesh->id, str_len, ptr);
				ptr = strtok(NULL, " ");

				str_len = strlen(ptr) + 1;
				us_flesh->phonennum = (char*)malloc(strlen(ptr));
				strcpy_s(us_flesh->phonennum, str_len, ptr);
				ptr = strtok(NULL, " ");

				str_len = strlen(ptr) + 1;
				us_flesh->money = (char*)malloc(strlen(ptr));
				strcpy_s(us_flesh->money, str_len, ptr);
				us_fresh(&us_flesh);//��ũ ������ ����
				user_count++;
				
			}

			if (strcmp(line, "B\n") == 0)
			{
				fgets(line, 1024, fp);

				ptr = strtok(line, " ");//������ ���ؼ� ĭ�� ������ 

				str_len = strlen(ptr) + 1;//�����Ҵ翡 NULLũ�⸦ �߰������ν� ���� �������� �˰��ϱ����ؼ� �ϳ� �߰�
				br_flesh->name = (char*)malloc(strlen(ptr));//�����Ҵ��̱⿡ �ٽ� ũ�⸦ �����Ѵ�.
				strcpy_s(br_flesh->name, str_len, ptr);
				ptr = strtok(NULL, " ");//�����ϰ����� ��ĭ�� \n����� �ϱ⿡ NULL���������� �ٽ� " "���� ������ �ش޶�� ������ ���δ�.

				br_flesh->title = (Video*)malloc(sizeof(Video));
				br_flesh->title->link = NULL;
				str_len = strlen(ptr) + 1;
				br_flesh->title->videoname = (char*)malloc(strlen(ptr));
				strcpy_s(br_flesh->title->videoname, str_len, ptr);
				ptr = strtok(NULL, " ");

				str_len = strlen(ptr) + 1;//�����Ҵ翡 NULLũ�⸦ �߰������ν� ���� �������� �˰��ϱ����ؼ� �ϳ� �߰�
				br_flesh->title->year = (char*)malloc(strlen(ptr));//�����Ҵ��̱⿡ �ٽ� ũ�⸦ �����Ѵ�.
				strcpy_s(br_flesh->title->year, str_len, ptr);
				br_fresh(&br_flesh);//��ũ ������ ����
				
			}
		}
	}
	fclose(fp);//���Ͽ������� �ݱ�
	(*video) = vd_flesh->link;//�տ� �̻��� ����� ���� ���ֱ� ���� ���Ŀ� ����
	(*user) = us_flesh->link;
	(*bring) = br_flesh->link;
	printf("�ҷ����⸦ �Ϸ��߽��ϴ�.\n");
	if (user_count>=1&&vd_count >= 1)
		return 1;
	if (user_count >= 1)
		return 2;
	if ( vd_count >= 1)
		return 3;
	else return 0;
}
void vd_fresh(Video **video)
{

	Video *temp = (Video*)malloc(sizeof(Video));//�ӽ÷� ��带 �ϳ� �����.->���Ŀ� �����ִ� ��尪�� �����Ѵ�.->�׸��� �ӽó���� ���� �������� ������ �ϸ鼭 �տ� �̻��� ���� �������� ����ǵ����Ѵ�.
	temp->link = *video;
	*video = temp;//�̷��� �ϸ��� �տ��� ��ũ �����ϰ� �ڿ����� ���� ��������

}

void us_fresh(User ** user)
{

	User *temp = (User*)malloc(sizeof(User));//�ӽ÷� ��带 �ϳ� �����.->���Ŀ� �����ִ� ��尪�� �����Ѵ�.->�׸��� �ӽó���� ���� �������� ������ �ϸ鼭 �տ� �̻��� ���� �������� ����ǵ����Ѵ�.
	temp->link = *user;
	*user = temp;//�̷��� �ϸ��� �տ��� ��ũ �����ϰ� �ڿ����� ���� ��������

}

void br_fresh(Bring ** bring)
{

	Bring *temp = (Bring*)malloc(sizeof(Bring));//�ӽ÷� ��带 �ϳ� �����.->���Ŀ� �����ִ� ��尪�� �����Ѵ�.->�׸��� �ӽó���� ���� �������� ������ �ϸ鼭 �տ� �̻��� ���� �������� ����ǵ����Ѵ�.
	temp->link = *bring;
	*bring = temp;//�̷��� �ϸ��� �տ��� ��ũ �����ϰ� �ڿ����� ���� ��������

}

void moneyplus(User ** user)
{
	User *temp_user = *user;
	char temp[1024] = { "\n," }, money_yang[1024];
	int jungbok = 0;
	char user_sr[1024];
	char tempflesh[1024] = { "\n," }, upcount[2] = { "0," };
	int count = 0;//�������� ����ü�� �����Ҵ��� ����
	int str_len1, str_len2, different = 0;//�ݾ��� �������� �˾ƺ��� ����
	printf("������ �� ������ �̸��� �Է��ϼ���.\n");
	scanf_s("%s", user_sr, 1024);
	jungbok = usersearch(*user, user_sr, 1);

	if (jungbok == 0)
	{
		printf("ã���ô� ������ �������� �ʽ��ϴ�.\n");
		return;
	}

	if (jungbok == 1)
	{
		while (temp_user)
		{
			if (strcmp(temp_user, user_sr) == 0)
			{
				break;
			}
			temp_user = temp_user->link;
			count++;//��ũ����Ƚ�� Ȯ�ο뵵
		}
	}

	if (jungbok >= 2)
	{
		printf("���������� �����մϴ�. id�� �Է����ּ���.\n");
		scanf_s("%s", user_sr, 1024);
		while (temp_user)
		{
			if (strcmp(temp_user, user_sr) == 0)
			{
				break;
			}
			temp_user = temp_user->link;
			count++;//��ũ�� ��� ����Ǿ����� �Ǵ��ϱ� ����
		}
	}
	temp_user = *user;//������ ��ũ�ؼ� NULL�� ��ȯ�Ǿ��⿡ �ٽ� ����
	printf("������ �ݾ��� �Է��ϼ���.\n(���� �ܾ� �ִ�ġ 99999)\n");
	scanf_s("%s", money_yang, 1024);

	for (int i = 0; money_yang[i]; i++)
	{
		temp[i] = money_yang[i];
	}
	str_len1 = strlen(temp_user->money);//NULL���� ���� ����
	str_len2 = strlen(temp);
	if (str_len2 >= 6)
	{
		printf("�ʰ������Դϴ�.\n");
		return;
	}
	different = str_len1 - str_len2;//str_len1���� NULL�� �� �ְ� str_len2���� NULL���� �ȵ� �ֱ⿡ �̷��� ��
	if (different == 0)
	{
		for (int i = str_len2 - 1; i >= 0; i--)
		{
			if (i == 0)
			{
				if (((int)tempflesh[i + 1] - 48) / 10 != 0)
				{
					upcount[0] = ((int)tempflesh[i + 1] - 48) / 10 + 48;
					tempflesh[i] = upcount[0];
					tempflesh[i + 1] = 48;
				}

				break;
			}
			tempflesh[i + 1] = temp_user->money[i] + temp[i] - 96 + upcount[0];//���ڸ��� ���
			


			upcount[0] = (((int)tempflesh[i + different + 1] - 48) / 10) + 48;//10���� ������ 10������ ���� ������ 0�� �����⿡ �ö󰡴��� �Ǻ�����

			tempflesh[i + 1] = (((int)tempflesh[i + different + 1] - 48) % 10) + 48;//������ ���� 10���� ������ ������ �������� ���ϴ� �����ν� ���� �ڸ����� ������ �˼��ִ�
		}
	}
	else
	{
		if (str_len1 > str_len2)//money�� ���� ������ �ݾ׺��� ū ���
		{
			for (int i = str_len2 - 1; i >= -1; i--)
			{
				if (i == -1)
				{
					for (int j = different - 1; j >= 0; j--)
					{
						if (j == different - 1)

							tempflesh[j + 1] = temp_user->money[j] + upcount[0] - 48;
						if (((int)tempflesh[j + 1] - 48) / 10 != 0)
						{
							upcount[0] = ((int)tempflesh[j + 1] - 48) / 10 + 48;
							tempflesh[j] = upcount[0];
						}
						//else
							//tempflesh[j + 1] = temp_user->money[j];

					}
					break;
				}
				tempflesh[i + different + 1] = temp_user->money[i + different] + temp[i] - 96 + upcount[0];//���ڸ��� ���

				
				upcount[0] = (((int)tempflesh[i + different + 1] - 48) / 10) + 48;//�迭���� ���� ���� int�̱⿡ 48�� ���༭ ������ ���� ������ ��ȯ��Ų�Ŀ� int�� ���� ������ 48�� ���ڸ� ���ؼ� �� ���ڸ�ŭ�� �÷��ش�.

				tempflesh[i + different + 1] = (((int)tempflesh[i + different + 1] - 48) % 10) + 48;

			}

		}
		if (str_len1 < str_len2)//money�� ���� ������ �ݾ׺��� ���� ���
		{
			different = -different;//�����϶� �ٽ� ����� ����� ����
			for (int i = str_len1 - 1; i >= -1; i--)
			{
				if (i == -1)
				{
					for (int j = different - 1; j >= 0; j--)
					{
						if (j == different - 1)

							tempflesh[j + 1] = temp[j] + upcount[0] - 48;
						if (((int)tempflesh[j + 1] - 48) / 10 != 0)
						{
							upcount[0] = ((int)tempflesh[j + 1] - 48) / 10 + 48;
							tempflesh[j] = upcount[0];
						}
						//else
							//tempflesh[j + 1] = temp_user->money[j];

					}
					break;
				}
				tempflesh[i + different + 1] = temp_user->money[i] + temp[i + different] - 96 + upcount[0];//���ڸ��� ���


				upcount[0] = (((int)tempflesh[i + different + 1] - 48) / 10) + 48;//10���� ������ 10������ ���� ������ 0�� �����⿡ �ö󰡴��� �Ǻ�����

				tempflesh[i + different + 1] = (((int)tempflesh[i + different + 1]-48) % 10) + 48;
			}
		}
	}
	if (tempflesh[0] == 10)
	{
		for (int i = 1; tempflesh[i]; i++)
		{
			temp[i - 1] = tempflesh[i];
		}
	}

	else//ù��° �׿� ���� ���� ��쿡�� 
	{
		printf("�ʰ������Դϴ�.\n");
		return;
	}

	str_len1 = strlen(temp) + 1;

	temp_user->money = (char*)malloc(sizeof(str_len1));//NULL���� �ޱ� ����
	strcpy_s(temp_user->money, str_len1, temp);//���ڿ� �Է��Լ����

}
