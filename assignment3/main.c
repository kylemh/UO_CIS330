/* This code collaberatively designed by Kyle Holmberg and Kristen Splonkowski */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#include "directory.h"

void clearInputBuffer() {
  while ( getchar() != '\n' );
}

static void getEntry() {
	int choice;
	printf("Please choose an option:\n");
	printf("1. Insert a new entry.\n"); 
	printf("2. Delete an entry.\n"); 
	printf("3. Display current directory.\n");
	printf("Option: ");
	scanf("%d", &choice);
	clearInputBuffer();

	if (choice == 1) {
		Contact entry;
		printf("Enter a name: ");
		scanf("%50[a-zA-Z ]", entry.name);
		clearInputBuffer();
		printf("Enter a phone number: ");
		scanf("%50s", entry.phone);
		clearInputBuffer();
		AddContact(entry);
		printf("\n");
	}
	
	if (choice == 2) {
		int option;
		printCurrentDirectory();
		printf("Which entry should I delete? ");
		scanf("%d", &option);
		clearInputBuffer();
		DeleteContact(option - 1);
		printf("\n");
	}
	
	if (choice == 3) {
		printCurrentDirectory();
		printf("\n");
	}
}

int main() {
	while (1) { getEntry(); }
	return 0;
}

