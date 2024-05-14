#include "main.h"

Queue *createQueue(){
    Queue *q;
    q = (Queue *)malloc(sizeof(Queue));

	if(q == NULL)
		return NULL;
	q->front = q->rear = NULL;

	return q;
}

void enQueue(Queue *q, Node *echipa_1, Node *echipa_2){
    Meciuri *meci = (Meciuri*)malloc(sizeof(Meciuri));
    if(meci == NULL)
        eroare_la_alocare();
    
    meci->echipa_1 = (Node*)malloc(sizeof(Node));
    meci->echipa_2 = (Node*)malloc(sizeof(Node));
    if(meci->echipa_1 == NULL || meci->echipa_2 == NULL)
        eroare_la_alocare();
    
    (meci->echipa_1)->val = echipa_1->val;
    (meci->echipa_2)->val = echipa_2->val;

    meci->next = NULL;
    if(q->rear == NULL){
        q->rear = meci;
    }
    else{
        (q->rear)->next = meci;
        (q->rear) = meci;
    }
    if(q->front == NULL)
        q->front = q->rear;
}

void enQueueBackward(Queue *q, Node *echipa_1, Node *echipa_2){
    Meciuri *meci = (Meciuri*)malloc(sizeof(Meciuri));
    if(meci == NULL)
        eroare_la_alocare();
    
    meci->echipa_1 = (Node*)malloc(sizeof(Node));
    meci->echipa_2 = (Node*)malloc(sizeof(Node));
    if(meci->echipa_1 == NULL || meci->echipa_2 == NULL)
        eroare_la_alocare();
    
    (meci->echipa_1)->val = echipa_1->val;
    (meci->echipa_2)->val = echipa_2->val;

    if(q->front == NULL){
        q->front = meci;
        q->rear = meci;
        meci->next = NULL;
    } 
    else{
        meci->next = q->front;
        q->front = meci;
    }
}

int isEmptyQueue(Queue *q){
	return (q->front == NULL);
}

Meciuri* deQueue(Queue *q){ 
    if(isEmptyQueue(q))
        return NULL;
    
    Meciuri *aux = q->front;
    Meciuri *rezultat = (Meciuri*)malloc(sizeof(Meciuri));
    if(rezultat == NULL)
        eroare_la_alocare();

    rezultat->echipa_1 = (Node*)malloc(sizeof(Node));
    rezultat->echipa_2 = (Node*)malloc(sizeof(Node));
    if(rezultat->echipa_1 == NULL || rezultat->echipa_2 == NULL)
        eroare_la_alocare();

    rezultat->echipa_1->val = aux->echipa_1->val;
    rezultat->echipa_2->val = aux->echipa_2->val;

    q->front = (q->front)->next;

    free(aux->echipa_1);
    free(aux->echipa_2);
    free(aux);

    return rezultat;
}