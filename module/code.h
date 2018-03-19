
#ifndef ASSEMBLER_CODE_H
#define ASSEMBLER_CODE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERROR_ALLOCATION "Error: Couldn't Allocate Memory To Parse Program."

const char *convert_2bits_to_32(const char *);

char *convert_10bits_to_2(signed int, _Bool);

#endif
