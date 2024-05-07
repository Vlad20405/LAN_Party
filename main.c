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
    head = citireDateEchipe(fisier_in, &nr_echipe);

    if(Cerinta[0] == 1)
        Cerinta1(fisier_out, head);
    
   // if(Cerinta[1] == 1)
        //afisare(fisier_out, head);

    fclose(fisier_sarcini);
    fclose(fisier_in);
    fclose(fisier_out);

    eliberareLista(head);

    return 0;
}
