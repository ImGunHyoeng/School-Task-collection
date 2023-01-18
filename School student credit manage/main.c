#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"

void main()
{
	int sunsa = 0;
	double cal = 0;
	linkedList_h *p = createLinkedList_h();
	char name[5][5] = { "dla","park","sue","kim","jang" };
	int score[5] = {100,10,30,50,60};
	for (int i = 0; i < 4; i++)
	{
	
		insertNode(p, score[i], name[i]);
	}
	printList(p);
	printRangedList(p, 30, 60);
	//deleteNode(p, "dla");
	//deleteNode(p, "jang");
	sunsa=searchbyName(p, "kim");
	sunsa = searchbyScore(p, 50);
	sunsa=findLowScore(p);
	sunsa = findMidScore(p);
	cal = calAve(p);
	changeScorebyName(p, 40, "dla");
	freeLinkedList_h(p);

	

}