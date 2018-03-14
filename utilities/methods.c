
/*******************************************************
   This file responsible for commend logic and checking.
 ******************************************************/

#include "../headers/methods.h"

void mov_handler(char *op, char **operands, int line, int n) {
    if(check_arguments(n, op, line, TWO_ARGUMENTS)){

    }else{
        return;
    }
}

void cmp_handler(char *op, char **operands, int line, int n) {
    if(check_arguments(n, op, line, TWO_ARGUMENTS)){

    }else{
        return;
    }
}

void add_handler(char *op, char **operands, int line, int n) {
    if(check_arguments(n, op, line, TWO_ARGUMENTS)){

    }else{
        return;
    }
}

void sub_handler(char *op, char **operands, int line, int n) {
    if(check_arguments(n, op, line, TWO_ARGUMENTS)){

    }else{
        return;
    }
}

void lea_handler(char *op, char **operands, int line, int n) {
    if(check_arguments(n, op, line, TWO_ARGUMENTS)){

    }else{
        return;
    }
}

void not_handler(char *op, char **operands, int line, int n) {
    if(check_arguments(n, op, line, ONE_ARGUMENTS)){

    }else{
        return;
    }
}

void clr_handler(char *op, char **operands, int line, int n) {
    if(check_arguments(n, op, line, ONE_ARGUMENTS)){

    }else{
        return;
    }
}

void inc_handler(char *op, char **operands, int line, int n) {
    if(check_arguments(n, op, line, ONE_ARGUMENTS)){

    }else{
        return;
    }
}

void dec_handler(char *op, char **operands, int line, int n) {
    if(check_arguments(n, op, line, ONE_ARGUMENTS)){

    }else{
        return;
    }
}

void jmp_handler(char *op, char **operands, int line, int n) {
    if(check_arguments(n, op, line, ONE_ARGUMENTS)){

    }else{
        return;
    }
}

void bne_handler(char *op, char **operands, int line, int n) {
    if(check_arguments(n, op, line, ONE_ARGUMENTS)){

    }else{
        return;
    }
}

void red_handler(char *op, char **operands, int line, int n) {
    if(check_arguments(n, op, line, ONE_ARGUMENTS)){

    }else{
        return;
    }
}

void prn_handler(char *op, char **operands, int line, int n) {
    if(check_arguments(n, op, line, ONE_ARGUMENTS)){

    }else{
        return;
    }
}

void jsr_handler(char *op, char **operands, int line, int n) {
    if(check_arguments(n, op, line, ONE_ARGUMENTS)){

    }else{
        return;
    }
}

void rts_handler(char *op, char **operands, int line, int n) {
    if(check_arguments(n, op, line, ZERO_ARGUMENTS)){

    }else{
        return;
    }
}

void stop_handler(char *op, char **operands, int line, int n) {
    if(check_arguments(n, op, line, ZERO_ARGUMENTS)){

    }else{
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

_Bool check_arguments(int cargs, char *op, int line, int nargs){
    if(cargs == nargs) {


    }else if(cargs > nargs) {
        printf(TOO_MANY_ARGUMENTS, op, line);
    }else{
        printf(TOO_LOW_ARGUMENTS, op, line);
    }
}

