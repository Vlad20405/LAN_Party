#include "main.h"

#define nrCerinte 5

int main(int arcg, char *argv[])
{   
    FILE *fisier_sarcini , *fisier_in, *fisier_out;
    if((fisier_sarcini = fopen(argv[1], "rt")) == NULL)
        eroare_la_deschidere();

    if((fisier_in = fopen(argv[2], "rt")) == NULL)
        eroare_la_deschidere();

    if((fisier_out = fopen(argv[3], "wt")) == NULL)
        eroare_la_deschidere();
    
    int Cerinta[nrCerinte] = {0};
    for(int i = 0; i < nrCerinte; i++)
        fscanf(fisier_sarcini, "%d", &Cerinta[i]);

    int nr_echipe;
    Node *head = NULL;
    fscanf(fisier_in, "%d", &nr_echipe);

    head = citireDateEchipe(fisier_in, nr_echipe);

    if(Cerinta[0] == 1 && Cerinta[1] == 0)
        Cerinta_1(fisier_out, head);

    if(Cerinta[1] == 1)
        Cerinta_2(fisier_out, &head, nr_echipe);

    Node *echipe_finaliste = NULL;
    if(Cerinta[2] == 1)
        Cerinta_3(fisier_out, head, &echipe_finaliste);
    // Node* current = echipe_finaliste;
    //     while (current != NULL) {
    //         printf("%s\n", current->val.Nume_echipa);
    //         current = current->next;
    //     }
    Arbore *BST = NULL;
    if(Cerinta[3] == 1)
        Cerinta_4(fisier_out, echipe_finaliste, BST);
    
    fclose(fisier_sarcini);
    fclose(fisier_in);
    fclose(fisier_out);

    eliberareLista(head);
    return 0;
}
