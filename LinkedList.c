#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int data;
    struct Node* next;
};
 

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
 
void deleteNode(struct Node* node_ptr)
{
    if (node_ptr->next == NULL) {
        free(node_ptr);
    }

    struct Node* temp = node_ptr->next; //12
    node_ptr->data = temp->data;
    node_ptr->next = temp->next;
    free(temp);
}
 
void deleteEveryNode(struct Node* head, struct Node* deleted) //O(1)
{
    if(head->next == NULL) {
        free(head);
    }
    struct Node* temp = deleted->next;
    deleted->data = temp->data;
    deleted-> next = temp ->next;
    free(temp);
    return;
}

void reverseLinkedList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}


int main()
{
    struct Node* head = NULL;
 
    /* Use push() to construct below list
    3->12->8->4->1  */
    push(&head, 33);
    push(&head, 4);
    push(&head, 8);
    //struct Node* deleted1 = head;
    push(&head, 12);
    push(&head, 3);
 
    printf("Before deleting:\n");
    printList(head);
    printf("\n");

    //deleteNode(head);
    //deleteEveryNode(head, deleted1);
    reverseLinkedList(&head);
    printf("After deleting:\n");
    printList(head);
    printf("\n");
    //getchar();
}