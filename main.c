#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

int main() {
    struct Node* head = NULL;  // Local head pointer for this run
    int index;
    char choice;
    struct PhoneRecord newRecord;
    do {
        printf("\nPhonebook Menu:\n");
        printf("[A]ppend\n");
        printf("[B]rowse\n");
        printf("[C]hange\n");
        printf("[D]elete\n");
        printf("[E]xit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

    switch (choice) {
      case 'A':
        // Get user input for new record details
        printf("Enter First Name: ");
        scanf("%s", newRecord.firstName);
        printf("Enter Middle Name: ");
        scanf("%s", newRecord.middleName);
        printf("Enter Last Name: ");
        scanf("%s", newRecord.lastName);
        printf("Enter Mobile Number: ");
        scanf("%s", newRecord.mobileNumber);
        printf("Enter Email: ");
        scanf("%s", newRecord.email);

        appendRecords(&head, newRecord);
        break;
      case 'B':
        browseRecords(head);
        break;
      case 'C':
        printf("Enter record index to change: ");
        scanf("%d", &index);
        changeRecords(head, index);
        break;
      case 'D':
        printf("Enter record index to delete: ");
        scanf("%d", &index);
        deleteRecords(&head, index);
        break;
      case 'E':
        printf("Exiting the phonebook. Goodbye!\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }

  } while (choice != 'E');

  // Free linked list nodes to avoid memory leaks
  while (head) {
    struct Node* temp = head;
    head = head->next;
    free(temp);
  }

  return 0;
}
