#pragma once
#include <vector>
using namespace std;

// Binary operations
extern bool IsPowerOf2(unsigned int value);
extern int CountBit(int value);

// String operations
extern char ToLower(const char ch);
extern int StrCmp(const char* str1, const char* str2);
extern int StrCmpN(const char* str1, const char* str2, unsigned int n);

// Linked list operations
#include "Quiz\LinkedListOperations.h"

// Sorting operations
extern void BubbleSort(std::vector<int>& v);
extern void QuickSort(std::vector<int>& v);

// BST opertions
#include "Quiz\BSTOperations.h"