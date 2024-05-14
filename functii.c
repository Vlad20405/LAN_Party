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

Node *citireDateEchipe(FILE *fisier_in, int nr_echipe){
    Node *head = NULL;
    int nr_coechipieri;
    char line[maxCaractere], *q;
    
    for (int i = 0; i < nr_echipe; i++){
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

    	if(e.Nume_echipa[strlen(e.Nume_echipa)-1] == ' ')
            e.Nume_echipa[strlen(e.Nume_echipa)-1] = '\0';
        
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

float punctajMinim(Node *head){
    float mini = INT_MAX;
    while(head != NULL){
        if(head->val.punctajTotal < mini)
            mini = head->val.punctajTotal;
        head = head->next;
    }
    return mini;
}

void eliminaEchipaPunctajMinim(Node** head){
    float minPunctaj = punctajMinim(*head);
    Node* prev = NULL;
    Node* current = *head; 
    if ((*head)->val.punctajTotal == minPunctaj){
        *head = (*head)->next;

        for(int i=0; i<current->val.Numar_persoane; i++){
            free(current->val.jucatori[i].firstName);
            free(current->val.jucatori[i].secondName);
        }
        free(current->val.Nume_echipa);
        free(current->val.jucatori);

        current->val.jucatori = NULL;

    free(current);
    } 
    else{
        while(current != NULL && current->val.punctajTotal != minPunctaj){
            prev = current; 
            current = current->next; 
        }
        if (current != NULL) {
            if (prev != NULL) {
                prev->next = current->next;
            }

            for(int i=0; i<current->val.Numar_persoane; i++){
                free(current->val.jucatori[i].firstName);
                free(current->val.jucatori[i].secondName);
            }
            free(current->val.Nume_echipa);
            free(current->val.jucatori);

            current->val.jucatori = NULL;

        free(current);
        }
    }
}

int numarEchipe(Node *head){
    int nr_echipe = 0;
    Node *aux = head;
    while(aux != NULL){
        nr_echipe++;
        aux = aux->next;
    }
    return nr_echipe;
}

void afisareMeci(FILE* fisier_out, Queue *coadaMeciuri, int runda) {
    fprintf(fisier_out, "\n--- ROUND NO:%d\n",  runda);

    Meciuri *current = coadaMeciuri->front;
    while (current != NULL){
        fprintf(fisier_out, "%-33s-%33s\n", (current->echipa_1)->val.Nume_echipa, (current->echipa_2)->val.Nume_echipa);
        current = current->next;
    }
}

//Principal:
void meciuri(FILE* fisier_out, Node **head, Node **echipe_finaliste, int nr_echipe, int runda){
    Queue *q = createQueue();
    Node *echipa = *head;
    int i = 0;
    while(i < nr_echipe && echipa != NULL && echipa->next != NULL){
        enQueue(q, echipa, echipa->next);
        echipa = echipa->next->next;
        i = i + 2;
    }
    afisareMeci(fisier_out, q, runda);

    Node *castigatori = NULL;
    Node *invinsi = NULL;

    
    while(!isEmptyQueue(q)){
        Meciuri *meci = deQueue(q);
        if((meci->echipa_1)->val.punctajTotal > (meci->echipa_2)->val.punctajTotal) {
            (meci->echipa_1)->val.punctajTotal++;
            push(&castigatori, (meci->echipa_1)->val);
            push(&invinsi, (meci->echipa_2)->val);
        } 
        else{
            (meci->echipa_2)->val.punctajTotal++;
            push(&castigatori, (meci->echipa_2)->val);
            push(&invinsi, (meci->echipa_1)->val);
        }
    free(meci);
    }
    deleteStack(&invinsi);
    *head = castigatori;

    if(nr_echipe == 16){
        Node* castigatori_c = castigatori;
        while(castigatori_c != NULL){
            addAtBeginning(echipe_finaliste, castigatori_c->val);
            castigatori_c = castigatori_c->next;
        }
    }
    
    fprintf(fisier_out, "\nWINNERS OF ROUND NO:%d\n", runda);
    while(castigatori != NULL){
        fprintf(fisier_out, "%-33s -  %.2f\n", castigatori->val.Nume_echipa, castigatori->val.punctajTotal);
        castigatori = castigatori->next;
    }
    deleteStack(&castigatori);
    free(q);
}

//Secundare (dand pop la castigatori ca sa ii afisez aveam probleme cu parcurgerea castigatorilor dupa prima runda, 
// deoarece parcurgeam in continuare dupa lista, iar afisarea era fix invers de cum ar fi trebuit sa fie astfel 
// am implementat o functie pentru pentru coada care adauga elementele invers):

// void meciuri(FILE* fisier_out, Node **head, int nr_echipe, int runda){
//     Queue *q = createQueue();
//     Node *echipa = *head;
//     int i = 0;
//     while(i < nr_echipe && echipa != NULL && echipa->next != NULL){
//         if(runda == 1){
//             enQueue(q, echipa, echipa->next);
//         }
//         else{
//             enQueueBackward(q, echipa->next, echipa);
//         }
//         echipa = echipa->next->next;
//         i = i + 2;
//     }
//     afisareMeci(fisier_out, q, runda);

//     Node *castigatori = NULL;
//     Node *invinsi = NULL;

//     while(!isEmptyQueue(q)){
//         Meciuri *meci = deQueue(q);
//         if((meci->echipa_1)->val.punctajTotal > (meci->echipa_2)->val.punctajTotal) {
//             (meci->echipa_1)->val.punctajTotal++;
//             push(&castigatori, (meci->echipa_1)->val);
//             push(&invinsi, (meci->echipa_2)->val);
//         } 
//         else{
//             (meci->echipa_2)->val.punctajTotal++;
//             push(&castigatori, (meci->echipa_2)->val);
//             push(&invinsi, (meci->echipa_1)->val);
//         }
//     free(meci);
//     }
//     deleteStack(&invinsi);
    
//     Node *temp_castigatori = castigatori;

//     while (temp_castigatori != NULL){
//         push(head, temp_castigatori->val);
//         temp_castigatori = temp_castigatori->next;
//     }  

//     fprintf(fisier_out, "\nWINNERS OF ROUND NO:%d\n", runda);
//     while(castigatori != NULL){
//         Echipa echipa = pop(&castigatori);
//         fprintf(fisier_out, "%-33s -  %.2f\n", echipa.Nume_echipa, echipa.punctajTotal);
//     }
//     free(q);
// }