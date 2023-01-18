#define _CRT_SECURE_NO_WARNINGS
#include "Linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


linkedList_h* createLinkedList_h(void)
{
	linkedList_h *p = (linkedList_h*)malloc(sizeof(linkedList_h));
	p->head = NULL;
	return p;
}

void freeLinkedList_h(linkedList_h* L)
{
	listNode *p;
	while (L->head != NULL)
	{
		p = L->head;
		L->head = L->head->link;
		free(p);
	//	p = NULL;없애도 차이 없음
	}
}

void printList(linkedList_h* L)
{
	listNode *p = L->head;
	while (p != NULL)
	{
		printf("이름: %s  성적: %d\n", p->name, p->score);
		p = p->link;
	}

}

void printRangedList(linkedList_h* L, int lowscore, int highscore)
{
	listNode *p = L->head;
	printf("해당 점수대의 학생 이름:");
	while (p != NULL)
	{
		if (p->score >= lowscore && p->score <= highscore)
		{
			printf("%s ",p->name);
		}
		p = p->link;
	}
	printf("출력이 끝났습니다.\n");
}

void insertNode(linkedList_h* L, int score, char* name)
{
	int gubal = 0,link_count=0;//linkcount는 p노드의 전노드를 찾기 위함
	listNode *p = L->head;
	listNode *pre = L->head;//전노드를 찾기 위함
	listNode *temp;
	temp = (listNode*)malloc(sizeof(listNode));
	strcpy(temp->name, name);
	temp->score = score;
	temp->link = NULL;
	if (L->head == NULL)
	{
		L->head = temp;
		return;
	}
	while (p != NULL)
	{
		if (p->score <= temp->score)
		{
			break;
		}
		p = p->link;
		link_count++;
	}
	if (p == NULL)
	{
		p = L->head;//맨앞의 노드로 초기화
		while (p->link != NULL)//맨뒤의 값까지 돌린다 제일 작기에
			p = p->link;
		p->link = temp;
		return;
	}
	else
	{
		if (link_count == 0)//첫노드랑 비교할때
		{
			if (p->score == temp->score)//같은경우
			{
				gubal = strcmp(p->score, temp->score);
				if (gubal == -1)//앞에가 더 사전적으로 앞에임
				{
					temp->link = p->link;//원래 가리키던것을 가르킴
					p->link = temp;//템프의 값을 가르킴
				}
				else
				{
					temp->link = p;//맨앞노드랑 비교하는것이기에
					L->head = temp;
				}
				return;
			}
			else//큰경우
			{
				temp->link = p;
				L->head = temp;
				return;
			}
		}
		if (p->score == temp->score)
		{
			gubal = strcmp(p->score, temp->score);
			if (gubal == -1)//앞에가 더 사전적으로 앞에임
			{
				temp->link = p->link;
				p->link = temp;
				return;
			}
			else
			{
				temp->link = p;
				//전노드에서 링크를 연결하기 위함
				for (int i = 0; i < link_count-1; i++)
					pre = pre->link;
				pre->link = temp;
				return;
			}

		}
		else//더 클때
		{
			temp->link = p;
			//전노드에서 링크를 연결하기 위함
			for (int i = 0; i < link_count-1; i++)
				pre = pre->link;
				pre->link = temp;
				return;
		}
	}
}

void deleteNode(linkedList_h* L, char* name)
{
	int link_count=0;
	listNode *old = (listNode*)malloc(sizeof(listNode));
	listNode *pre = L->head;
	listNode *p = L->head;
	while (p != NULL)
	{
		if (strcmp(p->name, name) == 0)
			break;
		p = p->link;
		link_count++;
	}
	if (p == NULL)
	{
		printf("해당하는 값이 없습니다\n");
		return;
	}
	else
	{
		old = p;
		for (int i = 0; i < link_count-1; i++)
			pre = pre->link;
		pre->link = old->link;
		
		p = p->link;//노드 사라지니 한칸 건너뛰게 하기
		if (old == L->head)
			L->head = p;
		free(old);
	}
}

int searchbyName(linkedList_h* L, char* name)
{
	listNode *p = L->head;
	int linkcount = 0;
	if (L->head == NULL)
		return;
	while (p != NULL)
	{
		if (strcmp(p->name, name) == 0)
			break;
		p = p->link;
		linkcount++;
	}
	if (p==NULL)
	{
		printf("해당하는 데이터가 존재하지 않습니다.\n");
	}
	return linkcount;
}

int searchbyScore(linkedList_h* L, int score) 
{
	listNode *p = L->head;
	int linkcount = 0;
	if (L->head == NULL)
		return;
	while (p != NULL)
	{
		if (p->score==score)
			break;
		p = p->link;//이미 앞에서 동점자일때 사전순서로 저장했기에 할필요x
		linkcount++;
	}
	if (p==NULL)
	{
		printf("해당하는 데이터가 존재하지 않습니다.\n");
	}
	return linkcount ;
}

