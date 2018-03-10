
/********************************************
   This file responsible for IO management.
 ********************************************/

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS_FILE_MESSAGE "Build: Successfully Accessed File - %s\n"
#define FAILURE_FILE_MESSAGE "Build: Shuting Down Program (File Not Found - %s)\n"
#define SPACE_ALLOCATION_FAILED "Error: Couldn't Allocate Enough Space To Parse File.\n"

#define failure_open(path) \
    printf(FAILURE_FILE_MESSAGE, path)

#define success_open(path) \
    printf(SUCCESS_FILE_MESSAGE, path)

#define _log(path , found) \
    found ? success_open (path) : failure_open(path)

enum status {OPCODE, OPRAND};

void cmd_handler(char*,int);

void file_exist(char** files){

    while(*++files){

        _Bool flag = 0;
        FILE * file = fopen(*files, "r+");

        file != NULL ? _log(*files, ++flag) : _log(*files, flag);

        if(file != NULL) fclose(file);

        if (!flag) exit(0);
    }

}

void assemble(char **paths){

    while(*++paths){
        FILE * fd = fopen(*paths, "r+");

        signed short int size = 1;
        char* commend = (char*) malloc((size_t) sizeof(char));

        enum status state = OPCODE;
        int line = 1;

        while (!feof(fd)){
            if(!commend){
                printf(SPACE_ALLOCATION_FAILED);
                exit(0);
            }

            char ch = (char) fgetc(fd);

            switch (state){
                case OPCODE:
                    if(ch == ' '  || ch == '\t' || ch == -1 || ch == '\n'){
                        if(size > 1){
                            *(commend + size - 1) = '/';
                            state = OPRAND;
                            if(ch == '\n'){
                                *(commend + size - 1) = '\0';
                                printf("%s\n", commend);
                                state = OPCODE;
                                cmd_handler(commend,line);
                                free(commend);
                                commend = (char*) malloc((size_t) sizeof(char));
                                size = 1;
                                line++;
                                break;
                            }
                        } else {
                            if(ch == '\n')
                                line++;
                            continue;
                        }
                    }
                    else
                        *(commend + size - 1) = ch;

                    size++;
                    commend = (char *) realloc(commend, sizeof(char) * size);
                    break;

                case OPRAND:
                    if(ch == ' ' || ch == '\t')
                        continue;
                    if (ch == '\n' || ch == -1) {
                        *(commend + size - 1) = '\0';
                        printf("%s\n", commend);
                        state = OPCODE;
                        cmd_handler(commend,line);
                        free(commend);
                        commend = (char*) malloc((size_t) sizeof(char));
                        size = 1;
                        line++;
                        break;
                    }
                    if(ch == ',')
                        *(commend + size - 1) = '/';
                    else
                        *(commend + size - 1) = ch;

                    size++;
                    commend = (char *) realloc(commend, sizeof(char) * size);
                    break;
            }
        }
    }
}