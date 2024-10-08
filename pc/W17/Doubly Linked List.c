#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}node;

void insert(node **head, int newdata)
{
    node *newnode = (node*)malloc(sizeof(node));

    newnode->data = newdata;
    newnode->prev = NULL;
    newnode->next = *head;

    if(*head != NULL)
    {
        (*head)->prev = newnode;
    }

    *head = newnode;
}

void deletenode(node **head,int deldata)
{
    node *cur = *head;

    while(cur != NULL && cur->data != deldata)
    {
        cur = cur->next;
    }

    if(cur == NULL)
    {
        printf("not found, %d\n", deldata);
        return;
    }

    if(cur->prev != NULL)
    {
        cur->prev->next = cur->next;
    } else {
        *head = cur->next;
    }

    if(cur->next != NULL)
    {
        cur->next->prev = cur->prev;
    }

    free(cur);
}

void printlist(node *head)
{
    while(head != NULL)
    {
        printf(" %d <->",head->data);
        head = head->next;
    }
    printf(" NULL\n");
}

void freelist(node *head)
{
    while(head !=NULL)
    {
        node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main()
{
    node *head = NULL;

    for(int i = 0;i<10;i++)
    {
        insert(&head,i);
    }
    
    printlist(head);

    deletenode(&head,2);

    printlist(head);

}