#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

void deleteRecords(struct Node** head, int index) {
    if (!*head || index < 1) {
        printf("Invalid index. Please try again.\n");
        return;
    }

    struct Node* current = *head;
    int count = 1;

    while (current && count < index) {
        current = current->next;
        count++;
    }

    if (!current) {
        printf("Invalid index. Please try again.\n");
        return;
    }

    // Update pointers for doubly linked list
    if (current->prev) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Record deleted successfully.\n");
}
