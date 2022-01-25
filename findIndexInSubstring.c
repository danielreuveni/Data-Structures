#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int findIndex(char* S, char* B) {
    char *e;
    char *result = strstr(S, B);
    int position = result - S;
    int substringLength = strlen(S) - position;
    return position;
}


int main () {
    char* S = "Hi there! I'm using Whatsapp!";
    char* B = "Hi";
    printf("The starting index of the substring is %d\n", findIndex(S, B));
    return 0;
}