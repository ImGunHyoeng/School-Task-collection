#include <stdio.h>
#include <stdlib.h>
#include "MatrixQueue.h"	

QueueType* createQueue(void)
{
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;//초기값 설정
	Q->rear = -1;
	return Q;
}

int isQueueEmpty(QueueType* Q)
{
	if (Q->front == Q->rear)
	{
		printf("\nisQueue Empty");
		return 1;
	}
	else return 0;
}

int isQueueFull(QueueType* Q)
{
	if (Q->rear==Q_SIZE-1)
	{
		printf("isQueue Full");
		return 1;
	}
	else return 0;
}

void enQueue(QueueType* Q, element item)
{
	if (isQueueFull(Q))return;
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}

element deQueue(QueueType* Q)
{
	if (isQueueEmpty(Q))return;
	else
	{
		Q->front++;
		return Q->queue[Q->front];
	}
}

element peekQ(QueueType* Q)
{
	if (isQueueEmpty(Q))return;
	else {
		return Q->queue[Q->front+1];
	}
}

void printQ(QueueType* Q)
{
	int i = 0;
	printf(" Queue:[");
	for (i = Q->front + 1; i < Q->rear; i++)
		printf("%3d", Q->queue[i]);
	printf(" ]");
}
