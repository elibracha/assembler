
/********************************************
   This file responsible for IO management.
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#define SUCCESS_FILE_MESSAGE "Build: Successfully Accessed File - %s\n"
#define FAILURE_FILE_MESSAGE "Build: Shuting Down Program (File Not Found - %s)\n"

#define failure_open(path) \
    printf(FAILURE_FILE_MESSAGE, path)

#define success_open(path) \
    printf(SUCCESS_FILE_MESSAGE, path)

#define _log(path , found) \
    found ? success_open (path) : failure_open(path)


const _Bool file_exist(const char** files){
    while(*++files){
        FILE * file = fopen(*files, "r+");
        _Bool flag = 0;

        file ? _log(*files, ++flag) : _log(*files, flag);
        fclose(file);

        if (!flag)
            exit(0);
    }

}