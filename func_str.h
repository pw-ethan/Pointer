#ifndef FUNC_STR_H_INCLUDED
#define FUNC_STR_H_INCLUDED

int compare(const char* s1, const char* s2);
int compareIgnoreCase(const char* s1, const char* s2);
char* stringToLower(const char* s);
typedef int (fptrOperation)(const char*, const char*);
void sort(char* array[], int size, fptrOperation operation);
void displayNames(char* names[], int size);


#endif // FUNC_STR_H_INCLUDED
