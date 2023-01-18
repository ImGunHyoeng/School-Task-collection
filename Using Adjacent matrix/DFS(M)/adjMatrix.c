#include <stdio.h>
#include <stdlib.h>
#include "adjMatrix.h"

void createGraph(graphType* g)
{
	int i, j;
	g->n = 0;
	for (i = 0; i < MAX_VERTEX; i++)
	{
		g->viseted[i] = FALSE;//�湮����
		for (j = 0; j < MAX_VERTEX; j++)
		{
			g->adjMatrix[i][j] = 0;//2���� �迭 �ʱ�ȭ
		}
	}
}

void insertVertex(graphType* g, int v)
{
	if ((g->n) + 1 > MAX_VERTEX)
	{
		printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�!\n");
		return;
	}
	if (v < (g->n))//�̹� �ִ� ���̱⿡ ����
		return;
	g->n++;//�����ǰ��� ����
}

void insertEdge(graphType* g, int u, int v)
{
	if (u >= g->n || v >= g->n)//2�����迭�̱⿡  �����ϴ� ������ �������� ũ�ų� ������ ���ڰ� �������� �������� ����
	{
		printf("\n�׷����� ���� �����Դϴ�!\n");
		return;
	}
	g->adjMatrix[u][v] = 1;//������ ������ 1 ó��
}

void print_adjMatrix(graphType* g)
{
	int p=0, q=0;
	for (; p < (g->n); p++)
	{
		printf("\n\t\t");
		for (q = 0; q < (g->n); q++)
			printf("%2d", g->adjMatrix[p][q]);//%2d�� ���ڸ� ������ ��������  �����̽��� ���ؼ� ��ĭ�� �߰� �����ش�  3=>x3  %02d�� 0���� �ڸ� �߰� 3=>03
	}
}