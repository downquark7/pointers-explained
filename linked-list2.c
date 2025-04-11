#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
typedef struct link {
    char c; // Character value
    struct link *next; // Pointer to the next node
} link;

int main(void) {
    link *start = NULL; // Pointer to the start of the linked list
    link *cursor = NULL; // Pointer to traverse the linked list

    // Allocate memory for the first node
    start = (link *) malloc(sizeof(link));
    if (start == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    cursor = start;

    // Input string to be stored in the linked list
    char input[] = "hello world";
    char *ptr = &input[0];

    // Create the linked list from the input string
    while (*ptr != '\0') {
        cursor->c = *ptr; // Assign the current character to the node
        if (ptr[1] != '\0') {
            // Allocate memory for the next node if not the last character
            cursor->next = (link *) malloc(sizeof(link));
            if (cursor->next == NULL) {
                fprintf(stderr, "Memory allocation failed\n");

                // Free already allocated nodes before exiting
                cursor = start;
                while (cursor != NULL) {
                    link *temp = cursor->next;
                    free(cursor);
                    cursor = temp;
                }
                return 1;
            }
        } else {
            // Set the next pointer to NULL for the last node
            cursor->next = NULL;
        }
        cursor = cursor->next; // Move to the next node
        ptr = ptr + 1; // Move to the next character in the string
    }

    // Print the linked list characters
    cursor = start;
    while (cursor != NULL) {
        printf("%c\n", cursor->c); // Print the character in the current node
        cursor = cursor->next; // Move to the next node
    }

    // Free the allocated memory for the linked list
    cursor = start;
    while (cursor != NULL) {
        link *temp = cursor->next; // Store the pointer to the next node
        free(cursor); // Free the current node
        cursor = temp; // Move to the next node
    }

    return 0;
}
