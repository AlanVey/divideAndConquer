#include "MergeSort.hpp"
#include <limits.h>
#include <iostream>

void MergeSort::sort(std::vector<int> &A)
{
	sortpart(A, 0, static_cast<int>(A.size())-1);
}

/******************************************************/
/*************** COMPLETE THIS FUNCTION ***************/
/******************************************************/
void MergeSort::sortpart(std::vector<int> &A, int p, int r)
{
	if(p < r)
	{
		int q = (p + r)/2;
		sortpart(A, p, q);
		sortpart(A, q + 1, r);
		merge(A, p, q, r);
	}
}

/******************************************************/
/*************** COMPLETE THIS FUNCTION ***************/
/******************************************************/
void MergeSort::merge(std::vector<int> &A, int p, int q, int r)
{
	int len_sub_1 = q - p + 1;
	int len_sub_2 = r - q;
	std::vector<int> sub_1 (len_sub_1 + 1);
	std::vector<int> sub_2 (len_sub_2 + 1);

	for(int i = 0; i < len_sub_1; i++) { sub_1[i] = A[p + i]; }
	for(int i = 0; i < len_sub_2; i++) { sub_2[i] = A[q + i + 1]; }

	sub_1[len_sub_1] = INT_MAX;
	sub_2[len_sub_2] = INT_MAX;
	int i 					 = 0;
	int j 					 = 0;

	for(int k = p; k <= r; k++)
	{
		if(sub_1[i] <= sub_2[j])
		{
			A[k] = sub_1[i];
			i++;
		}
		else
		{
			A[k] = sub_2[j];
			j++;
		}
	}
}
