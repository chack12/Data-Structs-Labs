#include "pch.h"
#include "CppUnitTest.h"
#include "../GraphsDLL/GraphsDLL.h"
#include <vector>
#include <iostream>

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
			Assert::IsFalse(graph.removeEdge(3, 1));
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
			std::vector<int> test1;
			test1.push_back(2);
			test1.push_back(0);
			test1.push_back(0);
			Graphs graph(3);
			Assert::IsTrue(graph.AddEdge(0, 1));
			Assert::IsTrue(graph.AddEdge(1, 2));
			Assert::IsTrue(graph.AddEdge(0, 2));
			Assert::IsTrue(graph.AddEdge(2, 0));

			std::vector<int> out = graph.outEdges(1);

			for (int i = 0; i < test1.size(); ++i) {
				Assert::AreEqual(out[i], test1[i]);
			}
		}

		TEST_METHOD(OutEdgeTest2) 
		{
			std::vector<int>test2;
			test2.push_back(1);
			test2.push_back(2);
			Graphs graph(3);
			Assert::IsTrue(graph.AddEdge(0, 1));
			Assert::IsTrue(graph.AddEdge(1, 2));
			Assert::IsTrue(graph.AddEdge(0, 2));
			Assert::IsTrue(graph.AddEdge(2, 0));

			std::vector<int> out = graph.outEdges(0);

			for (int i = 0; i < test2.size(); ++i) {
				Assert::AreEqual(out[i], test2[i]);
			}
		}

		TEST_METHOD(InEdgeTest1) 
		{
			std::vector<int>test1;
			test1.push_back(0);
			test1.push_back(2);
			Graphs graph(3);
			Assert::IsTrue(graph.AddEdge(0, 1));
			Assert::IsTrue(graph.AddEdge(1, 2));
			Assert::IsTrue(graph.AddEdge(0, 2));

			std::vector<int> out = graph.inEdges(1);

			for (int i = 0; i < test1.size(); ++i) {
				Assert::AreEqual(out[i], test1[i]);
			}
		}

		TEST_METHOD(InEdgeTest2) 
		{
			std::vector<int>test2;
			test2.push_back(1);
			test2.push_back(0);
			Graphs graph(3);
			Assert::IsTrue(graph.AddEdge(0, 1));
			Assert::IsTrue(graph.AddEdge(1, 2));
			Assert::IsTrue(graph.AddEdge(0, 2));

			std::vector<int> out = graph.inEdges(2);

			for (int i = 0; i < test2.size(); ++i) {
				Assert::AreEqual(out[i], test2[i]);
			}
		}
	};
}
