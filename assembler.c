
/******************************************************************************

                            NAME - ELI BRACHA.
                            DATE - 2/3/2018
        This Program Functions As Assembler For A specific Assembly Language.

*******************************************************************************/


#include <stdio.h>
#define MINIMUM_ARGUMENTS 1
#define STARTUP_ERROR "Error: No File Paths Specified As Arguments.\n"
#define SUCCESS_MESSAGE "Build: Success Building Output Files."

const char* convert_2bits_to_32(const char*);
const char* convert_10bits_to_2(signed int);
const _Bool file_exist(const char**);
void start_assembler(int, char **);

int main(int argc, char* argv[]){
    argc > MINIMUM_ARGUMENTS ? start_assembler(argc, argv): printf(STARTUP_ERROR);
    return 0;
}

void start_assembler(int count, char **files){
    file_exist(files);
    printf("%s\n", convert_10bits_to_2(100));
    printf("%s\n", convert_2bits_to_32(convert_10bits_to_2(100)));
    printf(SUCCESS_MESSAGE);
}