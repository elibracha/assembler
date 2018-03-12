#ifndef ASSEMBLER_COMMEND_H
#define ASSEMBLER_COMMEND_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COMMEND_SYNTEX_ERROR "Syntex: On Line %d Commend Not Recognized (%s).\n"
#define COMMEND_CHECK_FAILURE "Error: Not Enough Space To Analyze Commends.\n"
#define SPACE_ALLOCATION_FAILED "Error: Couldn't Allocate Enough Space To Varibles.\n"

unsigned int syntex(char *, char **, int);
void build_data(char *, char **, int);
void mov_handler(char, char**, int);
void cmp_handler(char, char**, int);
void add_handler(char, char**, int);
void sub_handler(char, char**, int);
void lea_handler(char, char**, int);
void not_handler(char, char**, int);
void clr_handler(char, char**, int);
void inc_handler(char, char**, int);
void dec_handler(char, char**, int);
void jmp_handler(char, char**, int);
void bne_handler(char, char**, int);
void red_handler(char, char**, int);
void prn_handler(char, char**, int);
void jsr_handler(char, char**, int);
void rts_handler(char, char**, int);
void stop_handler(char, char**, int);

#endif //ASSEMBLER_COMMEND_H
