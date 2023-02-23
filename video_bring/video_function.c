#define _CRT_SECURE_NO_WARNINGS//오류제거용
#include <stdio.h>
#include<string.h>
#include<stdlib.h>//strtok를 사용하기 위해서 가져옴
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
		printf("원하시는 검색기능을 선택하세요.\n1. 비디오검색\n2. 유저검색\n3. 대여목록\n");//스위치문으로 통해서 검색기능을 분화했다.
		scanf_s("%d", &op);
		while (getchar() != '\n');
		switch (op)
		{
		case 1:
			printf("검색하고자하는 비디오제목을 입력해주세요.\n");
			scanf_s("%s", temp, 1024);
			while (videosearch)
			{
				if (strcmp(videosearch->videoname, temp) == 0)//비디오의 제목과 입력한값을 비교한다
				{
					count++;
				}
				videosearch = videosearch->link;
			}
			videosearch = *video;//앞에서 videosearch를 끝까지 돌렸기에 처음에 값을 입력해주어서 재사용한다.
			if (count == 0)
			{
				printf("찾으시는 정보가 존재하지 않습니다.\n\n");
				return;
			}
			if (count == 1)
			{
				while (videosearch)
				{
					if (strcmp(videosearch->videoname, temp) == 0)
					{
						printf("비디오 제목:%s\n", videosearch->videoname);
						printf("비디오 연도:%s\n", videosearch->year);
						printf("검색이 완료되었습니다.\n\n");
						return;
					}
					videosearch = videosearch->link;
				}
			}
			if (count >= 2)//같은값이 있는경우에는 다른속성값을 입력받는다.
			{
				printf("같은제목의 비디오가 있습니다.\n");
				printf("찾으시는 비디오의 제작연도를 입력해주세요\n");
				scanf_s("%s", temp, 1024);
				while (videosearch)
				{
					if (strcmp(videosearch->year, temp) == 0)
					{
						printf("비디오 제목:%s\n", videosearch->videoname);
						printf("비디오 연도:%s\n", videosearch->year);
						printf("검색이 완료되었습니다.\n\n");
						return;
					}
					videosearch = videosearch->link;
				}
			}
			return;

		case 2:
			printf("검색하고자하는 유저의 이름을 입력해주세요.\n");
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
				printf("찾으시는 정보가 존재하지 않습니다.\n\n");
				return;
			}
			if (count == 1)
			{
				while (usersearch)
				{
					if (strcmp(usersearch->name, temp) == 0)
					{
						printf("유저의 이름:%s\n", usersearch->name);
						printf("유저의 아이디:%s\n", usersearch->id);
						printf("유저의 핸드폰번호:%s\n", usersearch->phonennum);
						printf("유저의 잔액:%s\n", usersearch->money);
						printf("검색이 완료되었습니다.\n\n");
						return;
					}
					usersearch = usersearch->link;
				}
			}
			if (count >= 2)
			{
				printf("동명이인이 있습니다.\n");
				printf("찾으시는 유저의 id를 입력해주세요\n");
				scanf_s("%s", temp, 1024);
				while (usersearch)
				{
					if (strcmp(usersearch->id, temp) == 0)
					{
						printf("유저의 이름:%s\n", usersearch->name);
						printf("유저의 아이디:%s\n", usersearch->id);
						printf("유저의 핸드폰번호:%s\n", usersearch->phonennum);
						printf("유저의 잔액:%s\n", usersearch->money);
						printf("검색이 완료되었습니다.\n\n");
						return;
					}
					usersearch = usersearch->link;
				}
			}
			return;

		case 3:
			printf("대여중인지 알고싶은 비디오를 입력하세요.\n");
			scanf_s("%s", temp, 1024);
			while (bringsearch)
			{
				if (strcmp(bringsearch->title->videoname, temp) == 0)//검색하고자하는 비디오의 값을 비교한다
				{
					count++;
				}
				bringsearch = bringsearch->link;
			}
			bringsearch = *bring;//앞에서 videosearch를 끝까지 돌렸기에 처음에 값을 입력해주어서 재사용한다.
			if (count == 0)
			{
				printf("현재 대여중이지 않습니다.\n\n");
				return;
			}
			if (count == 1)
			{
				while (bringsearch)
				{
					if (strcmp(bringsearch->title->videoname, temp) == 0)
					{
						printf("비디오 제목:%s\n", bringsearch->title->videoname);
						printf("비디오 연도:%s\n", bringsearch->title->year);
						printf("빌려간사람:%s\n", bringsearch->name);
						printf("검색이 완료되었습니다.\n\n");
						return;
					}
					bringsearch= bringsearch->link;
				}
			}
			if (count >= 2)//같은값이 있는경우에는 다른속성값을 입력받는다.
			{
				printf("같은제목의 비디오가 있습니다.\n");
				printf("찾으시는 비디오의 제작연도를 입력해주세요\n");
				scanf_s("%s", temp, 1024);
				while (bringsearch)
				{
					if (strcmp(bringsearch->title->year, temp) == 0)
					{
						printf("비디오 제목:%s\n", bringsearch->title->videoname);
						printf("비디오 연도:%s\n", bringsearch->title->year);
						printf("빌려간사람:%s\n", bringsearch->name);
						printf("검색이 완료되었습니다.\n\n");
						return;
					}
					bringsearch = bringsearch->link;
				}
			}
			return;

		default:
			printf("잘못된입력입니다. 다시입력해주세요.\n");
			break;
		}
	}
}

