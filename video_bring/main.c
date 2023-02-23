#include <stdio.h>
#include "video.h"


void main()
{
	Video *videolist = NULL;//비디오의 목록을 받을 노드
	User *userlist = NULL;//유저의 목록을 받을 노드
	Bring *bringlist = NULL;//빌려간 비디오를 받아둘 노드
	int op;
	int count_vd = 0, count_user = 0;

	printf("비디오 대여프로그램입니다. 원하시는 기능을 입력하세요.\n\n");
	for (; 1;) 
	{
		printf("1.검색\n2.대여\n3.반납\n4.출력\n5.가입자 추가\n6.비디오 추가\n7.저장\n8.불러오기\n9.잔액추가\n0.종료\n");
		scanf_s("%d", &op);
		while (getchar() != '\n');//문자도 받을수 있다 원리는 scanf는 입력값+\n의 값이 들어가게 되는데 getchar로 \n을 버퍼에서 없애줌으로써 다시 scanf를 사용할때 빈칸으로써 사용할수있게 해줘서 무한루프가 돌지않고 정상적으로 작동하게 된다.
			switch (op)
			{

			case 0:
				printf("프로그램을 종료합니다");
				return;

			case 1:
				search(&videolist, &userlist, &bringlist);
				break;

			case 2:
				if (count_vd >= 1 && count_user >= 1)
					video_trade(&videolist, &userlist, &bringlist);
				else
					printf("대여할수 있는 비디오나 유저가 없습니다.\n\n");
				break;

			case 3:
				if (bringlist)
					return_vd(&videolist, &userlist, &bringlist);
				else
					printf("대여한 비디오가 없습니다.\n\n");
				break;

			case 4:
				allprint(&videolist, &userlist, &bringlist);
				break;

			case 5:
				user_add(&userlist);
				printf("사용자 등록이 완료되었습니다.\n\n");
				count_user++;
				break;

			case 6:
				video_add(&videolist);
				printf("비디오 등록이 완료되었습니다.\n\n");
				count_vd++;
				break;

			case 7:
				save(&videolist, &userlist, &bringlist);
				break;

			case 8:
				op=load(&videolist, &userlist, &bringlist);//유저의 수와 비디오수가 1개 이상인지 체크하기 위한 리턴값
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
				printf("먼저 사용자를 추가해주세요\n");
				break;
			
			

			default:
				printf("잘못된 값입니다 다시 입력해주세요\n");
				continue;
		}
	}
}
