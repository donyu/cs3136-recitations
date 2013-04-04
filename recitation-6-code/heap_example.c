#include <stdio.h> // look!  a new library for malloc and free!
#include <stdlib.h>

int *allocateIntArray()
{
        int *p = (int *)malloc(3 * sizeof(int));
        return p;
}

void callNumber(int *p, int n)
{
        printf("Calling ");
        int i;
        for (i = 0; i < n; i++)
                {
                        printf("%d", *(p + i));
                }
        printf("\n");
}

void freeIntArray(int *p)
{
        free(p);
}

int main(int argc, char **argv)
{
        int emergency[3] = allocateIntArray();
        *(emergency) = 9;
        *(emergency + 1) = 1;
        *(emergency + 2) = 1;
        callNumber(emergency, sizeof(emergency));
        freeIntArray(emergency);
        return 0;
}
