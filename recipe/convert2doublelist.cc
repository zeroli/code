struct BSTreeNode
{
	int m_value;
	BSTreeNode* m_pLeft;
	BSTreeNode* m_pRight;
};

BSTreeNode* convert(BSTreeNode* phead, bool asRight)
{
	if (!phead)
		return NULL;
	BSTreeNode* pLeft = 0, *pRight=0;
	if (phead->m_pLeft)
		pLeft = convert(phead->m_pLeft, false);
	if (pLeft) {
		pLeft->m_pRight = phead;
		phead->m_pLeft = pLeft;
	}
	if (phead->m_pRight) 
		pRight = convert(phead->m_pRight, true);
	if (pRight) {
		pRight->m_pLeft = phead;
		phead->m_pRight = pRight;
	}
	BSTreeNode* ptmp = phead;
	if (asRight) {
		while (ptmp->m_pLeft) {
			ptmp = ptmp->m_pLeft;
		}
	} else {	
		while (ptmp->m_pRight) {
			ptmp = ptmp->m_pRight;
		}
	}
	return ptmp;
}

BSTreeNode* convert2doublelist(BSTreeNode* phead)
{
	return convert(phead, true);
}
	
	
