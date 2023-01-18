#include <stdio.h>
#include "adjMatrix.h"
#include "stack.h"
#include "DFS.h"

void DFS_adjMatrix(graphType* g, int v)
{
	int w;
	int i = 0;
	
	push(v);//�����ϴ� �������� ���� top=0;
	g->viseted[v] = TRUE;
	printf("%c", v + 65);//A�� ���
	//������ ������ �ƴ� ���� ���� �켱 Ž�� �ݺ�
	while (!isStackEmpty())//top==-1
	{
		w = g->adjMatrix[v][i];
		while (w == 1|| (g->n) > i)
		{
			if (!g->viseted[i]&&w==1)//�࿡ �湮�����ʰ�  w�� 1�̸� ����
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
				i++;//�����迭�� ĭ���� �Ѿ
				w = g->adjMatrix[v][i];//�����迭ĭ
			}
		}
		v = pop();//���ÿ� �׿��ִ°��� ������ ������ ���
		i = 0;//0���� ó������ ����
	}
}