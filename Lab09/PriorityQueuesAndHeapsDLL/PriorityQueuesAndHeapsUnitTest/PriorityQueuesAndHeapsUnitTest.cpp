#include "pch.h"
#include "CppUnitTest.h"
#include "../PriorityQueuesAndHeapsDLL/PriorityQueuesAndHeapsDLL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PriorityQueuesAndHeapsUnitTest
{
	TEST_CLASS(PriorityQueuesAndHeapsUnitTest)
	{
	public:
		
		//Unit test for Inserting into a priority queue.
		TEST_METHOD(PriorityQueueWithQueueInsert)
		{
			// Initialize Priority queue of size 3.
			PriorityQueuesWithQueue priorityQueue(3);

			// Insert values inside the priority queue.
			priorityQueue.Insert(3);
			priorityQueue.Insert(1);
			priorityQueue.Insert(4);

			std::string temp = priorityQueue.PrintQueue();

			// Testing that the output of the queue will match the string below in comparison.
			Assert::AreEqual(temp, std::string("1 3 4"));
		}

		//Unit test for removing from a priority queue.
		TEST_METHOD(PriorityQueueWithQueueRemove)
		{
			//Initialize Priority queue of size 3.
			PriorityQueuesWithQueue priorityQueue(3);

			// Insert values inside the priority queue.
			priorityQueue.Insert(3);
			priorityQueue.Insert(1);
			priorityQueue.Insert(4);

			//Remove the first value from the priority queue.
			priorityQueue.Remove();

			std::string temp = priorityQueue.PrintQueue();

			// Testing that the output of the queue will match the string below when removing the first value.
			Assert::AreEqual(temp, std::string("3 4"));
		}

		// Unit test for inserting into a priority queue with heap.
		TEST_METHOD(PriorityQueueWithHeapInsert)
		{
			//Initialize priority queue of size 3.
			PriorityQueuesWithHeap priorityQueue(3);
			
			// Insert values inside.
			priorityQueue.Insert(3);
			priorityQueue.Insert(1);
			priorityQueue.Insert(4);

			std::string temp = priorityQueue.PrintHeap();

			// Testing that the insert method is correct with the comparative string below.
			Assert::AreEqual(temp, std::string("4 1 3"));
		}

		// Unit test for removing from a priority queue with heap.
		TEST_METHOD(PriorityQueueWithHeapRemove)
		{
			// Initialize queue of size 3.
			PriorityQueuesWithHeap priorityQueue(3);

			//Inserting values into queue.
			priorityQueue.Insert(3);
			priorityQueue.Insert(1);
			priorityQueue.Insert(4);

			//Remove the first value from the queue.
			priorityQueue.Remove();

			std::string temp = priorityQueue.PrintHeap();

			// Testing that the remove method works and the printed heap matches the corresponding string below.
			Assert::AreEqual(temp, std::string("3 1"));
		}
	};
}
