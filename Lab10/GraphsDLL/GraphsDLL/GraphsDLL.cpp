// GraphsDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "GraphsDLL.h"


// This is an example of an exported variable
GRAPHSDLL_API int nGraphsDLL=0;

// This is an example of an exported function.
GRAPHSDLL_API int fnGraphsDLL(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CGraphsDLL::CGraphsDLL()
{
    return;
}
