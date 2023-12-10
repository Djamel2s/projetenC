#include "stdlib.h"
#include "stdio.h"

#ifndef AGENDA_APPLICATION_H
#define AGENDA_APPLICATION_H


typedef struct contact_cell{
    char *nom;
    char *prenom;
    struct rdv_cell *rdv;
    struct contact_cell* next;
} Contact;

typedef struct rdv_cell{
    int jour;
    int mois;
    int annee;
    int heurerdv;
    int tempsrdv;
    char *objet;
} RDV;

typedef struct agenda_cell{
    struct contact_cell **head;
    int max_level;
}Agenda;

Contact* createcontact();
RDV* createRDV();
Agenda* addRDV(Agenda*);
int compareNoms(char *, char *,char *, char *);
Contact* createContact(Agenda* );
Agenda* createAgenda(int );
void displaycontact(Agenda *);
void displayRDV(Agenda* );
void freeContact(Contact *);
void freeRDV(RDV *);
void freeAgenda(Agenda *);
#endif //AGENDA_APPLICATION_H
