#ifndef _TRIE_H_
#define _TRIE_H_

typedef int bool;
typedef int trieValueT;

typedef struct trieNodeTag
{
	char key;
	trieValueT value;
	struct trieNodeTag* next, *children;
} trieNodeT;

typedef struct trieCDT {
	trieNodeT* root;
} trieCDT;

typedef struct trieCDT* trieADT;

trieADT TrieCreate();
void TrieAdd(trieADT trie, const char* str, trieValueT val);
bool TrieIsMemeber(trieADT trie, const char* str);
void TrieRemove(trieADT trie, const char* str);
void TrieDestory(trieADT trie);

#endif

