#include <iostream>
#include <algorithm>
#include <cstdlib>

typedef int Object;


template <typename Comparable>
class BinarySearchTree 
{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& rhs);
	~BinarySearchTree();

	const Comparable& findMin() const;
	const Comparable& findMax() const;
	bool contains(const Comparable& x) const;
	bool isEmpty() const;
	void printTree() const;

	void makeEmpty();
	void insert(const Comparable& x);
	void remove(const Comparable& x);

	const BinarySearchTree& operator=(const BinarySearchTree& rhs);

private:
	struct BinaryNode 
	{
		Object element;
		BinaryNode* left;
		BinaryNode* right;

		BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt)
		: element(theElement), left(lt), right(rt) {}
	};

	BinaryNode* root;
	
	void insert(const Comparable& x, BinaryNode*& t) const;
	void remove(const Comparable& x, BinaryNode*& t) const;
	BinaryNode* findMin(BinaryNode* t) const;
	BinaryNode* findMax(BinaryNode* t) const;
	bool contains(const Comparable& x, BinaryNode* t) const;
	vid makeEmpty(BinaryNode*& t);
	void printTree(BinaryNode* t) const;
	BinaryNode* clone(BinaryNode* t) const;
};

bool BinarySearchTree::contains(const Comparable& x) const
{
	return contains(x, root);
}

void BinarySearchTree::insert(const Comparable& x)
{
	insert(x, root);
}

void BinarySearchTree::remove(const Comparable& x)
{
	remove(x, root);
}

bool BinarySearchTree::contains(const Comparable& x, BinaryNode* t) const
{
	if (t==NULL)
		return false;
	else if (x < t->element) 
		return contains(x, t->left);
	else if (t->element < x)
		return contains(x, t->right);
	else 
		return true;
}

bool BinarySearchTree::findMin(BinaryNode* t) const
{
	if (t == NULL) 
		return NULL;
	if (t->left == NULL)
		return t;
	return findMin(t->left);
}

bool BinarySearchTree::findMax(BinaryNode* t) const
{
	if (t == NULL)
		while (t->right) 
			t = t->right;
	return t;
}

void BinarySearchTree::remove(const Comparable& x, BinaryNode*& t)
{
	if (t==NULL)
		return;
	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != NULL && t->right != NULL) {
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	} else {
		BinaryNode* oldNode = t;
		t = (t->left!=NULL) ? t->left : t->right;
		delete oldNode;
	}
}

BinarySearchTree::~BinarySearchTree()
{
	makeEmpty();
}

void BinarySearchTree::makeEmpty(BinaryNode*& t)
{
	if (t) {
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}

const BinarySearchTree& BinarySearchTree::operator =(const BinarySearchTree& rhs)
{
	if (this != &rhs) {
		makeEmpty();
		root = clone(rhs.root);
	}
	return *this;
}

BinaryNode* BinarySearchTree::clone(BinaryNode* t) const
{
	if (t==NULL)
		return NULL;
	return new BinarySearchTree(t->element, clone(t->left), clone(t->right));
}

		
	
