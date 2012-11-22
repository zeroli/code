#include "trie.h"

#include "stdio.h"
#include "stdlib.h"

trieNodeT* createNode(char key, trieValueT val)
{
	trieNodeT* node = (trieNodeT*)malloc(sizeof(trieNodeT));
	node->key = key;
	node->value = val;
	node->next = node->children = NULL;
//	printf("create node '%c'\n", key);
	return node;
}

trieADT TrieCreate()
{
	trieADT trie = (trieADT)malloc(sizeof(trieCDT));
	memset(trie, 0, sizeof(trieCDT));
	trie->root = createNode('\0', 0);
	return trie;
}

void destroyNode(trieNodeT* node)
{
	trieNodeT* children = NULL;
	trieNodeT* next = NULL;
	if (node == NULL) return;

	next = node->next;
	children = node->children;

	free(node);

	if (children) destroyNode(children);

	node = next;
	while (node) {
		next = node->next;
		destroyNode(node);
		node = next;
	}
}

void TrieDestroy(trieADT trie)
{
	trieNodeT* node = trie->root;
	destroyNode(node);
	free(trie);
}


void TrieAdd(trieADT trie, const char* name, trieValueT val)
{
	printf("Add %s to trie.\n", name);
	trieNodeT* parent = trie->root;
	trieNodeT* level = parent->children;
	int i = 0;
	for (; ; i++) {
		if (level == NULL)
		{
			level = parent->children = createNode(name[i], 0);	
			if (name[i] == '\0')
			{
				level->value = val;
				break;
			}
			parent = level;	
			level = parent->children;
			continue;
		}
		trieNodeT* found = NULL, *prev = level, *curr;
		for (curr = prev; curr != NULL; curr = curr->next)
		{
			if (curr->key == name[i]) {
				found = curr;
				break;
			}
			prev = curr;
		}
		if (found == NULL)
		{
			parent = prev->next = createNode(name[i], 0);

			level = parent->children;
		}
		else
		{
			level = found->children;
		}
		if (name[i] == '\0')
		{
			found->value = val;
			break;
		}
	}
	printf("Add done\n");

}

bool removeNodeRecur(trieNodeT* pnode, const char* key, int pos)
{
	if (pnode == NULL) return 0;

	trieNodeT* node = pnode->children;
	if (node == NULL) return 0;

	trieNodeT* found = NULL;
	trieNodeT* curr, *prev = node;
	for (curr = prev; curr != NULL; curr = curr->next)
	{
		if (curr->key == key[pos])
		{
			found = curr;
			break;
		}
		prev = curr;
	}
	if (found == NULL) 
	{
		printf("remove node '%c' failed\n", key[pos]);
		return 0;
	}
	
	if ((key[pos] == '\0') ||
		removeNodeRecur(found, key, pos+1))
	{
		prev->next = curr->next;
		if (curr == node) pnode->children = curr->next; 
		free(found);
		printf("remove node '%c' done\n", key[pos]);
		return (pnode->children ? 0 : 1);
	}
	return 0;
}

void TrieRemove(trieADT trie, const char* name)
{
	printf("Remove %s from trie\n", name);

	trieNodeT* level = trie->root;
	
	removeNodeRecur(level, name, 0);
}

bool TrieIsMember(trieADT trie, const char* name)
{
	trieNodeT* level = trie->root->children;
	int i = 0;
	for (; ;) {
		trieNodeT* found = NULL;
		trieNodeT* curr;
		for (curr = level; curr != NULL; curr=curr->next)
		{
			if (curr->key == name[i]) {
				found = curr;
				break;
			}
		}

		if (found == NULL)
			return 0;
		
		if (name[i] == '\0')
			return 1;

		level = found->children;
		i++;
	}
}


void TriePrint(trieADT trie)
{
	trieNodeT* level = trie->root->children;
	while (level) {
		trieNodeT* curr = level;
		for (curr = level; curr != NULL; curr = curr->next)
		{
			printf("%c ", curr->key);
		}
		printf("\n");
		level = level->children;
	}
	printf("====================\n");
}

