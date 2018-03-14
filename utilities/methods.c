
/*******************************************************
   This file responsible for commend logic and checking.
 ******************************************************/

#include "../headers/methods.h"
#include "../headers/const.h"

method *MOV = &mov;
method *CMP = &cmp;
method *ADD = &add;
method *SUB = &sub;
method *NOT = &not;
method *CLR = &clr;
method *LEA = &lea;
method *INC = &inc;
method *DEC = &dec;
method *JMP = &jmp;
method *BNE = &bne;
method *RED = &red;
method *PRN = &prn;
method *JSR = &jsr;
method *RTS = &rts;
method *STOP = &stop;

_Bool check_Addressing_0(char *, int, int *);

_Bool check_Addressing_3(char *, int *);

void mov_handler(char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {
        commend cmd;
        cmd._opcode = MOV->opcode;
        int i;

        for (i = 0; i < TWO_ARGUMENTS; ++i) {
            int result;
            if ((result = check_Addressing_0(*(operands + i), line, &result))) {
                if (i == 0) {
                    cmd._src_operand = 0;
                    break;
                }
                cmd._des_operand = 0;
            } else if ((result = check_Addressing_3(*(operands + i), &result))) {
                if (i == 0) {
                    cmd._src_operand = 3;
                    break;
                }
                cmd._des_operand = 3;
            }
        }
    } else {
        return;
    }
}

void cmp_handler(char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {
        commend cmd;
        int result;
        cmd._opcode = CMP->opcode;
        check_Addressing_0(*operands, line, &result);
    } else {
        return;
    }
}

void add_handler(char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {

    } else {
        return;
    }
}

void sub_handler(char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {

    } else {
        return;
    }
}

void lea_handler(char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {

    } else {
        return;
    }
}

void not_handler(char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {

    } else {
        return;
    }
}

void clr_handler(char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {

    } else {
        return;
    }
}

void inc_handler(char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {

    } else {
        return;
    }
}

void dec_handler(char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {

    } else {
        return;
    }
}

void jmp_handler(char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {

    } else {
        return;
    }
}

void bne_handler(char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {

    } else {
        return;
    }
}

void red_handler(char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {

    } else {
        return;
    }
}

void prn_handler(char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {

    } else {
        return;
    }
}

void jsr_handler(char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {

    } else {
        return;
    }
}

void rts_handler(char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ZERO_ARGUMENTS)) {

    } else {
        return;
    }
}

void stop_handler(char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ZERO_ARGUMENTS)) {

    } else {
        return;
    }
}

void string_handler(char *op, char **operands, int line, int n) {
}

void data_handler(char *op, char **operands, int line, int n) {
}

void struct_handler(char *op, char **operands, int line, int n) {
}

void extern_handler(char *op, char **operands, int line, int n) {
}

void entry_handler(char *op, char **operands, int line, int n) {
}

_Bool check_Addressing_0(char *operand, int line, int *num) {
    if (*operand == ASTRICK) {
        int j = 1;
        if (*(operand + 1) == NEGATIVE || *(operand + 1) == POSITIVE) {
            j = 2;
        }
        char *clean_operand = (char *) malloc(sizeof(strlen(operand) - j));
        if (!clean_operand) {
            printf(SPACE_ALLOCATION_FAILED);
            exit(0);
        }
        int i;
        for (i = 0; i < strlen(operand) - 1; ++i) {
            if (i + j == strlen(operand)) {
                *(clean_operand + i) = END_OF_INPUT;
                continue;
            }
            if (!isdigit(*(operand + i + j))) {
                printf(INVALID_ADDRASSING_0, line, operand);
                return 0;
            }
            *(clean_operand + i) = *(operand + i + j);
        }
        int result = atoi(clean_operand);
        if (result == 0) {
            printf(INVALID_ADDRASSING_0, line, operand);
        } else {
            *num = result;
            return 1;
        }
    }
    return 0;
}

_Bool check_Addressing_1(char *operand) {

}

_Bool check_Addressing_2(char *operand) {

}

