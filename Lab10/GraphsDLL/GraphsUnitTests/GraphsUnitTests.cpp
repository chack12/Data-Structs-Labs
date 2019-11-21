#include "pch.h"
#include "CppUnitTest.h"
#include <list>
#include "../GraphsDLL/GraphsDLL.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphsUnitTests
{
	TEST_CLASS(GraphsUnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			GraphsDLL node;
			std::list<GraphsDLL*> listofN;
			Assert::IsTrue(node.addEdge(listofN, 1, 2));
		}
	};
}
