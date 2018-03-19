
/*******************************************************
   This file responsible for commend logic and checking.
 ******************************************************/

#include "builder.h"
#include "const.h"
#include "table.h"


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

_Bool check_Addressing_0(char *, int, int *);

_Bool check_Addressing_2(char *, int, int *, _Bool);

_Bool check_Addressing_1(char *, int, _Bool);

_Bool check_Addressing_3(char *, int, int *, _Bool);

_Bool check_arguments(int, char *, int, int);

char *convert_10bits_to_2(signed int, _Bool);

void insert_first_label(char *, int, _Bool, int);

void insert_last_label(char *, int, _Bool, int);

void insert_last_data(int, char *);

void insert_first_data(int, char *);

void insert_last_code(int, char *);

void insert_first_code(int, char *);

struct label *find_label(char *, int);

struct code *get_head_code();

struct data *get_head_data();

struct label *get_head_label();

void handle_case(int, int);

char *plus_to_minus(char *);

char *completing_number(char *, int);

void handle_round2_c1(int, int, char **, int);

void handle_round2_c2(int, int, char **, int, int);

void handle_cmd(char *, char **, int, int, method *, int, int);

void cmp_handler(char *label, char *op, char **operands, int line, int n, int round) {
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {
        handle_cmd(label, operands, line, n, CMP, TWO_ARGUMENTS, round);
    } else {
        return;
    }
}

void mov_handler(char *label, char *op, char **operands, int line, int n, int round) {
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {
        handle_cmd(label, operands, line, n, MOV, TWO_ARGUMENTS, round);
    } else {
        return;
    }
}

void add_handler(char *label, char *op, char **operands, int line, int n, int round) {
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {
        handle_cmd(label, operands, line, n, ADD, TWO_ARGUMENTS, round);
    } else {
        return;
    }
}

void sub_handler(char *label, char *op, char **operands, int line, int n, int round) {
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {
        handle_cmd(label, operands, line, n, SUB, TWO_ARGUMENTS, round);
    } else {
        return;
    }
}

void lea_handler(char *label, char *op, char **operands, int line, int n, int round) {
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {
        handle_cmd(label, operands, line, n, LEA, TWO_ARGUMENTS, round);
    } else {
        return;
    }
}

void inc_handler(char *label, char *op, char **operands, int line, int n, int round) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, n, INC, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

void clr_handler(char *label, char *op, char **operands, int line, int n, int round) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, n, CLR, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

void not_handler(char *label, char *op, char **operands, int line, int n, int round) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, n, NOT, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

void dec_handler(char *label, char *op, char **operands, int line, int n, int round) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, n, DEC, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

void jmp_handler(char *label, char *op, char **operands, int line, int n, int round) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, n, JMP, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

void bne_handler(char *label, char *op, char **operands, int line, int n, int round) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, n, BNE, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

void red_handler(char *label, char *op, char **operands, int line, int n, int round) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, n, RED, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

void prn_handler(char *label, char *op, char **operands, int line, int n, int round) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, n, PRN, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

