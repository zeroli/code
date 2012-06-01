#include <stdio.h>

typedef struct {
	int num;
	float ave;
} Back;

typedef struct node {
	float data;
	struct node* next;
} Node;

Back* average(Node* head)
{
	Back* p, *q;
	p = (Back*)malloc(sizeof(Back));
	if (head==NULL) {
		p->num = 0;
		p->ave = 0.f;
	} else {
		q = average(head->next);
		p->num = q->num+1;
		p->ave = (q->ave*q->num+head->data)/p->num;
	}
	return p;
}

int main()
{
	Node* h;
	Back* p;
	h = create();
	if (!h) 
		printf("no any elemnts.\n");
	else {
		p = average(h);
		printf("average of all elements : %.6f\n", p->ave);
	}
	return 0;
}

