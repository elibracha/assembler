
/********************************************
   This file responsible for IO management.
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <mem.h>

#define SUCCESS_FILE_MESSAGE "Build: Successfully Accessed File - %s\n"
#define FAILURE_FILE_MESSAGE "Build: Shuting Down Program (File Not Found - %s)\n"
#define SPACE_ALLOCATION_FAILED "Error: Couldn't Allocate Enough Space To Parse File.\n"
#define COMMEND_SYNTEX_ERROR "Syntex: On line %d Commend Not Recognized - %s\n"

#define MOVE_ARGUMENTS 2
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

#define failure_open(path) \
    printf(FAILURE_FILE_MESSAGE, path)

#define success_open(path) \
    printf(SUCCESS_FILE_MESSAGE, path)

#define _log(path , found) \
    found ? success_open (path) : failure_open(path)


typedef struct unit{
    unsigned int ERA : 2;
    unsigned int _des_operand : 2;
    unsigned int _src_operand : 2;
    unsigned int _opcode : 4;
} commend;

enum status {OPCODE, OPRAND, COMMA};

void file_exist(char** files){

    while(*++files){

        _Bool flag = 0;
        FILE * file = fopen(*files, "r+");

        file != NULL ? _log(*files, ++flag) : _log(*files, flag);

        if(file != NULL) fclose(file);

        if (!flag) exit(0);
    }

}

void parse(char** paths){

    while(*++paths){
        FILE * fd = fopen(*paths, "r+");

        signed short int size = 1;
        char* unit = (char*) malloc((size_t) sizeof(char));

        enum status state = OPCODE;
        int line = 1;

        while (!feof(fd)){
            if(!unit){
                printf(SPACE_ALLOCATION_FAILED);
                exit(0);
            }

            _Bool flag = 0;
            char ch = fgetc(fd);

            switch (state){
                case OPCODE:
                    if(isspace(ch) || ch == '\t' || flag){
                        unit = (char *) realloc(unit, sizeof(char) * size);
                        *(unit + size++ - 1) = '\0';

                        if(strcmp(unit, "move") == 0){
                            printf("equal\n");
                            size = 1;
                            flag = 0;
                            free(unit);
                            char* unit = (char*) malloc((size_t) sizeof(char));
                        }else{
                            printf(COMMEND_SYNTEX_ERROR, line, unit);
                            free(unit);
                            exit(0);
                        }

                        state = OPRAND;
                    }
                    else{
                        *(unit + size++ - 1) = ch;
                        unit = (char *) realloc(unit, sizeof(char) * size);
                        if(ch == '\n'){
                            flag = 1;
                            line++;
                        }
                    }
                    break;
            }
        }
    }

}

