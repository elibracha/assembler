
/******************************************************************************

                            NAME - ELI BRACHA.
                            DATE - 2/3/2018
        This Program Functions As Assembler For A specific Assembly Language.

*******************************************************************************/


#include <stdio.h>
#define MINIMUM_ARGUMENTS 1
#define STARTUP_ERROR "Error: No File Paths Specified As Arguments.\n"

const char* convert_2bits_to_32(char*);
const char* convert_10bits_to_2(char*);
void start(int, char*[]);

int main(int argc, char* argv[]){
    argc > MINIMUM_ARGUMENTS ? start(argc, argv): printf(STARTUP_ERROR);
    return 0;
}

void start(int count, char* paths[]){

    printf("\n");
    int i;

    for (i = 1; i < count; ++i) {
        printf("%s\n", *(paths + i));
    }

    printf("%s\n", convert_10bits_to_2("100"));
    printf("%s\n", convert_2bits_to_32("0000100100"));
}