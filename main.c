#include "main.h"

int main(int arcg, char *argv[])
{   
    FILE *fisier_sarcini , *fisier_in, *fisier_out;
    if((fisier_sarcini = fopen(argv[1], "rt")) == NULL)
        eroare_la_deschidere();

    if((fisier_in = fopen(argv[2], "rt")) == NULL)
        eroare_la_deschidere();

    if((fisier_out = fopen(argv[3], "wt")) == NULL)
        eroare_la_deschidere();
    
    int nr_echipe;
    Node *head = NULL;
    
    head = citireDateEchipe(fisier_in, &nr_echipe);
    
    afisare(fisier_out, head);
    fclose(fisier_in);
    
    return 0;
}
