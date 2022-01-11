#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "element.h"




int minimumFromElements(Element* elememt_array, const int SIZE) {
    Element min;
    min.c = 0;
    Stack *s1 = initStack(), *s2 = initStack();
    for (int i = 0; i < 6; i++) {
        push(s1, elememt_array[i]);
       if (i == 0) {
            min = elememt_array[0];
            push(s2, elememt_array[0]);
        }
        else if (elememt_array[i].c < min.c) {
            push(s2, elememt_array[i]);
        }
    }
    printStack(s1);
    return top(s2).c;
}

int main() {
    Element elememt_array[6];
    for (int i = 0; i < 6; i++)
        elememt_array[i].c = rand() % 100;

    
    //get the minimum from elemets in o(1)

    int min = minimumFromElements(elememt_array, 6);
    return 0;
}