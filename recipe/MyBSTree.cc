#include <iostream>
#include <stack>

typedef char elemtype;

typedef struct TreeNode {
	elemtype d;
	TreeNode* l;
	TreeNode* r;
	bool visited;
} Tree;

void TreeInit(Tree** t, elemtype e)
{
	(*t) = (Tree*)malloc(sizeof(TreeNode));
	(*t)->l = 0;
	(*t)->r = 0;
	(*t)->d = e;
	(*t)->visited = false;
}

bool TreeInsert(Tree* t, elemtype e)
{
	Tree* tmp = t;
	Tree* p = t;
	while (tmp) {
		p = tmp;
		if (tmp->d < e) 
			tmp = tmp->r;
		else if (tmp->d > e)
			tmp = tmp->l;
		else
			return false;
	}
	if (p->d < e) {
		tmp = (Tree*)malloc(sizeof(TreeNode));
		tmp->d = e;
		tmp->l = tmp->r = 0;
		tmp->visited = false;
		p->r = tmp;
	}
	if (p->d > e) {
		tmp = (Tree*)malloc(sizeof(TreeNode));
		tmp->d = e;
		tmp->l = tmp->r = 0;
		tmp->visited = false;
		p->l = tmp;
	}
	return true;
}

void destroyTree(Tree* t)
{
	Tree* tmp = t;
	if (tmp) {
		if (tmp->l) destroyTree(tmp->l);
		if (tmp->r) destroyTree(tmp->r);
		free(tmp);
		tmp = 0;
	}
}

void preorder1(Tree* t)
{
	if (t) {
		printf("%c ", t->d);
		if (t->l) preorder1(t->l);
		if (t->r) preorder1(t->r);
	}	
}

void preorder2(Tree* t)
{
	std::stack<Tree*> s;
	s.push(t);
	while (!s.empty()) {
		Tree* tmp = s.top();
		s.pop();
		printf("%c ", tmp->d);
		if (tmp->r) s.push(tmp->r);
		if (tmp->l) s.push(tmp->l);
	}
}

void inorder1(Tree* t)
{
  if (t) {
    if (t->l) inorder1(t->l);
    printf("%c ", t->d);
    if (t->r) inorder1(t->r);
  }
}

void inorder2_1(Tree* t)
{
	std::stack<Tree*> s;
	Tree* tmp = t;
	while (tmp || !s.empty()) {
		while (tmp) {
			s.push(tmp);
			tmp = tmp->l;
		}
		if (!s.empty()) {
			tmp = s.top(); s.pop();
			printf("%c ", tmp->d);
			tmp = tmp->r;
		}
	}
}

void inorder2(Tree* t)
{
	std::stack<Tree*> s;
	t->visited = false;
	s.push(t);
	while (!s.empty()) {
		Tree* tmp = s.top();
		s.pop();
		if (tmp->visited) {
			printf("%c ", tmp->d);
			continue;
		}
		if (tmp->r) { tmp->r->visited = false; s.push(tmp->r); }
		if (tmp) { tmp->visited = true; s.push(tmp); }
		if (tmp->l) { tmp->l->visited = false; s.push(tmp->l); }
	}	
}

void postorder1(Tree* t)
{
	if (t) {
		if (t->l) postorder1(t->l);
		if (t->r) postorder1(t->r);
		printf("%c ", t->d);
	}
}

void postorder2(Tree* t)
{
	std::stack<Tree*> s;
	t->visited = false;
	s.push(t);
	while (!s.empty()) {
		Tree* tmp = s.top(); s.pop();
		if (tmp->visited) {
			printf("%c ", tmp->d);
			continue;
		}
		if (tmp) { tmp->visited = true; s.push(tmp); }
		if (tmp->r) { tmp->r->visited = false; s.push(tmp->r); }
		if (tmp->l) { tmp->l->visited = false; s.push(tmp->l); }
	}
}	

int main()
{
	Tree* t = 0;
	TreeInit(&t, 'E');
	char arr[8] = {'D', 'H', 'B', 'A', 'C', 'F', 'G', 'E'};
	for (int i = 0; i < sizeof(arr)/sizeof(char); i++)
		TreeInsert(t, arr[i]);
	
	printf("preorder with recursively:\n");
	preorder1(t);
	printf("\n");
	printf("preorder with iteratively:\n");
	preorder2(t);
	printf("\n\n");
	
    printf("inorder with recursively:\n");
    inorder1(t);
    printf("\n");
    printf("inorder with iteratively with version1:\n");
	inorder2_1(t);
	printf("\n");
	printf("inorder with iteratively with version2:\n");
    inorder2(t);
    printf("\n\n");

    printf("postorder with recursively:\n");
    postorder1(t);
    printf("\n");
    printf("postorder with iteratively:\n");
    postorder2(t);
    printf("\n");

	destroyTree(t);
	return 0;
}


