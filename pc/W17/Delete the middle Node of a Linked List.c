#include<stdio.h>
#include<stdlib.h>

struct LinkedList{
    int data;
    struct LinkedList *next; 
};
struct LinkedList* Insert(struct LinkedList* head,int newData){ 
    struct LinkedList* newNode = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    struct LinkedList* temp = head;
    newNode->data = newData;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        return head;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}
void printLinkedList(struct LinkedList* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void deleteMiddle(struct LinkedList* head){ 
    if(!head->next) return;

    struct LinkedList *fast = head->next;
    struct LinkedList *slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        if(!fast) break;
        slow = slow->next;
    }
    struct LinkedList *n = slow->next;
    slow->next = slow->next->next;
    free(n);
    
}

int main(){
    struct LinkedList *head=NULL;
    int i, total, num;
    scanf("%d", &total);
    for(i = 0; i < total; i++){
        scanf("%d", &num);
        head = Insert(head,num);
    }
    printLinkedList(head);
    deleteMiddle(head);
    printLinkedList(head);
}