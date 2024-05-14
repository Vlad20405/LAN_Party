#include "main.h"

void addAtBeginning(Node **head, Echipa e){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = e;
    newNode->next = *head;
    *head = newNode;
}

void eliberareLista(Node *head) {
    Node *temp;
    while (head != NULL) {
        free(head->val.Nume_echipa);
        
        for (int i = 0; i < head->val.Numar_persoane; i++){
            free(head->val.jucatori[i].firstName);
            free(head->val.jucatori[i].secondName);
        }
        free(head->val.jucatori);
        
        temp = head;
        head = head->next;
        
        free(temp);
    }
}
