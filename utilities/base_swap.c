
/********************************************

   This file responsible for base swapping.

 ********************************************/

#include <mem.h>
#include <stdlib.h>

/*
 * This function responsible for swapping between number on base 2 to base 32.
 */

const char* convert2BitsTo32(char* number_to_convert){

    char BaseChars32[] = { '!','@','#','$','%','^','&'
            ,'*','<','>','a','b','c','d'
            ,'e','f','g','h','i','j','k'
            ,'l','m','n','o','p','q','r'
            ,'s','t','u','v' };

    short int length = (short) strlen(number_to_convert);
    short int numbersBase10[length/5];
    short int currentSum = 0;
    short int currentIndex = 0;
    short int stages[] = {16,8,4,2,1};

    for (int i=0; i < length; i++) {
        int temp = number_to_convert[i] - '0';
        if (temp == 1)
            currentSum += temp*stages[i%5];
        if((i+1)%5 == 0 && i != 0){
            numbersBase10[currentIndex++] = currentSum;
            currentSum = 0;
        }
    }

    int arr_length = sizeof(numbersBase10)/sizeof(short int);

    char result[arr_length + 1];

    for (int j = 0; j < arr_length; j++){
        char convertedLetter = BaseChars32[numbersBase10[j]];
        result[j] = convertedLetter;
    }

    char* res = result;
    return res;
}

/*
 * This function responsible for swapping between number on base 10 to base 2.
 */

const char* convert10BitsTo2(char* number_to_convert) {

    unsigned int number = (unsigned int) atoi(number_to_convert);
    unsigned short int* binary_number = NULL;
    unsigned short int *temp = NULL;
    short int counter = 0;
    _Bool flag1 = 1;

    for (counter; number >= 0 && flag1; ++counter) {

        if(number == 0)
            flag1 = 0;

        temp = (unsigned short int *) calloc((size_t) (counter + 1)
                , sizeof(unsigned short int));

        if (temp != NULL) {
            for (int i = 0; i < counter; ++i) {
                *(temp + i) = *(binary_number + i);
            }
            free(binary_number);
            binary_number = temp;
        }
        if (number % 2 == 0)
            number = number / 2;
        else {
            binary_number[counter] = (unsigned short) (number % 2);
            number = (number - 1) / 2;
        }
    }

    char* binary_number_str = NULL;
    _Bool flag2 = 1;
    int i = 0;

    while (counter > 0) {
        if(flag2){
            if(*(binary_number + counter-1) == 0){
                counter--;
                continue;
            }
        }

        flag2 = 0;
        if(binary_number_str == NULL)
            binary_number_str = (char*) calloc((size_t) (counter + 1), sizeof(char));

        if(*(binary_number + counter -1) == 1)
            binary_number_str[i] = '1';
        else
            binary_number_str[i] = '0';

        counter--;
        i++;
    }

    char *binary_number_str_final = NULL;

    if(strlen(binary_number_str) % 5 != 0){
        int current = 0;
        int length = (5 - strlen(binary_number_str) % 5) + strlen(binary_number_str);

        binary_number_str_final = (char*) calloc((size_t) (length + 1), sizeof(char));

        for (int j = 0; j < length; ++j) {
            if(j < 5 - strlen(binary_number_str) % 5)
                binary_number_str_final[j] = '0';
            else
                binary_number_str_final[j] = binary_number_str[current++];
        }

    }

    free(binary_number);
    free(binary_number_str);
    free(temp);

    return binary_number_str_final;
}