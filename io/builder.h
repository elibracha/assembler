#ifndef ASSEMBLER_BUILDER_H
#define ASSEMBLER_BUILDER_H

#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

#define SUCCESS_FILE_MESSAGE "Build: File Was Found - %s.\n"
#define FAILURE_FILE_MESSAGE "Build: File Not Found - %s.\n"
#define FILE_EXTENSION "Build: File Extenstion Is Incorrect Checking Next File (%s).\n"
#define SPACE_ALLOCATION_FAILED "Error: Couldn't Allocate Enough Space To Parse File.\n"

#define failure_open(path) \
    printf(FAILURE_FILE_MESSAGE, path)

#define success_open(path) \
    printf(SUCCESS_FILE_MESSAGE, path)

#define _log(path, found) \
    found ? success_open (path) : failure_open(path)

#define extension(file, result) \
{\
    char *extension = NULL;\
    if((extension = strrchr(file,'.')) != NULL ) {\
        if(strcmp(extension,".as") != 0) {\
            printf(FILE_EXTENSION, extension);\
            result = 0;\
        }\
    }\
}

enum status {OPCODE, OPRAND, COMMENT};
enum sub_status {INSIDE_QUOTATION_MARK, OUTSIDE_QUOTATION_MARK};

void handle_commend(char *, int, _Bool);
_Bool handle_label(char, enum status *, _Bool *);
void forward(signed short int *, char **);
_Bool check_for_comment(char ch, enum status *);
void mem_check(char **);
void handle_comment(signed short int *, char, signed short int *, _Bool *, char **, enum status *);
_Bool handle_line(signed short int *, char, signed short int *, _Bool *, char **, enum status *);
void handle_operand(signed short int*, char, signed short int*, _Bool*, char **, enum status *, enum sub_status *);
void handle_opcode(signed short int*, char, signed short int*, _Bool*, char **, enum status *);

#endif //ASSEMBLER_BUILDER_H
