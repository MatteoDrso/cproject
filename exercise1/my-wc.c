#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

    int c;
    int countChars = 0, countWords = 0, countLines = 1;

    while(c = getchar(), c != EOF){
        countChars++;
        if(c == 10) countLines++;
        if(c == 32) countWords++;
    }

    printf("%i, %i, %i\n", countChars, countWords, countLines);

    return (0);

}
