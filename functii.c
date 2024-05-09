#include "main.h"

#define maxCaractere 50

void eroare_la_deschidere(){
    puts("Fisierul nu poate fi deschis!\n");
    exit(1);
}

void eroare_la_alocare(){
    puts("Nu s-a putut aloca memorie!\n");
    exit(1);
}

Node *citireDateEchipe(FILE *fisier_in, int *nr_echipe){
    Node *head = NULL;
    int nr_coechipieri;
    char line[maxCaractere], *q;
    
    for (int i = 0; i < *nr_echipe; i++) {
        Echipa e;
        float punctajTotal = 0;

        fscanf(fisier_in, "%d", &nr_coechipieri);
        fgetc(fisier_in);
        fgets(line, sizeof(line), fisier_in);
        line[strlen(line)-1]='\0';
        
        e.Numar_persoane = nr_coechipieri;

        e.jucatori = (Player*)malloc(nr_coechipieri * sizeof(Player));
        if(e.jucatori == NULL)
            eroare_la_alocare();

        e.Nume_echipa = (char*)malloc((strlen(line)+1) * sizeof(char));
        if(e.Nume_echipa == NULL)
            eroare_la_alocare();

        strcpy(e.Nume_echipa, line);
        e.Nume_echipa[strlen(e.Nume_echipa)-1]='\0';

        for(int j=0; j < nr_coechipieri; j++){
            fgets(line, sizeof(line), fisier_in);
            line[strlen(line)-1] = '\0';

            q = strtok(line, " ");
            while(q != NULL){
                if(e.jucatori[j].firstName == NULL){
                    e.jucatori[j].firstName = (char*)malloc((strlen(line)+1) * sizeof(char));
                    if(e.jucatori[j].firstName == NULL)
                        eroare_la_alocare();

                    strcpy(e.jucatori[j].firstName, q);
                }
                else if(e.jucatori[j].secondName == NULL){
                    e.jucatori[j].secondName = (char*)malloc((strlen(line)+1) * sizeof(char));
                    if(e.jucatori[j].secondName == NULL)
                        eroare_la_alocare();

                    strcpy(e.jucatori[j].secondName, q);
                }
                else{
                    e.jucatori[j].points = atoi(q);
                    punctajTotal += e.jucatori[j].points; 
                }
                q = strtok(NULL, " ");
            }
        }
        e.punctajTotal = punctajTotal/nr_coechipieri;
        addAtBeginning(&head, e);
    }
    return head;
}

int numarEchipeMultipluDe_2(int nr_echipe){
    int nr_echipe_dupa_eliminare = 1;
    while(nr_echipe_dupa_eliminare * 2 <= nr_echipe){
        nr_echipe_dupa_eliminare *= 2;
    }
    return nr_echipe_dupa_eliminare;
}

Node* echipaPunctajMinim(Node* head) {
    Node* minNode = NULL;
    float minPunctaj = INT_MAX; 

    while (head != NULL) {
        if (head->val.punctajTotal < minPunctaj) { 
            minPunctaj = head->val.punctajTotal; 
            minNode = head;
        }
        head = head->next;
    }
    return minNode;
}

void eliminaEchipaPunctajMinim(Node** head) {
    if (*head == NULL) {
        return;
    }

    Node* minNode = echipaPunctajMinim(*head);

    if (minNode != NULL) {
        if (*head == minNode) {
            *head = (*head)->next;
        } else {
            Node* prev = *head;
            while (prev->next != minNode) {
                prev = prev->next;
            }
            prev->next = minNode->next;
        }

        free(minNode->val.Nume_echipa);
        for (int i = 0; i < minNode->val.Numar_persoane; i++) {
            free(minNode->val.jucatori[i].firstName);
            free(minNode->val.jucatori[i].secondName);
        }
        free(minNode->val.jucatori);
        free(minNode);
    }
}

