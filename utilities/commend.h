#ifndef ASSEMBLER_COMMEND_H
#define ASSEMBLER_COMMEND_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COMMEND_SYNTEX_ERROR "Syntex: On Line %d Commend Not Recognized (%s).\n"
#define COMMEND_CHECK_FAILURE "Error: Not Enough Space To Analyze Commends.\n"
#define SPACE_ALLOCATION_FAILED "Error: Couldn't Allocate Enough Space To Varibles.\n"

#define MOV_ARGUMENTS 2
#define CMP_ARGUMENTS 2
#define ADD_ARGUMENTS 2
#define SUB_ARGUMENTS 2
#define LEA_ARGUMENTS 2
#define NOT_ARGUMENTS 1
#define CLR_ARGUMENTS 1
#define INC_ARGUMENTS 1
#define DEC_ARGUMENTS 1
#define JMP_ARGUMENTS 1
#define BNE_ARGUMENTS 1
#define RED_ARGUMENTS 1
#define PRN_ARGUMENTS 1
#define JSR_ARGUMENTS 1
#define RTS_ARGUMENTS 0
#define STOP_ARGUMENTS 0

typedef struct {
    unsigned int _ERA : 2;
    unsigned int _des_operand : 2;
    unsigned int _src_operand : 2;
    unsigned int _opcode : 4;
} commend;

unsigned int check_syntax(char *, char **, int);
void build_data(char *, char **, int);

#endif //ASSEMBLER_COMMEND_H
