#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

void changeRecords(struct Node* head, int index) {
  if (!head || index < 1) {
    printf("Invalid index. Please try again.\n");
    return;
  }

  struct Node* current = head;
  int count = 1;

  // Find the target node
  while (current && count < index) {
    current = current->next;
    count++;
  }

  if (!current) {
    printf("Invalid index. Please try again.\n");
    return;
  }

  char fieldToChange[50];
  printf("Enter the field to change (firstName, middleName, lastName, mobileNumber, email): ");
  scanf("%s", fieldToChange);

  // Modify the record based on the field
  if (strcmp(fieldToChange, "firstName") == 0) {
    printf("Enter new first name: ");
    scanf("%s", current->record.firstName);
  } else if (strcmp(fieldToChange, "middleName") == 0) {
    printf("Enter new middle name: ");
    scanf("%s", current->record.middleName);
  } else if (strcmp(fieldToChange, "lastName") == 0) {
    printf("Enter new last name: ");
    scanf("%s", current->record.lastName);
  } else if (strcmp(fieldToChange, "mobileNumber") == 0) {
    printf("Enter new mobile number: ");
    scanf("%s", current->record.mobileNumber);
  } else if (strcmp(fieldToChange, "email") == 0) {
    printf("Enter new email: ");
    scanf("%s", current->record.email);
  } else {
    printf("Invalid field name. Please try again.\n");
    return;
  }

  // Allow navigation and changes based on previous or next nodes
  char choice;
    do {
        printf("\nNavigate or modify another field?\n");
        printf("[N]ext | [P]revious | [C]hange another field | [E]xit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'N':
                if (current->next) {
                current = current->next;
                count++;
                printf("\nRecord %d details:\n", count);
                // Display current record details
                } else {
                    printf("Reached the end of the list.\n");
                }
                break;
            case 'P':
                if (current->prev) {
                current = current->prev;
                count--;
                printf("\nRecord %d details:\n", count);
                // Display current record details
            }   else {
                printf("Reached the beginning of the list.\n");
                }
                break;
            case 'C':
                char answer;
                printf("Do you want to change another field in this record (Y/N)? ");
                scanf(" %c", &answer);
        } while (toupper(answer) == 'Y');
                break;
            case 'E':
                printf("Exiting change mode.\n");
                break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
        } while (choice != 'E');
            printf("Record modified successfully.\n");
}
