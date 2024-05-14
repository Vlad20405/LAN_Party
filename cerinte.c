#include "main.h"

void Cerinta_1(FILE* fisier_out, Node *head){
    while(head != NULL){
		fprintf(fisier_out, "%s\n", head->val.Nume_echipa);
        head = head->next;
    }
    eliberareLista(head);
}

void Cerinta_2(FILE* fisier_out, Node **head, int nr_echipe){
    int maxEchipeMultipluDe_2 = numarEchipeMultipluDe_2(nr_echipe);

    while(nr_echipe > maxEchipeMultipluDe_2){
        eliminaEchipaPunctajMinim(head);
        nr_echipe--;
    }
    Node* current = *head;
    while(current != NULL){
        if (current->val.Nume_echipa != NULL) {
            fprintf(fisier_out, "%s\n", current->val.Nume_echipa);
        }
        current = current->next;
    }
}

void Cerinta_3(FILE* fisier_out, Node *head){
    int runda = 0;
    int nr_echipe = numarEchipe(head);

    while(nr_echipe > 1){
        runda++;
        meciuri(fisier_out, &head, nr_echipe, runda);
        nr_echipe = nr_echipe / 2;
    }
}
