struct Tree {
	Tree* left;
	Tree* right;
};

int get_depth(Tree* t)
{
	int depth = 0;
	if (t) {
		int a = get_depth(t->left);
		int b = get_depth(t->right);		
		depth = a>b?a:b;
		depth++;
	}
	return depth;
}

int get_maxdistance(Tree* t)
{
	int maxd = 0;
	if (t) {
		maxd = get_depth(t->left) + get_depth(t->right);
		int maxdl = get_maxdistance(t->left);
		int maxdr = get_maxdistance(t->right);
		maxd = maxdl > maxd ? maxdl : maxd;
		maxd = maxdr > maxd ? maxdr : maxd;
	}
	return maxd;
}


