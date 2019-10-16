// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the BINARYSEARCHTREES_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// BINARYSEARCHTREES_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BINARYSEARCHTREES_EXPORTS
#define BINARYSEARCHTREES_API __declspec(dllexport)
#else
#define BINARYSEARCHTREES_API __declspec(dllimport)
#endif

// This class is exported from the dll
class BINARYSEARCHTREES_API CBinarySearchTrees {
public:
	CBinarySearchTrees(void);
	// TODO: add your methods here.
};

extern BINARYSEARCHTREES_API int nBinarySearchTrees;

BINARYSEARCHTREES_API int fnBinarySearchTrees(void);