void allprint(Video **videolist, User ** userlist, Bring **bringlist)
{
	Video *videoprint = *videolist;
	User *userprint = *userlist;
	Bring *bringprint = *bringlist;
	printf("---------------------비디오목록------------------------\n");
	while (videoprint)
	{
		printf("비디오 제목 : %s\n", videoprint->videoname);
		printf("비디오 연도 : %s\n", videoprint->year);
		videoprint = videoprint->link;
	}
	printf("\n\n");
	printf("---------------------사용자목록------------------------\n");
	while (userprint)
	{
		printf("유저의 이름 : %s\n", userprint->name);
		printf("유저의 아이디 : %s\n", userprint->id);
		printf("유저의 핸드폰 번호 : %s\n", userprint->phonennum);
		printf("유저의 잔액 : %s\n", userprint->money);
		userprint = userprint->link;
	}
	printf("\n\n");
	printf("---------------------대여품목록------------------------\n");
	while (bringprint)
	{
		printf("대여 비디오제목 : %s\n", bringprint->title->videoname);
		printf("대여 비디오연도 : %s\n", bringprint->title->year);
		printf("대여한 사람의 이름 : %s\n\n", bringprint->name);
		bringprint = bringprint->link;
	}
	printf("\n\n");
	printf("출력이 완료되었습니다.\n\n");
}

void user_add(User ** user)
{

	char temp[1024];
	User *userflash = (User*)malloc(sizeof(User));//임시로 유저의 목록을 받아줄 구조체 선언 NULL로 선언시에 종료되기에 초기화 선언해줌
	int str_len;
	printf("사용자 이름을 입력하세요.\n");
	scanf_s("%s", temp, 1024);//제목을 받음
	str_len = strlen(temp) + 1;//제목의 길이보다 하나 증가시켜서 널값을 받음
	userflash->name = (char*)malloc(strlen(temp));//temp의 길이만큼 구조체 멤버에 공간을 할당해준다.
	strcpy_s(userflash->name, str_len, temp);//문장의 구조를 복사한다.

	printf("사용자 아이디를 입력하세요.(중복불가능)\n");
	for (; 1;)//아이디를 중복되었는지 알아내기 위한 함수이다
	{
		int jung = 0;
		scanf_s("%s", temp, 1024);
		jung=usersearch(*user,temp,0);//중복되었으면 중복된 값을 리턴받아서 if문으로 잡아낸다. user구조체의 값과 id입력값을 넣어준다.
		if (jung == 1)
			printf("중복된 아이디입니다.다시 입력해주세요.\n");
		else
			printf("사용가능한 아이디입니다.\n");
			break;
	}
	str_len = strlen(temp) + 1;
	userflash->id = (char*)malloc(strlen(temp));
	strcpy_s(userflash->id, str_len, temp);

	printf("전화번호를 입력하세요.\n");
	scanf_s("%s", temp, 1024);
	str_len = strlen(temp) + 1;
	userflash->phonennum = (char*)malloc(strlen(temp));
	strcpy_s(userflash->phonennum, str_len, temp);
	
	userflash->money = (char*)malloc(1024);
	userflash->money = "10000";

	if (*user == NULL)//처음에 유저를 NULL값으로 해놨기에 처음이라는 경우를 받은 if문이다
	{
		*user = userflash;//위에서 입력한 값을 넣어준다
		(*user)->link = NULL;//그리고 링크를 NULL로 바꾸어준다
	}
	else {
		userflash->link = *user;//두번째 이상 된 것이기에 flash의 링크를 원래 구조체에 연결하고
		*user = userflash;//처음노드값을 가르친다
	}
}

