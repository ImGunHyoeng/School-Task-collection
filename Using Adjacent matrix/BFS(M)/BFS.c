#include "adjMatrix.h"
#include "BFS.h"
#include "MatrixQueue.h"

void BFS_adjMatrix(graphType* g, int v)
{
	
	int w;
	int i = 0;
	QueueType* Q;
	Q = createQueue();
	g->viseted[v] = TRUE;
	printf("%c", v + 65);//A�� ���
	enQueue(Q, v);
	//������ ������ �ƴ� ���� ���� �켱 Ž�� �ݺ�
	while (!isQueueEmpty(Q))//top==-1
	{
		v = deQueue(Q);//0�� ��ȯ
		w = g->adjMatrix[v][i];
		while (w == 1 || (g->n) > i)
		{
			if (!g->viseted[i] && w == 1)//�࿡ �湮�����ʰ�  w�� 1�̸� ����
			{
				enQueue(Q,i);
				g->viseted[i] = TRUE;
				printf(" %c", i + 65);//
				//v = i;
				//i = 0;
				i++;
				w = g->adjMatrix[v][i];
				
			}
			else
			{
				i++;//�����迭�� ĭ���� �Ѿ
				w = g->adjMatrix[v][i];//�����迭ĭ
			}
		}
		//���ÿ� �׿��ִ°��� ������ ������ ���
		i = 0;//0���� ó������ ����
	}
}