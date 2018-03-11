
/********************************************
   This file responsible for IO management.
 ********************************************/

#include "./builder.h"

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
        _Bool has_label = 0;
        signed short int line = 1;

        while (!feof(fd)) {
            if (!commend) {
                printf(SPACE_ALLOCATION_FAILED);
                exit(0);
            }

            char ch = (char) fgetc(fd);

            switch (state) {
                case OPCODE:
                    handle_opcode(&size, ch, &line, &has_label, &commend, &state);
                    break;
                case OPRAND:
                    handle_operand(&size, ch, &line, &has_label, &commend, &state, &sub_state);
                    break;
                case COMMENT:
                    handle_comment(&size, ch, &line, &has_label, &commend, &state);
            }
        }
    }
}

void handle_opcode(signed short int *size, char ch, signed short int *line, _Bool *has_label, char **commend,
                    enum status *pstatus){
    if(check_for_comment(ch, pstatus))
        return;
    handle_label(ch, pstatus, has_label);
    if (ch == ' ' || ch == '\t' || ch == -1 || ch == '\n' || ch == '\r') {
        if (*size > 1) {
            *((*commend) + *size - 1) = '/';
            *pstatus = OPRAND;
            if(handle_line(size, ch, line, has_label, &(*commend), pstatus))
                return;
        } else {
            if (ch == '\n')
                *line += 1;
            return;
        }
    }
    else
    if(*pstatus != COMMENT)
        *(*(commend) + *size - 1) = ch;

    forward(size, commend);
}

void handle_operand(signed short int *size, char ch, signed short int *line, _Bool *has_label, char **commend,
                    enum status *pstatus, enum status *psub_status){

    if(handle_label(ch, pstatus, has_label) || check_for_comment(ch, pstatus)
       || handle_line(size, ch, line, has_label, &(*commend), pstatus)
       || ch == ' ' || ch == '\t')
        return;
    if(ch=='(')
        *psub_status = INSIDE_QUOTATION_MARK;
    else if(ch == ')')
        *psub_status = OUTSIDE_QUOTATION_MARK;
    if (ch == ',' && *psub_status != INSIDE_QUOTATION_MARK)
        *((*commend) + *size - 1) = '/';
    else
    if(*pstatus != COMMENT)
        *(*(commend) + *size - 1) = ch;

    forward(size,commend);
}

_Bool check_for_comment(char ch, enum status *pStatus) {
    if (ch == ';') {
        *pStatus = COMMENT;
        return 1;
    }
    return 0;
}

_Bool handle_label(char ch, enum status *state, _Bool *has_label){
    if (ch == ':') {
        *has_label = 1;
        *state = OPCODE;
        return 1;
    }
    return 0;
}

_Bool handle_line(signed short int *size, char ch, signed short int *line, _Bool *has_label, char **commend,
                  enum status *pStatus) {
    if (ch == '\n' || ch == -1) {
        *(*commend + *size - 1) = '\0';
        printf("%s\n", *commend);
        *pStatus = OPCODE;
        handle_commend(*commend, *line, *has_label);
        *has_label = 0;
        free(*commend);
        *commend = (char *) malloc((size_t) sizeof(char));
        *size = 1;
        *line = (short) (*line + 1);
        return 1;
    }
    return 0;
}

void handle_comment(signed short int *size, char ch, signed short int *line, _Bool *has_label, char **commend,
                    enum status *pStatus){
    if(ch == '\n'){
        if(*size > 1){
            handle_line(size, ch, line, has_label, commend, pStatus);
        }else {
            *pStatus = OPCODE;
            *line = (short) (*line + 1);
        }
    }
}

void forward(signed short int *size, char **commend){
    *size = (short) (*size + 1);
    *commend = (char *) realloc(*commend, sizeof(char) * *size);
}