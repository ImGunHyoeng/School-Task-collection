#include <stdio.h>
#include <stdlib.h>
#include "adjMatrix.h"

void createGraph(graphType* g)
{
	int i, j;
	g->n = 0;
	for (i = 0; i < MAX_VERTEX; i++)
	{
		g->viseted[i] = FALSE;//방문안함
		for (j = 0; j < MAX_VERTEX; j++)
		{
			g->adjMatrix[i][j] = 0;//2차원 배열 초기화
		}
	}
}

void insertVertex(graphType* g, int v)
{
	if ((g->n) + 1 > MAX_VERTEX)
	{
		printf("\n 그래프 정점의 개수를 초과하였습니다!\n");
		return;
	}
	if (v < (g->n))//이미 있는 것이기에 리턴
		return;
	g->n++;//정점의개수 증가
}

void insertEdge(graphType* g, int u, int v)
{
	if (u >= g->n || v >= g->n)//2차원배열이기에  존재하는 정점의 개수보다 크거나 간선의 숫자가 존재하지 않으면은 리턴
	{
		printf("\n그래프에 없는 정점입니다!\n");
		return;
	}
	g->adjMatrix[u][v] = 1;//정점과 간선에 1 처리
}

void print_adjMatrix(graphType* g)
{
	int p=0, q=0;
	for (; p < (g->n); p++)
	{
		printf("\n\t\t");
		for (q = 0; q < (g->n); q++)
			printf("%2d", g->adjMatrix[p][q]);//%2d는 두자리 수보다 작으면은  스페이스를 통해서 한칸을 추가 시켜준다  3=>x3  %02d는 0으로 자리 추가 3=>03
	}
}