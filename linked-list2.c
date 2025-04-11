#include <stdio.h>
#include <stdlib.h>

typedef struct link {
    char c;
    struct link *next;
} link;

int main(void) {
    link *start = NULL;
    link *cursor = NULL;

    start = (link *) malloc(sizeof(link));
    cursor = start;

    char input[] = "hello world";
    char *ptr = &input[0];
    while (1) {
        cursor->c = *ptr;
        ptr = ptr + 1;
        if (*ptr) {
            cursor->next = (link *) malloc(sizeof(link));
        }
        else {
            cursor->next = NULL;
            break;
        }
        cursor = cursor->next;
    }
    cursor->next = NULL;
    free(cursor->next);

    cursor = start;
    while (1) {
        printf("%c\n", cursor->c);
        if (cursor->next == NULL)
            break;
        cursor = cursor->next;
    }

    cursor = start;
    while (1) {
        link *temp = cursor->next;
        free(cursor);
        if (temp->next == NULL)
            break;
        cursor = temp;
    }

    return 0;
}
