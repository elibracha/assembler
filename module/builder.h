#ifndef ASSEMBLER_METHODS_H
#define ASSEMBLER_METHODS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TOO_MANY_ARGUMENTS "Syntex: Too Many Aruments For %s Commend (On Line - %d).\n"
#define TOO_LOW_ARGUMENTS "Syntex: Commend %s Needs More Arguments (On Line - %d).\n"
#define INVALID_ADDRASSING_0 "Syntex: Invalid Paramter in line %d (%s).\n"
#define SPACE_ALLOCATION_FAILED "Error: Couldn't Allocate Enough Space.\n"
#define MISSPLACED_ADDRESSING "Syntex: Addressing Operand Number %d , With Addressing Method Number %d (%s) Is Invalid (line - %d).\n"
#define UNKNOWN_CHAR_MIDDLE "Syntex: Invalid Char In Middle Of A Number.\n"
#define TOO_MANY_STRINGS "Syntex: To Many Aruments For String.\n"
#define NO_MARKS_AT_BEGINING "Syntex: String Data Most start With ' \" ' .\n"
#define NO_MARKS_AT_END "Syntex: String Data Most End With ' \" ' .\n"
#define EXTERN_ARGS_NUMBER "Syntex: To Many Aruments For Extern Or No Arguments. \n"
#define INVALID_LABEL_START "Syntex: Label Can't Start With '%c', Invalid (line - %d).\n"
#define INVALID_LABEL_MIDDLE "Syntex: Label Can't Contain '%c' Or Too Long, Invalid (line - %d).\n"
#define INVALID_STRUCT_START "Syntex: Struct Can't Start With '%c', Invalid (line - %d).\n "
#define INVALID_STRUCT_MIDDLE "Syntex: Struct Can't Contain '%c' Or Too Long, Invalid (line - %d).\n"
#define STRCUT_SECOND_PARAM_ERROR "Syntex: Struct Fields Most Be Address With 1 or 2, Invalid (line - %d).\n"
#define LABEL_NOT_FOUND "Syntex: Label Not Found Or Not Declared Please Fix Line - %d.\n"

#define TWO_ARGUMENTS 2
#define ONE_ARGUMENTS 1
#define ZERO_ARGUMENTS 0
#define ASTRICK '#'

typedef struct {
    unsigned int _ERA : 2;
    unsigned int _des_operand : 2;
    unsigned int _src_operand : 2;
    unsigned int _opcode : 4;
} commend;

typedef struct item {
    unsigned int opcode;
    _Bool op1[4];
    _Bool op2[4];
} method;

struct row *code = NULL;
int IC = 100, DC = 0;

method mov, add, sub, cmp, not, clr, lea, inc, dec, jmp, bne, red, prn, jsr, rts, stop;

_Bool check_Addressing_0(char *, int, int *);

_Bool check_Addressing_2(char *, int, int *);

_Bool check_Addressing_1(char *, int, _Bool);

_Bool check_Addressing_3(char *, int *);

_Bool check_arguments(int, char *, int, int, int);

char *convert_10bits_to_2(signed int, _Bool);

void insert_first_label(char *, int, _Bool, int);

void insert_last_label(char *, int, _Bool, int);

void insert_last_data(int, char *);

void insert_first_data(int, char *);

void insert_last_code(int, char *);

void insert_first_code(int, char *);

struct label *find_label(char *, int);

struct code *get_head_code();

struct data *get_head_data();

struct label *get_head_label();

void insert_ent_label(char *, int);

void handle_case(int, int);

char *plus_to_minus(char *);

char *completing_number(char *, int);

void handle_round2_c1(int, int, char **, int);

void handle_round2_c2(int, int, char **, int, int);

void handle_cmd(char *, char **, int, method *, int, int);

#endif
