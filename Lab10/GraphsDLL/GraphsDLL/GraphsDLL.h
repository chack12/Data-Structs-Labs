// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the GRAPHSDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// GRAPHSDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef GRAPHSDLL_EXPORTS
#define GRAPHSDLL_API __declspec(dllexport)
#else
#define GRAPHSDLL_API __declspec(dllimport)
#endif

// This class is exported from the dll
class GRAPHSDLL_API CGraphsDLL {
public:
	CGraphsDLL(void);
	// TODO: add your methods here.
};

extern GRAPHSDLL_API int nGraphsDLL;

GRAPHSDLL_API int fnGraphsDLL(void);