void video_add(Video **video)
{
	char temp[1024];
	Video *videoflash=(Video*)malloc(sizeof(Video));//임시로 비디오의 목록을 받아줄 구조체 선언 NULL로 선언시에 종료되기에 초기화 선언해줌
	int str_len;
	printf("입력하실 비디오제목을 입력하세요.\n");
	scanf_s("%s", temp, 1024);//제목을 받음
	str_len = strlen(temp) + 1;//제목의 길이보다 하나 증가시켜서 널값을 받음
	videoflash->videoname = (char*)malloc(strlen(temp));//temp의 길이만큼 구조체 멤버에 공간을 할당해준다.
	strcpy_s(videoflash->videoname, str_len, temp);//문장의 구조를 복사한다.

	printf("비디오의 제작연도를 입력하세요.\n");
	scanf_s("%s", temp, 1024);
	str_len = strlen(temp) + 1;
	videoflash->year = (char*)malloc(strlen(temp));
	strcpy_s(videoflash->year, str_len, temp);
	
	if (*video == NULL)//처음에 비디오를 NULL값으로 해놨기에 처음이라는 경우를 받은 if문이다
	{
		*video = videoflash;//위에서 입력한 값을 넣어준다
		(*video)->link = NULL;//그리고 링크를 NULL로 바꾸어준다
	}
	else {
		videoflash->link = *video;//두번째 이상 된 것이기에 flash의 링크를 원래 구조체에 연결하고
		*video = videoflash;//비디오의 값에 videoflash를 넣음으로써 video가 맨앞 노드를 가르치게 된다.
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
	printf("반납하실 비디오제목을 입력해주세요.\n");
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
		printf("해당하는 비디오는 대여되지 않았습니다.\n");
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
			printf("동일한 제목의 비디오가 존재합니다. 비디오의 제작연도도 입력해주세요\n");
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
	printf("%s님의 %s비디오가 반납되었습니다.!\n\n", temp_bring->name, temp_bring->title->videoname);
	

	for (int i = 0; i < count_link-1 ; i++)//링크를 한만큼의 한단계 전을 택함으로써 전노드를 가르킨다.
		pre = pre->link;

	if (count_link  == 0)
		(*bring) = (*bring)->link;//첫번째 노드를 이동하는 경우
	
	if (count_link != 0)//링크가 한번이라도 진행되었다면 이렇게 진행
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
	int count = 0, count_link = 0;//link가 몇번 진행되었는지 세기 위함 인와 동명이인을 찾기위한 int
	char temp[1024];
	char *tempmoney;
	Video *videosearch = *video;
	Video *pre = *video;//전노드의 위치를 찾기위함
	User *usersearch = *user;
	Bring *bringlist = (Bring*)malloc(sizeof(Bring));//bring은 초기화가 위에서 NULL값만 크기를 받아온다.
	printf("!!!!!!!!!대여시 필독사항 ::어떤 비디오든 대여시 잔액에서 1000원이 차감된다.!!!!!!!!!\n\n");
	printf("대여하고자하는 비디오의 이름을 입력하세요.\n");

	scanf_s("%s", temp, 1024);
	while (videosearch)
	{
		if (strcmp(videosearch->videoname, temp) == 0)//비디오의 제목과 입력한값을 비교한다
		{
			count++;
		}
		videosearch = videosearch->link;
	}
	videosearch = *video;//앞에서 videosearch를 끝까지 돌렸기에 처음에 값을 입력해주어서 재사용한다.

	if (count == 0)
	{
		printf("찾으시는 정보가 존재하지 않습니다.\n\n");
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
			count_link++;//전노드의 링크를 찾기 위한 작업
		}
	}

	if (count >= 2)//같은값이 있는경우에는 다른속성값을 입력받는다.
	{

		printf("같은제목의 비디오가 있습니다.\n");
		printf("찾으시는 비디오의 제작연도를 입력해주세요\n");
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

	count = 0;//카운트 초기화 동명이인찾기
	printf("대여하고자 하는 사람의 이름을 입력해주세요.\n");
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
		printf("찾으시는 유저가 존재하지 않습니다.\n\n");
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
					usersearch->money = (char*)malloc(sizeof(count));//동적할당이기에 크기를 다시 선언해준다
					strcpy_s(usersearch->money, count, tempmoney);//문자열을 다시 받아줌
					printf("대여가 완료되었습니다\n\n");
				}
				break;
			}
			usersearch = usersearch->link;

		}
	}
	if (count >= 2)
	{

		printf("동명이인이 있습니다.\n");
		printf("찾으시는 유저의 id를 입력해주세요\n");
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
					usersearch->money = (char*)malloc(sizeof(count));//동적할당이기에 크기를 다시 선언해준다
					strcpy_s(usersearch->money, count, tempmoney);//문자열을 다시 받아줌
					printf("대여가 완료되었습니다\n\n");
				}
				break;
			}
			usersearch = usersearch->link;


		}
	}

	for (int i = 0; i < count_link - 1; i++)
			pre = pre->link;

	if (count_link  == 0)//링크를 하나도 이동하지 않았다면
			(*video) = (*video)->link;//첫번째 노드를 이동하는 경우
	if (count_link != 0)//링크를 하나라도 움직였다면
	{
		pre->link = pre->link->link;
		(*video) = pre;
	}

	if (*bring == NULL)
	{
		*bring = bringlist;
		(*bring)->link = NULL;
		(*bring)->title->link = NULL;//빌린노드에 연결된 값을 없애기 위함
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
	Video *vd_flesh = *video;//각자의 구조체의 값을 받아줄 구조체 포인터를 선언한다.
	User *us_flesh = *user;
	Bring *br_flesh = *bring;
	FILE *fp = NULL;//파일을 받아올 포인터 선언
	printf("저장할 파일이름을 입력하세요\n");
	scanf_s("%s", f_n, 1024);
	fp = fopen(f_n, "w");//파일을 원하는 이름으로 만들고 쓰기모드로 함
	while (vd_flesh)
	{
		fputs("V\n", fp);
		fputs(vd_flesh->videoname, fp);//각 구조체의 속성을 안에 넣어놈
		fputs(" ", fp);//빈칸을 통해서 값을 구별하기 위한 밑작업
		fputs(vd_flesh->year, fp);
		fputs(" \n", fp);//fgets를 사용하면 문장이 끝나면 자동으로 한칸 뛰어지기에 범위를 맞추기위해서 한칸 뛰고 빈칸을 받으면 작동안되게 했기에 이렇게 함
		vd_flesh = vd_flesh->link;
	}
	while (us_flesh)
	{
		fputs("U\n", fp);
		fputs(us_flesh->name, fp);//각 구조체의 속성을 안에 넣어놈
		fputs(" ", fp);//빈칸을 통해서 값을 구별하기 위한 밑작업
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
		fputs(br_flesh->name, fp);//각 구조체의 속성을 안에 넣어놈
		fputs(" ", fp);//빈칸을 통해서 값을 구별하기 위한 밑작업
		fputs(br_flesh->title->videoname, fp);
		fputs(" ", fp);//빈칸을 통해서 값을 구별하기 위한 밑작업
		fputs(br_flesh->title->year, fp);
		fputs(" ", fp);//빈칸을 통해서 값을 구별하기 위한 밑작업
		fputs(" \n", fp);
		br_flesh = br_flesh->link;
	}
	fclose(fp);//파일열었으면 닫기
	printf("저장되었습니다.\n\n");
}