void jsr_handler(char *label, char *op, char **operands, int line, int n, int round) {
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, n, JSR, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

void rts_handler(char *label, char *op, char **operands, int line, int n, int round) {
    if (check_arguments(n, op, line, ZERO_ARGUMENTS)) {
        handle_cmd(label, operands, line, n, RTS, ZERO_ARGUMENTS, round);
    } else {
        return;
    }
}

void stop_handler(char *label, char *op, char **operands, int line, int n, int round) {
    if (check_arguments(n, op, line, ZERO_ARGUMENTS)) {
        handle_cmd(label, operands, line, n, STOP, ZERO_ARGUMENTS, round);
    } else {
        return;
    }
}

void data_handler(char *label, char **operands, int params, int line) {
    _Bool flag = 0;
    if (label != NULL) {
        struct label *head = get_head_label();
        if (head == NULL) {
            insert_first_label(label, DC, 0, 0);
        } else
            insert_last_label(label, DC, 0, 0);
    }
    while (params) {
        int i = 0;
        for (i = 0; *((*operands) + i) != '\0'; ++i) {
            if (i == 0 && *((*operands) + i) == '-' || *((*operands) + i) == '+') {
                flag = 1;
                continue;
            }if (*((*operands) + i) <= 57 && *((*operands) + i) >= 48) {
                continue;
            } else {
                printf("Syntex: Invalid Char In Middle Of A Number.\n");
                return;
            }
        }
        int number;
        if(flag)
            number = atoi((*operands)+1);
        else
            number = atoi(*operands);
        if (get_head_data() == NULL) {
            if(flag){
                insert_first_data(DC++, plus_to_minus(convert_10bits_to_2(number, 1)));
            }else {
                insert_first_data(DC++, convert_10bits_to_2(number, 1));
            }
        } else {
            if(flag){
                insert_last_data(DC++, plus_to_minus(convert_10bits_to_2(number, 1)));
            }else {
                insert_last_data(DC++, convert_10bits_to_2(number, 1));
            }
        }
        operands++;
        params--;
        flag--;
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
            insert_first_label(label, DC, 0, 0);
        } else
            insert_last_label(label, DC, 0, 0);
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
                insert_last_data(DC++, convert_10bits_to_2(0, 1));
                continue;
            } else {
                printf("Syntex: String Data Most End With ' \" '.");
                return;
            }
        }

        if (get_head_data() == NULL) {
            insert_first_data(DC++, convert_10bits_to_2((int) *((*operands) + i), 1));
        } else {
            insert_last_data(DC++, convert_10bits_to_2((int) *((*operands) + i), 1));
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

void extern_handler(char *label, char **operands, int params) {
    if (params != 1) {
        printf("Syntex: To Many Aruments For Extern Or No Arguments.");
        return;
    }
    struct label *head = get_head_label();
    if (head == NULL) {
        insert_first_label(*operands, 0, 1, -1);
    } else
        insert_last_label(*operands, 0, 1, -1);
}

void entry_handler(char *label, char *op, char **operands, int line, int n) {
    if (check_arguments(n, op, line, ZERO_ARGUMENTS)) {

    } else {
        return;
    }
}


_Bool check_Addressing_0(char *operand, int line, int *num) {
    if (*operand == ASTRICK) {
        int j = 1;
        if (*(operand + 1) == POSITIVE) {
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
                if(!(*(operand + 1) == NEGATIVE &&  i + j ==  1)) {
                    printf(INVALID_ADDRASSING_0, line, operand);
                    return 0;
                }
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
        if (num_operand == 0)
            printf(MISSPLACED_ADDRESSING, 2, 1, "Immediate Number", line);
        else
            printf(MISSPLACED_ADDRESSING, 1, 1, "Immediate Number", line);
        return 0;
    } else if (check_Addressing_2(operand, line, &temp_result, num_operand)) {
        return 0;
    }
    if (strcmp(operand, "r0") == 0 || strcmp(operand, "r1") == 0 || strcmp(operand, "r2") == 0 ||
        strcmp(operand, "r3") == 0 || strcmp(operand, "r4") == 0 || strcmp(operand, "r5") == 0 ||
        strcmp(operand, "r6") == 0) {
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

_Bool check_Addressing_2(char *operand, int line, int *num, _Bool num_operand) {

    char *field = NULL;
    if ((field = strchr(operand, '.'))) {
        if (strcmp(field + 1, "1") == 0 || strcmp(field + 1, "2") == 0) {
            *num = atoi(field + 1);
            _Bool begin = 1;
            while (*(operand + 2) != '\0') {
                if (begin) {
                    if (*operand < 97 && *operand > 90 || *operand > 120 || *operand < 65 ||
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

_Bool check_Addressing_3(char *operand, int line, int *result, _Bool num_operand) {

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

void handle_cmd(char *label, char **operands, int line, int n, method *md, int args, int round) {
    commend cmd;
    int i = 0, k = 0, j, val_op1 = -1, val_op2 = -1, result_op1 = 0, result = 0;
    _Bool on_p1 = 1, addressing = 0;

    cmd._opcode = md->opcode;
    cmd._src_operand = 0;
    cmd._des_operand = 0;
    cmd._ERA = 0;

    for (j = 1; j < 5; ++j) {
        if (on_p1 && args == 2)
            addressing = md->op1[i];
        else if (args == 1) {
            addressing = md->op2[i];
            on_p1 = 0;
        } else
            break;

        if (addressing) {
            switch (i) {
                case 0:
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
                case 1:
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
                case 2:
                    if (check_Addressing_2(*(operands + k), line, &result, on_p1)) {
                        cmd._ERA = 0;
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
                case 3:;
                    if (check_Addressing_3(*(operands + k), line, &result, on_p1)) {
                        cmd._ERA = 0;
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
                default:
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

    if (round == 2) {
        IC++;
        if (val_op1 == 3 && val_op2 == 3) {
            IC++;
            return;
        }
        int t = IC;

        switch (val_op1) {
            case 0:
                IC++;
                break;
            case 1:
                handle_round2_c1(val_op1, val_op2, operands, line);
                break;
            case 2:
                handle_round2_c2(val_op1, val_op2, operands, line, 1);
                IC++;
                break;
            case 3:
                IC++;
            default:
                break;
        }

        t = IC;
        switch (val_op2) {
            case 0:
                IC++;
                break;
            case 1:
                handle_round2_c1(val_op1, val_op2, operands, line);
                break;
            case 2:
                handle_round2_c2(val_op1, val_op2, operands, line, 2);
                IC++;
                break;
            case 3:
                IC++;
            default:
                break;
        }
        return;
    }

    if (label != NULL) {
        struct label *head = get_head_label();
        if (head == NULL) {
            insert_first_label(label, IC, 0, 1);
        } else
            insert_last_label(label, IC, 0, 1);
    }

    char *o = convert_10bits_to_2(cmd._opcode, 0);
    char *p1 = convert_10bits_to_2(cmd._src_operand, 0);
    char *p2 = convert_10bits_to_2(cmd._des_operand, 0);
    char *era = convert_10bits_to_2(cmd._ERA, 0);

    o = completing_number(o, 4);
    p1 = completing_number(p1, 2);
    p2 = completing_number(p2, 2);
    era = completing_number(era, 2);

    if (get_head_code() == NULL) {
        insert_first_code(IC++, strcat(o, strcat(p1, strcat(p2, era))));
    } else {
        insert_last_code(IC++, strcat(o, strcat(p1, strcat(p2, era))));
    }

    if (val_op1 == 3 && val_op2 == 3) {
        char *pv1 = convert_10bits_to_2(result_op1, 0);
        char *pv2 = convert_10bits_to_2(result, 0);

        pv1 = completing_number(pv1, 4);
        pv2 = completing_number(pv2, 4);

        if (get_head_code() == NULL) {
            insert_first_code(IC++, strcat(strcat(pv1, pv2), "00"));
        } else {
            insert_last_code(IC++, strcat(strcat(pv1, pv2), "00"));
        }

    } else {
        switch (val_op1) {
            case 0:
                handle_case(result_op1, 0);
                break;
            case 1:
                IC++;
                break;
            case 2:
                IC++;
                handle_case(result_op1, 0);
                break;
            case 3:
                handle_case(result_op1, 1);
            default:
                break;
        }

        switch (val_op2) {
            case 0:
                handle_case(result, 0);
                break;
            case 1:
                IC++;
                break;
            case 2:
                IC++;
                handle_case(result, 0);
                break;
            case 3:
                handle_case(result, 2);
                break;
            default:
                break;
        }
    }
}

char *completing_number(char *s, int n) {
    if (strlen(s) != n) {
        int length = n - strlen(s);
        char *str = (char *) malloc(2);
        int l, q = 0;
        for (l = 0; l < n + 1; ++l) {
            if (l < length)
                str[l] = '0';
            else {
                if (l == n)
                    str[l] = '\0';
                else
                    str[l] = s[q++];
            }
        }
        return str;
    }
    return s;
}

void handle_round2_c2(int val_op1, int val_op2, char **operands, int line, int param) {
    char *m1 = NULL;
    if (val_op1 == 2 && param == 1) {
        int size = (strlen(*(operands)) - 2);
        m1 = (char *) malloc((size_t) size);
        memcpy(m1, *(operands), (size_t) size);
        m1[size] = '\0';
    }

    if (val_op2 == 2 && param == 2) {
        int size = (strlen(*(operands)) - 2);
        m1 = (char *) malloc((size_t) size);
        memcpy(m1, *(operands), (size_t) size);
        m1[size] = '\0';
    }

    if (m1 != NULL) {
        struct label *lab = find_label(m1, IC);
        if (lab != NULL) {
            char *ln = convert_10bits_to_2(lab->line, 0);
            ln = completing_number(ln, 8);
            if (get_head_code() == NULL) {
                insert_first_code(IC++, strcat(ln, "10"));
            } else {
                insert_last_code(IC++, strcat(ln, "10"));
            }
        } else {
            printf("Syntex: Label Not Found Or Not Declared Please Fix Line - %d.\n", line);
            return;
        }
    }
}

void handle_round2_c1(int val_op1, int val_op2, char **operands, int line) {
    struct label *lab;
    if (val_op1 != -1 && val_op2 != -1)
        lab = find_label(*(operands + 1), IC);
    else
        lab = find_label(*operands, IC);

    if (lab != NULL) {
        char *ln = convert_10bits_to_2(lab->line, 0);
        ln = completing_number(ln, 8);
        if (get_head_code() == NULL) {
            if (lab->ext == 1)
                insert_first_code(IC++, strcat(ln, "01"));
            else
                insert_first_code(IC++, strcat(ln, "10"));
        } else {
            if (lab->ext == 1)
                insert_last_code(IC++, strcat(ln, "01"));
            else
                insert_last_code(IC++, strcat(ln, "10"));
        }
    } else {
        printf("Syntex: Label Not Found Or Not Declared Please Fix Line - %d", line);
        return;
    }
}

void handle_case(int result, int pos) {
    char *number = convert_10bits_to_2(abs(result), 0);
    _Bool flag = 0;

    if(result < 0){
        flag = 1;
    }
    if (pos == 1) {
        number = completing_number(number, 4);
        strcat(number, "000000");
    } else if (pos == 2) {
        number = completing_number(number, 4);
        char *temp = (char *) calloc((size_t) temp, 11);
        if (!temp) {
            printf("Syntex: Not Enough Space In Memory To parse");
            return;
        }
        int k;
        for (k = 0; k < 4; ++k) {
            temp[k] = '0';
        }
        strcat(temp, number);
        strcat(temp, "00");
        number = temp;
    } else {
        if(flag)
            number = plus_to_minus(completing_number(number, 8));
        else
            number = completing_number(number, 8);

        strcat(number, "00");
    }
    if (get_head_code() == NULL) {
        insert_first_code(IC++, number);
    } else {
        insert_last_code(IC++, number);
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
