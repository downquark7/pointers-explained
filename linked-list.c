# include <stdio.h>

struct linked {
    char c;
    struct linked *next;
};

void main(void) {

    struct linked a = {'a', NULL};

    struct linked b = {'b', NULL};
    a.next = &b;

    struct linked c = {'c', NULL};
    b.next = &c;

    // uncomment to find out what happens
    // a.next = &c;

    while (1) {
        printf("%c\n", a.c);
        if (a.next == NULL)
            break;
        a = *a.next;
    }
}
