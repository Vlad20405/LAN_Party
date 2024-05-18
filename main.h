#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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
    float punctajTotal;
};
typedef struct Echipa Echipa;

struct Elem{
	Echipa val;
	struct Elem* next;
};
typedef struct Elem Node;

struct Q_Elem{
	Node *echipa_1, *echipa_2;
	struct Q_Elem* next;
};
typedef struct Q_Elem Meciuri;

struct Queue{
    Meciuri *front, *rear;
};
typedef struct Queue Queue;

struct Arbore{
    Echipa val;
    struct Arbore *left, *right;
};
typedef struct Arbore Arbore;
void eroare_la_deschidere();
void eroare_la_alocare();

//Cerinte:
void Cerinta_1(FILE* fisier_out, Node *head);
void Cerinta_2(FILE* fisier_out, Node **head, int nr_echipe);
void Cerinta_3(FILE* fisier_out, Node *head, Node **echipe_finaliste);
void Cerinta_4(FILE* fisier_out, Node *echipe_finaliste, Arbore *BST);

//Functii cerinta 1:
Node* citireDateEchipe(FILE *fisier_in, int nr_echipe);
void addAtBeginning(Node **head, Echipa e);
void eliberareLista(Node *head);

//Functii cerinta 2:
int numarEchipeMultipluDe_2(int nr_echipe);
void eliminaEchipaPunctajMinim(Node** head);

//Functii cerinta 3:
int numarEchipe(Node *head);
void meciuri(FILE* fisier_out, Node **head, Node **echipe_finaliste, int nr_echipe, int runda);

//Functii cerinta 4:
void afisareTop8Echipe(FILE* fisier_out, Arbore *root);

//Functii coada:
int isEmptyQueue(Queue *q);
Queue *createQueue();
void enQueue(Queue *q, Node *valoare1, Node *valoare2);
void enQueueBackward(Queue *q, Node *echipa_1, Node *echipa_2);
Meciuri* deQueue(Queue *q);

//Functii stiva:
int isEmptyStack(Node *top);
void push(Node **top, Echipa echipa);
Echipa pop(Node **top);
void deleteStack(Node **top);

//Functii arbore:
Arbore* newNode(Node data);
Arbore* insert(Arbore* node, Node key);