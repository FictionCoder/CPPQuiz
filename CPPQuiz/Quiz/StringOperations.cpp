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
	for (; (*str1 != '\0') && (*str1 == *str2); ++ str1, ++str2)
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