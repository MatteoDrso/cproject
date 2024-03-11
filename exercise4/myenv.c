#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

enum{
    MAX_BUFF_SIZE = 64,
};

extern char **environ;

bool isValidEnv(char *envVar);

int main(int argc, char *argv[]){
    if (argc == 1) {
        // print out env variablen 
        int counter = 0;
        while (environ[counter] != NULL) {
            printf("%s\n", environ[counter]);
            counter++;
        }
        return 0;
    }

    
    bool nonKVread = false;
    for (int i=1; i < argc; i++) {  
        if (isValidEnv(argv[i]) && !nonKVread) {
            printf("%s is now envVar\n", argv[i]);
            putenv(argv[i]);
        }else {
            execvp(argv[i], argv + i);
            nonKVread =true;
        }
    }

    return 0;
}

bool isValidEnv(char *envVar){
    char c;
    int counter = 0;
    bool isValidEnvVar = false;
    while (c = envVar[counter], c != '\0') {
        if(c == '=' && counter != 0){// '=' is not first char
            // check for isPrint(envVar[counter+1])?
            isValidEnvVar = envVar[counter+1] != '\0'; // '=' is not last char
        }
        if (isValidEnvVar) {
            break;
        }
        counter++;
    }
    return isValidEnvVar;
}

