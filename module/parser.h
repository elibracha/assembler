#ifndef ASSEMBLER_COMMEND_H
#define ASSEMBLER_COMMEND_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COMMEND_SYNTEX_ERROR "Syntex: On Line %d Commend Not Recognized (%s).\n"
#define COMMEND_CHECK_FAILURE "Error: Not Enough Space To Analyze Commends.\n"
#define SPACE_ALLOCATION_FAILED "Error: Couldn't Allocate Enough Space To Varibles.\n"
#define CONNA_AT_THE_END "Syntex: Unecpected End Of Input, Comma At The End. (line - %d)\n"
#define TOO_MANY_COMMAS "Syntex: Too Many Commas, Missing Parameters. (line - %d)\n"

unsigned int build_data(char*, char *, char **, int, int, int);

void mov_handler(char*, char *, char **, int, int, int);

void cmp_handler(char*, char *, char **, int, int, int);

void add_handler(char*, char *, char **, int, int, int);

void sub_handler(char*, char *, char **, int, int, int);

void lea_handler(char*, char *, char **, int, int, int);

void not_handler(char*, char *, char **, int, int, int);

void clr_handler(char*, char *, char **, int, int, int);

void inc_handler(char*, char *, char **, int, int, int);

void dec_handler(char*, char *, char **, int, int, int);

void jmp_handler(char*, char *, char **, int, int, int);

void bne_handler(char*, char *, char **, int, int, int);

void red_handler(char*, char *, char **, int, int, int);

void prn_handler(char*, char *, char **, int, int, int);

void jsr_handler(char*, char *, char **, int, int, int);

void rts_handler(char*, char *, char **, int, int, int);

void stop_handler(char*, char *, char **, int, int, int);

void string_handler(char*, char **, int, int);

void data_handler(char*, char **, int, int);

void struct_handler(char*, char **, int, int);

void extern_handler(char*, char **, int);

void entry_handler(char*, char *, char **, int, int);

#endif //ASSEMBLER_COMMEND_H
