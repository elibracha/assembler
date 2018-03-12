#ifndef ASSEMBLER_METHODS_H
#define ASSEMBLER_METHODS_H

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

#endif
