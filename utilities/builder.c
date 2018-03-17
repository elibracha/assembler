
/*******************************************************
   This file responsible for commend logic and checking.
 ******************************************************/

#include "../headers/builder.h"
#include "../headers/const.h"

method *MOV = &mov;
method *CMP = &cmp;
method *ADD = &add;
method *SUB = &sub;
method *NOT = &not;
method *CLR = &clr;
method *LEA = &lea;
method *INC = &inc;
method *DEC = &dec;
method *JMP = &jmp;
method *BNE = &bne;
method *RED = &red;
method *PRN = &prn;
method *JSR = &jsr;
method *RTS = &rts;
method *STOP = &stop;

void print_label_list();
_Bool check_Addressing_0(char *, int, int *);

_Bool check_Addressing_1(char *, int, _Bool);

_Bool check_Addressing_2(char *, int, _Bool);

_Bool check_Addressing_3(char *, int, int *, _Bool);

_Bool check_arguments(int, char *, int, int);

char *convert_10bits_to_2(signed int, _Bool);

char *convert_2bits_to_32(const char *);

void insert_first_label(char *, int, _Bool, _Bool);

void insert_last_label(char *, int, _Bool, _Bool);

void insert_last_data(int, int, char *);

void insert_first_data(int, int, char *);

void insert_last_code(int, char *);

void insert_first_code(int, char *);

struct code *get_head_code();

struct data *get_head_data();

struct label *get_head_label();

void handle_cmd(char *, char *, char **, int, int, method *, int);

void cmp_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, CMP, TWO_ARGUMENTS);
    } else {
        return;
    }
}

void mov_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, MOV, TWO_ARGUMENTS);
    } else {
        return;
    }
}

void add_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, ADD, TWO_ARGUMENTS);
    } else {
        return;
    }
}

void sub_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, SUB, TWO_ARGUMENTS);
    } else {
        return;
    }
}

void lea_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, LEA, TWO_ARGUMENTS);
    } else {
        return;
    }
}

void inc_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, INC, ONE_ARGUMENTS);
    } else {
        return;
    }
}

void clr_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, CLR, ONE_ARGUMENTS);
    } else {
        return;
    }
}

void not_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, NOT, ONE_ARGUMENTS);
    } else {
        return;
    }
}

void dec_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, DEC, ONE_ARGUMENTS);
    } else {
        return;
    }
}

void jmp_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, NOT, ONE_ARGUMENTS);
    } else {
        return;
    }
}

void bne_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, BNE, ONE_ARGUMENTS);
    } else {
        return;
    }
}

void red_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, RED, ONE_ARGUMENTS);
    } else {
        return;
    }
}

void prn_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, PRN, ONE_ARGUMENTS);
    } else {
        return;
    }
}

void jsr_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, JSR, ONE_ARGUMENTS);
    } else {
        return;
    }
}

void rts_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ZERO_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, RTS, ZERO_ARGUMENTS);
    } else {
        return;
    }
}

void stop_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ZERO_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, STOP, ZERO_ARGUMENTS);
    } else {
        return;
    }
}

void data_handler(char *label, char **operands, int params, int line) {
    if (label != NULL) {
        struct label *head = get_head_label();
        if (head == NULL) {
            insert_first_label(label, IC, 0, 0);
        } else
            insert_last_label(label, IC, 0, 0);
    }
    while (params) {
        int i = 0;
        for (i = 0; i != '\0'; ++i) {
            if (*(*(operands + i)) <= 57 && *(*(operands + i)) >= 48) {
                continue;
            } else {
                printf("Syntex: Invalid Char In Middle O f A Number.");
                return;
            }
        }
        int number = atoi(*operands);
        if (get_head_data() == NULL) {
            insert_first_data(DC++, line, convert_10bits_to_2(number, 1));
        } else {
            insert_last_data(DC++, line, convert_10bits_to_2(number, 1));
        }
        operands++;
        params--;
    }
}

void string_handler(char *label, char **operands, int params, int line) {
    if (params > 1) {
        printf("Syntex: To Many Aruments For String.");
        return;
    }

    if (label != NULL) {
        struct label *head = get_head_label();
        if (head == NULL) {
            insert_first_label(label, IC, 0, 0);
        } else
            insert_last_label(label, IC, 0, 0);
    }

    int i;
    for (i = 0; i < strlen(*operands); ++i) {
        if (i == 0) {
            if (**operands == '\"') {
                continue;
            } else {
                printf("Syntex: String Data Most start With ' \" '.");
                return;
            }
        }

        if (i + 1 == strlen(*operands)) {
            if (*((*operands) + i) == '\"') {
                continue;
            } else {
                printf("Syntex: String Data Most End With ' \" '.");
                return;
            }
        }

        if (get_head_data() == NULL) {
            insert_first_data(DC++, line, convert_10bits_to_2((int) *((*operands) + i), 1));
        } else {
            insert_last_data(DC++, line, convert_10bits_to_2((int) *((*operands) + i), 1));
        }
    }

}

