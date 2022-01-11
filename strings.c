/*************************
* Daniel Reuveni
**************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "strings.h"
#include "element.h"
#include "stack.h"


int isLegalString(char str[]) {
	int i = 0;
	Stack* stack = initStack();
	while (str[i] != '\0') {
		//sheck if there is left bracket in the string
		if (str[i] == '(' || str[i] == '[' || str[i] == '{' || str[i] == '<') {
			Element b;
			b.c = str[i];
			// if there is, push it
			push(stack, b);
			i++;
		}
		// check if there is right bracket in the string and compare its to the top element in the stack
		// if there is compitable bracket, remove it form the top of the stack
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}' || str[i] == '>') {
			Element a;
			a = top(stack);
			if (a.c == '(' && str[i] == ')') {
				a = pop(stack); 
				i++;
			}
			else if (a.c == '[' && str[i] == ']') {
				a = pop(stack); 
				i++;
			}
			else if (a.c == '{' && str[i] == '}') {
				a = pop(stack);
				i++;
			}
			else if (a.c == '<' && str[i] == '>') {
				a = pop(stack); 
				i++;
			}
			else
				i++;
		}
		else
			i++;


	}
	// return 1 if stack is empty and string is valid, 0 if not and free the stack
	if (isStackEmpty(stack) == 1) {
		destroyStack(stack);
		return 1;
	}
	else {
		destroyStack(stack);
		return 0;
	}
}
