#include "HybridSort.hpp"
#include "InsertionSort.hpp"
#include "MergeSort.hpp"

#define TURNING_POINT 360

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
    int q = (p + r)/2;
    bool sub1 = q - p + 1 > TURNING_POINT;
    bool sub2 = r - q     > TURNING_POINT;
    if(sub1 && sub2)
    {
      sortpart(A, p, q);
      sortpart(A, q + 1, r);
      MergeSort::merge(A, p, q, r);
    }
    else if(!sub1)
    {
      InsertionSort::sortpart(A, p, q);
      sortpart(A, q + 1, r);
      MergeSort::merge(A, p, q, r);
    }
    else if(!sub2)
    {
      sortpart(A, p, q);
      InsertionSort::sortpart(A, q + 1, r);
      MergeSort::merge(A, p, q, r);
    }
    else
    {
      InsertionSort::sortpart(A, p, q);
      InsertionSort::sortpart(A, q + 1, r);
      MergeSort::merge(A, p, q, r);
    } 
  }
}
