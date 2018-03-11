#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COMMEND_SYNTEX_ERROR "Syntex: On Line %d Commend Not Recognized (%s).\n"
#define COMMEND_CHECK_FAILURE "Error: Not Enough Space To Analyze Commends.\n"

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

void build(char *, char **, int);

void cmd_handler(char *opcmd, int line, _Bool label) {

    char *op = NULL, *lab = NULL;
    char **operands = NULL;
    unsigned short int flag = 0;
    signed short int counter = 0;
    int i, j = 0, size = 1, k = 0;;

    for (i = 0; i < strlen(opcmd) && !flag; ++i) {
        if (*(opcmd + i) == '/' && op == NULL && operands == NULL) {
            op = (char *) malloc(sizeof(char));
            operands = (char **) malloc(sizeof(char*));

            if (!op || !operands ) {
                printf(COMMEND_CHECK_FAILURE);
                exit(0);
            }
            flag = 1;
        }
        if (label && lab == NULL) {
            lab = (char *) malloc(sizeof(char));
            if (!lab) {
                printf(COMMEND_CHECK_FAILURE);
                exit(0);
            }
        }
    }

    if (op == NULL && !label)
        op = opcmd;

    if (flag) {
        flag = 0;
        for (i = 0; i <= strlen(opcmd); ++i) {
            switch (flag) {
                case 0:
                    if (label) {
                        if (*(opcmd + i) != '/') {
                            lab = (char *) realloc(lab, (size_t) size++);
                            lab[j++] = *(opcmd + i);
                        } else {
                            size = 1;
                            lab[j] = '\0';
                            j = 0;
                            flag++;
                        }
                    }
                    else{
                        flag++;
                        i--;
                    }
                    break;
                case 1:
                    if (*(opcmd + i) != '/') {
                        op = (char *) realloc(op, (size_t) ++size);
                        op[j++] = *(opcmd + i);
                    } else {
                        size = 1;
                        op[j] = '\0';
                        j = 0;
                        flag++;
                        k++;
                    }
                    break;
                default:
                    if (*(opcmd + i) != '/') {
                        if(size == 1)
                             operands[counter] = (char *) malloc(sizeof(char));
                        operands[counter] = (char *) realloc(operands[counter], (size_t) size++);
                        operands [counter][j++] = *(opcmd + i);
                    } else {
                        size = 1;
                        operands [counter][j++] = '\0';
                        counter++;
                        k++;
                        j = 0;
                    }
                    break;
            }
        }
    }

    while(--k != -1) {
        printf("%s\n",operands[k]);
    }

    build(op, operands, line);
}

void build(char *op, char **operands, int line) {
    unsigned int result = check_syntax(op, operands, line);
    commend operation;
    operation._opcode = result;
    printf("OPCODE - %d\n", operation._opcode);
}

unsigned int check_syntax(char *op, char **operands, int line) {
    if (strcmp(op, "mov") == 0) {
        return 0;
    } else if (strcmp(op, "cmp") == 0) {
        return 1;
    } else if (strcmp(op, "add") == 0) {
        return 2;
    } else if (strcmp(op, "sub") == 0) {
        return 3;
    } else if (strcmp(op, "not") == 0) {
        return 4;
    } else if (strcmp(op, "clr") == 0) {
        return 5;
    } else if (strcmp(op, "lea") == 0) {
        return 6;
    } else if (strcmp(op, "inc") == 0) {
        return 7;
    } else if (strcmp(op, "dec") == 0) {
        return 8;
    } else if (strcmp(op, "jmp") == 0) {
        return 9;
    } else if (strcmp(op, "bne") == 0) {
        return 10;
    } else if (strcmp(op, "red") == 0) {
        return 11;
    } else if (strcmp(op, "prn") == 0) {
        return 12;
    } else if (strcmp(op, "jsr") == 0) {
        return 13;
    } else if (strcmp(op, "rts") == 0) {
        return 14;
    } else if (strcmp(op, "stop") == 0) {
        return 15;
    } else if (strcmp(op, ".string") == 0) {
        return 16;
    } else if (strcmp(op, ".module") == 0) {
        return 17;
    } else if (strcmp(op, ".struct") == 0) {
        return 18;
    } else if (strcmp(op, ".entry") == 0) {
        return 19;
    } else if (strcmp(op, ".extern") == 0) {
        return 20;
    } else {
        printf(COMMEND_SYNTEX_ERROR, op);
        exit(0);
    }
}

