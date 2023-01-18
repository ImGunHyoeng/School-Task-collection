#pragma once
#define MAX_VERTEX 30
#define FALSE 0
#define TRUE 1

typedef struct graphType {
	int n;//그래프의 정점 개수
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];//30 30 행렬 생성
	int viseted[MAX_VERTEX];
}graphType;

void createGraph(graphType* g);
void insertVertex(graphType* g, int v);
void insertEdge(graphType* g, int u, int v);
void print_adjMatrix(graphType* g);