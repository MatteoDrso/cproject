#include <stdio.h>
#include <stdlib.h>

enum{
    MAX_BUFF_SIZE=1024,
};

// unit are equal to their lowercase ascii value summed
enum Unit {
    
    //weight
    KG = 210,
    G = 103,
    LB = 206,
    OUNCES = 653,
    
    //length
    CM = 208,
    M = 109,
    KM = 216,
    FEET = 420,
    INCHES = 634,
    MILES = 538,

    // temperature
    CELSIUS = 67,
    FAHRENHEIT = 70
};

double conversionTable[MAX_BUFF_SIZE][MAX_BUFF_SIZE] = {0};
void InitConvTable();

int getUnit(char *unit);
double getVal(char *val);

int main(int argc, char *argv[]){
    if (argc != 4) {
        printf("Use like: %s \"value\" \"from Unit\" \"to Unit\"\n", argv[0]);
        return 1;
    }

    InitConvTable();
    char *InvalidUnits = "Only Units from the same set can be converted into eachother."; 
    // check which unit
    // from kg, g to lb, ounces, 
    // cm , m, km to feet, inches, miles
    // Celcius to Fahrenheit
    // in between each unit set
    // and vice versa
    double val = atof(argv[1]);
    
    int fromUnit = getUnit(argv[2]);
    int toUnit = getUnit(argv[3]);
 
    float convVal = conversionTable[fromUnit][toUnit];

    if (convVal == 0) {
        puts(InvalidUnits);
        return 1;
    }else if (fromUnit == CELSIUS) {
        printf("%f %s = %f %s\n", val, argv[2], convVal*val + 32, argv[3]);
        return 0;
    }else if (fromUnit == FAHRENHEIT) {
        printf("%f %s = %f %s\n", val, argv[2], (val-32)/convVal, argv[3]);
        return 0;
    }

    printf("%f %s = %f %s\n", val, argv[2], convVal*val, argv[3]);
    return 0;
}

void InitConvTable(){
   

    //weight
    conversionTable[KG][KG] = 1;
    conversionTable[KG][G] = 1000;
    conversionTable[KG][LB] = 2.20462;
    conversionTable[KG][OUNCES] = 35.274;

    conversionTable[G][KG] = 0.001;
    conversionTable[G][G] = 1;
    conversionTable[G][LB] = 0.00220462;
    conversionTable[G][OUNCES] = 0.035274;

    conversionTable[LB][KG] = 0.453592;
    conversionTable[LB][G] = 453.592;
    conversionTable[LB][LB] = 1;
    conversionTable[LB][OUNCES] = 16;

    conversionTable[OUNCES][KG] = 0.0283495;
    conversionTable[OUNCES][G] = 28.3495;
    conversionTable[OUNCES][LB] = 0.0625;
    conversionTable[OUNCES][OUNCES] = 1;
    
    //length
    conversionTable[CM][CM] = 1;
    conversionTable[CM][M] = 0.01;
    conversionTable[CM][KM] = 0.00001;
    conversionTable[CM][FEET] = 0.0328084;
    conversionTable[CM][INCHES] = 0.393701;
    conversionTable[CM][MILES] = 6.2137e-6;

    conversionTable[M][CM] = 100;
    conversionTable[M][M] = 1;
    conversionTable[M][KM] = 0.001;
    conversionTable[M][FEET] = 3.28084;
    conversionTable[M][INCHES] = 39.3701;
    conversionTable[M][MILES] = 0.000621371;

    conversionTable[KM][CM] = 100000;
    conversionTable[KM][M] = 1000;
    conversionTable[KM][KM] = 1;
    conversionTable[KM][FEET] = 3280.84;
    conversionTable[KM][INCHES] = 39370.1;
    conversionTable[KM][MILES] = 0.621371;

    conversionTable[FEET][CM] = 30.48;
    conversionTable[FEET][M] = 0.3048;
    conversionTable[FEET][KM] = 0.0003048;
    conversionTable[FEET][FEET] = 1;
    conversionTable[FEET][INCHES] = 12;
    conversionTable[FEET][MILES] = 0.000189394;

    conversionTable[INCHES][CM] = 2.54;
    conversionTable[INCHES][M] = 0.0254;
    conversionTable[INCHES][KM] = 0.0000254;
    conversionTable[INCHES][FEET] = 0.0833333;
    conversionTable[INCHES][INCHES] = 1;
    conversionTable[INCHES][MILES] = 1.57828e-5;

    conversionTable[MILES][CM] = 160934;
    conversionTable[MILES][M] = 1609.34;
    conversionTable[MILES][KM] = 1.60934;
    conversionTable[MILES][FEET] = 5280;
    conversionTable[MILES][INCHES] = 63360;
    conversionTable[MILES][MILES] = 1;


    // temperature
    conversionTable[CELSIUS][CELSIUS] = 1;
    conversionTable[CELSIUS][FAHRENHEIT] = 1.8;

    conversionTable[FAHRENHEIT][CELSIUS] = 1.8;
    conversionTable[FAHRENHEIT][FAHRENHEIT] = 1;
}

int getUnit(char *val){
    int x = 0;
    for (int i = 0; val[i] != '\0'; ++i) {
        x += val[i];
    }
    return x;
}

