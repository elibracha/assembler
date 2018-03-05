
/********************************************

   This file responsible for base swapping.

 ********************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MEMORY_OVERFLOW "Error: No Memory Space To Execute Convertion Between Bases.\n"

void exit_program();

/*
 * This function responsible for swapping between number on base 2 to base 32.
 */

const char* convert_2bits_to_32(const char* number_to_convert){

    char BaseChars32[] = { '!','@','#','$','%','^','&'
            ,'*','<','>','a','b','c','d'
            ,'e','f','g','h','i','j','k'
            ,'l','m','n','o','p','q','r'
            ,'s','t','u','v' };

    short int length = (short) strlen(number_to_convert);
    short int numbers_base_10[length/5];
    short int current_sum = 0;
    short int current_index = 0;
    short int stages[] = {16,8,4,2,1};

    int i;

    for (i = 0; i < length; i++) {
        int temp = number_to_convert[i] - '0';
        if (temp == 1)
            current_sum += temp*stages[i%5];
        if((i+1)%5 == 0 && i != 0){
            numbers_base_10[current_index++] = current_sum;
            current_sum = 0;
        }
    }

    int result_length = sizeof(numbers_base_10)/sizeof(short int);

    char* result = (char*) calloc(result_length, sizeof(char));
    int j;

    if(result != NULL)
        for (j = 0; j < result_length; j++){
            char convertedLetter = BaseChars32[numbers_base_10[j]];
            result[j] = convertedLetter;
        }
    else
        exit_program();

    return result;
}

/*
 * This function responsible for swapping between number on base 10 to base 2.
 */

const char* convert_10bits_to_2(const char* number_to_convert) {

    signed int number = atoi(number_to_convert);
    short int counter = 0;
    _Bool* binary_number = (_Bool *) calloc((size_t) (counter + 1), sizeof(_Bool));

    while (number >= 0) {

        if(number == 0){
            break;
        }

        if (binary_number == NULL) {
            exit_program();
        }

        binary_number[counter] = (_Bool) (number % 2);

        if (number % 2 == 0){
            number = number / 2;
        } else {
            number = (number - 1) / 2;
        }

        counter++;
        if(number != 0)
            binary_number = (_Bool*) realloc(binary_number, (size_t) (counter + 1));
    }

    int j, i;
    _Bool flag = 1;
    int length = (5 - (counter % 5)) % 5;
    char* result = (char*) calloc((size_t) (counter + length), sizeof(char));

    for (i = counter-1; i >= 0; --i) {
        if(counter  %5 != 0 && flag) {
            for (j = 0; j < length; ++j)
                *(result + j) = '0';
        }
        flag = 0;

        if(*(binary_number + i) == 1)
            *(result + length++) = '1' ;
        else
            *(result + length++) = '0';
    }

    free(binary_number);
    return result;
}

void exit_program(){
    printf(MEMORY_OVERFLOW);
    exit(0);
}