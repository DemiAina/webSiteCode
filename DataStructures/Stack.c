#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void print(Node **);
void push(Node **, int);
int pop(Node **);

int main(void)
{

    Node *Head = NULL;

    int choice;

    while (1)
    {

        printf(" \n 1. Push \t 2. Pop \t 3. Print \t 4. Exit \n");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        int data = 0;
        switch (choice)
        {
        case 1:
            printf(" Enter data: ");
            scanf("%d", &data);
            push(&Head, data);
            break;
        case 2:
            if (Head == NULL)
            {
                printf(" Stack is empty");
                break;
            }
            printf("\n Popped data: %d\n", pop(&Head));
            print(&Head);
            break;
        case 3:
            print(&Head);
            break;
        case 4:
            return 0;
        default:
            printf(" Invalid choice");
        }
    }
}

void push(Node **head, int data)
{

    Node *current = malloc(sizeof(Node));

    if (head == NULL)
    {
        current->data = data;
        current->next = NULL;
        *head = current;
        print(head);
    }
    else if (current != NULL)
    {
        current->data = data;
        current->next = *head;
        *head = current;
        print(head);
    }
    else
    {
        printf("%d no memory avabile for it");
    }
}

void print(Node **head)
{
    if (*head == NULL)
    {
        printf(" Stack is empty");
        return;
    }
    Node *current = *head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("end\n");
}

int pop(Node **head)
{
    Node *current = *head;
    int value = 0;
    value = (*head)->data;
    *head = current->next;
    free(current);
    return value;
}