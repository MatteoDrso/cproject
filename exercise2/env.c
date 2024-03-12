#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool isEnvVar(char *s){
    for(int i = 0; i < sizeof(s)-1; i++){
        if(s[i] == '=') return true;
    }
    return false;
}


int main(int argc, char *argv[]){

    int counter = 1;

    extern char **environ;

    if(argc==1) {
        while(true){
            if(environ[counter] == NULL)
                break;
            puts(environ[counter]);
            counter++;
        }
    } else {
        while(isEnvVar(argv[counter])){
            putenv(argv[counter]);
            counter++;
        }
    }
    return 0;
}
