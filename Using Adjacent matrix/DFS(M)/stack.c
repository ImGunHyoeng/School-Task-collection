#include <stdio.h>
#include "stack.h"

int static top = -1;
int isStackEmpty(void)//����ִٸ� 1 �ƴϸ� 0
{
	if (top == -1)return 1;
	else return 0;
}

int isStackFull(void)
{
	if (top == STACK_SIZE - 1)
		return 1;
	else
		return 0;
}

void push(element item)
{
	if (isStackFull())//���ϰ�� 1�̱⿡ 1�ϋ� �ؿ��� ����
	{
		printf("\n stack is Full!\n");
		return;
	}
	else stack[++top] = item;//ž�� 1��ŭ �ø��� �̰Ϳ� item ����
}

element pop(void)
{
	if (isStackEmpty())
	{
		printf("\n stack is Empty!\n");
		return;
	}
	else
		return stack[top--];//top�� ���ҽ�Ų��
}

element peek(void)
{
	if (isStackEmpty())
	{
		printf("\n stack is Empty!\n");
		return;
	}
	else return stack[top];
}

void printStack(void)
{
	int i;
	printf("\n STACK[");
	for (i = 0; i <= top; i++)
	{
		printf("%d", stack[i]);
	}
	printf("] ");
}