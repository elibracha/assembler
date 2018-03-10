#include <stdio.h>
#include <mem.h>
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

int check_syntax(char *, char*, char*, int);
void build(char*, char*, char*, int);

void cmd_handler(char *opcmd, int line ){

    char *op = NULL, *operand1 = NULL, *operand2 = NULL;
    signed short int flag = 0;
    int i, j = 0, size = 1;

    for (i = 0; i < strlen(opcmd); ++i) {
        if (*(opcmd + i) == '/'){
            op = (char*) malloc(sizeof(char));
            operand1 = (char*) malloc(sizeof(char));
            operand2 = (char*) malloc(sizeof(char));
            flag = 1;
        }
    }

    if(op == NULL)
        op = opcmd;

    if(flag){
        flag = 0;
        for (i = 0; i <= strlen(opcmd); ++i) {
            if(!op || !operand1 || !operand2) {
                printf(COMMEND_CHECK_FAILURE);
                exit(0);
            }
            if(i == strlen(opcmd)){
                switch(flag){
                    case 0:
                        op = (char *) realloc(op, (size_t) ++size);
                        op[j++] = '\0';
                        break;
                    case 1:
                        operand1 = (char *) realloc(operand1, (size_t) ++size);
                        operand1[j++] = '\0';
                        break;
                    case 2:
                        operand2 = (char *) realloc(operand2, (size_t) ++size);
                        operand2[j++] = '\0';
                }
            }
            switch (flag) {
                case 0:
                    if (*(opcmd + i) != '/') {
                        op = (char *) realloc(op, (size_t) ++size);
                        op[j++] = *(opcmd + i);
                    } else {
                        size = 1;
                        op[j] = '\0';
                        j = 0;
                        flag++;
                    }
                    break;
                case 1:
                    if (*(opcmd + i) != '/') {
                        operand1 = (char *) realloc(operand1, (size_t) size++);
                        operand1[j++] = *(opcmd + i);
                    }else {
                        size = 1;
                        op[i] = '\0';
                        j = 0;
                        flag++;
                    }
                    break;
                case 2:
                    if (*(opcmd + i) != '/'){
                        operand2 = (char *) realloc(operand2, (size_t) size++);
                        operand2[j++] = *(opcmd + i);
                    }else{
                        size = 1;
                        op[i] = '\0';
                        j = 0;
                        flag++;
                    }
                    break;
            }
        }
    }

    build(op, operand1, operand2, line);
}

void build(char *op, char *operand1, char *operand2, int line) {
    int result = check_syntax(op, operand1, operand2, line);
    commend operation;
    operation. _opcode = result;
    printf("OPCODE - %d\n" , operation._opcode);
}

int check_syntax(char *op, char *operand1, char *operand2, int line){
    if(strcmp(op, "mov") == 0){
        return 0;
    }else if(strcmp(op, "cmp") == 0){
        return 1;
    }else if(strcmp(op, "add") == 0){
        return 2;
    }else if(strcmp(op, "sub") == 0){
        return 3;
    }else if(strcmp(op, "not") == 0){
        return 4;
    }else if(strcmp(op, "clr") == 0){
        return 5;
    }else if(strcmp(op, "lea") == 0){
        return 6;
    }else if(strcmp(op, "inc") == 0){
        return 7;
    }else if(strcmp(op, "dec") == 0){
        return 8;
    }else if(strcmp(op, "jmp") == 0){
        return 9;
    }else if(strcmp(op, "bne") == 0){
        return 10;
    }else if(strcmp(op, "red") == 0){
        return 11;
    }else if(strcmp(op, "prn") == 0){
        return 12;
    }else if(strcmp(op, "jsr") == 0){
        return 13;
    }else if(strcmp(op, "rts") == 0){
        return 14;
    }else if(strcmp(op, "stop") == 0){
        return 15;
    }else{
        printf(COMMEND_SYNTEX_ERROR, line, op);
        exit(0);
    }
}