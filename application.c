#include "stdlib.h"
#include "stdio.h"
#include "fichier.h"
#include "application.h"
#include <stdio.h>
#include <stdlib.h>
/*
typedef struct {
    char *nom;
    char *prenom;
    struct RDV *rdv;
    struct Contact* next;
} Contact;

typedef struct {
    int jour;
    int mois;
    int annee;
    int heurerdv;
    int tempsrdv;
    char *objet;
} RDV;

typedef struct {
    struct Contact **head;
    int max_level;
}Agenda;
*/
Contact* createContact(Agenda* list){
    Contact *newContact = (Contact *)malloc(sizeof(Contact));
    newContact->nom = (char *)malloc(50 * sizeof(char));
    newContact->prenom = (char *)malloc(50 * sizeof(char));
    printf("Saisir le NOM : ");
    scanf("%s", newContact->nom);
    printf("Saisir le PRENOM : ");
    scanf("%s", newContact->prenom);
    newContact->next = NULL;
    Contact* actuel = list->head[0];
    Contact* prev = NULL;
    while (actuel != NULL) {
        if (compareNoms(actuel->nom, newContact->nom, actuel->prenom, newContact->prenom) >= 0) {
            break;
        }
        prev = actuel;
        actuel = actuel->next;
    }
    if (prev == NULL) {
        newContact->next = list->head[0];
        list->head[0] = newContact;
    } else {
        newContact->next = actuel;
        prev->next = newContact;
    }
    return newContact;
}

RDV* createRDV() {
    RDV *newRDV = (RDV *)malloc(sizeof(RDV));
    newRDV->objet = (char *)malloc(1000 * sizeof(char));
    int jour, mois, annee;
    int heurerdv, tempsrdv;
    printf("Saisir la date du rendez-vous (j/m/a) : ");
    scanf("%d/%d/%d", &jour, &mois, &annee);
    getchar();
    printf("Saisir l'heure du rendez-vous (h.m) : ");
    scanf("%d", &heurerdv);
    getchar();
    printf("Saisir la duree du rendez-vous : ");
    scanf("%d", &tempsrdv);
    getchar();
    printf("Saisir la raison du rendez-vous : ");
    fgets(newRDV->objet, 1000, stdin);

    newRDV->jour = jour;
    newRDV->mois = mois;
    newRDV->annee = annee;
    newRDV->heurerdv = heurerdv;
    newRDV->tempsrdv = tempsrdv;

    return newRDV;
}

Agenda* createAgenda(int max_niv) {
    Agenda* agenda;
    agenda = (Agenda*) malloc(sizeof(Agenda));
    agenda->max_level = max_niv;
    agenda->head = (Contact**)malloc(sizeof(Contact*) * max_niv);
    for (int i = 0; i < max_niv; i++) {
        agenda->head[i] = NULL;
    }
    return agenda;
}
Agenda* addRDV(Agenda* agenda){
    int level = 0;
    Contact *newContact = createContact(agenda);
    RDV *newRDV = createRDV();
    newContact->rdv = newRDV;

    while (level <= agenda->max_level) {
        Contact *currentContact = agenda->head[level];
        Contact *prev = NULL;
        int found = 0;
        while (currentContact != NULL) {
            if (compareNoms(currentContact->nom, newContact->nom, currentContact->prenom, newContact->prenom) == 0) {
                found = 1;
                break;
            }
            prev = currentContact;
            currentContact = currentContact->next;
        }

        if (!found) {
            if (level == 0) {
                newContact->next = agenda->head[level];
                agenda->head[level] = newContact;
            } else {
                newContact->next = NULL;
                prev->next = newContact;
            }
            break; // Sortir de la boucle après l'insertion
        } else {
            level++; // Passer au niveau suivant si le contact est trouvé à ce niveau
        }
    }
    return agenda;
}



void displaycontact(Agenda * list){
    int niv =0;
    printf("[list head_%d @-]--> ",niv);
    Contact * p = list->head[niv];
    while (p != NULL){
        printf("[%s|@-]--> ", p->nom);
        p = p->next;
    }
    printf("NULL\n");
    return;
}

void displayRDV(Agenda* agenda) {
    displaycontact(agenda);
    for (int level = 1; level < agenda->max_level; level++) {
        Contact* actuelContact = agenda->head[level];
        printf("[list  rdv_%d @-]--> ", level);
        while (actuelContact != NULL) {
            RDV* currRDV = actuelContact->rdv;
            printf("[%d/%d/%d @-]--> ", currRDV->jour, currRDV->mois, currRDV->annee);
            actuelContact = actuelContact->next;
        }
        printf("NULL\n");
        Contact* p = agenda->head[level];
        printf("                --> ");
        while (p != NULL) {
            RDV* RDV = p->rdv;
            printf("[%d|%d @-]--> ", RDV->heurerdv, RDV->tempsrdv);
            p = p->next;
        }
        printf("NULL\n");
        Contact* p1 = agenda->head[level];
        printf("                --> ");
        while (p1 != NULL) {
            RDV* RDV = p1->rdv;
            printf("[%s @-]--> ", RDV->objet);
            p1 = p1->next;
        }
        printf("NULL\n");
    }
    return;
}


int compareNoms(char *nom1, char *nom2, char *prenom1, char *prenom2) {
    while (*nom1 && *nom2) {
        char c1 = *nom1;
        char c2 = *nom2;
        if (c1 >= 'A' && c1 <= 'Z') {
            c1 += 'a' - 'A';
        }
        if (c2 >= 'A' && c2 <= 'Z') {
            c2 += 'a' - 'A';
        }
        if (c1 != c2) {
            return c1 - c2;
        }
        nom1++;
        nom2++;
    }
    while (*prenom1 && *prenom2) {
        char c1 = *prenom1;
        char c2 = *prenom2;
        if (c1 >= 'A' && c1 <= 'Z') {
            c1 += 'a' - 'A';
        }
        if (c2 >= 'A' && c2 <= 'Z') {
            c2 += 'a' - 'A';
        }
        if (c1 != c2) {
            return c1 - c2;
        }
        prenom1++;
        prenom2++;
    }
    int nom=(*nom1) - (*nom2);
    int prenom=(*prenom1) - (*prenom2);
    if (prenom==1){
        return 1;
    }
    if (nom==1){
        return 1;
    }
    else{
        return 0;
    }
}

void freeContact(Contact *contact) {
    free(contact->nom);
    free(contact->prenom);
    free(contact);
}

void freeRDV(RDV *rdv) {
    free(rdv->objet);
    free(rdv);
}

void freeAgenda(Agenda *agenda) {
    for (int i = 0; i < agenda->max_level; i++) {
        Contact *current = agenda->head[i];
        while (current != NULL) {
            Contact *temp = current;
            current = current->next;
            freeRDV(temp->rdv);
            freeContact(temp);
        }
    }
    free(agenda->head);
    free(agenda);
}