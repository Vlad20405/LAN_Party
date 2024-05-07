#include "main.h"

void addAtBeginning(Node **head, Echipa e){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = e;
    newNode->next = *head;
    *head = newNode;
}

void Cerinta1(FILE* fisier_out, Node *head)
{
    while(head != NULL)
        {
			fprintf(fisier_out, "%s\n", head->val.Nume_echipa);
            head = head->next;
        }
}

void eliberareLista(Node *head) {
    Node *temp;
    while (head != NULL) {
        free(head->val.Nume_echipa);
        
        for (int i = 0; i < head->val.Numar_persoane; i++) {
            free(head->val.jucatori[i].firstName);
            free(head->val.jucatori[i].secondName);
        }
        
        free(head->val.jucatori);
        
        temp = head;
        head = head->next;
        
        free(temp);
    }
}
