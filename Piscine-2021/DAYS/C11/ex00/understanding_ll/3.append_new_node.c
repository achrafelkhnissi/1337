/*
 *  From: Delete a linked list
 */

#include <stdio.h>
#include <stdlib.h>

struct s_node
{
    int data;
    struct s_node *next;
};

struct s_node * append_node(struct s_node *end, struct s_node *new);
struct s_node * create_node(int d);
void free_nodes(struct s_node *h);
void print_nodes(struct s_node *h);

int main(void)
{
    /*
    1. We'll need three structure pointer *head, *end, *new_p
        - *head: to keep track of the start of the linked list.
        - *end: to keep track of the end of the linked list.
        - *new_node: to store the new created pointer. (like a place holder?)
    */
    struct s_node *head, *end, *new_node;

    /*
    2. And we'll need to more int variables: num and i. And also a place holder
       for the structure data.
    */
    int num, i, data;

    /*
    3. First we need to ask the user how many nodes does he want the linked list
       to store! Much like asking the user for the size of the list, and then
       we store the value in the variable num.
    */
    printf("How many nodes you wish to create?: ");
    scanf("%d", &num);

    /*4. Creating a for loop (or while) and inside the loop we need:*/
    for(i = 0; i < num; i++)
    {
        /* - To ask the user for the data of each node. */
        printf("Add data to node(%d): ", i + 1);
        scanf("%d", &data);

        /* - Create a new node with a function create_node(data)
            then return the address of it to the structure pointer
            new_node created in step (1) */
        new_node = create_node(data);

        /* - Time of start the process of linking the newly created node
            to the end of our current linked list.

           - An if/else to check if the list is already exist or not.
            if (i == 0) is True, then the list doesn't exit yet therefore
            the start of the list gonna be the same as the end of the list
            and the new_node as well.
           - if (i == 0) is false, then we already have a start and an end
            of the list, so we need to append new_node to the end of the list
            using the previous line (end = append_node(end, new_node).
        */
        if(i == 0)
        {
            head = end = new_node;
        }
        else
        {
            end = append_node(end, new_node);
        }
    }

    printf("\nYou entered: \n");
    print_nodes(head);

    free_nodes(head);
    return 0;
}
void free_nodes(struct s_node *h)
{
    /* - We want to delete the first element then move to the next
     * but once you delete the first element of the list you gonna lose
     * the pointer to the second element address.
     * - So we first need to grab the second element of the list before
     * we we can delete the first element.
     * - First we need to declare a new structure node pointer that to points
     * to the beginning of the list.  */
    struct s_node *tmp;
    tmp = h;

    /* - We need to keep track of where the next element before delete the first */
    while(tmp != NULL)
    {
        h = tmp; // First save the new start of the list
        tmp  = tmp -> next; // Then we gonna update "h" with the next element
        free(h); // then delete the current start of the list.

        /* And then once we go through the loop again..
         * The new start is going to be the previous saved next element */
    }
}

void print_nodes(struct s_node *h)
{
    struct s_node *current;
    current = h;
    while(current != NULL)
    {
        printf("%d\n", current -> data);
        current = current -> next;
    }
    printf("\n");

    /* Note: How (current != NULL) works:
       1. First current is not NULL because it pointer to (h)
       2. After that current gets updated to hold the address of
            current -> next.
       3. It keeps looping till we reach the last node which its
            (node -> next == nude) and so the current -> next == NULL
            therefore current == NULL;
     */
}

struct s_node * append_node(struct s_node *end, struct s_node *new)
{
    return end -> next = new;
}

struct s_node * create_node(int d)
{
    /* - We can simply pass to it the data by value.
     * - Create a new pointer to a structure and allocate memory to it.*/
    struct s_node *node = NULL;
    node = (struct s_node *) malloc(sizeof(struct s_node));

    /* - We store the value passed to the function in the data of the
     * newly created pointer. */
    node -> data = d;

    /* - Put the NULL value to the node - > next (for safety) */
    node -> next = NULL;

    /* - Return the newly created node pointer */
    return node;
}

