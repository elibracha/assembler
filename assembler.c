
/******************************************************************************

                            NAME - ELI BRACHA.
                            DATE - 2/3/2018
        This Program Functions As Assembler For A specific Assembly Language.

*******************************************************************************/


#include <stdio.h>
#define MINIMUM_ARGUMENTS 1

const char* convert2BitsTo32(char*);
const char* convert10BitsTo2(char*);
void start(int, char*[]);

int main(int argc, char* argv[]){
    if(argc > MINIMUM_ARGUMENTS)
        start(argc, argv);
    else
        printf("Error: No File Paths Specified As Arguments.");
    return 0;
}

void start(int count, char* args[]){
    printf("\n");
    for (int i = 1; i < count; ++i) {
        printf("%s\n", *(args + i));
    }

    printf("%s\n", convert10BitsTo2("100"));
    printf("%s\n", convert2BitsTo32("0000100100"));
}
