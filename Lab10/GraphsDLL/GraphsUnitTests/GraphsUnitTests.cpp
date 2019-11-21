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
		TEST_METHOD(ConstructorTest1)
		{
			Graphs graph();
		}

		TEST_METHOD(ConstructorTest1)
		{
			Graphs graph(1, 3);
		}

		TEST_METHOD(AddEdgeTest1) 
		{

		}

		TEST_METHOD(AddEdgeTest2) 
		{

		}

		TEST_METHOD(RemoveEdgeTest1) 
		{

		}

		TEST_METHOD(RemoveEdgeTest2) 
		{

		}

		TEST_METHOD(HasEdgeTest1) 
		{

		}

		TEST_METHOD(HasEdgeTest2) 
		{

		}

		TEST_METHOD(OutEdgeTest1) 
		{

		}

		TEST_METHOD(OutEdgeTest2) 
		{

		}

		TEST_METHOD(InEdgeTest1) 
		{

		}

		TEST_METHOD(InEdgeTest2) 
		{

		}
	};
}