int findLowScore(linkedList_h* L)
{
	listNode *p = L->head;
	
	while (p->link!= NULL)
		p = p->link;//가장 맨뒤 까지 링크 보내기
	return p->score;

}

int findMidScore(linkedList_h* L)
{
	int link_count = 0;
	listNode *p = L->head;
	if (L->head == NULL)
		return;
	while (p != NULL)
	{ 
		p = p->link;
		link_count++;
	}
	link_count = link_count / 2;
	p = L->head;
	for (int i = 0; i < link_count; i++)
		p = p->link;
	return p->score;

		
}

double calAve(linkedList_h* L)
{
	double sum=0;
	double result = 0;
	int link_count = 0;
	listNode *p = L->head;
	if (L->head == NULL)
		return;
	while (p != NULL)
	{
		sum = sum + p->score;
		p = p->link;
		link_count++;
	}
	
	result = sum / link_count;
	
	return result;
}

void changeScorebyName(linkedList_h* L, int score, char* name)
{
	int gubal = 0;
	listNode *p = L->head;//학생이 있다는 가정
	listNode *pre = (listNode*)malloc(sizeof(listNode));
	listNode *temp = (listNode*)malloc(sizeof(listNode));
	int link_count = 0;
	link_count=searchbyName(L, name);
	if (link_count == 0)//첫번째 항인경우
	{
		temp = L->head;
		L->head = p->link;
		p = L->head;
		temp->score = score;
		temp->link = NULL;
	}
	else
	{
		for (int i = 0; i <= link_count; i++)
			p = p->link;
		for (int i = 0; i <= link_count - 1; i++)
			pre = pre->link;
		pre->link = p->link;
		temp = p;
		temp->score = score;
		temp->link = NULL;
	}
	/////////////////////////////////////////////////////앞에 insertNode의 일부를 가져옴
	link_count = 0;
	pre = L->head;//헤드가 바뀌었다는 경우도 있기에 이렇게 선언
	while (p != NULL)
	{
		if (p->score <= temp->score)
		{
			break;
		}
		p = p->link;
		link_count++;
	}
	if (p == NULL)
	{
		p = L->head;//맨앞의 노드로 초기화
		while (p->link != NULL)//맨뒤의 값까지 돌린다 제일 작기에
			p = p->link;
		p->link = temp;
		return;
	}
	else
	{
		if (link_count == 0)//첫노드랑 비교할때
		{
			if (p->score == temp->score)//같은경우
			{
				gubal = strcmp(p->score, temp->score);
				if (gubal == -1)//앞에가 더 사전적으로 앞에임
				{
					temp->link = p->link;//원래 가리키던것을 가르킴
					p->link = temp;//템프의 값을 가르킴
				}
				else
				{
					temp->link = p;//맨앞노드랑 비교하는것이기에
					L->head = temp;
				}
				return;
			}
			else//큰경우
			{
				temp->link = p;
				L->head = temp;
				return;
			}
		}
		if (p->score == temp->score)
		{
			gubal = strcmp(p->score, temp->score);
			if (gubal == -1)//앞에가 더 사전적으로 앞에임
			{
				temp->link = p->link;
				p->link = temp;
				return;
			}
			else
			{
				temp->link = p;
				//전노드에서 링크를 연결하기 위함
				for (int i = 0; i < link_count - 1; i++)
					pre = pre->link;
				pre->link = temp;
				return;
			}

		}
		else//더 클때
		{
			temp->link = p;
			//전노드에서 링크를 연결하기 위함
			for (int i = 0; i < link_count - 1; i++)
				pre = pre->link;
			pre->link = temp;
			return;
		}
	}
	/*while (p->link != NULL)
	{
		if (p->score <= temp->score)
		{
			break;
		}
		p = p->link;
		link_count++;
	}
	if (p->link == NULL)
	{
		p->link = temp;
		return;
	}
	else
	{
		if (p->score == temp->score)
		{
			gubal = strcmp(p->score, temp->score);
			if (gubal == -1)//앞에가 더 사전적으로 앞에임
			{
				temp->link = p->link;
				p->link = temp;
			}
			else
			{
				temp->link = p;
				p = L->head;//전노드에서 링크를 연결하기 위함
				for (int i = 0; i < link_count; i++)
					p = p->link;
				p->link = temp;
			}

		}
		else//더 클때
		{
			temp->link = p;
			p = L->head;//전노드에서 링크를 연결하기 위함
			for (int i = 0; i < link_count; i++)
				p = p->link;
			if (p == L->head)
				L->head = temp;
			else
			{
				p->link = temp;
			}
		}
	}*/
}