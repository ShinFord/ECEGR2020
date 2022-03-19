#include <stdio.h>
#include <stdlib.h>
// Data structure to represent a queue
typedef struct Queue
{
    float items;
	struct Queue* next;
} Queue;
 
Queue* head = NULL;

// Utility function to initialize the queue
Queue* newQueue(float capacity)
{
    Queue* pQueue = (Queue*) malloc(sizeof(Queue));
 
    if (pQueue != NULL) {
		pQueue->items = capacity;
		pQueue->next = NULL;
	}
 
    return pQueue;
}
 
// Utility function to return the size of the queue
int size() {
    int sizeCount = 0;
	Queue* ptr = head;
	while(ptr != NULL) {
		sizeCount++;
		ptr = ptr->next;
	}
	return sizeCount;
}
 
// Utility function to check if the queue is empty or not
int isEmpty() {
    if(head == NULL) {
		return 1;
	}
	else {
		return 0;
	}     
}
 
// Utility function to check if the queue is full or not
int isFull() {
    return (malloc(sizeof(Queue)) == NULL);
}
 
// Utility function to add an element `x` to the queue
int insert(float x)
{
	Queue* newPtr = newQueue(x);
	Queue* ptr = head;
	
    // check if the queue is already full
    if (isFull())
    {
        printf("Queue Full!\n");
        return -1;
    }
 
    printf("Inserting %f\n", x);
 
    // add an element to queue
    if(head == NULL) {
		head = newPtr;
		return 0;
	}
	else {
		while(ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = newPtr;
		newPtr->next = NULL;
		return 0;
	}
}
 
// Utility function to remove an element from the queue
int queueRemove()
{
	Queue* ptr = head;
    // check for queue underflow
    if (isEmpty())
    {
        printf("Queue Empty!\n");
        return -1;
    }
 
    // remove element decrement queue size by 1
    printf("Removing %f\n", head->items);
	head = head->next;
	free(ptr);
    return 0;
}
 
// Utility function to peek at first element from the queue
int peek(float* x)
{
    // check for queue underflow
    if (isEmpty())
    {
        printf("Queue Empty!\n");
        return -1;
    }
 
    // return front of queue value
    *x = head->items;
    return 0;
}
 
int main()
{
    // create a queue of capacity 5
    float  value;
 
    insert(1.0);
    insert(2.0);
    insert(3.0);
 
    printf("The queue size is %d\n", size());
    peek(&value);
    printf("Top val on queue is %f\n", value);
    queueRemove();
    queueRemove();
    queueRemove();
 
    if (isEmpty()) {
        printf("The queue is empty\n");
    }
    else {
        printf("The queue is not empty\n");
    }
 
    return 0;
}