/*
 *  From: Print a linked list
 */

#include <stdio.h>

struct s_node
{
    int data;
    struct s_node *next;
};

void print_nodes(struct s_node *p);

int main(void)
{
    struct s_node one = {1, NULL};
    struct s_node two = {2, NULL};
    struct s_node three = {3, NULL};
    struct s_node *head;

    head = &one;
    one.next = &two;
    two.next = &three;
    print_nodes(head);
    return 0;
}

void print_nodes(struct s_node *p)
{
    //! showMemory(start = 65520, cursors=[p])

    struct s_node *current;
    current = p;
    while(current != NULL)
    {
        printf("%d.\n", current -> data);
        current = current -> next;
    }
}
