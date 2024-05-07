#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player
{
    char* firstName;
    char* secondName;
    int points;
};
typedef struct Player Player;

struct Echipa{
    int Numar_persoane;
    char* Nume_echipa;
    Player* jucatori; 
};
typedef struct Echipa Echipa;

struct Elem{
	Echipa val;
	struct Elem* next;
};
typedef struct Elem Node;

Node* citireDateEchipe(FILE *fisier_in, int *nr_echipe);
void eroare_la_deschidere();
void addAtBeginning(Node **head, Echipa e);
void Cerinta1(FILE* fisier_in, Node *head);
void eliberareLista(Node *head);