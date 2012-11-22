#include "trie.h"
#include "stdio.h"
#include "string.h"

void testFind(trieADT trie)
{
	const char* testStr = 0;
	const char* array[] = {"amy", "amyk", "ann", "abbb", "bcccc"};
	int i = 0;
	for (i = 0; i < sizeof(array)/sizeof(const char*); i++)
	{
		testStr = array[i];
		if (TrieIsMember(trie, testStr))
		{
			printf("%s is in trie!\n", testStr);
		}
		else
		{
			printf("%s is not in trie!\n", testStr);
		}
	}
}

void testTrie()
{
	trieADT trie;
	trie = TrieCreate();

	TrieAdd(trie, "amy", 56);
	TrieAdd(trie, "amyk", 90);
	TrieAdd(trie, "ann", 15);
	TrieAdd(trie, "abbb", 90);
	TrieAdd(trie, "bccccc", 90);
	printf("======================\n");
	TriePrint(trie);

	printf("Test search...\n");
	testFind(trie);

	TrieRemove(trie, "amy");
	TrieRemove(trie, "abbb");
	testFind(trie);

	TrieDestroy(trie);
}


int main()
{
	testTrie();
	return 0;
}

