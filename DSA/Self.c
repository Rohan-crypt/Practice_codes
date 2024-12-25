#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// To create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the start of the linked list
void insert_at_beginning(struct Node **head, int value)
{
    /* Insertion at the beginnig of the linked list is done by creating a node and initializing the
    data with the value given and the next(pointer) pointing to the first elemint of the linked list.
    Thus, becoming the new first element of the linked list*/
    struct Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// A function that inserts a value at the end of the single linked list
void insert_at_end(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    /*First we need to check if the linked list provided to us even have an element in it or not
    if there is no element in th linked list then we simple assign the newNode that we created to
    head and terminate the function*/
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    /* If there is at least even one element in the linked list then we check the linked list for
    the last known element. We do this by checking the next(pointer) for any address if there is anything
    then we reassign a temporary variable to next known adredd, this is done till we reach the end of the
    linked list where next is initialized with NULL*/
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insertion at a certain index
void insert_at_position(struct Node **head, int value, int position)
{
    struct Node *newNode = createNode(value);
    /*If the position to insert is 1 (the head of the list):
    The new node’s next pointer is set to the current head.
    The head pointer is updated to point to the new node.
    The function then exits (return).*/
    if (position == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Invalid position!\n");
        free(newNode); // Free the allocated memory for the new node
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Deletion from the Head of the linked list
void delete_from_beginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = temp->next;
    free(temp);
}

// deleting a value from the end of the linked list
void delete_from_end(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    /*If the head’s next pointer is NULL, it means there is only one node in the list.
    The single node is freed using free(*head).
    The head pointer is set to NULL to indicate that the list is now empty.*/
    if (temp->next == NULL)
    {
        free(temp);
        temp = NULL;
        *head = temp;
        return;
    }
    /*A temporary pointer temp is initialized to the head of the list.
    The loop traverses the list until temp points to the second-to-last node. This is achieved by checking temp->next->next != NULL:
    temp->next is the last node.
    temp->next->next will be NULL for the last node.
    By stopping at the second-to-last node, the loop ensures that temp can modify the next pointer to remove the last node.*/
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    /*The memory of the last node (currently pointed to by temp->next) is freed.
    The next pointer of the second-to-last node (temp) is set to NULL, effectively removing the reference to the last node.*/
    free(temp->next);
    temp->next = NULL;
}

// Deleting an element from a position
void delete_from_position(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    /*If the position is 1, the node to delete is the head.
    The head pointer is updated to point to the second node (temp->next), effectively removing the first node.
    The memory of the old head node is freed.*/
    if (position == 1)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    /*If temp is NULL, the specified position is invalid (e.g., position is greater than the size of the list).
    If temp->next is NULL, the target position is also invalid because there is no node at that position.*/
    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid Input");
        free(temp);
        return;
    }
    struct Node *todelete = temp->next;
    temp->next = todelete->next;
    free(todelete);
}

// To display all the remaining elements in the linked list
void display(struct Node *head)
{
    struct Node *temp = head;
    // Check if the list is empty
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> "); // Add arrow between nodes
        temp = temp->next;
    }
    printf(" -> Null\n");
}

int main()
{
    struct Node *head = NULL;

    // Insert elements
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_position(&head, 15, 2); // Insert 15 at position 2

    // Display list
    display(head);

    // Delete elements
    delete_from_beginning(&head);
    delete_from_end(&head);
    delete_from_position(&head, 1);

    // Display list again
    display(head);

    return 0;
}
