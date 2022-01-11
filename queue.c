/*************************
* Daniel Reuveni
**************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "queue.h"
#include "element.h"

/************
* Function Name: initQueue
* Input: ---
* Output: dinamic aloocation of structure called 'Queue' and pointer to 2 array: s1, s2
* Function Operation: initializing of dinamic arrays in the heap, initializing the size and the topIndex
*************/
Queue* initQueue(Queue* queue) {
	queue = (Queue*)malloc(sizeof(Queue));
	if (queue == NULL) {
		printf("Stack: initStack: Heap memory error!\n");
		return queue;
	}
	queue->s1 = initStack();
	if (queue->s1 == NULL) {
		printf("Stack: initStack: Heap memory error!\n");
		return queue->s1;
	}

	queue->s2 = initStack();
	if (queue->s2 == NULL) {
		printf("Stack: initStack: Heap memory error!\n");
		return queue->s2;
	}
	return queue;
}

/************
* Function Name: destroyQueue
* Input: the structure queue
* Output: ---
* Function Operation: free the arrays and the structure from the heap
*************/
void destroyQueue(Queue* queue) {
	destroyStack(queue->s1);
	destroyStack(queue->s2);
	if (queue != NULL)
		free(queue);
}

/************
* Function Name: isQueueEmpty
* Input: the structure queue
* Output: 1 if queue is empty, 0 if not
* Function Operation: check the size and top index of s1 and s2
*************/
int isQueueEmpty(Queue* queue) {
	if (queue->s1->topIndex == -1 && queue->s2->topIndex == -1)
		return 1;
	else
		return 0;
}

/************
* Function Name: lenOfQueue
* Input: the structure queue
* Output: the number of the elements in the queue
* Function Operation: check the topIndex of s1 and s2 and return it
*************/
int lenOfQueue(Queue* queue) {
	int lenOfQueue = 0;
	if (queue->s1->topIndex == -1 && queue->s2->topIndex == -1)
	{
		return 0;
	}
	else if (queue->s2->topIndex == -1)
	{
		return queue->s1->topIndex;
	}
	else if (queue->s1->topIndex == -1)
	{
		return queue->s2->topIndex;
	}
	else {
		lenOfQueue = queue->s2->topIndex + queue->s1->topIndex;
		return lenOfQueue;
	}
}

/************
* Function Name: capacityOfQueue
* Input: the structure queue
* Output: the number of the bytes of arrays
* Function Operation: the size * size of Element of s1 and s2
*************/
int capacityOfQueue(Queue* queue) {
	int capacityOfStack = sizeof(Element) * queue->s1->size + sizeof(Element) * queue->s2->size;
	return capacityOfStack;
}

/************
* Function Name: enqueue
* Input: the structure queue, element from the user
* Output: ---
* Function Operation: push the element from the user to the top of the queue
*************/
void enqueue(Queue* queue, Element element) {
	// if I lost the access to the arrays in case of failed realoocation, temp is save the access for it
	int* temp = queue->s1->content;
	// check if there is lot of space in the array s1 or not, realloc if yes
	if (queue->s1->size - queue->s1->topIndex == 1 || queue->s1->topIndex == -1) {
		queue->s1->content = (Element*)realloc(queue->s1->content, (queue->s1->size) * 2 * sizeof(Element));
		queue->s1->size = queue->s1->size * 2;
	}
	if (queue->s1->content == NULL) {
		printf("Stack: initStack: Heap memory error!\n");
		
	}
	// change the topIndex and size of s1
	if (queue->s1->topIndex == -1)
		queue->s1->topIndex = 1;
	else
		queue->s1->topIndex++;

	if (queue->s1->topIndex == 1)
		queue->s1->content->c = element.c;
	else {
		//move the elements down and push the element from the user in the top of s1
		for (int i = queue->s1->topIndex; i > 0; i--) {
			char* ptr;
			char* ptr2;
			ptr = queue->s1->content + sizeof(Element) * (i);
			ptr2 = queue->s1->content + sizeof(Element) * (i - 1);
			*ptr = *ptr2;
		}
		queue->s1->content->c = element.c;
	}
}

/************
* Function Name: dequeue
* Input: the structure queue
* Output: the element in the top of the queue
* Function Operation: check the pointer to the top of the queue and remove it
*************/
Element dequeue(Queue* queue) {
	Element e;
	//check if s2 is not empty and return the top element
	if (queue->s2->topIndex != -1) {
		e = pop(queue->s2);
		return e;
	}
	// move the elemnts from s1 to s2: last is the first....
	for (int i = queue->s1->topIndex; i > 0; i--) {
		Element* ptr1;
		ptr1 = queue->s1->content + sizeof(Element) * (queue->s1->topIndex - i);
		push(queue->s2, *ptr1);
	}
	// initializing again the s1 
	destroyStack(queue->s1);
	queue->s1 = initStack();
	e = pop(queue->s2);

	return e;
}

/************
* Function Name: peek
* Input: the structure queue
* Output: the element in the top of the queue
* Function Operation: check the pointer to the top of the queue
*************/
Element peek(Queue* queue) {
	Element e;
	if (queue->s2->topIndex != -1)
		e = top(queue->s2);
	else {
		char* ptr;
		ptr = queue->s1->content + sizeof(Element) * (queue->s1->topIndex - 1);
		e.c = *ptr;
	}
	return e;
}


