#include <stdio.h>
#include "stack.h"

int static top = -1;
int isStackEmpty(void)//비어있다면 1 아니면 0
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
	if (isStackFull())//참일경우 1이기에 1일떄 밑에항 실행
	{
		printf("\n stack is Full!\n");
		return;
	}
	else stack[++top] = item;//탑의 1만큼 올리고 이것에 item 삽입
}

element pop(void)
{
	if (isStackEmpty())
	{
		printf("\n stack is Empty!\n");
		return;
	}
	else
		return stack[top--];//top을 감소시킨다
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