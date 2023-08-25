#include "linkedList.h"

int insert_to_the_list(struct Person **list, struct Person *person, int position)
{
	struct Person *temp = *list;
	int i		    = 1;
	if (temp == NULL) {
		*list = person;
		return i == 1? 0 : 2;
	}

	if (position == 1) {
		person->next = temp;
		*list	     = person;
		return 0;
	}

	while (temp != NULL) {
		if (temp->next == NULL && (position - 1) > i) {
			temp->next = person;
			return 3;
		} else if ((position - 1) == i) {
			person->next = temp->next;
			temp->next   = person;
			return 0;
		}
		temp = temp->next;
		i++;
	}
	return 1;
}

void add_to_the_end_of_the_list(struct Person **list, struct Person *person)
{
	struct Person *temp = *list;
	if (temp == NULL) {
		*list = person;
		return;
	}

	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = person;
}

struct Person *create_node(char *name, char *surname, char *email, char *number)
{
	struct Person *person = NULL;
	person = (struct Person *)malloc(sizeof(struct Person));
	if (person == NULL) {
		return NULL;
	}
	strcpy(person->name, name);
	strcpy(person->surname, surname);
	strcpy(person->email, email);
	strcpy(person->number, number);

	person->next = NULL;
	return person;
}

struct Person *copy_node(struct Person *src)
{
	struct Person *person_copy = NULL;
	person_copy = create_node(src->name, src->surname, src->email, src->number);
	return person_copy;
}

int delete_addr_at_pos(struct Person **list, int position)
{
	struct Person *prev = *list;
	struct Person *temp = *list;
	int i = 1;
	if (*list == NULL) {
		return 1;
	}
	if (position == 1){
		*list = (*list)->next;
		free(temp);
		return 0;
	}

	while (temp != NULL) {
		if (position == i) {
			prev->next = temp->next;
			free(temp);
			return 0;
		}
		prev = temp;
		temp = temp->next;
		i++;
	}
	return 1;
}

void delete_list(struct Person **list)
{
	struct Person *to_delete = *list;
	struct Person *next;

	while (to_delete != NULL) {
		next = to_delete->next;
		free(to_delete);
		to_delete = next;
	}

	*list = NULL;
}

struct Person *find_address_by_keyword(struct Person *list, char *keyword)
{
	struct Person *temp_list = NULL;
	struct Person *node	 = NULL;
	struct Person *temp	 = list;
	int found = 0;

	while (temp != NULL) {
		if (strcmp(temp->name, keyword) == 0) {
			found = 1;
		} else if (strcmp(temp->surname, keyword) == 0) {
			found = 1;
		} else if (strcmp(temp->email, keyword) == 0) {
			found = 1;
		} else if (strcmp(temp->number, keyword) == 0) {
			found = 1;
		}

		if (found) {
			found = 1;
			node = copy_node(temp);
			add_to_the_end_of_the_list(&temp_list, node);
		}
		temp = temp->next;
	}
	
	return temp_list;
}

struct Person *find_address(struct Person **list, int index)
{
	struct Person *curr = *list;

	if (index == 1)
		return curr;
	else if (index > 1) {
		for (int i = 0; i < index - 1; i++) {
			if (curr == NULL) {
				return NULL;
			}
			curr = curr->next;
		}
		return curr;
	}

	return NULL;
}

void print_list(struct Person *list)
{
	int entry = 1;

	if (list == NULL)
		printf("The address book is empty.\n");

	struct Person *temp = list;
	while (temp != NULL) {
		printf("Entry %d -> Name - %s --- Surname - %s --- Email - %s --- Number - %s\n", entry,
		       temp->name, temp->surname, temp->email, temp->number);

		temp = temp->next;
		entry++;
	}
	printf("\n");
}

int size_of_the_book(struct Person *list)
{
	struct Person *temp = list;
	int size = 0;
	if (temp != NULL) {
		while (temp != NULL) {
			temp = temp->next;
			size++;
		}
	}

	return size;
}