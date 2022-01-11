/*************************
* Daniel Reuveni
**************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "stack.h"
#include "element.h"

int SIZE = 2;

Stack* initStack(Stack* stack) {
	stack = (Stack*)malloc(sizeof(Stack));
	// if the dinamic allocation falied
	if (stack == NULL) {
		printf("Stack: initStack: Heap memory error!\n");
		return stack;
	}
	stack->content = (Element*)malloc(sizeof(Element));
	// if the dinamic allocation falied

	if (stack->content == NULL) {
		printf("Stack: initStack: Heap memory error!\n");
		return stack->content;
	}

	stack->topIndex = -1;
	stack->size = 1;

	return stack;

}

void destroyStack(Stack* stack) {
	if (stack->content != NULL)
		free(stack->content);

	if (stack != NULL)
		free(stack);
}


int isStackEmpty(Stack* stack) {
	if (stack->topIndex == -1 && stack->size == 1)
		return 1;
	else
		return 0;
}


int lenOfStack(Stack* stack) {
	return stack->topIndex;
}


int capacityOfStack(Stack* stack) {
	int capacityOfStack = sizeof(Element) * stack->size;
	return capacityOfStack;
}


void push(Stack* stack, Element element) {
	int* temp = stack->content;
	// reallocation of the stack if there is no Availability
	if (stack->size - stack->topIndex == 1 || stack->topIndex == -1) {
		stack->content = (Element*)realloc(stack->content, (stack->size) * 2 * sizeof(Element));
		stack->size = stack->size * 2;
	}
	if (stack->content == NULL) { 
		printf("Stack: initStack: Heap memory error!\n");
	}
	
	//change the topIndex after the initializing and the pushing
	if (stack->topIndex == -1)
		stack->topIndex = 1;
	else
		stack->topIndex++;

	if (stack->topIndex == 1)
		stack->content->c = element.c;
	// move the elements down to push the element from the user in the top of the stack
	else {
		for (int i = stack->topIndex; i > 0; i--) {
			char* ptr;
			char* ptr2;
			ptr = stack->content + sizeof(Element) * (i);
			ptr2 = stack->content + sizeof(Element) * (i - 1);
			*ptr = *ptr2;
		}
		stack->content->c = element.c;
	}

}

void printStack(Stack* stack) {
	for (int i = stack->topIndex; i > 0; i--) {
		char* ptr;
		ptr = stack->content + sizeof(Element) * (stack->topIndex - i);
		printf("%d: %d\n", i, *ptr);
	}
	
}

Element top(Stack* stack) {
	Element e;
	e.c = stack->content->c;
	return e;
}

Element pop(Stack* stack) {
	// if I lost the access to the array in case of failed realoocation, temp is save the access for it
	Element* temp = stack->content;
	if (stack->size - stack->topIndex >= stack->size / 2) {
		// If a lot of space is left, the function reduces the array by 2x 
		stack->content = (Stack*)realloc(stack->content, sizeof(Element) * stack->size / 2);
		stack->size = stack->size / 2;
	}

	if (stack->content == NULL) {
		printf("Stack: initStack: Heap memory error!\n");
	
	}
	// move the elements up after pop and reomving the top element
	Element e;
	if (stack->content != NULL) {
		e.c = stack->content->c;
	}
	if (stack->content != NULL) {
		for (int i = stack->topIndex; i > 0; i--) {
			char* ptr;
			char* ptr2;
			ptr = stack->content + sizeof(Element) * (stack->topIndex - i + 1);
			ptr2 = stack->content + sizeof(Element) * (stack->topIndex - i);
			*ptr2 = *ptr;
		}
	}
	stack->topIndex--;
	if (stack->topIndex == 0)
	{
		stack->size = 1;
		stack->topIndex = -1;
	}
	return e;
}

