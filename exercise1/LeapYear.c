#include <stdio.h>
#include <stdlib.h>

int leapYear(int year){
    
    if (year%400 == 0 || (year%4 == 0 && !(year%100 == 0))) {
        printf("The year %d is a leap year\n", year);
        return 1;
    }
    printf("The year %d is not a leap year\n", year);
    return 0;
}

int main(int argc, char *argv[]){

    if(argc >= 1){
        int year = atoi(argv[1]);
        leapYear(year);
    }

    return 0;
}