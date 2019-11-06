#include "pch.h"
#include "CppUnitTest.h"
#include "../PriorityQueuesAndHeapsDLL/PriorityQueuesAndHeapsDLL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PriorityQueuesAndHeapsUnitTest
{
	TEST_CLASS(PriorityQueuesAndHeapsUnitTest)
	{
	public:
		
		TEST_METHOD(PriorityQueueWithQueueInsert)
		{
			PriorityQueuesWithQueue priorityQueue(3);

			priorityQueue.Insert(3);
			priorityQueue.Insert(1);
			priorityQueue.Insert(4);

			Assert::AreEqual(priorityQueue.PrintQueue(), "1 3 4");
		}

		TEST_METHOD(PriorityQueueWithQueueRemove)
		{
			PriorityQueuesWithQueue priorityQueue(3);

			priorityQueue.Insert(3);
			priorityQueue.Insert(1);
			priorityQueue.Insert(4);

			priorityQueue.Remove(3);

			Assert::AreEqual(priorityQueue.PrintQueue(), "1 4");
		}

		TEST_METHOD(PriorityQueueWithHeapInsert)
		{
			PriorityQueuesWithHeap priorityQueue(3);

			priorityQueue.Insert(3);
			priorityQueue.Insert(1);
			priorityQueue.Insert(4);

			Assert::IsEqual(priorityQueue.PrintHeap(), "1 3 4");
		}

		TEST_METHOD(PriorityQueueWithHeapRemove)
		{
			PriorityQueuesWithHeap priorityQueue(3);

			priorityQueue.Insert(3);
			priorityQueue.Insert(1);
			priorityQueue.Insert(4);

			priorityQueue.Remove(3);

			Assert::IsEqual(priorityQueue.PrintHeap(), "1 4");
		}
	};
}
