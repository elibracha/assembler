#ifndef ASSEMBLER_METHODS_H
#define ASSEMBLER_METHODS_H

#include <stdio.h>
#include <string.h>

#define TOO_MANY_ARGUMENTS "Syntex: Too Many Aruments For %s Commend (On Line - %d).\n"
#define TOO_LOW_ARGUMENTS "Syntex: Commend %s Needs More Arguments (On Line - %d).\n"

#define TWO_ARGUMENTS 2
#define ONE_ARGUMENTS 1
#define ZERO_ARGUMENTS 0

_Bool check_arguments(int, char*, int, int);

typedef struct {
    unsigned int _ERA : 2;
    unsigned int _des_operand : 2;
    unsigned int _src_operand : 2;
    unsigned int _opcode : 4;
} commend;

#endif
