template <class E, class K>
class BSTree : public BinaryTree<E> {
public:
	bool Search(const K& k, E& e) const;
	BSTree<E, K>& Insert(const E& e);
	BSTree<E, K>& Delete(const K& k, E& e);
	void Ascend() { InOutput(); }
};

template <class E, class K>
bool BSTree<E, K>::Search(const K& k, E& e) const
{
	BinaryTreeNode<E>* p = root;
	while (p) {
		if (k < p->data) p = p->LeftChild;
		else if (k > p->data) p = p->RighChild;
		else {	// hit it
			e = p->data;
			return true;
		}
	}
	return false;
}

template <class E, class K>
BSTree<E, K>& BSTree<E, K>::Insert(const E& e)
{
	BinaryTreeNode<E>* p = root;
	BinaryTreeNode<E>* pp = 0;
	// search it	
	while (p) {
		pp = p;
		if (e < p->data) p = p->LeftChild;
		else if (e > p->data) p = p->RightChild;
		else 
			throw BadInput();
	}
	// if not, insert 
	BinaryTreeNode<E>* r = new BinaryTreeNode<E>(e);
	if (root) {
		if (e < pp->data) pp->LeftChild = r;
		else pp->RightChild = r;
	} else 
		root = r;
	
	return *this;
}

template <class E, class K>
BSTree<E, K>& BSTree:Delete(const K& k, E& e)
{
	BinaryTreeNode<E>* p = root;
	BinaryTreeNode<E>* pp = 0;

	while (p && p->data!=k) {
		pp = p;
		if (k < p->data) 
			p = p->LeftChild;
		else
			p = p->RightChild;
	}

	if (!p) throw BadInput();
	e = p->data;

	if (p->LeftChild && p->RightChild) {
		// also can search until minimum element in its right child
		BinaryTreeNode<E>* s = p->LeftChild, ps = s;
		while (s->RightChild) {
			ps = s;
			s = s->RightChild;
		}
		p->data = s->data;
		p = s;
		pp = ps;
	}

	BinaryTreeNode<E>* c;
	if (p->LeftChild) 
		c = p->LeftChild;
	else
		c = p->RightChild;

	if (p==root) root = c;
	else if (p==pp->LeftChild) 
		pp->LeftChild = c;
	else
		pp->RightChild = c;

	delete p;
	return *this;
}
	
	
