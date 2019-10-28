// TemplatesAndClassesDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "TemplatesAndClassesDLL.h"


// This is an example of an exported variable
TEMPLATESANDCLASSESDLL_API int nTemplatesAndClassesDLL=0;

// This is an example of an exported function.
TEMPLATESANDCLASSESDLL_API int fnTemplatesAndClassesDLL(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CTemplatesAndClassesDLL::CTemplatesAndClassesDLL()
{
    return;
}
