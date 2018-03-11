#ifndef ASSEMBLER_BUILDER_H
#define ASSEMBLER_BUILDER_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS_FILE_MESSAGE "Build: Successfully Accessed File - %s\n"
#define FAILURE_FILE_MESSAGE "Build: Shuting Down Program (File Not Found - %s)\n"
#define SPACE_ALLOCATION_FAILED "Error: Couldn't Allocate Enough Space To Parse File.\n"

#define failure_open(path) \
    printf(FAILURE_FILE_MESSAGE, path)

#define success_open(path) \
    printf(SUCCESS_FILE_MESSAGE, path)

#define _log(path, found) \
    found ? success_open (path) : failure_open(path)

enum status { OPCODE, OPRAND , INSIDE_QUOTATION_MARK, OUTSIDE_QUOTATION_MARK, COMMENT};

void handle_commend(char *, int, _Bool);
_Bool handle_label(char, enum status *, _Bool *);
void forward(signed short int *, char **);
_Bool check_for_comment(char ch, enum status *);
void handle_comment(signed short int *, char, signed short int *, _Bool *, char **, enum status *);
_Bool handle_line(signed short int *, char, signed short int *, _Bool *, char **, enum status *);
void handle_operand(signed short int*, char, signed short int*, _Bool*, char **, enum status *, enum status *);
#endif //ASSEMBLER_BUILDER_H
