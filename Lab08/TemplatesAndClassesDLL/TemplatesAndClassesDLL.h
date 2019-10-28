// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the TEMPLATESANDCLASSESDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// TEMPLATESANDCLASSESDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

// This class is exported from the dll
class TEMPLATESANDCLASSESDLL_API CTemplatesAndClassesDLL {
public:
	CTemplatesAndClassesDLL(void);
	// TODO: add your methods here.
};

extern TEMPLATESANDCLASSESDLL_API int nTemplatesAndClassesDLL;

TEMPLATESANDCLASSESDLL_API int fnTemplatesAndClassesDLL(void);