void struct_handler(char *label, char **operands, int params, int line) {
    if (params == 2) {
        data_handler(label, operands, 1, line);
        string_handler(NULL, (operands + 1), 1, line);
    } else {
        return;
    }
}

void extern_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ZERO_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, STOP, ZERO_ARGUMENTS);
    } else {
        return;
    }
}

void entry_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ZERO_ARGUMENTS)) {
        handle_cmd(label, op, operands, line, n, STOP, ZERO_ARGUMENTS);
    } else {
        return;
    }
}


_Bool check_Addressing_0(char *operand, int line, int *num) {
    if (*operand == ASTRICK) {
        int j = 1;
        if (*(operand + 1) == NEGATIVE || *(operand + 1) == POSITIVE) {
            j = 2;
        }
        char *clean_operand = (char *) malloc(sizeof(strlen(operand) - j));
        if (!clean_operand) {
            printf(SPACE_ALLOCATION_FAILED);
            exit(0);
        }
        int i;
        for (i = 0; i < strlen(operand) - 1; ++i) {
            if (i + j == strlen(operand)) {
                *(clean_operand + i) = END_OF_INPUT;
                continue;
            }
            if (!isdigit(*(operand + i + j))) {
                printf(INVALID_ADDRASSING_0, line, operand);
                return 0;
            }
            *(clean_operand + i) = *(operand + i + j);
        }
        int result = atoi(clean_operand);
        if (result == 0) {
            printf(INVALID_ADDRASSING_0, line, operand);
        } else {
            *num = result;
            return 1;
        }
    }
    return 0;
}

_Bool check_Addressing_1(char *operand, int line, _Bool num_operand) {
    int temp_result;
    if (check_Addressing_0(operand, line, &temp_result)) {
        printf(MISSPLACED_ADDRESSING, num_operand + 1, 1, "Immediate Number", line);
        return 0;
    } else if (check_Addressing_3(operand, line, &temp_result, num_operand)) {
        printf(MISSPLACED_ADDRESSING, num_operand + 1, 1, "Register", line);
        return 0;
    }

    char *field = NULL;
    if ((field = strchr(operand, '.'))) {
        if (strcmp(field + 1, "1") == 0 || strcmp(field + 1, "2") == 0) {
            _Bool begin = 1;
            while (operand) {
                if (begin) {
                    if (*(operand + 1) < 97 && *operand > 90 || *operand > 120 || *operand < 65 ||
                        strlen(field) != 2) {
                        printf("Syntex: Struct Can't Start With '%c', Invalid (line - %d).\n ", *operand, line);
                        return 0;
                    }
                    begin = 0;
                } else {
                    if ((*operand < 97 && *operand > 90) || *operand > 120 ||
                        (*operand < 65 && *operand > 57) || *operand < 48 || strlen(operand) >= 32) {
                        printf("Syntex: Struct Can't Contain '%c' Or Too Long, Invalid (line - %d).\n", *operand, line);
                        return 0;
                    }
                    operand++;
                }
            }
            return 1;
        } else {
            printf("Syntex: Struct Fields Most Be Address With 1 or 2, Invalid (line - %d).\n", line);
            return 0;
        }
    }


}

_Bool check_Addressing_2(char *operand, int line, _Bool num_operand) {
    int temp_result;
    if (check_Addressing_0(operand, line, &temp_result)) {
        printf(MISSPLACED_ADDRESSING, num_operand + 1, 1, "Immediate Number", line);
        return 0;
    } else if (check_Addressing_3(operand, line, &temp_result, num_operand)) {
        printf(MISSPLACED_ADDRESSING, num_operand + 1, 1, "Register", line);
        return 0;
    } else if (check_Addressing_1(operand, line, num_operand)) {
        printf(MISSPLACED_ADDRESSING, num_operand + 1, 1, "Struct", line);
        return 0;
    }
    int i;
    for (i = 0; i < strlen(operand); ++i) {
        if (i == 0) {
            if (*operand < 97 && *operand > 90 || *operand > 120 || *operand < 65) {
                printf("Syntex: Label Can't Start With '%c', Invalid (line - %d).\n", *operand, line);
                return 0;
            }
        } else if ((*(operand + i) < 97 && *(operand + i) > 90) || *(operand + i) > 120 ||
                   (*(operand + i) < 65 && *(operand + i) > 57) ||
                   *(operand + i) < 48 && *(operand + i) != 0 && strlen(operand) <= 32) {
            printf("Syntex: Label Can't Contain '%c' Or Too Long, Invalid (line - %d).\n", *(operand + i), line);
            return 0;
        }
    }
}

