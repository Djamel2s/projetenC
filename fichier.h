#include "stdlib.h"
#include "stdio.h"

#ifndef AGENDA_FICHIER_H
#define AGENDA_FICHIER_H

typedef struct s_d_cell {
    int value;
    struct s_d_cell* next;
} t_d_cell;

typedef struct s_d_list {
    struct s_d_cell** head;
    int max_level;
} t_d_list;

t_d_cell* createCell(int);
t_d_list* createList(int);
t_d_list* InsertionListentete(t_d_list* ,int ,int);
t_d_list* InsertionList(t_d_list* , int , int );
t_d_list* Listlevel(t_d_list* );
void displaylist(t_d_list*, int);
void displaylistaligne(t_d_list* , int );
void rechercheclassic(t_d_list* list, int val);
void recherchehigh(t_d_list* list, int val);
#endif //AGENDA_FICHIER_H
