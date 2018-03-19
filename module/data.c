/******************************************************

 This file responsible for tracking after code section.

 *******************************************************/

#include "./data.h"

struct data *get_head_data() {
	return head;
}

//writing data to the file
void write_data_list(char *name) {
	struct data *ptr = head;

	FILE *fptr = fopen(name, "a");

	if (!fptr) {
		printf("Error!");
		exit(1);
	}

	while (ptr != NULL) {
		const char *t = convert_2bits_to_32(
				convert_10bits_to_2(ptr->addressing_data, 1));
		fprintf(fptr, "%s\t%s \n",
				convert_2bits_to_32(
						convert_10bits_to_2(ptr->addressing_data, 1)),
				convert_2bits_to_32(ptr->data));
		ptr = ptr->next;
	}

	fclose(fptr);
}

//insert link at the end location
void insert_last_data(int dc, char *data) {
	//create a link
	struct data *link = (struct data *) malloc(sizeof(struct data));

	if (!link) {
		printf(ERROR_ALLOCATION);
		exit(0);
	}

	link->addressing_data = dc;
	link->data = data;
	link->next = NULL;

	current_data = head;
	//if it is last data
	while (current_data->next != NULL) {
		current_data = current_data->next;
	}

	current_data->next = link;
}

//updating data and addresses after first round
void update_data(int number) {
	//create a link
	current_data = head;
	struct data *link = current_data;
	if (current_data == NULL)
		return;
	//if it is last data
	while (current_data->next != NULL) {
		current_data->addressing_data += number;
		current_data = current_data->next;
	}
	current_data->addressing_data += number;
}

//insert link at the first location
void insert_first_data(int dc, char *data) {
	//create a link
	struct data *link = (struct data *) malloc(sizeof(struct data));

	if (!link) {
		printf(ERROR_ALLOCATION);
		exit(0);
	}

	link->addressing_data = dc;
	link->data = data;

	//point it to old first data
	link->next = head;

	//point first to new first data
	head = link;
}

