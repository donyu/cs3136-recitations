// A linked list example program.
// To compile & link: gcc -g -Wall linked-list-1.c -lm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

struct Node {
    double data;
    struct Node *next;
};

/*
 * Create a node that holds the given data x,
 * add the node to the front of the given list,
 * and returns the resulting list.
 *
 * Returns NULL if malloc for the node fails.
 */
struct Node *prepend(struct Node *list, double x)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
	return NULL;

    node->data = x;
    node->next = list;
    return node;
}

void print(struct Node *list)
{
    struct Node *node = list;
    while (node) {
        printf("-> %g ", node->data);
	node = node->next;
    }
    printf("\n");
}

/*
 * Apply f(x) on each data item in the list.
 */
void apply(struct Node *list, double (*f)(double))
{
    if (list) {
        list->data = f(list->data);
        apply(list->next, f);
    }
}

/*
 * Removes the first node (deallocating the memory for the node) 
 * and returns the rest of the list.  
 *
 * Returns NULL if list is NULL.
 */
struct Node *remove_front(struct Node *list)
{
    struct Node *rest = NULL;
    if (list) {
        rest = list->next;
        free(list);
    }
    return rest;
}

/*
 * Deallocates all nodes.  Returns NULL.
 */
struct Node *remove_all_nodes(struct Node *list)
{
    while (list) {
        list = remove_front(list);
    }
    return list;
}

int main()
{
    double a[] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
    int n = sizeof(a) / sizeof(a[0]);

    // An initially empty list
    struct Node *list = NULL;

    int i;
    for (i = 0; i < n; i++) {
        list = prepend(list, a[i]);
    }

    // print the list, apply 2^x, and print the list again.
    print(list);
    apply(list, exp2);
    print(list);

    // remove first and print.
    list = remove_front(list);
    print(list);

    // remove first and print one more time.
    list = remove_front(list);
    print(list);

    // remove all nodes
    list = remove_all_nodes(list);
    assert(list == NULL);

    return 0;
}
