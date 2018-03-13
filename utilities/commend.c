
/*******************************************************
   This file responsible for commend check and handle.
 ******************************************************/

#include "../headers/commend.h"
#include "../headers/const.h"

void handle_commend(char *opcmd, int line, _Bool is_label) {

    char *opcode = NULL, *label = NULL;
    char **operands = NULL;
    unsigned short int mem_allocated = 0, counter = 0, params = 0;
    int i, l, j = 0, k = 0, size = 1;

    char last_char = 0;
    for (l = 0; l <= strlen(opcmd); ++l) {
        if(opcmd[l] - last_char == 0 && last_char == SEPARATOR) {
            printf(TOO_MANY_COMMAS, line);
            return;
        }
        last_char = opcmd[l];
    }

    char c = *(opcmd + strlen(opcmd) - 1);
    if((*(opcmd + strlen(opcmd) - 1)) == SEPARATOR) {
        printf(CONNA_AT_THE_END, line);
        return;
    }

    for (i = 0; i < strlen(opcmd) && !mem_allocated; ++i) {
        if (*(opcmd + i) == SEPARATOR && opcode == NULL && operands == NULL) {
            opcode = (char *) malloc(sizeof(char));
            operands = (char **) malloc(sizeof(char *));

            if (!opcode || !operands) {
                printf(COMMEND_CHECK_FAILURE);
                exit(0);
            }
            mem_allocated = 1;
        }
        if (is_label && label == NULL) {
            label = (char *) malloc(sizeof(char));
            if (!label) {
                printf(COMMEND_CHECK_FAILURE);
                exit(0);
            }
        }
    }

    if (opcode == NULL && !is_label)
        opcode = opcmd;

    if (mem_allocated) {

        mem_allocated = 0;

        for (i = 0; i <= strlen(opcmd); ++i) {
            switch (mem_allocated) {
                case 0:
                    if (is_label) {
                        if (*(opcmd + i) != SEPARATOR) {
                            label = (char *) realloc(label, (size_t) size++);
                            if (!label) {
                                printf(SPACE_ALLOCATION_FAILED);
                                exit(0);
                            }
                            label[j++] = *(opcmd + i);
                        } else {
                            size = 1;
                            label[j] = END_OF_INPUT;
                            j = 0;
                            mem_allocated++;
                        }
                    } else {
                        mem_allocated++;
                        i--;
                    }
                    break;
                case 1:
                    if (*(opcmd + i) != SEPARATOR) {
                        opcode = (char *) realloc(opcode, (size_t) ++size);
                        if (!opcode) {
                            printf(SPACE_ALLOCATION_FAILED);
                            exit(0);
                        }
                        opcode[j++] = *(opcmd + i);
                    } else {
                        size = 1;
                        opcode[j] = END_OF_INPUT;
                        j = 0;
                        mem_allocated++;
                        k++;
                    }
                    break;
                default:
                    if (*(opcmd + i) != SEPARATOR && *(opcmd + i) != END_OF_INPUT) {
                        if (size == 1) {
                            operands[counter] = (char *) malloc(sizeof(char));
                            size++;
                        } else
                            operands[counter] = (char *) realloc(operands[counter], (size_t) size++);
                        if (!operands[counter]) {
                            printf(SPACE_ALLOCATION_FAILED);
                            exit(0);
                        }
                        operands[counter][j++] = *(opcmd + i);
                    } else {
                        operands[counter][j++] = END_OF_INPUT;
                        mem_allocated++;
                        size = 1; 
                        j = 0;
                        params++;
                        counter++;
                        k++;
                    }
                    break;
            }
        }
    }


    int t = 0;
    printf("%s -", opcode);
    for (t = 0; t < params; ++t ) {
        printf(" %s ", operands[t]);
    }
    printf("%c",NEW_LINE);

    build_data(opcode, operands, line);
}

void build_data(char *op, char **operands, int line) {
    syntex(op, operands, line);
}

unsigned int syntex(char *op, char **operands, int line) {
    if (strcmp(op, "mov") == 0) {
        return 0;
    } else if (strcmp(op, "cmp") == 0) {
        return 1;
    } else if (strcmp(op, "add") == 0) {
        return 2;
    } else if (strcmp(op, "sub") == 0) {
        return 3;
    } else if (strcmp(op, "not") == 0) {
        return 4;
    } else if (strcmp(op, "clr") == 0) {
        return 5;
    } else if (strcmp(op, "lea") == 0) {
        return 6;
    } else if (strcmp(op, "inc") == 0) {
        return 7;
    } else if (strcmp(op, "dec") == 0) {
        return 8;
    } else if (strcmp(op, "jmp") == 0) {
        return 9;
    } else if (strcmp(op, "bne") == 0) {
        return 10;
    } else if (strcmp(op, "red") == 0) {
        return 11;
    } else if (strcmp(op, "prn") == 0) {
        return 12;
    } else if (strcmp(op, "jsr") == 0) {
        return 13;
    } else if (strcmp(op, "rts") == 0) {
        return 14;
    } else if (strcmp(op, "stop") == 0) {
        return 15;
    } else if (strcmp(op, ".string") == 0) {
        return 16;
    } else if (strcmp(op, ".struct") == 0) {
        return 18;
    } else if (strcmp(op, ".entry") == 0) {
        return 19;
    } else if (strcmp(op, ".extern") == 0) {
        return 20;
    } else if (strcmp(op, ".data") == 0) {
        return 20;
    } else {
        printf(COMMEND_SYNTEX_ERROR, line, op);
    }
}

