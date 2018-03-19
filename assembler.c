
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

void write_code_list(char *);

void write_data_list(char *);

void write_label_list(char *);

int main(int argc, char *argv[]) {
    initialize();
    argc > MINIMUM_ARGUMENTS ? start_assembler(argv) : printf(STARTUP_ERROR);
    return 0;
}

void start_assembler(char **files) {

    while (*++files) {
        if (validate_files(*files)) {
            assemble(*files);
            char *code_data = (char *) malloc(sizeof(char) * strlen(*files));
            char *ext = (char *) malloc(sizeof(char) * strlen(*files));
            char *ent = (char *) malloc(sizeof(char) * strlen(*files));
            strcpy(code_data, *files);
            code_data[strlen(code_data) - 1] = 0;
            code_data[strlen(code_data) - 2] = 0;
            strcpy(ext, code_data);
            strcpy(ent, code_data);
            strcat(code_data, ".ob");
            write_code_list(code_data);
            write_data_list(code_data);
            strcat(ext, ".ext");
            write_label_list(ext);
            printf(SUCCESS_MESSAGE);
        }
    }
}