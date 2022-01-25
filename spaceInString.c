#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* removeSpaces (char* S) {
    //printf("%c", *S++);
    int i = 0, j = 0;
    while (S[i] != '1') {
        if (S[i] != ' '){
        S[j] = S[i];
        j++;
        }
        i++;
    }
    S[j] = '\0';

    return S;
}


int main () {
    char S[1000] = "hello     m ggg f            wre 62             6                        1           h jiof s sdfd              \n";
    printf("The new string is %s\n", removeSpaces(S));
    return 0;
}