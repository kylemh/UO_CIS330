#include <stdio.h>
#include "directory.h"

#define MAX_LENGTH 50

static Contact phoneBook[MAX_LENGTH];
static int entryNum = 0;

/* Add a phonebook entry */
void AddContact(Contact entry) {
	if (entryNum == MAX_LENGTH) {
		return;
	}
	phoneBook[entryNum] = entry;
	entryNum++;

}

/* Delete a phonebook entry */
void DeleteContact(int index){
	if (index < 0 || index > entryNum - 1) {
		return;
	}

	for (int i = index + 1; i < entryNum; i++) {
		phoneBook[i - 1] = phoneBook[i];
	}

	entryNum--;

}

/* Get the number of phonebook entries */
int ContactCount() {
	return entryNum;
}

/* Get all of the phonebook entries */
Contact ContactGet(int index) {
	return phoneBook[index];
}

void printCurrentDirectory() {
	printf("\nCurrent directory:\n");
	int entryNum = ContactCount();
	for (int i = 0; i < entryNum; i++) {
		Contact entry = ContactGet(i);
		printf("%d. %s, %s\n", i + 1, entry.name, entry.phone);
	}
}



