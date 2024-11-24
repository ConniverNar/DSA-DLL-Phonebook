#include <stdio.h>
#include <string.h>
#include "phonebook.h"

void browseRecords(struct Node* head) {
    if (!head) {
        printf("Phonebook is empty.\n");
        return;
    }

    int choice;
    int found = 0;
    char lastName[50];
    char mobileNumber[50];
        printf("Browse Options:\n");
        printf("[1] Browse All\n");
        printf("[2] Browse by Last Name\n");
        printf("[3] Browse by Mobile No.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

  switch (choice) {
    case 1:
      //browseAll(head);
       printf("Last Name\tFirst Name\tMiddle Name\tMobile No.\tEmail Address\n");
        printf("================================================================");

        // Loop through the linked list
        while (head) {
        // Print details of the current record
    printf("\n%-15s %-15s %-15s %-15s %-15s", head->record.lastName, head->record.firstName, head->record.middleName, head->record.mobileNumber, head->record.email);
    head = head->next;
        }
      break;
    case 2:
      //browseLastName(head);
        printf("Enter last name to search: ");
        scanf("%s", lastName);

        while (head) {
            if (strcmp(head->record.lastName, lastName) == 0) {
                printf("\n%-15s %-15s %-15s %-15s %-15s", head->record.lastName, head->record.firstName, head->record.middleName, head->record.mobileNumber, head->record.email);
                found = 1; // Set flag if a match found
                }
            head = head->next;
        }

        if (!found) {
            printf("\nNo records found with that last name.\n");
        }
        break;
    case 3:
      //browseEmail(head);
        printf("Enter number to search: ");
        scanf("%s", mobileNumber);

        while (head) {
            if (strcmp(head->record.mobileNumber, mobileNumber) == 0) {
                printf("\n%-15s %-15s %-15s %-15s %-15s", head->record.lastName, head->record.firstName, head->record.middleName, head->record.mobileNumber, head->record.email);
                found = 1; // Set flag if a match found
            }
            head = head->next;
        }

        if (!found) {
            printf("\nNo records found with that Mobile No..\n");
    }
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
  }
}

