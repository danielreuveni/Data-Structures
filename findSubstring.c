#include <stdio.h>
#include <stdlib.h>


char* findSubstring(int begin, int end, char* string) {
    int length = end - begin + 1;
    char substring[length];
    char* ptr = substring;
    for (int i = 0; i < length; i++) {
        char c = string[begin];
        substring[i] = c;
        begin++;
    }
    return ptr; 

}

int main() {
    char* string = "hello brother!";
    int begin = 6, end = 12;
    char* substring = findSubstring(begin, end, string);
    printf("the substring of %s is %s\n",string, substring);
    return 0;
}
