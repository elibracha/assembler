#ifndef ASSEMBLER_METHODS_H
#define ASSEMBLER_METHODS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TOO_MANY_ARGUMENTS "Syntex: Too Many Aruments For %s Commend (On Line - %d).\n"
#define TOO_LOW_ARGUMENTS "Syntex: Commend %s Needs More Arguments (On Line - %d).\n"
#define INVALID_ADDRASSING_0 "Syntex: Invalid Paramter in line %d (%s).\n"
#define SPACE_ALLOCATION_FAILED "Error: Couldn't Allocate Enough Space To Varibles.\n"
#define MISSPLACED_ADDRESSING "Syntex: Addressing Operand Number %d , With Addressing Method Number %d (%s) Is Invalid (line - %d).\n"

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

struct row * code = NULL;
int IC = 100, DC = 0;

method mov, add, sub, cmp, not, clr, lea, inc, dec, jmp, bne, red, prn, jsr, rts, stop;

#endif
