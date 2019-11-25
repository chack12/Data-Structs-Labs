// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the HASHSDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// HASHSDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef HASHSDLL_EXPORTS
#define HASHSDLL_API __declspec(dllexport)
#else
#define HASHSDLL_API __declspec(dllimport)
#endif

// This class is exported from the dll
class HASHSDLL_API CHashsDLL {
public:
	CHashsDLL(void);
	// TODO: add your methods here.
};

extern HASHSDLL_API int nHashsDLL;

HASHSDLL_API int fnHashsDLL(void);
