#define _CRT_SECURE_NO_WARNINGS
#include "WordSpellingChecker.h"

int parseWordsToTable(char* path, HashTable* ht);
SpellingSuggestion* spellingCheck(char* text);
/*
	Add help functions here...
*/

int main()
{
	char* text = "iam afraid youare about to become teh immexdiate pst president of teh eing alive club ha ha glados";
	SpellingSuggestion* spellingSuggestions = spellingCheck(text);
	printSpellingSuggestions(spellingSuggestions);
	return 0;
}
