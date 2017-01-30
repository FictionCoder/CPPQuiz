#include "stdafx.h"

char ToLower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		return ch + 'a' - 'A';
	}

	return ch;
}

char ToUpper(char ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		return ch - ('a' - 'A');
	}

	return ch;
}

int StrCmp(const char* str1, const char* str2)
{
	for (; (*str1 != '\0') && (*str1 == *str2); ++str1, ++str2)
	{
	}

	return (unsigned char)(*str1) - (unsigned char)(*str2);
}

int StrCmpN(const char* str1, const char* str2, unsigned int n)
{
	if (n == 0)
	{
		return 0;
	}

	for (; *str1 != '\0' && *str1 == *str2 && --n != 0; ++str1, ++str2)
	{
	}

	return *((unsigned char*)str1) - *((unsigned char*)str2);
}

void _ReverseWord(char* begin, char* end)
{
	char temp;
	while (begin < end)
	{
		temp = *begin;
		*begin = *end;
		*end = temp;
		begin++; end--;
	}
}

void ReverseWordsInSentence(char* str)
{
	char* wordBegin = str;
	char* wordEnd = str;

	while (*wordEnd != '\0')
	{
		// Step 1: reverse every char in a word
		++wordEnd;
		if (*wordEnd == '\0')
		{
			_ReverseWord(wordBegin, wordEnd - 1);
		}
		if (*wordEnd == ' ')
		{
			_ReverseWord(wordBegin, wordEnd -1);
			wordBegin = wordEnd + 1;
		}
	}

	// Step 2: reverse the whole sentence
	_ReverseWord(str, wordEnd - 1);
}

void ReverseWordsInSentenceIgnoreSpaces(char* str)
{
	char *wordBegin = nullptr;
	char *temp = str;

	while (*temp)
	{
		// Ignore space
		if ((wordBegin == NULL) && (*temp != ' '))
		{
			wordBegin = temp;
		}
		if (wordBegin != '\0' && ((*(temp + 1) == ' ') || (*(temp + 1) == '\0')))
		{
			// Step 1: reverse every char in a word.
			_ReverseWord(wordBegin, temp);
			wordBegin = nullptr;
		}

		temp++;
	}

	// Step 2: reverse the whole sentence
	_ReverseWord(str, temp - 1);
}