#include "lab4_priority_queue.hpp"

using namespace std;

// PURPOSE: Parametric constructor 
// initializes heap to an array of (n_capacity + 1) elements
PriorityQueue::PriorityQueue(unsigned int n_capacity) {
	//heap = new TaskItem*[n_capacity + 1];
}

// PURPOSE: Explicit destructor of the class PriorityQueue
PriorityQueue::~PriorityQueue() {
    /*
	for(int i = 0; i < size; i++) {
		if(heap[i] != NULL) {
			heap[i] = NULL;
			delete heap[i];
		}
	}
	delete [] heap;
     */
}

// PURPOSE: Returns the number of elements in the priority queue
unsigned int PriorityQueue::get_size() const {
	return size;
}

// PURPOSE: Returns true if the priority queue is empty; false, otherwise
bool PriorityQueue::empty() const {
	return size == 0;
}

// PURPOSE: Returns true if the priority queue is full; false, otherwise
bool PriorityQueue::full() const {
	return size == capacity;
}

// PURPOSE: Prints the contents of the priority queue; format not specified
void PriorityQueue::print() const {

}

// PURPOSE: Returns the max element of the priority queue without removing it
// if the priority queue is empty, it returns (-1, "N/A")
PriorityQueue::TaskItem PriorityQueue::max() const {
    if(empty()) {
        return TaskItem(-1, "N/A");
    } else {
        return **heap;
    }
}

// PURPOSE: Inserts the given value into the priority queue
// re-arranges the elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::enqueue( TaskItem val ) {
	// Check if heap is at capacity or empty
	/*
	if(full()) {
		return false;
	} else if(empty()) {
		heap[0] = new TaskItem(val.priority, val.description);
		size++;
		return true;
	}
	// Insert to end of array
    heap[size] = new TaskItem(val.priority, val.description);
	size++;

	int childIndex = size;
	int parentIndex = (size - 1) / 2;
    // Restore heap property
    while(heap[parentIndex]->priority < heap[childIndex]->priority) {
    	TaskItem* temp = heap[parentIndex];
    	heap[parentIndex] = heap[childIndex];
    	heap[childIndex] = temp;
		childIndex = parentIndex;
		parentIndex = (childIndex - 1) / 2;
    }
    return true;
    */
}

// PURPOSE: Removes the top element with the maximum priority
// re-arranges the remaining elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::dequeue() {
	/*
	if(empty()) {
		return true;
	} else if(size == 1) {
		delete heap[0];
		size--;
		return true;
	}

	// Remove top element
	delete heap[0];
	// Copy last element to index 0 and decrement size
	heap[0] = heap[size - 1];
	heap[size - 1] = NULL;
	size--;
	// Restore heap property
	int parentIndex = 0;
	int leftChildIndex = 1;
	int rightChildIndex = 2;
	while((heap[leftChildIndex] && heap[parentIndex]->priority < heap[leftChildIndex]->priority) || (heap[rightChildIndex] && heap[parentIndex]->priority < heap[rightChildIndex]->priority)) {
		if(heap[leftChildIndex] && heap[rightChildIndex]) {
			if(heap[leftChildIndex]->priority < heap[rightChildIndex]->priority) {
				TaskItem* temp = heap[rightChildIndex];
				heap[rightChildIndex] = heap[parentIndex];
				heap[parentIndex] = temp;
				parentIndex = rightChildIndex;
				leftChildIndex = (parentIndex * 2) + 1;
				rightChildIndex = (parentIndex * 2) + 2;
			}
		}
		if(heap[leftChildIndex] && heap[parentIndex]->priority < heap[leftChildIndex]->priority) {

		} else if(heap[rightChildIndex] && heap[parentIndex]->priority < heap[rightChildIndex]->priority) {

		}
	}

	return false;
	 */
}
