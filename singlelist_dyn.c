typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, *LinkList;

void InitList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(struct LNode));
	if (!*L)
		exit(OVERFLOW);
	(*L)->next = NULL;
}

void DestoryList(LinkList* L)
{
	LinkList q;
	while (*L) {
		q = (*L)->next;
		free(*L);
		*L = q;
	}
}

void ClearList(LinkList L)
{
	Linkist p, q;
	p = L->next;
	while (p) {
		q = p->next;
		free(p);
		q = p;
	}
	L->next = NULL;
}

Status ListEmpty(LinkList L)
{
	return L->next = NULL;
}

int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next;
	while (p) {
		++i;
		p=p->next;
	}
	return i;
}

Status GetElem(LinkList L, int i, ElemType* e)
{
	int j = 1;
	LinkList p = L->next;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j>i)
		return ERROR;
	*e = p->data;
	return OK;
}

int LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
	int i =0;
	LinkList p = L->next;
	while (p) {
		i++;
		if (compare(p->data, e))
			return i;
		p = p->next;
	}
	return 0;
}

Status PrioElem(LinkList L, ElemType cur_e, ElemType* pre_e)
{
	LinkList q, p = L->next;
	while (p->next) {
		q = p->next;
		if (q->data == cur_e) {
			*pre_e = p->data;
			return OK;
		}
		p = q;
	}
	return INFEASIBLE;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType* next_e)
{
	LinkList p = L->next;
	while (p->next) {
		if (p->data == cur_e) {
			*next_e = p->next->data;
			return OK;
		}
		p = p->next;
	}
	return INFEASIBLE;
}

Status ListInsert(LinkList L, int i, ElemType e)
{
	int j = 0;
	LinkList p = L, s;
	while (p && j<i-1) {
		p = p->next;
		j++;
	}
	if (!p || j< i-1)
 		return ERROR;
	s = (LinkList)malloc(sizeof(struct LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList L, int i, ElemType* e)
{
	int j = 0; 
	LinkList p = L, q;
	while (p->next && j < i-1) {
		p = p->next;
		j++;
	}
	if (!p->next || j >i-1)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

void ListTraverse(LinkList L, void (*vi)(ElemType))
{
	LinkList p = L->next;
	while (p) {
		vi(p->data);
		p=p->next;
	}
	printf("\n");
}