_Bool check_Addressing_3(char *operand, int *result) {
    if (strcmp(operand, "r0") == 0 || strcmp(operand, "r1") == 0 || strcmp(operand, "r1") == 0 ||
        strcmp(operand, "r2") == 0 || strcmp(operand, "r3") == 0 || strcmp(operand, "r4") == 0 ||
        strcmp(operand, "5") == 0) {
        if (strcmp(operand, "r0") == 0) {
            *result = 0;
        } else if (strcmp(operand, "r1") == 0) {
            *result = 1;
        } else if (strcmp(operand, "r2") == 0) {
            *result = 2;
        } else if (strcmp(operand, "r3") == 0) {
            *result = 3;
        } else if (strcmp(operand, "r4") == 0) {
            *result = 4;
        } else if (strcmp(operand, "r5") == 0) {
            *result = 5;
        } else if (strcmp(operand, "r6") == 0) {
            *result = 6;
        } else {
            *result = 7;
        }
        printf("\n\n\n");
        return 1;
    }
    return 0;
}

_Bool check_arguments(int cargs, char *op, int line, int nargs) {
    if (cargs == nargs) {
        return 1;
    } else if (cargs > nargs) {
        printf(TOO_MANY_ARGUMENTS, op, line);
    } else {
        printf(TOO_LOW_ARGUMENTS, op, line);
    }
    return 0;
}

void initialize() {

    MOV->opcode = 1;
    CMP->opcode = 2;
    ADD->opcode = 3;
    SUB->opcode = 4;
    NOT->opcode = 5;
    CLR->opcode = 6;
    LEA->opcode = 7;
    INC->opcode = 8;
    DEC->opcode = 9;
    JMP->opcode = 10;
    BNE->opcode = 11;
    RED->opcode = 12;
    PRN->opcode = 13;
    JSR->opcode = 14;
    RTS->opcode = 15;
    STOP->opcode = 16;

    int i;

    for (i = 0; i < 4; ++i) {
        MOV->op1[i] = 1;
        ADD->op1[i] = 1;
        SUB->op1[i] = 1;
        CMP->op1[i] = 1;
        NOT->op1[i] = 0;
        CLR->op1[i] = 0;
        INC->op1[i] = 0;
        DEC->op1[i] = 0;
        JMP->op1[i] = 0;
        BNE->op1[i] = 0;
        RED->op1[i] = 0;
        PRN->op1[i] = 0;
        JSR->op1[i] = 0;
        RTS->op1[i] = 0;
        STOP->op1[i] = 0;

        i > 0 && i < 3 ? (LEA->op1[i] = 1) : (LEA->op1[i] = 0);

        i > 0 ? (MOV->op2[i] = 1) : (MOV->op2[i] = 0);
        i > 0 ? (JSR->op2[i] = 1) : (JSR->op2[i] = 0);
        i > 0 ? (ADD->op2[i] = 1) : (ADD->op2[i] = 0);
        i > 0 ? (SUB->op2[i] = 1) : (SUB->op2[i] = 0);
        i > 0 ? (NOT->op2[i] = 1) : (NOT->op2[i] = 0);
        i > 0 ? (CLR->op2[i] = 1) : (CLR->op2[i] = 0);
        i > 0 ? (LEA->op2[i] = 1) : (LEA->op2[i] = 0);
        i > 0 ? (INC->op2[i] = 1) : (INC->op2[i] = 0);
        i > 0 ? (DEC->op2[i] = 1) : (DEC->op2[i] = 0);
        i > 0 ? (JMP->op2[i] = 1) : (JMP->op2[i] = 0);
        i > 0 ? (BNE->op2[i] = 1) : (BNE->op2[i] = 0);
        i > 0 ? (RED->op2[i] = 1) : (RED->op2[i] = 0);
        i > 0 ? (JSR->op2[i] = 1) : (JSR->op2[i] = 0);

        RTS->op2[i] = 0;
        STOP->op2[i] = 0;
        PRN->op2[i] = 1;
        CMP->op2[i] = 1;
    }
}
