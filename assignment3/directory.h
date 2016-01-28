#ifndef DIRECTORY_H_
#define DIRECTORY_H_

#define MAX_LENGTH 50

typedef struct {
	char name[MAX_LENGTH];
	char phone[MAX_LENGTH];
	struct Contact* next;
} Contact;

/* Add a phonebook entry */
void AddContact(Contact entry);

/* Delete a phonebook entry */
void DeleteContact(int index);

/* Get the number of phonebook entries */
int ContactCount();

/* Get all of the phonebook entries */
Contact ContactGet(int index);

/* Show the current list of entries */
void printCurrentDirectory();

#endif /* DIRECTORY_H_ */