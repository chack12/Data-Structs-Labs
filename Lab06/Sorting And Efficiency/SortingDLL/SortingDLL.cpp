// SortingDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "SortingDLL.h"


// This is an example of an exported variable
SORTINGDLL_API int nSortingDLL=0;

// This is an example of an exported function.
SORTINGDLL_API int fnSortingDLL(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CSortingDLL::CSortingDLL()
{
    return;
}
