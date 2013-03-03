#include <stdio.h>
#include <stdlib.h> // for malloc and qsort()
#include <string.h> // for strncmp

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

/* prints a contact info */
void printContact(struct Contact *c)
{
        printf("%s %s's number is %d\n", c -> first, c -> last, c -> number);
}

// void qsort(void *baseAddress, size_t numElem, size_t sizeElem,
//  int (*compareFn)(const void *, const void *));

int compareContacts(const void *c1, const void *c2)
{
        int val;
        if ((val = strncmp(((struct Contact *)c1) -> last,
                           ((struct Contact *)c2) -> last, 20)) == 0)
                return strncmp(((struct Contact *)c1) -> first,
                               ((struct Contact *)c2) -> first, 20);
        return val;
}

int main(int argc, char **argv)
{
        struct Contact myContacts[3];   //our array of contacts that will be sorted

        // allocate memory on heap
        struct Contact *c1 = createContact("Don", "Yu", 1234567890);
        struct Contact *c2 = createContact("Etan", "Zapinsky", 1867877234);
        struct Contact *c3 = createContact("Louis", "Croce", 1555555555);

        // assign contacts
        myContacts[0] = *c1;
        myContacts[1] = *c2;
        myContacts[2] = *c3;

        // call qsort
        qsort(myContacts, 3, sizeof(struct Contact), compareContacts);

        int i;
        for (i = 0; i < 3; i++)
                {
                        printContact(&myContacts[i]);
                }

        // free space allocated on heap
        deleteContact(c1);
        deleteContact(c2);
        deleteContact(c3);
        return 0;
}
