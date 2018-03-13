#ifndef ASSEMBLER_METHODS_H
#define ASSEMBLER_METHODS_H

#define TWO_ARGUMENTS 2
#define ONE_ARGUMENTS 1
#define ZERO_ARGUMENTS 0

const char *two_arguments[5] = {"mov", "cmp", "add", "sub", "lea"};
const char *one_arguments[9] = {"not", "clr", "inc", "dec", "jmp", "bne", "red", "prn", "jsr"};
const char *zero_arguments[5] = {"rts", "stop"};

typedef struct {
    unsigned int _ERA : 2;
    unsigned int _des_operand : 2;
    unsigned int _src_operand : 2;
    unsigned int _opcode : 4;
} commend;

#endif
