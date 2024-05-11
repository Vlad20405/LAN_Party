#include "main.h"

void addAtBeginning(Node **head, Echipa e){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = e;
    newNode->next = *head;
    *head = newNode;
}

void Cerinta_1(FILE* fisier_out, Node *head){
    while(head != NULL){
		fprintf(fisier_out, "%s\n", head->val.Nume_echipa);
        head = head->next;
    }
    eliberareLista(head);
}

void Cerinta_2(FILE* fisier_out, Node *head, int nr_echipe){
    int maxEchipeMultipluDe_2 = numarEchipeMultipluDe_2(nr_echipe);

    while(nr_echipe > maxEchipeMultipluDe_2){
        eliminaEchipaPunctajMinim(&head);
        nr_echipe--;
    }

    while(head != NULL){
		fprintf(fisier_out, "%s\n", head->val.Nume_echipa);
        head = head->next;
    }
    eliberareLista(head);
}

void Cerinta_3(FILE* fisier_out, Node *head, int nr_echipe){
    int contor_runde = 1;
    Queue *coadaEchipa = createQueue();
    for(int i = nr_echipe - 1; i >= 0; i--)
        enQueue(coadaEchipa, head);

    fprintf(fisier_out, "\n--- ROUND NO:%d\n",  contor_runde);

    Echipa *primaechipa = deQueue(coadaEchipa), *adouaechipa = deQueue(coadaEchipa);
    fprintf(fisier_out, "%s   %s",primaechipa->Nume_echipa, adouaechipa->Nume_echipa);

    //functia de meciuri
    //eliberareLista(head);
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
