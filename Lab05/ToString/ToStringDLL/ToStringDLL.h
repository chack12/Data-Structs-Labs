// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the TOSTRINGDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// TOSTRINGDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TOSTRINGDLL_EXPORTS
#define TOSTRINGDLL_API __declspec(dllexport)
#else
#define TOSTRINGDLL_API __declspec(dllimport)
#endif

// This class is exported from the dll
class TOSTRINGDLL_API CToStringDLL {
public:
	CToStringDLL(void);
	// TODO: add your methods here.
};

extern TOSTRINGDLL_API int nToStringDLL;

TOSTRINGDLL_API int fnToStringDLL(void);
