#include "HybridSort.hpp"
#include "InsertionSort.hpp"
#include "MergeSort.hpp"

#define MERGE_VS_INSERT_TURNING_POINT 350

void HybridSort::sort(std::vector<int> &A)
{
	sortpart(A, 0, static_cast<int>(A.size())-1);
}

/******************************************************/
/*************** COMPLETE THIS FUNCTION ***************/
/******************************************************/
void HybridSort::sortpart(std::vector<int> &A, int p, int r)
{
  if(p < r)
  {
    if(r - p > MERGE_VS_INSERT_TURNING_POINT)
    {
      int q = (p + r)/2;
      MergeSort::sortpart(A, p, q);
      MergeSort::sortpart(A, q + 1, r);
      MergeSort::merge(A, p, q, r);
    }
    else
    {
      InsertionSort::sortpart(A, p, r);
    }
  }
}
