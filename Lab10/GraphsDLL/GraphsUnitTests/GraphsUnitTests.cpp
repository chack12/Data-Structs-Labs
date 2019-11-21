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

		TEST_METHOD(ConstructorTest2)
		{
			Graphs graph(3);
		}

		TEST_METHOD(AddEdgeTest1) 
		{
			Graphs graph(3);
			Assert::IsTrue(graph.AddEdge(0, 1));
			Assert::IsTrue(graph.AddEdge(1, 2));
			Assert::IsFalse(graph.AddEdge(0, 5));
			Assert::IsFalse(graph.AddEdge(5, 4));
		}

		TEST_METHOD(AddEdgeTest2) 
		{
			Graphs graph(3);
			Assert::IsTrue(graph.AddEdge(0, 1));
			Assert::IsTrue(graph.AddEdge(1, 2));
			Assert::IsTrue(graph.AddEdge(0, 2));
			Assert::IsTrue(graph.AddEdge(2, 0));
		}

		TEST_METHOD(RemoveEdgeTest1) 
		{
			Graphs graph(3);
			Assert::IsTrue(graph.AddEdge(0, 1));
			Assert::IsTrue(graph.AddEdge(1, 2));
			Assert::IsTrue(graph.removeEdge(0, 1));
			Assert::IsTrue(graph.removeEdge(1, 2));
		}

		TEST_METHOD(RemoveEdgeTest2) 
		{
			Graphs graph(3);
			Assert::IsTrue(graph.AddEdge(0, 1));
			Assert::IsTrue(graph.AddEdge(1, 2));
			Assert::IsFalse(graph.removeEdge(0, 4));
			Assert::IsTrue(graph.removeEdge(3, 1));
		}

		TEST_METHOD(HasEdgeTest1) 
		{
			Graphs graph(3);
			Assert::IsTrue(graph.AddEdge(0, 1));
			Assert::IsTrue(graph.AddEdge(1, 2));
			Assert::IsTrue(graph.hasEdge(0, 1));
			Assert::IsTrue(graph.hasEdge(1, 2));
		}

		TEST_METHOD(HasEdgeTest2) 
		{
			Graphs graph(3);
			Assert::IsTrue(graph.AddEdge(0, 1));
			Assert::IsTrue(graph.AddEdge(1, 2));
			Assert::IsFalse(graph.hasEdge(0, 5));
			Assert::IsFalse(graph.hasEdge(4, 2));
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
