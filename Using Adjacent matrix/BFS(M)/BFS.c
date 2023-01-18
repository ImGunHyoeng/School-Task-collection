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
	printf("%c", v + 65);//A를 출력
	enQueue(Q, v);
	//스택이 공백이 아닌 동안 깊이 우선 탐색 반복
	while (!isQueueEmpty(Q))//top==-1
	{
		v = deQueue(Q);//0이 반환
		w = g->adjMatrix[v][i];
		while (w == 1 || (g->n) > i)
		{
			if (!g->viseted[i] && w == 1)//행에 방문하지않고  w가 1이면 실행
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
				i++;//다음배열의 칸으로 넘어감
				w = g->adjMatrix[v][i];//다음배열칸
			}
		}
		//스택에 쌓여있는값을 가지고 인접항 계산
		i = 0;//0부터 처음부터 실행
	}
}