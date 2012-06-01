typedef struct DulNode {
	ElemType data;
	struct DulNode* prio, *next;
} DulNode, *DuLinkList;


void InitList(DuLinkList *L)
{
	*L = (DuLinkList)malloc(sizeof(DulNode));
	if (*L) 
		(*L)->next = (*L)->prio = *L;
	else
		exit(OVERFLOW);
}

void DestoryList(DuLinkList *L)
{
	DuLinkList q, p = (*L)->next;
	while (p!=*L) {
		q = p->next;
		free(p);
		p = q;
	}
	free(*L);
	*L = NULL;
}

void ClearList(DuLinkList L)
{
	DuLinkList q, p = L->next;
	while (p!=L) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = L->prio = L;
}

Status ListEmpty(DuLinkList L)
{
	if (L->next == L && L->prior == L)
		return TRUE;
	else
		return FALSE;
}

int ListLength(DuLinkList L)
{
	int i = 0;
	DuLinkList p = L->next;
	while (p!=L) {
		i++;
		p = p->next;
	}
	return i;
}

Status GetElem(DuLinkList L, int i, ElemType* e)
{
	int j = 1;
	DuLinkList p = L->next;
	while (p!=L && j < i)
		p = p->next;
		j++;
	}
	if (p==L || j > i) 
		return ERROR;
	*e = p->data;
	return OK;
}

int LocateElem(DuLinkList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
	int i = 0;
	DuLinkList p = L->next;
	while (p!=L) {
		i++;
		if (compare(p->data,e))
			return i;
		p = p->next;
	}

	return 0;
}

Status PrioElem(DuLinkList L, ElemType cur_e, ElemType* pre_e)
{
	DuLinkList p = L->next->next;
	while (p!=L) {
		if (p->data == cur_e) {
			*pre_e = p->prior->data;
			return TRUE;
		}
		p = p->next;
	}
	return FALSE;
}

Status NextElem(DuLink L, ElemType cur_e, ElemType* next_e)
{
	DuLinkList p = L->next->next;
	while (p!=L) {
		if (p->prior->data == cur_e) {
			*next_e = p->data;
			return TRUE;
		}
		p = p->next;
	}
	return FALSE;
}

DuLinkList GetElemP(DuLinkList L, int i)
{
	int j;
	DuLinkList p = L;
	if (i < 0 || i> ListLength(L))
		return NULL;
	for (j = 1; j <= i; j++)
		p = p->next;
	return p;
}

Status ListInsert(DuLinkList L, int i, ElemType e)
{
	DuLinkList p, s;
	if (i < 1 || i > ListLength(L)+1) 
		return ERROR;
	p = GetElemP(L, i-1);
	if (!p)
		return ERROR;
	s = (DuLinkList)malloc(sizeof(DuLNode));
	if (!s) 
		return OVERFLOW;
	s->data = e;
	s->prior = p;
	s->next = p->next;
	p->next->prior = s;
	p->next = s;
	return OK;
}

Status ListDelete(DuLinkList L, int i, ElemType* e)
{
	DuLinkList p;
	if (i<1)
		return ERROR;
	p = GetElemP(L, i);
	if (!p)
		return ERROR;
	*e = p->data;
	p->prior->next = p->next;
	p->next->prio = p->prior;
	free(p);
	return OK;
}

void ListTraverse(DuLinkList L, void (*visit)(ElemType))
{
	DuLinkList p = L->next;
	while (p!=L) {
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}

void ListTraverseBack(DuLinkList L, void (*visit)(ElemtType))
{
	DuLinkList p = L->prior;
	while (p!=L) {
		visit(p->data);
		p = p->prior;
	}
	printf("\n");
}

		