char* moneycheck(char *money)//동적할당을 하면은 메모리상에 해제하기 전까지 값이 남아있기에 함수내의 지역변수의 값을 리턴할수 있기에 char*로 해서 동적할당을 반환한다는 뜻으로 사용했따
{
	char *tradefee = (char*)malloc(7);
	tradefee = "1000\n";
	int diffrent = 0;
	int str_len,str_len1;//돈이 얼마나 길이를 제는 용도
	int tradefee_i = 0;
	char temp_money[1024] = { "\n", };
	char temp[1024] = { "\n" }, zero = 0;//둘의 돈의 양을 계산하고서 리턴해줄값
	
	for(int i=0;money[i];i++)//char의 값을 포인터로 받으면서 strlen에 temp배열로써 선언해서 넣기위해서 임시적으로 배열의 크기를 이용함
	temp_money[i] = money[i];
	str_len=strlen(temp_money)+1;//NULL값을 받기 위함
	str_len1 = strlen(tradefee);
	diffrent = str_len - str_len1;
	if (diffrent == 0)
	{
		for (int i = 0; temp_money[i+1]; i++)
		{
			temp[i] = temp_money[i] - tradefee[i];
			if ((int)temp[0] < 0)
			{
				printf("잔액부족입니다.\n");
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
			printf("잔액부족입니다.\n");
			return "x";
		}
		else
		for (int i = diffrent; i < str_len; i++)//차이만큼 나는 자리수부터 시작해서 끝까지
		{
			temp[i] = temp_money[i] - tradefee[tradefee_i];
			if (temp[i] <= -1)//위에항끼리 계산하다가 값이 -1이하가 나올경우에 돌리게 되며 이항을 충족시키기위해서 아래 조건들을 따른다
			{
				/*if (diffrent == 0)//둘이 자릿수 차이가 안나는데 음수가 나올경우에 리턴한다.
				{
					printf("잔액부족입니다.\n");
					return "x";
				}*/
				for (int j = diffrent -i+1; j > 0; j--)//두개항의 차이가 적어도 1이상
				{
					if ((temp_money[j-i] - 49) < 0)//왼쪽은 i-j항의 값에 -1을 뺏을때 그값이 0보다작을때와 오른쪽은 i-j는 차이값과 똑같아졌을때 두가지 조건이 모두충족시 실행
					{
						printf("잔액부족으로 대여가 불가능합니다.\n");//잔액부족시에 대여불가 출력
						return "x";
					}
					else
					{
						temp_money[j-i] = (temp_money[j-i] - 49) + 48;//i-j항의 값에 -1을 한값을 대입해준다
						temp_money[i] = (10 + (int)temp[i]) + 48;//위에서 값이 하나 내려오기에 10에서 빠진 금액만큼 계산하고서 다시 문자의 크기로 돌려준다.
					}
				}
			}
			//temp[i]=
			tradefee_i++;
		}

		if (temp_money[0] == 48)//첫번째 항이 0인경우에는 두번째 항의 값부터 temp에 넣고 아니면 그대로 다 넣어준다.
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
		return tradefee;//동적할당된 포인터 주솟값을 보내기에 삭제되지 않고 리턴할수 있다
	}
	
}

int load(Video **video, User **user, Bring **bring)
{
	char f_n[1024];
	int vd_count = 0, user_count = 0;
	Video *vd_flesh = (Video*)malloc(sizeof(Video));//각자의 구조체의 값을 받아줄 구조체 포인터를 선언한다.
	User *us_flesh = (User*)malloc(sizeof(User));
	Bring *br_flesh = (Bring*)malloc(sizeof(Bring));
	vd_flesh->link = NULL;//앞에 head처럼 NULL으로 마지막노드는 선언해놓기
	us_flesh->link = NULL;
	br_flesh->link = NULL;
	
	FILE *fp = NULL;//파일을 받아올 포인터 선언
	char *ptr;//값을 공백단위마다 짤라서 받기위해서 사용
	char line[1024];//한줄당 불러오기위함
	int str_len = 0;
	printf("불러올 파일이름을 입력하세요\n");
	scanf_s("%s", f_n, 1024);
	
	fp = fopen(f_n, "r");//파일을 원하는 이름으로 만들고 쓰기모드로 함
	if (fp == NULL)//파일이름이 없다면 출력
	{
		printf("입력하신 파일을 찾을수 없습니다.\n");
		return 0;
	}
	else
	{
		while (fgets(line, 1024, fp) != NULL)//출력할것이 남아있다면은 line저장하고 1024사이즈 파일포인터의 주소를 가져온다
		{
			if (strcmp(line,"V\n")==0)//위에서 비디오인지 유저인지 나누기 위해서 저장할때 맨앞줄을 다르게 해놓음
			{
				fgets(line, 1024, fp);
				
				ptr = strtok(line, " ");//공백을 통해서 칸을 구별함 

				str_len = strlen(ptr) + 1;//동적할당에 NULL크기를 추가함으로써 언제 끝나는지 알게하기위해서 하나 추가
				vd_flesh->videoname = (char*)malloc(strlen(ptr));//동적할당이기에 다시 크기를 수정한다.
				strcpy_s(vd_flesh->videoname, str_len, ptr);
				ptr = strtok(NULL, " ");//구별하고나면은 그칸을 \n취급을 하기에 NULL값에서부터 다시 " "으로 구별을 해달라는 뜻으로 쓰인다.


				str_len = strlen(ptr) + 1;
				vd_flesh->year = (char*)malloc(strlen(ptr));
				strcpy_s(vd_flesh->year, str_len, ptr);
				vd_fresh(&vd_flesh);//링크 연결을 위함
				vd_count++;
			}

			if (strcmp(line, "U\n") == 0)
			{
				fgets(line, 1024, fp);

				ptr = strtok(line, " ");//공백을 통해서 칸을 구별함 

				str_len = strlen(ptr) + 1;//동적할당에 NULL크기를 추가함으로써 언제 끝나는지 알게하기위해서 하나 추가
				us_flesh->name = (char*)malloc(strlen(ptr));//동적할당이기에 다시 크기를 수정한다.
				strcpy_s(us_flesh->name, str_len, ptr);
				ptr = strtok(NULL, " ");//구별하고나면은 그칸을 \n취급을 하기에 NULL값에서부터 다시 " "으로 구별을 해달라는 뜻으로 쓰인다.


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
				us_fresh(&us_flesh);//링크 연결을 위함
				user_count++;
				
			}

			if (strcmp(line, "B\n") == 0)
			{
				fgets(line, 1024, fp);

				ptr = strtok(line, " ");//공백을 통해서 칸을 구별함 

				str_len = strlen(ptr) + 1;//동적할당에 NULL크기를 추가함으로써 언제 끝나는지 알게하기위해서 하나 추가
				br_flesh->name = (char*)malloc(strlen(ptr));//동적할당이기에 다시 크기를 수정한다.
				strcpy_s(br_flesh->name, str_len, ptr);
				ptr = strtok(NULL, " ");//구별하고나면은 그칸을 \n취급을 하기에 NULL값에서부터 다시 " "으로 구별을 해달라는 뜻으로 쓰인다.

				br_flesh->title = (Video*)malloc(sizeof(Video));
				br_flesh->title->link = NULL;
				str_len = strlen(ptr) + 1;
				br_flesh->title->videoname = (char*)malloc(strlen(ptr));
				strcpy_s(br_flesh->title->videoname, str_len, ptr);
				ptr = strtok(NULL, " ");

				str_len = strlen(ptr) + 1;//동적할당에 NULL크기를 추가함으로써 언제 끝나는지 알게하기위해서 하나 추가
				br_flesh->title->year = (char*)malloc(strlen(ptr));//동적할당이기에 다시 크기를 수정한다.
				strcpy_s(br_flesh->title->year, str_len, ptr);
				br_fresh(&br_flesh);//링크 연결을 위함
				
			}
		}
	}
	fclose(fp);//파일열었으면 닫기
	(*video) = vd_flesh->link;//앞에 이상한 노드의 값을 없애기 위함 그후에 연결
	(*user) = us_flesh->link;
	(*bring) = br_flesh->link;
	printf("불러오기를 완료했습니다.\n");
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

	Video *temp = (Video*)malloc(sizeof(Video));//임시로 노드를 하나 만든다.->그후에 현재있는 노드값과 연결한다.->그리고 임시노드의 값을 현재노드의 값으로 하면서 앞에 이상한 노드와 이전값이 연결되도록한다.
	temp->link = *video;
	*video = temp;//이렇게 하면은 앞에서 링크 연결하고 뒤에서는 값을 연결해줌

}

void us_fresh(User ** user)
{

	User *temp = (User*)malloc(sizeof(User));//임시로 노드를 하나 만든다.->그후에 현재있는 노드값과 연결한다.->그리고 임시노드의 값을 현재노드의 값으로 하면서 앞에 이상한 노드와 이전값이 연결되도록한다.
	temp->link = *user;
	*user = temp;//이렇게 하면은 앞에서 링크 연결하고 뒤에서는 값을 연결해줌

}

void br_fresh(Bring ** bring)
{

	Bring *temp = (Bring*)malloc(sizeof(Bring));//임시로 노드를 하나 만든다.->그후에 현재있는 노드값과 연결한다.->그리고 임시노드의 값을 현재노드의 값으로 하면서 앞에 이상한 노드와 이전값이 연결되도록한다.
	temp->link = *bring;
	*bring = temp;//이렇게 하면은 앞에서 링크 연결하고 뒤에서는 값을 연결해줌

}

void moneyplus(User ** user)
{
	User *temp_user = *user;
	char temp[1024] = { "\n," }, money_yang[1024];
	int jungbok = 0;
	char user_sr[1024];
	char tempflesh[1024] = { "\n," }, upcount[2] = { "0," };
	int count = 0;//마지막에 구조체의 동적할당을 위함
	int str_len1, str_len2, different = 0;//금액이 동일한지 알아보기 위함
	printf("충전을 할 유저의 이름을 입력하세요.\n");
	scanf_s("%s", user_sr, 1024);
	jungbok = usersearch(*user, user_sr, 1);

	if (jungbok == 0)
	{
		printf("찾으시는 유저가 존재하지 않습니다.\n");
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
			count++;//링크진행횟수 확인용도
		}
	}

	if (jungbok >= 2)
	{
		printf("동명이인이 존재합니다. id를 입력해주세요.\n");
		scanf_s("%s", user_sr, 1024);
		while (temp_user)
		{
			if (strcmp(temp_user, user_sr) == 0)
			{
				break;
			}
			temp_user = temp_user->link;
			count++;//링크가 몇번 진행되었는지 판단하기 위함
		}
	}
	temp_user = *user;//위에서 링크해서 NULL로 변환되었기에 다시 선언
	printf("충전할 금액을 입력하세요.\n(유저 잔액 최대치 99999)\n");
	scanf_s("%s", money_yang, 1024);

	for (int i = 0; money_yang[i]; i++)
	{
		temp[i] = money_yang[i];
	}
	str_len1 = strlen(temp_user->money);//NULL값을 뺴기 위함
	str_len2 = strlen(temp);
	if (str_len2 >= 6)
	{
		printf("초과충전입니다.\n");
		return;
	}
	different = str_len1 - str_len2;//str_len1에는 NULL이 들어가 있고 str_len2에는 NULL값이 안들어가 있기에 이렇게 함
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
			tempflesh[i + 1] = temp_user->money[i] + temp[i] - 96 + upcount[0];//각자리수 계산
			


			upcount[0] = (((int)tempflesh[i + different + 1] - 48) / 10) + 48;//10으로 나누면 10이하인 수는 값으로 0이 나오기에 올라가는지 판별가능

			tempflesh[i + 1] = (((int)tempflesh[i + different + 1] - 48) % 10) + 48;//정수의 값을 10으로 나누면 나오는 나머지를 구하는 것으로써 일의 자리수의 개수를 알수있다
		}
	}
	else
	{
		if (str_len1 > str_len2)//money의 값이 충전할 금액보다 큰 경우
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
				tempflesh[i + different + 1] = temp_user->money[i + different] + temp[i] - 96 + upcount[0];//각자리수 계산

				
				upcount[0] = (((int)tempflesh[i + different + 1] - 48) / 10) + 48;//배열안의 값은 숫자 int이기에 48을 뺴줘서 원래의 숫자 값으로 변환시킨후에 int의 값이 나오면 48의 숫자를 더해서 각 숫자만큼을 올려준다.

				tempflesh[i + different + 1] = (((int)tempflesh[i + different + 1] - 48) % 10) + 48;

			}

		}
		if (str_len1 < str_len2)//money의 값이 충전할 금액보다 작은 경우
		{
			different = -different;//음수일때 다시 양수로 만들기 위함
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
				tempflesh[i + different + 1] = temp_user->money[i] + temp[i + different] - 96 + upcount[0];//각자리수 계산


				upcount[0] = (((int)tempflesh[i + different + 1] - 48) / 10) + 48;//10으로 나누면 10이하인 수는 값으로 0이 나오기에 올라가는지 판별가능

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

	else//첫번째 항에 값이 들어갔을 경우에는 
	{
		printf("초과충전입니다.\n");
		return;
	}

	str_len1 = strlen(temp) + 1;

	temp_user->money = (char*)malloc(sizeof(str_len1));//NULL값도 받기 위함
	strcpy_s(temp_user->money, str_len1, temp);//문자열 입력함수사용

}
