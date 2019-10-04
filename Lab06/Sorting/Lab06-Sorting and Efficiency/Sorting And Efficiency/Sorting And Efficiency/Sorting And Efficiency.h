// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the SORTINGANDEFFICIENCY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// SORTINGANDEFFICIENCY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SORTINGANDEFFICIENCY_EXPORTS
#define SORTINGANDEFFICIENCY_API __declspec(dllexport)
#else
#define SORTINGANDEFFICIENCY_API __declspec(dllimport)
#endif

// This class is exported from the dll
class SORTINGANDEFFICIENCY_API CSortingAndEfficiency {
public:
	CSortingAndEfficiency(void);
	// TODO: add your methods here.
};

extern SORTINGANDEFFICIENCY_API int nSortingAndEfficiency;

SORTINGANDEFFICIENCY_API int fnSortingAndEfficiency(void);
