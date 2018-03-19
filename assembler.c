
/******************************************************************************

                            NAME - ELI BRACHA.
                            DATE - 2/3/2018
        This Program Functions As Assembler For A specific Assembly Language.

*******************************************************************************/


#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MINIMUM_ARGUMENTS 1
#define STARTUP_ERROR "Error: No File Paths Specified As Arguments.\n"
#define SUCCESS_MESSAGE "Build: Success Building Files.\n"

void initialize();

void assemble(char *);

_Bool validate_files(char *);

void start_assembler(char **);

void write_code_list(char*);

void write_data_list(char *);

int main(int argc, char *argv[]) {
    initialize();
    argc > MINIMUM_ARGUMENTS ? start_assembler(argv) : printf(STARTUP_ERROR);
    return 0;
}

void start_assembler(char **files) {
    while (*++files) {
        if (validate_files(*files)) {
            assemble(*files);
            char *name = (char*) malloc(sizeof(char) * strlen(*files));
            strcpy(name, *files);
            name[strlen(name)-1] = 0;
            name[strlen(name)-2] = 0;
            strcat(name, ".txt");
            write_code_list("prog.txt");
            write_data_list("prog.txt");
            printf(SUCCESS_MESSAGE);
        }
    }
}