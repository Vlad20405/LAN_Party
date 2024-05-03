#include "main.h"
#include "functii.h"

void addAtBeginning(Node **head, Echipa e){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = e;
    newNode->next = *head;
    *head = newNode;
}

void afisare(FILE* fisier_out, Node *head)
{
    while(head != NULL)
        {
			fprintf(fisier_out, "%s\n", head->val.Nume_echipa);
            //for(int i = 0; i < head->val.Numar_persoane; i++)
                //printf("%s\n", head->val.Nume_echipa);
            head = head->next;
        }
}

/*
void addAtEnd(Node** head, Echipa e){
	Node *aux = *head;
	Node *newNode = (Node*)malloc(sizeof(Node)); 
	newNode->echipa = e; 
	if (*head == NULL) addAtBeginning(head, e);
	else{ 
		while (aux->next!=NULL) 
			aux = aux->next;
		aux->next = newNode;
		newNode->next = NULL; 
	}
}

void deleteNode(Node **head, Echipa e){	
	if (*head==NULL) return; 
	Node *headcopy = *head;
	if (strcmp(headcopy->echipa.Nume_echipa, e.Nume_echipa) == 0){
		*head = (*head)->next;
		free(headcopy);
		return; 
	}
	Node *prev = *head;
	while (headcopy!=NULL){
		if(strcmp(headcopy->echipa.Nume_echipa, e.Nume_echipa) != 0){
			prev = headcopy;
			headcopy = headcopy->next;
		}else{
			prev->next = headcopy->next;
			free(headcopy); 
			return; 
		} 
	}
}
*/

void deleteList(Node **head){
    Node *headcopy;

    while(*head != NULL){
        headcopy = (*head)->next;
        free(*head);
        *head = headcopy;
    }

    *head = NULL;
}