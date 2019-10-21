// BinarySearchTreesDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "BinarySearchTreesDLL.h"


// This is an example of an exported variable
BINARYSEARCHTREESDLL_API int nBinarySearchTreesDLL=0;

// This is an example of an exported function.
BINARYSEARCHTREESDLL_API int fnBinarySearchTreesDLL(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CBinarySearchTreesDLL::CBinarySearchTreesDLL()
{
    return;
}
