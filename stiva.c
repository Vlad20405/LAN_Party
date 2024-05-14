#include "main.h"

int isEmptyStack(Node *top){
    return (top == NULL);
}

void push(Node **top, Echipa echipa){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode == NULL)
        eroare_la_alocare();

    newNode->val = echipa;
    newNode->next = *top;
    *top=newNode;
}

Echipa pop(Node **top){
    if (isEmptyStack(*top))
        exit(-1);
    
    Node *temp=(*top);  		
    Echipa aux=temp->val;			
    *top=(*top)->next; 

    //free(temp->val.Nume_echipa);     		
    free(temp);
    
    return aux;
}

void deleteStack(Node **top){
    Node  *temp;
    while ((*top)!=NULL){
        temp=*top;
        *top=(*top)->next;
        free(temp);
    }
}

