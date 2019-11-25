// HashsDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "HashsDLL.h"


// This is an example of an exported variable
HASHSDLL_API int nHashsDLL=0;

// This is an example of an exported function.
HASHSDLL_API int fnHashsDLL(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CHashsDLL::CHashsDLL()
{
    return;
}
