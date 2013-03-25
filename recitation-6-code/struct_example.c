#include <stdio.h>
#include <stdlib.h> // for malloc

struct Contact {
        char *first;
        char *last;
        int number;
};

/* Met a cute girl at Mel's, gotta add her */
struct Contact *createContact(char *_first, char *_last, int _number)
{
        struct Contact *new = (struct Contact *)malloc(sizeof(struct Contact));
        if (new == NULL)
                {
                        printf("malloc failed");
                        return NULL;
                }
        new -> first = _first;
        new -> last = _last;
        new -> number = _number;
        return new;
}

/* And now she's making out with my friend, forget her */
void deleteContact(struct Contact *c)
{
        free(c);
}

void printContact(struct Contact *c)
{
        printf("%s %s's number is %d\n", c -> first, c -> last, c -> number);
}

int main(int argc, char **argv)
{
        struct Contact *c1 = createContact("Don", "Yu", 1234567890);
        printContact(c1);
        deleteContact(c1);
        return 0;
}
