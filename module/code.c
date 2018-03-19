/******************************************************

 This file responsible for tracking after code section.

 *******************************************************/

#include "./code.h"

struct code {
	char *data;
	int addressing_code;
	struct code *next;
};

struct code *head_code = NULL;
struct code *current_code = NULL;

extern int IC, DC;

struct code *get_head_code() {
	return head_code;
}

//writing code to a file
void write_code_list(char *name) {
	struct code *ptr = head_code;

	FILE *fptr = fopen(name, "w");

	if (!fptr) {
		printf("Error!");
		exit(1);
	}

	fprintf(fptr, "%s\t%s \n",
			convert_2bits_to_32(convert_10bits_to_2(IC - 100, 1)),
			convert_2bits_to_32(convert_10bits_to_2(DC, 1)));

	while (ptr != NULL) {
		fprintf(fptr, "%s\t%s \n",
				convert_2bits_to_32(
						convert_10bits_to_2(ptr->addressing_code, 1)),
				convert_2bits_to_32(ptr->data));
		ptr = ptr->next;
	}

	fclose(fptr);
}

//insetting code to the end of the list
void insert_last_code(int ic, char *number) {
	struct code *link = (struct code *) malloc(sizeof(struct code));

	if (!link) {
		printf(ERROR_ALLOCATION);
		exit(0);
	}

	link->addressing_code = ic;
	link->data = number;
	link->next = NULL;

	current_code = head_code;

	while (current_code->next != NULL) {
		current_code = current_code->next;
	}

	current_code->next = link;
}

//insetting code to the beginning of the list
void insert_first_code(int ic, char *number) {
	struct code *link = (struct code *) malloc(sizeof(struct code));

	if (!link) {
		printf(ERROR_ALLOCATION);
		exit(0);
	}

	link->addressing_code = ic;
	link->data = number;

	link->next = head_code;

	head_code = link;
}

//getting the length of the list
int length() {
	int length = 0;
	struct code *current;

	for (current = head_code; current != NULL; current = current->next) {
		length++;
	}

	return length;
}

//sortting the list by address
void sort() {

	int i, j, k, tempKey;
	char *tempData;
	struct code *current;
	struct code *next;

	int size = length();
	k = size;

	for (i = 0; i < size - 1; i++, k--) {
		current = head_code;
		next = head_code->next;

		for (j = 1; j < k; j++) {

			if (current->addressing_code > next->addressing_code) {
				tempData = current->data;
				current->data = next->data;
				next->data = tempData;

				tempKey = current->addressing_code;
				current->addressing_code = next->addressing_code;
				next->addressing_code = tempKey;
			}

			current = current->next;
			next = next->next;
		}
	}
}
