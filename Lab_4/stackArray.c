#include <stdio.h>
#include <stdlib.h>

// Data structure to represent a stack
typedef struct Stack
{
    float items;
	struct Stack* next;
} Stack;
 
Stack* head = NULL;
 
// Utility function to initialize the stack
Stack* newStack(float capacity)
{
    Stack* pStack = (Stack*) malloc(sizeof(Stack));
 
    if(pStack != NULL) {
		pStack->items = capacity;
		pStack->next = NULL;
	}
    return pStack;
}
 
// Utility function to return the size of the stack
int size() {
    int sizeCount = 0;
	Stack* ptr = head;
	while(ptr != NULL) {
		sizeCount++;
		ptr = ptr->next;
	}
	return sizeCount;
}
 
// Utility function to check if the stack is empty or not
int isEmpty() {
    if(head == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
 
// Utility function to check if the stack is full or not
int isFull() {
	return (malloc(sizeof(Stack)) == NULL);
}
 
// Utility function to add an element `x` to the stack
int push(float x)
{
	Stack* ptr = newStack(x);
    // check if the stack is already full. Then inserting an element would
    // lead to stack overflow
    if (isFull())
    {
        printf("Stack Full!\n");
        return -1;
    }
 
    printf("Inserting %f\n", x);

    // add an element and increment the top's index
    if(head == NULL) {
		head = ptr;
		return 0;
	}
	else {
		ptr->next = head;
		head = ptr;
		return 0;
	}
}
 
// Utility function to pop a top element from the stack
int pop()
{
	Stack* top = head;
    // check for stack underflow
    if (isEmpty())
    {
        printf("Stack Empty!\n");
        return -1;
    }
 
    // remove element decrement stack size by 1
    printf("Removing %f\n", head->items);
	head = head->next;
	free(top);
    return 0;
}
 
// Utility function to peek at top element from the stack
int peek(float* x)
{
    // check for stack underflow
    if (isEmpty())
    {
        printf("Stack Empty!\n");
        return -1;
    }
 
    // return top of stack value
    *x = head->items;
    return *x;
}
 
int main() {
    // create a stack of capacity 5
    float value;
 
    push(1.0);
    push(2.0);
    push(3.0);
 
    printf("The stack size is %d\n", size());

    peek(&value);
    printf("Top val on stack is %f\n", value);

    pop();
    pop();
    pop();
 
    if (isEmpty()) {
        printf("The stack is empty\n");
    }
    else {
        printf("The stack is not empty\n");
    }
 
    return 0;
}
