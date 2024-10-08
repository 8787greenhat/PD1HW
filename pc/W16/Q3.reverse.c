#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedList{
	int data;
	struct LinkedList *next; 
}LinkedList;
void Insert(struct LinkedList** head,int newData){
	LinkedList *newnode= (LinkedList*)malloc(sizeof(LinkedList));

    newnode -> data = newData;
    newnode -> next = *head;

    *head = newnode;
}
void Reverse(struct LinkedList** head)
{
    LinkedList *current = *head;
    LinkedList *next;
    LinkedList *pre = NULL;

    while(current != NULL)
    {
        next = current->next;
        current ->next = pre;
        pre = current;
        current = next;
    }

    *head = pre;
}
void printLinkedList(struct LinkedList* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main()
{
    struct LinkedList *head = NULL;
	
    Insert(&head,3);
    Insert(&head,7);
    Insert(&head,10); 
    
    
    printf("before:\n");
    printLinkedList(head);
	
    printf("after:\n");
    Reverse(&head);
    printLinkedList(head);
}