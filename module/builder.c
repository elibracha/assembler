
/*******************************************************
   This file responsible for commend logic and management.
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

// Variable To Share Errors And Decide If To Produce Files.
int ERRORS = 0;

// This Function Responsable For Handling The CMP OPCODE And Commend.
void cmp_handler(char *label, char *op, char **operands, int line, int n, int round) {
    //Checking Minimum Arguments Passed.
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {
        handle_cmd(label, operands, line, CMP, TWO_ARGUMENTS, round);
    } else {
        return;
    }
}

// This Function Responsable For Handling The MOV OPCODE And Commend.
void mov_handler(char *label, char *op, char **operands, int line, int n, int round) {
    //Checking Minimum Arguments Passed.
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {
        handle_cmd(label, operands, line, MOV, TWO_ARGUMENTS, round);
    } else {
        return;
    }
}

// This Function Responsable For Handling The ADD OPCODE And Commend.
void add_handler(char *label, char *op, char **operands, int line, int n, int round) {
    //Checking Minimum Arguments Passed.
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {
        handle_cmd(label, operands, line, ADD, TWO_ARGUMENTS, round);
    } else {
        return;
    }
}

// This Function Responsable For Handling The SUB OPCODE And Commend.
void sub_handler(char *label, char *op, char **operands, int line, int n, int round) {
    //Checking Minimum Arguments Passed.
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {
        handle_cmd(label, operands, line, SUB, TWO_ARGUMENTS, round);
    } else {
        return;
    }
}

// This Function Responsable For Handling The LEA OPCODE And Commend.
void lea_handler(char *label, char *op, char **operands, int line, int n, int round) {
    //Checking Minimum Arguments Passed.
    if (check_arguments(n, op, line, TWO_ARGUMENTS)) {
        handle_cmd(label, operands, line, LEA, TWO_ARGUMENTS, round);
    } else {
        return;
    }
}

// This Function Responsable For Handling The INC OPCODE And Commend.
void inc_handler(char *label, char *op, char **operands, int line, int n, int round) {
    //Checking Minimum Arguments Passed.
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, INC, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

// This Function Responsable For Handling The CLR OPCODE And Commend.
void clr_handler(char *label, char *op, char **operands, int line, int n, int round) {
    //Checking Minimum Arguments Passed.
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, CLR, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

// This Function Responsable For Handling The NOT OPCODE And Commend.
void not_handler(char *label, char *op, char **operands, int line, int n, int round) {
    //Checking Minimum Arguments Passed.
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, NOT, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

// This Function Responsable For Handling The DEC OPCODE And Commend.
void dec_handler(char *label, char *op, char **operands, int line, int n, int round) {
    //Checking Minimum Arguments Passed.
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, DEC, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

// This Function Responsable For Handling The JMP OPCODE And Commend.
void jmp_handler(char *label, char *op, char **operands, int line, int n, int round) {
    //Checking Minimum Arguments Passed.
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, JMP, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

// This Function Responsable For Handling The BNE OPCODE And Commend.
void bne_handler(char *label, char *op, char **operands, int line, int n, int round) {
    //Checking Minimum Arguments Passed.
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, BNE, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

// This Function Responsable For Handling The RED OPCODE And Commend.
void red_handler(char *label, char *op, char **operands, int line, int n, int round) {
    //Checking Minimum Arguments Passed.
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, RED, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

// This Function Responsable For Handling The PRN OPCODE And Commend.
void prn_handler(char *label, char *op, char **operands, int line, int n, int round) {
    //Checking Minimum Arguments Passed.
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, PRN, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

// This Function Responsable For Handling The JSR OPCODE And Commend.
void jsr_handler(char *label, char *op, char **operands, int line, int n, int round) {
    //Checking Minimum Arguments Passed.
    if (check_arguments(n, op, line, ONE_ARGUMENTS)) {
        handle_cmd(label, operands, line, JSR, ONE_ARGUMENTS, round);
    } else {
        return;
    }
}

// This Function Responsable For Handling The RTS OPCODE And Commend.
void rts_handler(char *label, char *op, char **operands, int line, int n, int round) {
    //Checking Minimum Arguments Passed.
    if (check_arguments(n, op, line, ZERO_ARGUMENTS)) {
        handle_cmd(label, operands, line, RTS, ZERO_ARGUMENTS, round);
    } else {
        return;
    }
}

// This Function Responsable For Handling The STOP OPCODE And Commend.
void stop_handler(char *label, char *op, char **operands, int line, int n, int round) {
    //Checking Minimum Arguments Passed.
    if (check_arguments(n, op, line, ZERO_ARGUMENTS)) {
        handle_cmd(label, operands, line, STOP, ZERO_ARGUMENTS, round);
    } else {
        return;
    }
}

//Data Function Handler, Checking And Responding To .data Defined.
void data_handler(char *label, char **operands, int params) {
    _Bool flag = 0; // flag to notice minus or plus.
    if (label != NULL) { // handling new label if label not Null.
        struct label *head = get_head_label();
        if (head == NULL) {
            insert_first_label(label, DC, 0, 0);
        } else
            insert_last_label(label, DC, 0, 0);
    }
    while (params) { //building the clean string number without any unknown chars.
        int i = 0;
        for (i = 0; *((*operands) + i) != '\0'; ++i) {
            if (i == 0 && *((*operands) + i) == '-' || *((*operands) + i) == '+') {
                flag = 1;
                continue;
            }
            if (*((*operands) + i) <= 57 && *((*operands) + i) >= 48) {
                continue;
            } else {
                printf(UNKNOWN_CHAR_MIDDLE); // handling unknown char in middle of number.
                ERRORS++;
                return;
            }
        }
        int number;
        if (flag) // responding to minus or plus
            number = atoi((*operands) + 1);
        else
            number = atoi(*operands);

        //handling the number if its the frist number and also if it is not.
        if (get_head_data() == NULL) {
            if (flag) {
                insert_first_data(DC++, plus_to_minus(
                        convert_10bits_to_2(number, 1))); // handling first data and also minus number.
            } else {
                insert_first_data(DC++, convert_10bits_to_2(number, 1)); // normal positive number at the beginning.
            }
        } else {
            if (flag) {
                insert_last_data(DC++, plus_to_minus(convert_10bits_to_2(number, 1))); // handling minus number.
            } else {
                insert_last_data(DC++, convert_10bits_to_2(number, 1)); // normal positive number at the end.
            }
        }
        operands++;
        params--;
        flag--;
    }
}

//String Function Handler, Checking And Responding To .string Defined.
void string_handler(char *label, char **operands, int params) {
    //checking if more then 1 string was passed.
    if (params > 1) {
        printf(TOO_MANY_STRINGS); // handling too many strings passed.
        ERRORS++;
        return;
    }

    //handling new labal in the string.
    if (label != NULL) {
        if (get_head_label()) {
            insert_first_label(label, DC, 0, 0);
        } else
            insert_last_label(label, DC, 0, 0);
    }


    int i;
    for (i = 0; i < strlen(*operands); ++i) { // running on each char in the string to asign a "byte".
        if (i == 0) {
            if (**operands == MARKS) { // ignoring first quotation mark.
                continue;
            } else {
                printf(NO_MARKS_AT_BEGINING); //showing error if no quotation mark is at the begining.
                ERRORS++;
                return;
            }
        }

        if (i + 1 == strlen(*operands)) { // handling end of a string.
            if (*((*operands) + i) == '\"') {
                insert_last_data(DC++, convert_10bits_to_2(0, 1)); // adding null char.
                continue;
            } else {
                printf(NO_MARKS_AT_END); // show error if no quotation mark at the end.
                ERRORS++;
                return;
            }
        }

        if (get_head_data() == NULL) { // defualt add to a char after passing all tests above for valid char.
            insert_first_data(DC++, convert_10bits_to_2((int) *((*operands) + i), 1));
        } else {
            insert_last_data(DC++, convert_10bits_to_2((int) *((*operands) + i), 1));
        }
    }

}

//Struct Function Handler, Checking And Responding To .struct Defined.
void struct_handler(char *label, char **operands, int params) {
    //checking only 2 params was passed
    if (params == 2) {
        data_handler(label, operands, 1); // firing data handler for first param (number).
        string_handler(NULL, (operands + 1), 1); // firing string handler for second param (string).
    } else {
        return;
    }
}

//Extern Function Handler, Checking And Responding To .extern Defined.
void extern_handler(char **operands, int params) {
    //checking only 1 param was passed
    if (params != 1) { // too many or too low params entered.
        printf(EXTERN_ARGS_NUMBER);
        ERRORS++;
        return;
    }

    if (get_head_label() == NULL) { // adding the extern label to table.
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

// This Function Checks Addressing Method 0 (Immediate number).
_Bool check_Addressing_0(char *operand, int line, int *num) {
    if (*operand == ASTRICK) { // checking astrick at the beginning.
        int j = 1;
        if (*(operand + 1) == POSITIVE) { // marking and handling positive number
            j = 2;
        }
        char *clean_operand = (char *) malloc(sizeof(strlen(operand) - j));
        //checking for space allocation fail.
        if (!clean_operand) {
            printf(SPACE_ALLOCATION_FAILED);
            ERRORS++;
            exit(0);
        }
        int i;
        for (i = 0; i < strlen(operand) - 1; ++i) {
            if (i + j == strlen(operand)) { // adding end of string char.
                *(clean_operand + i) = END_OF_INPUT;
                continue;
            }

            if (!isdigit(*(operand + i + j))) { // checking all numbers are digits.
                if (!(*(operand + 1) == NEGATIVE && i + j == 1)) {
                    printf(INVALID_ADDRASSING_0, line, operand);
                    ERRORS++;
                    return 0;
                }
            }
            *(clean_operand + i) = *(operand + i + j);
        }
        int result = atoi(clean_operand); // parsing number to int.
        if (result == 0) {
            printf(INVALID_ADDRASSING_0, line, operand);
            ERRORS++;
        } else {
            *num = result; // asigning result to number.
            return 1;
        }
    }
    return 0;
}

// This Function Checks Addressing Method 1 (data number).
_Bool check_Addressing_1(char *operand, int line, _Bool num_operand) {
    int temp_result;
    if (check_Addressing_0(operand, line, &temp_result)) { // checking that no data variable gets number representation.
        if (num_operand == 0) {
            printf(MISSPLACED_ADDRESSING, 2, 1, "Immediate Number",
                   line); // case first operand is assigned with a number.
            ERRORS++;
        } else {
            printf(MISSPLACED_ADDRESSING, 1, 1, "Immediate Number",
                   line); // case second operand is assigned with a number.
            ERRORS++;
        }
        return 0;
    } else if (check_Addressing_2(operand, line, &temp_result)) { // checking for method number 2 addressing.
        return 0;
    }
    // checking for method number 3 addressing.
    if (strcmp(operand, "r0") == 0 || strcmp(operand, "r1") == 0 || strcmp(operand, "r2") == 0 ||
        strcmp(operand, "r3") == 0 || strcmp(operand, "r4") == 0 || strcmp(operand, "r5") == 0 ||
        strcmp(operand, "r6") == 0) {
        return 0;
    }

    int i;
    for (i = 0; i < strlen(operand); ++i) {
        if (i == 0) {
            if (*operand < 97 && *operand > 90 || *operand > 120 || *operand < 65) { // checking start char is valid.
                printf(INVALID_LABEL_START, *operand, line);
                ERRORS++;
                return 0;
            }
        } else if ((*(operand + i) < 97 && *(operand + i) > 90) || *(operand + i) > 120 ||
                   //checking middle chars are valid.
                   (*(operand + i) < 65 && *(operand + i) > 57) ||
                   *(operand + i) < 48 && *(operand + i) != 0 && strlen(operand) <= 32) {
            printf(INVALID_LABEL_MIDDLE, *(operand + i), line);
            ERRORS++;
            return 0;
        }
    }
}

// This Function Checks Addressing Method 2 (struct).
_Bool check_Addressing_2(char *operand, int line, int *num) {

    char *field = NULL;
    if ((field = strchr(operand, '.'))) { // checking struct addressing with dot.
        if (strcmp(field + 1, "1") == 0 || strcmp(field + 1, "2") == 0) { // checking second varialbe is 1 or 2.
            *num = atoi(field + 1);
            _Bool begin = 1;
            while (*(operand + 2) != '\0') {
                if (begin) {
                    if (*operand < 97 && *operand > 90 || *operand > 120 || *operand < 65 ||
                        strlen(field) != 2) { // checks that struct starts with valid char.
                        printf(INVALID_STRUCT_START, *operand, line);
                        ERRORS++;
                        return 0;
                    }
                    begin = 0;
                } else {
                    if ((*operand < 97 && *operand > 90) || *operand > 120 ||
                        (*operand < 65 && *operand > 57) || *operand < 48 ||
                        strlen(operand) >= 32) { // checks that struct conatins only valid chars.
                        printf(INVALID_STRUCT_MIDDLE, *operand, line);
                        ERRORS++;
                        return 0;
                    }
                    operand++;
                }
            }
            return 1;
        } else {
            printf(STRCUT_SECOND_PARAM_ERROR, line); // handlling struct second param error
            ERRORS++;
            return 0;
        }
    }


}

// This Function Checks Addressing Method 1 (register).
_Bool check_Addressing_3(char *operand, int *result) {

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

// The Main Method To Handle Incoming Commend
void handle_cmd(char *label, char **operands, int line, method *md, int args, int round) {
    commend cmd;
    int i = 0, k = 0, j, val_op1 = -1, val_op2 = -1, result_op1 = 0, result = 0;
    _Bool on_p1 = 1, addressing = 0;

    //defualt set up for struct and commmend
    cmd._opcode = md->opcode;
    cmd._src_operand = 0;
    cmd._des_operand = 0;
    cmd._ERA = 0;

    //looping for possible argument support of each method. (the initialize helps here)
    for (j = 1; j < 5; ++j) {
        if (on_p1 && args == 2)
            addressing = md->op1[i]; // possiable methos for argument 1
        else if (args == 1) {
            addressing = md->op2[i]; // possiable methos for argument 2
            on_p1 = 0;
        } else
            break; // zero support for arguments

        if (addressing) {
            switch (i) {
                case 0:
                    if (check_Addressing_0(*(operands + k), line, &result)) { //checking method 0
                        //if on oprand 1 setting the operand else setting second (on_p1 used as flag to know with to set)
                        if (on_p1) {
                            val_op1 = 0; // setting the value of the method (addressing 0) for future use.
                            cmd._src_operand = (unsigned int) val_op1; //assigning result.
                        } else {
                            val_op2 = 0; // setting the value of the method (addressing 0) for future use.
                            cmd._des_operand = (unsigned int) val_op2; //assigning result.
                        }
                        j = 4;
                        k++;
                    }
                    break;
                case 1:
                    if (check_Addressing_1(*(operands + k), line, on_p1)) { //checking method 1
                        //if on oprand 1 setting the operand else setting second (on_p1 used as flag to know with to set)
                        if (on_p1) {
                            val_op1 = 1; // setting the value of the method (addressing 1) for future use.
                            cmd._src_operand = (unsigned int) val_op1; //assigning result.
                        } else {
                            val_op2 = 1; // setting the value of the method (addressing 1) for future use.
                            cmd._des_operand = (unsigned int) val_op2; //assigning result.
                        }
                        j = 4;
                        k++;
                    }
                    break;
                case 2:
                    if (check_Addressing_2(*(operands + k), line, &result)) { //checking method 2
                        //if on oprand 1 setting the operand else setting second (on_p1 used as flag to know with to set)
                        if (on_p1) {
                            val_op1 = 2;// setting the value of the method (addressing 2) for future use.
                            cmd._src_operand = (unsigned int) val_op1; //assigning result.
                        } else {
                            val_op2 = 2;// setting the value of the method (addressing 2) for future use.
                            cmd._des_operand = (unsigned int) val_op2; //assigning result.
                        }
                        j = 4;
                        k++;
                    }
                    break;
                case 3:;
                    if (check_Addressing_3(*(operands + k), &result)) { //checking method 3
                        //if on oprand 1 setting the operand else setting second (on_p1 used as flag to know with to set)
                        if (on_p1) {
                            val_op1 = 3; // setting the value of the method (addressing 3) for future use.
                            cmd._src_operand = (unsigned int) val_op1; //assigning result.
                        } else {
                            val_op2 = 3; // setting the value of the method (addressing 3) for future use.
                            cmd._des_operand = (unsigned int) val_op2; //assigning result.
                        }
                        j = 4;
                        k++;
                    }
                    break;
                default:
                    break;
            }
        }

        //if some method was supported and passed setting all to zero and moving to second operand.
        if (j == 4 && on_p1) {
            result_op1 = result;
            args--;
            on_p1 = 0;
            j = -1;
            i = -1;
        }

        i++;
    }

    // checking if current run is in round 2.
    if (round == 2) {
        IC++;
        if (val_op1 == 3 && val_op2 == 3) { // IC increse to handle 2 registers to follow up
            IC++;
            return;
        }

        switch (val_op1) {
            case 0:
                IC++;// IC increse to follow up
                break;
            case 1:
                handle_round2_c1(val_op1, val_op2, operands, line); // filling missing label address
                break;
            case 2:
                handle_round2_c2(val_op1, val_op2, operands, line, 1); //filling missing struct address
                IC++;
                break;
            case 3:
                IC++;// IC increse to follow up
            default:
                break;
        }

        switch (val_op2) {
            case 0:
                IC++;// IC increse to follow up
                break;
            case 1:
                handle_round2_c1(val_op1, val_op2, operands, line); //filling missing label address
                break;
            case 2:
                handle_round2_c2(val_op1, val_op2, operands, line, 2); //filling missing struct address
                IC++;
                break;
            case 3:
                IC++;// IC increse to follow up
            default:
                break;
        }
        return;
    }

    //handliing new label in commend
    if (label != NULL) {
        struct label *head = get_head_label();
        if (head == NULL) {
            insert_first_label(label, IC, 0, 1);
        } else
            insert_last_label(label, IC, 0, 1);
    }

    char *o = convert_10bits_to_2(cmd._opcode, 0); // getting opcode representation as bits
    char *p1 = convert_10bits_to_2(cmd._src_operand, 0); // getting operand 1 representation as bits
    char *p2 = convert_10bits_to_2(cmd._des_operand, 0); // getting operand 2 representation as bits
    char *era = convert_10bits_to_2(cmd._ERA, 0); // getting era representation as bits

    // filling missing zeros in the computer 10 bits representation
    o = completing_number(o, 4);
    p1 = completing_number(p1, 2);
    p2 = completing_number(p2, 2);
    era = completing_number(era, 2);

    //adding code
    if (get_head_code() == NULL) {
        insert_first_code(IC++, strcat(o, strcat(p1, strcat(p2, era))));
    } else {
        insert_last_code(IC++, strcat(o, strcat(p1, strcat(p2, era))));
    }

    //handling 2 registers
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
        // final setup each operand gets a switch and when method is selected the commend is finished and proccessed.
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

//Filling Missing Zeros When Needed With n As Number Of The Number You Need.
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

//This Function Hnadles Case 2 (Method 2) In Round 2.
void handle_round2_c2(int val_op1, int val_op2, char **operands, int line, int param) {
    char *m1 = NULL;

    //handling operand 1 struct
    if (val_op1 == 2 && param == 1) {
        int size = (strlen(*(operands)) - 2);
        m1 = (char *) malloc((size_t) size);
        memcpy(m1, *(operands), (size_t) size);
        m1[size] = END_OF_INPUT;
    }

    //handling operand 2 struct
    if (val_op2 == 2 && param == 2) {
        int size = (strlen(*(operands)) - 2);
        m1 = (char *) malloc((size_t) size);
        memcpy(m1, *(operands), (size_t) size);
        m1[size] = END_OF_INPUT;
    }

    if (m1 != NULL) {
        struct label *lab = find_label(m1, IC); // finding label in table
        if (lab != NULL) {
            char *ln = convert_10bits_to_2(lab->line, 0); // getting label address
            ln = completing_number(ln, 8); // adding missing zeros
            if (get_head_code() == NULL) {
                insert_first_code(IC++, strcat(ln, "10")); // setting era
            } else {
                insert_last_code(IC++, strcat(ln, "10"));  // setting era
            }
        } else {
            printf(LABEL_NOT_FOUND, line); // label not found
            return;
        }
    }
}

//This Function Hnadles Case 1 (Method 1) In Round 2.
void handle_round2_c1(int val_op1, int val_op2, char **operands, int line) {
    struct label *lab;
    //findding label
    if (val_op1 != -1 && val_op2 != -1)
        lab = find_label(*(operands + 1), IC);
    else
        lab = find_label(*operands, IC);

    if (lab != NULL) {
        char *ln = convert_10bits_to_2(lab->line, 0);
        ln = completing_number(ln, 8);
        if (get_head_code() == NULL) {
            if (lab->ext == 1)
                insert_first_code(IC++, strcat(ln, "01")); //extern label
            else
                insert_first_code(IC++, strcat(ln, "10")); //address location label
        } else {
            if (lab->ext == 1)
                insert_last_code(IC++, strcat(ln, "01")); //extern label
            else
                insert_last_code(IC++, strcat(ln, "10")); //address location label
        }
    } else {
        printf(LABEL_NOT_FOUND, line); // label not found
        return;
    }
}

// handling case in round 1.
void handle_case(int result, int pos) {
    // converting number to bits
    char *number = convert_10bits_to_2(abs(result), 0);
    _Bool flag = 0;

    // minus flag
    if (result < 0) {
        flag = 1;
    }
    //flag for pos (register) left side
    if (pos == 1) {
        number = completing_number(number, 4);
        strcat(number, "000000"); // adding missing zeros
    } else if (pos == 2) { //flag for pos (register) right side

        number = completing_number(number, 4); // completting zeros
        char *temp = NULL;

        temp = (char *) calloc((size_t) temp, 11);
        if (!temp) {
            printf(SPACE_ALLOCATION_FAILED); // allocation fail.
            return;
        }

        int k;
        for (k = 0; k < 4; ++k) {
            temp[k] = '0'; // adding missing zeros
        }
        strcat(temp, number);
        strcat(temp, "00");
        number = temp;
        
    } else {
        if (flag)
            number = plus_to_minus(completing_number(number, 8)); // 2 completion flag minus
        else
            number = completing_number(number, 8); // normal number

        strcat(number, "00");
    }

    //adding number to code table
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

//initializing all methods support for arguments
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
