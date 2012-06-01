#include <iostream>

struct listNode {
	listNode* next;
	int value;
};

void printList(listNode* phead)
{
	listNode* p = phead;
	while (p) {
		std::cout << p->value << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

listNode* constructList(int arr[], int length)
{
	listNode* phead = 0;
	for (int i = length-1; i >= 0; i--) {
		listNode* p = new listNode;
		p->next = phead;
		p->value = arr[i];
		phead = p;
	}
	return phead;
}

listNode* reverseList(listNode* phead)
{
	listNode* pcur = phead;
	listNode* pprev = 0, *pnext;
	while (pcur) {
		pnext = pcur->next;
		pcur->next = pprev;

		pprev = pcur;
		pcur = pnext;
	}
	return pprev;
}

int main()
{
	int arr[10] = { 1, 2, 5, 3, 10, 9, 7, 6, 8, 4 };
	listNode* phead = constructList(arr, sizeof(arr)/sizeof(int));
	std::cout << "single list: ";
	printList(phead);
	listNode* prevhead = reverseList(phead);
	std::cout << "reversed single list: ";
	printList(prevhead);
	return 0;
}

