#include "main.h"
#include "functii.h"

int main(int arcg, char *argv[])
{   
    FILE *fisier_sarcini , *fisier_in, *fisier_out;
    if((fisier_sarcini = fopen(argv[1], "rt")) == NULL)
    {
        puts("Fisierul de intrare nu poate fi deschis\n");
        exit(1);
    }

    if((fisier_in = fopen(argv[2], "rt")) == NULL)
    {
        puts("Fisierul de intrare nu poate fi deschis\n");
        exit(1);
    }

    if((fisier_out = fopen(argv[3], "wt")) == NULL)
    {
        puts("Fisierul de intrare nu poate fi deschis\n");
        exit(1);
    }
    
    int nr_echipe;
    Node *head = NULL;
    
    head = citireDateEchipe(fisier_in, &nr_echipe);
    
    afisare(fisier_out, head);
    fclose(fisier_in);
    
/*
    for (int i = 0; i < nr_echipe; i++) {
        free(echipe[i]->Nume_echipa);
        for (int j = 0; j < echipe[i]->Numar_persoane; j++) {
            free(echipe[i]->jucatori[j].firstName);
            free(echipe[i]->jucatori[j].secondName);
        }
        free(echipe[i]->jucatori);
        free(echipe[i]);
    }
    free(echipe);
    */

    return 0;
}