_Bool check_Addressing_3(char *operand, int line, int *result, _Bool num_operand) {
    int *temp;
    if (check_Addressing_0(operand, line, temp)) {
        printf(MISSPLACED_ADDRESSING, num_operand + 1, 1, "Immediate Number", line);
        return 0;
    }
    if (strcmp(operand, "r0") == 0 || strcmp(operand, "r1") == 0 || strcmp(operand, "r2") == 0 ||
        strcmp(operand, "r3") == 0 || strcmp(operand, "r4") == 0 || strcmp(operand, "r5") == 0 ||
        strcmp(operand, "r6") == 0) {
        if (strcmp(operand, "r0") == 0) {
            *result = 0;
        } else if (strcmp(operand, "r1") == 0) {
            *result = 1;
        } else if (strcmp(operand, "r2") == 0) {
            *result = 2;
        } else if (strcmp(operand, "r3") == 0) {
            *result = 3;
        } else if (strcmp(operand, "r4") == 0) {
            *result = 4;
        } else if (strcmp(operand, "r5") == 0) {
            *result = 5;
        } else if (strcmp(operand, "r6") == 0) {
            *result = 6;
        } else {
            *result = 7;
        }

        return 1;
    }
    return 0;
}

void handle_cmd(char *label, char *op, char **operands, int line, int n, method *md, int args) {
    commend cmd;
    int i = 0, k = 0, j, val_op1 = 0, val_op2 = 0, result_op1 = 0, result = 0;
    _Bool on_p1 = 1, addressing = 0;

    cmd._opcode = md->opcode;

    for (j = 1; j < 5; ++j) {
        if (on_p1 && args == 2)
            addressing = md->op1[i];
        else if (args == 1)
            addressing = md->op2[i];
        else
            break;

        if (addressing) {
            switch (i) {
                case 1:
                    if (check_Addressing_0(*(operands + k), line, &result)) {
                        cmd._ERA = 0;
                        if (on_p1) {
                            val_op1 = 0;
                            cmd._src_operand = (unsigned int) val_op1;
                        } else {
                            val_op2 = 0;
                            cmd._des_operand = (unsigned int) val_op2;
                        }
                        j = 4;
                        k++;
                    }
                    break;
                case 2:
                    if (check_Addressing_3(*(operands + k), line, &result, on_p1)) {
                        cmd._ERA = 1;
                        if (on_p1) {
                            val_op1 = 3;
                            cmd._src_operand = (unsigned int) val_op1;
                        } else {
                            val_op2 = 3;
                            cmd._des_operand = (unsigned int) val_op2;
                        }
                        j = 4;
                        k++;
                    }
                    break;
                case 3:
                    if (check_Addressing_2(*(operands + k), line, on_p1)) {
                        cmd._ERA = 1;
                        if (on_p1) {
                            val_op1 = 2;
                            cmd._src_operand = (unsigned int) val_op1;
                        } else {
                            val_op2 = 2;
                            cmd._des_operand = (unsigned int) val_op2;
                        }
                        j = 4;
                        k++;
                    }
                    break;
                case 4:
                    if (check_Addressing_1(*(operands + k), line, on_p1)) {
                        cmd._ERA = 0;
                        if (on_p1) {
                            val_op1 = 1;
                            cmd._src_operand = (unsigned int) val_op1;
                        } else {
                            val_op2 = 1;
                            cmd._des_operand = (unsigned int) val_op2;
                        }
                        j = 4;
                        k++;
                    }
                    break;
            }
        }

        if (j == 4 && on_p1) {
            result_op1 = result;
            args--;
            on_p1 = 0;
            j = -1;
            i = -1;
        }

        i++;
    }


    if (label != NULL) {
        struct label *head = get_head_label();
        if (head == NULL) {
            insert_first_label(label, IC, 0, 1);
        } else
            insert_last_label(label, IC, 0, 1);
    }

    print_label_list();
    char *o = convert_10bits_to_2(cmd._opcode, 0);
    char *p1 = convert_10bits_to_2(cmd._src_operand, 0);
    char *p2 = convert_10bits_to_2(cmd._des_operand, 0);
    char *era = convert_10bits_to_2(cmd._ERA, 0);

    if (strlen(o) != 4) {
        int length = 4 - strlen(o);
        char *str = (char *) malloc(5);
        int l, q = 0;
        for (l = 0; l < 5; ++l) {
            if (l < length)
                str[l] = '0';
            else {
                if (l == 4)
                    str[l] = '\0';
                else
                    str[l] = o[q++];
            }
        }
        o = str;
    }
    if (strlen(p1) != 2) {
        int length = 2 - strlen(p1);
        char *str = (char *) malloc(2);
        int l, q = 0;
        for (l = 0; l < 3; ++l) {
            if (l < length)
                str[l] = '0';
            else {
                if (l == 2)
                    str[l] = '\0';
                else
                    str[l] = p1[q++];
            }
        }
        p1 = str;
    }
    if (strlen(p2) != 2) {
        int length = 2 - strlen(p2);
        char *str = (char *) malloc(2);
        int l, q = 0;
        for (l = 0; l < 3; ++l) {
            if (l < length)
                str[l] = '0';
            else {
                if (l == 2)
                    str[l] = '\0';
                else
                    str[l] = p2[q++];
            }
        }
        p2 = str;
    }
    if (strlen(era) != 2) {
        int length = 2 - strlen(era);
        char *str = (char *) malloc(2);
        int l, q = 0;
        for (l = 0; l < 3; ++l) {
            if (l < length)
                str[l] = '0';
            else {
                if (l == 2)
                    str[l] = '\0';
                else
                    str[l] = p1[q++];
            }
        }
        era = str;
    }

    struct code *codes = get_head_code();

    if (codes == NULL) {
        insert_first_code(IC++, strcat(o, strcat(p1, strcat(p2, era))));
    } else {
        insert_last_code(IC++, strcat(o, strcat(p1, strcat(p2, era))));
    }

    switch (val_op1) {
        case 0:
            if (codes == NULL) {
                insert_last_code(IC++, convert_10bits_to_2(result_op1, 1));
            } else {
                insert_last_code(IC++, convert_10bits_to_2(result_op1, 1));
            }
            break;
        case 1:

        case 2:

        case 3:
            break;
    }

    switch (val_op2) {
        case 0:
            if (codes == NULL) {
                insert_last_code(IC++, convert_10bits_to_2(result_op1, 1));
            } else {
                insert_last_code(IC++, convert_10bits_to_2(result_op1, 1));
            }
            break;
        case 1:

        case 2:

        case 3:
            break;
    }

}

