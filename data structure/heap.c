#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

// ���� ������ �����ϴ� ����
heapType* createHeap() {
	heapType* h = (heapType*)malloc(sizeof(heapType));
	h->heap_size = 0;
	return h;
}

// ������ item�� �����ϴ� ����
void insertHeap(heapType* h, int item) {
	int i;
	h->heap_size = h->heap_size + 1;//1�����߰���
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

// ������ ��Ʈ�� �����Ͽ� ��ȯ�ϴ� ����
int deleteHeap(heapType* h) {
	int parent, child;
	int item, temp;
	item = h->heap[1];
	temp = h->heap[h->heap_size];//���� ������� ����������
	h->heap_size = h->heap_size - 1;
	parent = 1;
	child = 2;
	while (child <= h->heap_size)
	{
		if (child < h->heap_size)
		{
			if (h->heap[child] < h->heap[child + 1])//�ڽĳ����� ũ�� ��
				child = child + 1;
		}
		if (temp >= h->heap[child])//�ڽİ��� ���ų� �������
			break;
		else//�ӽð��� �ڽİ����� ��������� ��
		{
			h->heap[parent] = h->heap[child];
			parent = child;
			child = child * 2;
		}
	}
	h->heap[parent] = temp;//ù��° ����� ��
	return item;//item�� ����ū��
}

// 1���� �迭 ������ ������ ����ϴ� ����
void printHeap(heapType* h) {
	int i;
	printf("Heap : ");
	for (i = 1; i <= h->heap_size; i++)
		printf("[%d] ", h->heap[i]);
}