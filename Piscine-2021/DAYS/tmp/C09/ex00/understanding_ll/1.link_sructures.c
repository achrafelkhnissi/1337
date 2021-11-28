/*
 * From: Link structures together in a linked list
 */

#include <stdio.h>
#include <stdlib.h>

struct s_node
{
    int x;
    int y;

    //we also want to store the subsequent
    //element of the list.
    struct s_node *next;
};

int main(void)
{
    struct s_node one = {1, 2, NULL};
    struct s_node two = {10, 20, NULL};
    struct s_node three = {100, 200, NULL};
    struct s_node *head, *current;

    //linking the structures together.
    head = &one;
    one.next = &two;
    two.next = &three;

    //"current" is a s_node structure pointer to help us move through the list
    current = head;
    while(current != NULL)
    {
        //printing the current s_node's x,y
        printf("(%d, %d)\n", current -> x, current -> y);
        //moving the pointer node to the next
        //node on the linked list.
        current = current -> next;
    }
    return 0;
}

