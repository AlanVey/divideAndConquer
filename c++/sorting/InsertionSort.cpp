#include "InsertionSort.hpp"

void InsertionSort::sort(std::vector<int> &A)
{
	sortpart(A, 0, static_cast<int>(A.size())-1);
}

/******************************************************/
/*************** COMPLETE THIS FUNCTION ***************/
/******************************************************/
void InsertionSort::sortpart(std::vector<int> &A, int p, int r)
{
	for(int j = p + 1; j <= r; j++)
	{
		int key = A[j];
		int i = j - 1;
		for(; i >= p && A[i] > key; i--)
		{
			A[i+1] = A[i];
		}
		A[i+1] = key;
	}
}
