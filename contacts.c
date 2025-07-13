#include "include/input_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME  50
#define MAX_PHONE 20
#define MAX_EMAIL 50
#define MAX_LINE  256

typedef struct {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];
} Contact;

void print_contacts(Contact *list, size_t total) {
    if (total == 0) {
        printf("No contacts yet.\n");
        return;
    }

    for (size_t i = 0; i < total; i++) {
        printf("[%zu] %s | %s | %s\n", i, list[i].name, list[i].phone, list[i].email);
    }
}

void find_contact(Contact *list, size_t total, const char *keyword) {
    int match = 0;
    for (size_t i = 0; i < total; i++) {
        if (strstr(list[i].name, keyword)) {
            printf("[%zu] %s | %s | %s\n", i, list[i].name, list[i].phone, list[i].email);
            match = 1;
        }
    }

    if (!match) {
        printf("No contact found matching: %s\n", keyword);
    }
}

void input_contact(Contact *list, size_t *total) {
    char line[MAX_LINE];

    printf("Enter name: ");
    if (!fgets(line, sizeof(line), stdin)) return;
    line[strcspn(line, "\n")] = '\0';
    strncpy(list[*total].name, line, MAX_NAME - 1);

    printf("Enter phone: ");
    if (!fgets(line, sizeof(line), stdin)) return;
    line[strcspn(line, "\n")] = '\0';
    strncpy(list[*total].phone, line, MAX_PHONE - 1);

    printf("Enter email: ");
    if (!fgets(line, sizeof(line), stdin)) return;
    line[strcspn(line, "\n")] = '\0';
    strncpy(list[*total].email, line, MAX_EMAIL - 1);

    printf("Contact added at position [%zu].\n", *total);
    (*total)++;
}

void delete_contact(Contact *list, size_t *total, size_t index) {
    if (index >= *total) {
        printf("Invalid index.\n");
        return;
    }

    for (size_t i = index; i + 1 < *total; i++) {
        list[i] = list[i + 1];
    }

    (*total)--;
    printf("Contact at position [%zu] removed.\n", index);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s MAX_CONTACTS\n", argv[0]);
        return 1;
    }

    int max_contacts = atoi(argv[1]);
    if (max_contacts <= 0) {
        printf("MAX_CONTACTS must be greater than 0.\n");
        return 1;
    }

    Contact *contacts = malloc(max_contacts * sizeof(Contact));
    if (!contacts) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    size_t total = 0;
    char input[MAX_LINE];

    printf("Contact Manager ready. Max slots: %d\n", max_contacts);

    while (1) {
        printf("\nOptions: list | search <name> | add | remove <index> | exit\n");
        printf("Enter command: ");

        if (!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            break;

        } else if (strcmp(input, "list") == 0) {
            print_contacts(contacts, total);

        } else if (strncmp(input, "search ", 7) == 0) {
            find_contact(contacts, total, input + 7);

        } else if (strcmp(input, "add") == 0) {
            if (total >= (size_t)max_contacts) {
                printf("Contact list is full.\n");
            } else {
                input_contact(contacts, &total);
            }

        } else if (strncmp(input, "remove ", 7) == 0) {
            size_t index = atoi(input + 7);
            delete_contact(contacts, &total, index);

        } else {
            printf("Unknown command.\n");
        }
    }

    free(contacts);
    printf("Goodbye!\n");
    return 0;
}
