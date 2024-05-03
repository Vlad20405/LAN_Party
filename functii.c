#include "main.h"

#define maxCaractere 50

Node *citireDateEchipe(FILE *fisier_in, int *nr_echipe){
    Node *head = NULL;
    int nr_coechipieri;
    char line[maxCaractere], *q;

    fscanf(fisier_in, "%d", nr_echipe);

    for (int i = 0; i < *nr_echipe; i++) {
        Echipa e;

        fscanf(fisier_in, "%d", &nr_coechipieri);
        fgetc(fisier_in);
        fgets(line, sizeof(line), fisier_in);
        line[strlen(line)-1]='\0';
        
        e.Numar_persoane = nr_coechipieri;

        e.jucatori = (Player*)malloc(nr_coechipieri * sizeof(Player));

        e.Nume_echipa = (char*)malloc((strlen(line)+1) * sizeof(char));
        strcpy(e.Nume_echipa, line);

        for(int j=0; j < nr_coechipieri; j++){
            fgets(line, sizeof(line), fisier_in);
            line[strlen(line)-1] = '\0';

            q = strtok(line, " ");
            while(q != NULL){
                if(e.jucatori[j].firstName == NULL){
                    e.jucatori[j].firstName = (char*)malloc((strlen(line)+1) * sizeof(char));
                    strcpy(e.jucatori[j].firstName, q);
                }
                else if(e.jucatori[j].secondName == NULL){
                    e.jucatori[j].secondName = (char*)malloc((strlen(line)+1) * sizeof(char));
                    strcpy(e.jucatori[j].secondName, q);
                }
                else{
                    e.jucatori[j].points = atoi(q);
                }
                q = strtok(NULL, " ");
            }
        }
        addAtBeginning(&head, e);
    }
    return head;
}