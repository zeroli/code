#include <cstdio>
#include <cstdlib>
#include <vector>
typedef int ElemType;

typedef struct BtNode {
	ElemType data;
	struct BtNode* lchild, *rchild;
} BtNode, *BTree;

typedef struct StNode {
	BTree elem;
	struct StNode* link;
} StNode;

void visit(StNode* v)
{
	printf("visit node : %d\n", v->elem->data);
}

int inOrder(BTree root)
{
	printf("Enter inOrder function call\n");
	BTree ptr;
	StNode* q;
	StNode* stacktop = NULL;
	ptr = root;
	while (ptr!=NULL || stacktop != NULL) {
		while (ptr != NULL) {
			q = (StNode*)malloc(sizeof(StNode));
			if (q==NULL)
				return -1;
			q->elem = ptr;
			q->link = stacktop;
			stacktop = q;
			printf("node: %d\n", ptr->data);
			ptr = ptr->lchild;					
		}
		q = stacktop;
		stacktop = stacktop->link;
		visit(q);
		ptr = q->elem->rchild;
		free(q);
	}
	return 0;
}

int main()
{
	std::vector<int> vt;
	int a;
	int count = 10;
	printf("please type in 10 numbers:\n");
	for (int i = 0; i < count; i++)  {
		scanf("%d", &a);
		vt.push_back(a);
	}
	for (int i = 0; i  < count; i++) {
		printf("%d ", vt.at(i));
	}
	printf("\n");
	
	BTree root = (BTree)malloc(sizeof(BtNode));
	root->data = 100;
	root->lchild = root->rchild = 0;
	BtNode* t = root;
	printf("setup binary tree\n");
	for (int i = 0; i < count; i++) {
		int d = vt.at(i);
		
		BtNode* node = (BtNode*)malloc(sizeof(BtNode));
		node->data = d;
		node->lchild = node->rchild = 0;
		BtNode* ptr = 0;
		int lOrr = 0;
		printf("%d ", d);
		t = root;
		while (t) {
			if (d < t->data) {					
				ptr = t; lOrr = 0;
				t = t->lchild;
			} else {
				ptr = t; lOrr = 1;
				t = t->rchild;
			}
		}
		if (lOrr) {
			ptr->rchild = node;
			printf("node %d => right of node %d\n", node->data, ptr->data);
		}
		else {
			ptr->lchild= node;
			printf("node %d => left of node %d\n", node->data, ptr->data);
		}
	}
	printf("\n");
	inOrder(root);
	free(root);
	return 0;
}
