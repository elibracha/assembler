
/*******************************************************
   This file responsible for commend check and handle.
 ******************************************************/

#include "./commend.h"

void handle_commend(char *opcmd, int line, _Bool label) {

    char *op = NULL, *lab = NULL;
    char **operands = NULL;
    unsigned short int flag = 0;
    signed short int counter = 0;
    int i, j = 0, size = 1, k = 0;;

    for (i = 0; i < strlen(opcmd) && !flag; ++i) {
        if (*(opcmd + i) == '/' && op == NULL && operands == NULL) {
            op = (char *) malloc(sizeof(char));
            operands = (char **) malloc(sizeof(char *));

            if (!op || !operands) {
                printf(COMMEND_CHECK_FAILURE);
                exit(0);
            }
            flag = 1;
        }
        if (label && lab == NULL) {
            lab = (char *) malloc(sizeof(char));
            if (!lab) {
                printf(COMMEND_CHECK_FAILURE);
                exit(0);
            }
        }
    }

    if (op == NULL && !label)
        op = opcmd;

    if (flag) {
        flag = 0;
        for (i = 0; i <= strlen(opcmd); ++i) {
            switch (flag) {
                case 0:
                    if (label) {
                        if (*(opcmd + i) != '/') {
                            lab = (char *) realloc(lab, (size_t) size++);
                            if (!lab) {
                                printf(SPACE_ALLOCATION_FAILED);
                                exit(0);
                            }
                            lab[j++] = *(opcmd + i);
                        } else {
                            size = 1;
                            lab[j] = '\0';
                            j = 0;
                            flag++;
                        }
                    } else {
                        flag++;
                        i--;
                    }
                    break;
                case 1:
                    if (*(opcmd + i) != '/') {
                        op = (char *) realloc(op, (size_t) ++size);
                        if (!op) {
                            printf(SPACE_ALLOCATION_FAILED);
                            exit(0);
                        }
                        op[j++] = *(opcmd + i);
                    } else {
                        size = 1;
                        op[j] = '\0';
                        j = 0;
                        flag++;
                        k++;
                    }
                    break;
                default:
                    if (*(opcmd + i) != '/') {
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
                        size = 1;
                        operands[counter][j++] = '\0';
                        counter++;
                        k++;
                        j = 0;
                    }
                    break;
            }
        }
    }
    build_data(op, operands, line);
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

