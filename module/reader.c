
/********************************************
   This file responsible for IO management.
 ********************************************/

#include "reader.h"
#include "const.h"

int cround = 1;
extern int IC;

_Bool validate_files(char *file) {
    _Bool exist_or_not = 0;
    _Bool _valid = 1;

    FILE *fd = fopen(file, "r");
    fd ? _log(file, ++exist_or_not) : _log(file, exist_or_not);

    extension(file, _valid);

    if (fd != NULL) {
        fclose(fd);
        if (_valid)
            return 1;
    }
    return 0;
}

void assemble(char *file) {

    FILE *fd = fopen(file, "r+");

    signed short int size = 1;
    char *cmd = (char *) malloc((size_t) sizeof(char));

    enum status state = OPCODE;
    enum sub_status sub_state = OUTSIDE_PARENTHESIS;
    _Bool has_label = 0;
    signed short int line = 1;

    while (!feof(fd)) {
        mem_check(&cmd);

        char ch = (char) fgetc(fd);

        switch (state) {
            case OPCODE:
                handle_opcode(&size, ch, &line, &has_label, &cmd, &state);
                break;
            case OPRAND:
                handle_operand(&size, ch, &line, &has_label, &cmd, &state, &sub_state);
                break;
            case COMMENT:
                handle_comment(ch, &line, &state);
        }
    }

    update_data(IC);
    update_label(IC);
    size = 1;
    free(cmd);
    cmd = (char *) malloc((size_t) sizeof(char));
    state = OPCODE;
    sub_state = OUTSIDE_PARENTHESIS;
    has_label = 0;
    line = 1;
    IC = 100;
    cround++;
    rewind(fd);

    while (!feof(fd)) {
        mem_check(&cmd);

        char ch = (char) fgetc(fd);

        switch (state) {
            case OPCODE:
                handle_opcode(&size, ch, &line, &has_label, &cmd, &state);
                break;
            case OPRAND:
                handle_operand(&size, ch, &line, &has_label, &cmd, &state, &sub_state);
                break;
            case COMMENT:
                handle_comment(ch, &line, &state);
        }
    }

    sort();
}

_Bool continue_2_operand = 0, ignore_spacing = 0, check_for_label = 1;

void handle_opcode(signed short int *size, char ch, signed short int *line, _Bool *has_label, char **commend,
                   enum status *pstatus) {
    if (check_for_comment(ch, pstatus) || handle_label(ch, pstatus, has_label))
        return;
    if (ch == SPACE ||
        ch == TAB || ch == END_OF_FILE || ch == NEW_LINE || ch == WIN_NEW_LINE) {
        if (!ignore_spacing && *size > MIN_CHARS) {
            check_for_label = 0;
            *((*commend) + *size - 1) = SEPARATOR;
        } else if (ch == SPACE || ch == TAB)
            return;
        if (handle_line(size, ch, line, has_label, &(*commend), pstatus))
            return;
        else if (!continue_2_operand)
            *pstatus = OPRAND;
        ignore_spacing = 1;
    } else if (*pstatus != COMMENT) {
        ignore_spacing = 0;
        if (continue_2_operand)
            continue_2_operand = 0;
        *(*(commend) + *size - 1) = ch;
    }
    forward(size, commend);
}

_Bool after_param = 0, before_param = 1, comma_next = 0, comma_error = 0;

void handle_operand(signed short int *size, char ch, signed short int *line, _Bool *has_label, char **commend,
                    enum status *pstatus, enum sub_status *psub_status) {
    int result = 0;
    if (before_param || after_param) {
        if (handle_line(size, ch, line, has_label, &(*commend), pstatus) || ch == SPACE || ch == TAB) {
            return;
        }
    } else if ((result = handle_line(size, ch, line, has_label, &(*commend), pstatus)) || ch == SPACE || ch == TAB) {
        if (result)
            comma_error = 0;
        else {
            after_param = 1;
            comma_next = 1;
        }
        return;
    }
    if (ch == PARENTHESIS_IN)
        *psub_status = INSIDE_PARENTHESIS;
    else if (ch == PARENTHESIS_OUT)
        *psub_status = OUTSIDE_PARENTHESIS;
    if (before_param && ch == COMMA && *psub_status != INSIDE_PARENTHESIS) {
        *((*commend) + *size - 1) = SEPARATOR;
        comma_next = 0;
        before_param = 1;
    } else {
        if (comma_next == 1 && ch != COMMA)
            comma_error = 1;
        *(*(commend) + *size - 1) = ch;
        after_param = 0;
        before_param = 1;
    }
    forward(size, commend);
}

_Bool handle_line(signed short int *size, char ch, signed short int *line, _Bool *label, char **commend,
                  enum status *pstatus) {
    if (ch == NEW_LINE || ch == END_OF_FILE) {
        if (*size == MIN_CHARS) {
            (*line)++;
            return 1;
        }

        if (comma_error)
            printf(COMMA_ERROR, *line);

        *(*commend + *size - 1) = END_OF_INPUT;

        if (!comma_error) {
            handle_commend(*commend, *line, *label, cround);
        }

        free(*commend);
        *commend = (char *) malloc((size_t) sizeof(char));
        *pstatus = OPCODE;
        *label = 0;
        *line += 1;
        *size = 1;
        comma_next = 0;
        before_param = 1;
        after_param = 0;
        check_for_label = 1;
        continue_2_operand = 1;
        return 1;
    }
    return 0;
}

void handle_comment(char ch, signed short int *line, enum status *pstatus) {
    if (ch == NEW_LINE) {
        *pstatus = OPCODE;
        *line = (short) (*line + 1);
    }
}

_Bool check_for_comment(char ch, enum status *pstatus) {
    if (ch == DOT_COMMA) {
        *pstatus = COMMENT;
        return 1;
    }
    return 0;
}

_Bool handle_label(char ch, enum status *state, _Bool *label) {
    if (check_for_label && ch == TWO_DOTS) {
        *label = 1;
        *state = OPCODE;
        continue_2_operand = 1;
        return 1;
    }
    return 0;
}

void forward(signed short int *size, char **commend) {
    *size = (short) (*size + 1);
    *commend = (char *) realloc(*commend, sizeof(char) * *size);
}