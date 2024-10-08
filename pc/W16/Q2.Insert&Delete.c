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

void Delete(struct LinkedList** head,int delData)
{
	LinkedList *current = *head;
    LinkedList *pre = NULL;

    while (current != NULL && current -> data != delData)
    {
        pre = current;
        current = current ->next;
    }

    if(current!= NULL)
    {
        if(pre!=NULL)
        {
            pre->next = current->next;
        }else{
            *head = current->next;
        }

    }else{
        printf("not found\n");
    }
    
    
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
    struct LinkedList *head=NULL;
    int i,del_num;
    
    for(i=0;i<10;i++)
    {
        Insert(&head,i);
    }
    printLinkedList(head);
	
    printf("Enter del_num:");
    scanf("%d",&del_num);	
    Delete(&head,del_num);
    printLinkedList(head);
	
}