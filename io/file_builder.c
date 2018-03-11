
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

#define _log(path, found) \
    found ? success_open (path) : failure_open(path)

enum status { OPCODE, OPRAND , INSIDE_QUOTATION_MARK, OUTSIDE_QUOTATION_MARK};

void cmd_handler(char *, int, _Bool);
_Bool check_for_label(char ch, enum status *state, _Bool *has_label);
_Bool handle_new_line(signed short int *, char, int *, _Bool*, char **, enum status *);
void advance_parse(signed short int *, char **);

void file_exist(char **files) {

    while (*++files) {

        _Bool flag = 0;
        FILE *file = fopen(*files, "r+");

        file != NULL ? _log(*files, ++flag) : _log(*files, flag);

        if (file != NULL) fclose(file);

        if (!flag) exit(0);
    }

}

void assemble(char **paths) {

    while (*++paths) {
        FILE *fd = fopen(*paths, "r+");

        signed short int size = 1;
        char *commend = (char *) malloc((size_t) sizeof(char));

        enum status state = OPCODE;
        enum status sub_state = OUTSIDE_QUOTATION_MARK;
        int line = 1;
        _Bool has_label = 0;

        while (!feof(fd)) {
            if (!commend) {
                printf(SPACE_ALLOCATION_FAILED);
                exit(0);
            }

            char ch = (char) fgetc(fd);

            switch (state) {
                case OPCODE:
                    check_for_label(ch,&state,&has_label);
                    if (ch == ' ' || ch == '\t' || ch == -1 || ch == '\n' || ch == '\r') {
                        if (size > 1) {
                            *(commend + size - 1) = '/';
                            state = OPRAND;
                            handle_new_line(&size, ch, &line, &has_label, &commend, &state);
                        } else {
                            if (ch == '\n')
                                line++;
                            continue;
                        }
                    }
                    else
                        *(commend + size - 1) = ch;

                    advance_parse(&size,&commend);
                    break;

                case OPRAND:
                    if(check_for_label(ch,&state,&has_label)
                        || handle_new_line(&size, ch, &line, &has_label, &commend, &state)
                                    || ch == ' ' || ch == '\t')
                        continue;
                    if(ch=='(')
                        sub_state = INSIDE_QUOTATION_MARK;
                    if(ch == ')')
                        sub_state = OUTSIDE_QUOTATION_MARK;
                    if (ch == ',' && sub_state != INSIDE_QUOTATION_MARK)
                        *(commend + size - 1) = '/';
                    else
                        *(commend + size - 1) = ch;


                    advance_parse(&size,&commend);
                    break;
            }
        }
    }
}

_Bool check_for_label(char ch, enum status *state, _Bool *has_label){
    if (ch == ':') {
        *has_label = 1;
        *state = OPCODE;
        return 1;
    }
    return 0;
}

_Bool handle_new_line(signed short int *size, char ch, int *line, _Bool *has_label, char **commend, enum status *state) {
    if (ch == '\n' || ch == -1) {
        *(*commend + *size - 1) = '\0';
        printf("%s\n", *commend);
        *state = OPCODE;
        cmd_handler(*commend, *line, *has_label);
        *has_label = 0;
        free(commend);
        *commend = (char *) malloc((size_t) sizeof(char));
        *size = 1;
        *line++;
        return 1;
    }
    return 0;
}

void advance_parse(signed short int *size, char **commend){
    *size = *size + 1;
    *commend = (char *) realloc(*commend, sizeof(char) * *size);
}