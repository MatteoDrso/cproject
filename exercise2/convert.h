#ifndef convert
#define convert

int myatoi(char c){
    int x = c;
    if(x >= 48 && x <= 57){
        return x-48;
    }
    return x;   
}

char myitoa(int i){
    char c = i;
    return c;
}

#endif
