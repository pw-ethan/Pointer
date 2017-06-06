#include "func_str.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int compare(const char* s1, const char* s2)
{
    return strcmp(s1, s2);
}

int compareIgnoreCase(const char* s1, const char* s2)
{
    char* t1 = stringToLower(s1);
    char* t2 = stringToLower(s2);
    int result = strcmp(t1, t2);
    free(t1);
    free(t2);
    return result;
}

char* stringToLower(const char* s)
{
    char* tmp = (char*)malloc(strlen(s) + 1);
    char* start = tmp;
    while(*s){
        *tmp++ = tolower(*s++);
    }
    *tmp = 0;
    return start;
}

void sort(char* array[], int size, fptrOperation operation)
{
    int swap = 1;
    int bound = size - 1, top = bound;
    while(top > 0 && swap){
        swap = 0;
        for(int j = 0; j < top; ++j){
            if(operation(array[j], array[j + 1]) > 0){
                bound = j;
                swap = 1;
                char* tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
        top = bound;
    }
}

void displayNames(char* names[], int size)
{
    for(int i = 0; i < size; ++i){
        printf("%s  ", names[i]);
    }
    printf("\n");
}
