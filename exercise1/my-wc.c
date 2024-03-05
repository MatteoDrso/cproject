#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

    int c;
    int countChars = 0, countWords = 0, countLines = 0;

    while(c = getchar(), c != EOF){
        countChars++;
        if(c == 10){
            countLines++;
            countWords++;
        }
        if(c == 32) countWords++;
    }

    printf("%i, %i, %i\n", countChars, countWords, countLines); //result is faulty depending on whether the file has a trailing '\n' or not.

    return (0);

}