_Bool check_arguments(int cargs, char *op, int line, int nargs) {
    if (cargs == nargs) {
        return 1;
    } else if (cargs > nargs) {
        printf(TOO_MANY_ARGUMENTS, op, line);
    } else {
        printf(TOO_LOW_ARGUMENTS, op, line);
    }
    return 0;
}

void initialize() {

    MOV->opcode = 0;
    CMP->opcode = 1;
    ADD->opcode = 2;
    SUB->opcode = 3;
    NOT->opcode = 4;
    CLR->opcode = 5;
    LEA->opcode = 6;
    INC->opcode = 7;
    DEC->opcode = 8;
    JMP->opcode = 9;
    BNE->opcode = 10;
    RED->opcode = 11;
    PRN->opcode = 12;
    JSR->opcode = 13;
    RTS->opcode = 14;
    STOP->opcode = 15;

    int i;

    for (i = 0; i < 4; ++i) {
        MOV->op1[i] = 1;
        ADD->op1[i] = 1;
        SUB->op1[i] = 1;
        CMP->op1[i] = 1;
        NOT->op1[i] = 0;
        CLR->op1[i] = 0;
        INC->op1[i] = 0;
        DEC->op1[i] = 0;
        JMP->op1[i] = 0;
        BNE->op1[i] = 0;
        RED->op1[i] = 0;
        PRN->op1[i] = 0;
        JSR->op1[i] = 0;
        RTS->op1[i] = 0;
        STOP->op1[i] = 0;

        i > 0 && i < 3 ? (LEA->op1[i] = 1) : (LEA->op1[i] = 0);

        i > 0 ? (MOV->op2[i] = 1) : (MOV->op2[i] = 0);
        i > 0 ? (JSR->op2[i] = 1) : (JSR->op2[i] = 0);
        i > 0 ? (ADD->op2[i] = 1) : (ADD->op2[i] = 0);
        i > 0 ? (SUB->op2[i] = 1) : (SUB->op2[i] = 0);
        i > 0 ? (NOT->op2[i] = 1) : (NOT->op2[i] = 0);
        i > 0 ? (CLR->op2[i] = 1) : (CLR->op2[i] = 0);
        i > 0 ? (LEA->op2[i] = 1) : (LEA->op2[i] = 0);
        i > 0 ? (INC->op2[i] = 1) : (INC->op2[i] = 0);
        i > 0 ? (DEC->op2[i] = 1) : (DEC->op2[i] = 0);
        i > 0 ? (JMP->op2[i] = 1) : (JMP->op2[i] = 0);
        i > 0 ? (BNE->op2[i] = 1) : (BNE->op2[i] = 0);
        i > 0 ? (RED->op2[i] = 1) : (RED->op2[i] = 0);
        i > 0 ? (JSR->op2[i] = 1) : (JSR->op2[i] = 0);

        RTS->op2[i] = 0;
        STOP->op2[i] = 0;
        PRN->op2[i] = 1;
        CMP->op2[i] = 1;
    }
}
