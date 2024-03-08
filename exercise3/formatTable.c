#include <stdbool.h>
#include <stdio.h>

enum{
    MAX_BUFF_SIZE = 128,
};

void getWordLength(FILE *file, int array[]);
void printTable(FILE *file, int array[]);
bool isValidCellContent(int x);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("provide arguments like: %s \"path_to_file\"\n", argv[0]);
        return 1;
    }
    char *filepath = argv[1];
    int longestWordForRow[MAX_BUFF_SIZE] = {0};

    FILE *file = fopen(filepath, "r");
    getWordLength(file, longestWordForRow);

    file = fopen(filepath, "r");
    printTable(file, longestWordForRow);

    fclose(file);

    return 0;
}

void getWordLength(FILE *file, int array[]){
    int currentWordLength = 0;
    int c;
    int col = 0;

    while ((c = fgetc(file)) != EOF) {
        if (c == 10) {
            if (currentWordLength > array[col]) {
                array[col] = currentWordLength;
            }
            currentWordLength = 0;
            col = 0;
            continue;
        }
        if (c == 44) {
            if (currentWordLength > array[col]) {
                array[col] = currentWordLength;
            }
            currentWordLength = 0;
            col++;
            continue;
        }
        if(isValidCellContent(c)){
            currentWordLength++;
        }
    }
}

void printTable(FILE *file, int array[]){
    int c;
    int col = 0;
    int longestWord = array[col];

    while(c = fgetc(file), c != EOF){
        if (isValidCellContent(c)) {
            printf("%c", c);
            longestWord--;
        }

        if (c == 44) {
            for (int i = 0; i < longestWord+2; i++) {
                printf("%c",32);
            }
            col++;
            longestWord = array[col];
        }

        if (c == 10) {
            col = 0;
            longestWord = array[col];
            printf("%c", c);
        }
    }
    printf("\n");
}

bool isValidCellContent(int x){
    if(((x >= 65 && x <= 90) || (x >= 97 && x <= 122)) ||
        (x >= 48 && x <= 57) || (x == 45) || (x == 46)){
        return true;
    }

    return false;
}