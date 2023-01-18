#include <stdio.h>
#include "adjMatrix.h"
#include "stack.h"
#include "DFS.h"

void DFS_adjMatrix(graphType* g, int v)
{
	int w;
	int i = 0;
	
	push(v);//시작하는 정점으로 시작 top=0;
	g->viseted[v] = TRUE;
	printf("%c", v + 65);//A를 출력
	//스택이 공백이 아닌 동안 깊이 우선 탐색 반복
	while (!isStackEmpty())//top==-1
	{
		w = g->adjMatrix[v][i];
		while (w == 1|| (g->n) > i)
		{
			if (!g->viseted[i]&&w==1)//행에 방문하지않고  w가 1이면 실행
			{
				push(i);
				g->viseted[i] = TRUE;
				printf(" %c", i + 65);//
				v = i;
				i = 0;
				w = g->adjMatrix[v][i];
			}
			else 
			{
				i++;//다음배열의 칸으로 넘어감
				w = g->adjMatrix[v][i];//다음배열칸
			}
		}
		v = pop();//스택에 쌓여있는값을 가지고 인접항 계산
		i = 0;//0부터 처음부터 실행
	}
}