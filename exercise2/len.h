#include <stdio.h>

int lenInt(int array[]){
    size_t arrayLength = sizeof(array) / sizeof(array[0]);
    return arrayLength;
}

int lenChar(char array[]){
    size_t arrayLength = sizeof(array) / sizeof(array[0]);
    return arrayLength;
}