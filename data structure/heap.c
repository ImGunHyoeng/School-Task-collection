#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

// 공백 히프를 생성하는 연산
heapType* createHeap() {
	heapType* h = (heapType*)malloc(sizeof(heapType));
	h->heap_size = 0;
	return h;
}

// 히프에 item을 삽입하는 연산
void insertHeap(heapType* h, int item) {
	int i;
	h->heap_size = h->heap_size + 1;//1개씩추가됨
	i = h->heap_size;
	while (1) {
		if (i == 1)break;
		if (item <= h->heap[i / 2])
			break;
		h->heap[i] = h->heap[i / 2];
		i = i / 2;
	}
	h->heap[i] = item;
}

// 히프의 루트를 삭제하여 반환하는 연산
int deleteHeap(heapType* h) {
	int parent, child;
	int item, temp;
	item = h->heap[1];
	temp = h->heap[h->heap_size];//힙의 사이즈에서 가장작은값
	h->heap_size = h->heap_size - 1;
	parent = 1;
	child = 2;
	while (child <= h->heap_size)
	{
		if (child < h->heap_size)
		{
			if (h->heap[child] < h->heap[child + 1])//자식끼리의 크기 비교
				child = child + 1;
		}
		if (temp >= h->heap[child])//자식값과 같거나 작을경우
			break;
		else//임시값이 자식값보다 작을경우의 수
		{
			h->heap[parent] = h->heap[child];
			parent = child;
			child = child * 2;
		}
	}
	h->heap[parent] = temp;//첫번째 노드의 값
	return item;//item은 가장큰값
}

// 1차원 배열 히프의 내용을 출력하는 연산
void printHeap(heapType* h) {
	int i;
	printf("Heap : ");
	for (i = 1; i <= h->heap_size; i++)
		printf("[%d] ", h->heap[i]);
}