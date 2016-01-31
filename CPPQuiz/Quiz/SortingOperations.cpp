#include "stdafx.h"

void BubbleSort(std::vector<int>& v)
{
	for (auto j = v.begin(); j != v.end(); ++j)
	{
		bool isSwitched = false;
		for (auto i = j + 1; i != v.end(); ++i)
		{
			if (*j > *i)
			{
				int tmp = *i;
				*i = *j;
				*j = tmp;
				isSwitched = true;
			}
		}

		if (!isSwitched)
		{
			break;
		}
	}
}

void _QuickSort(std::vector<int>& v, int left, int right)
{
	int i = left;
	int j = right;
	int p = v[(left + right) >> 1];
	while (i <= j)
	{
		while (v[i] < p)
		{
			++i;
		}

		while (p < v[j])
		{
			--j;
		}

		if (i <= j)
		{
			int tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
			++i;
			--j;
		}
	}

	if (left < j)
		_QuickSort(v, left, j);

	if (i < right)
		_QuickSort(v, i, right);
}

void QuickSort(std::vector<int>& v)
{
	if (v.size() == 0)
	{
		return;
	}

	_QuickSort(v, 0, v.size() - 1);
}