#include "stdlib.h"
#include "stdio.h"
#include "fichier.h"

t_d_cell* createCell(int val){//création de cellule avec une valeur stockée
    t_d_cell* cell=(t_d_cell*) malloc(sizeof(t_d_cell));
    cell->value=val;
    cell->next=NULL;
    return cell;
}

t_d_list* createList(int max_niv) {//création d'une liste avec le nombre de niveaux
    t_d_list* list;
    list=(t_d_list*) malloc(sizeof(t_d_list));
    list->max_level=max_niv;
    list->head=(t_d_cell**)malloc(sizeof(t_d_cell*)*max_niv);
    for (int i=0;i<max_niv;i++){
        list->head[i]=NULL;
    }
    return list;
}

t_d_list* InsertionListentete(t_d_list* list,int val,int niv) {//insertion en tete de list
    t_d_cell* cell = createCell(val);
    if ((niv >= 0)&&(niv<list->max_level)) {
        cell->next = list->head[niv];
        list->head[niv] = cell;
    }
    return list;
}

t_d_list* InsertionList(t_d_list* list, int val, int niv) {//permet d'insérer n'importe où dans la liste
    while (niv>=0) {
        t_d_cell* cell = list->head[niv];
        t_d_cell* insert = createCell(val);
        t_d_cell* temp = NULL;
        while (cell != NULL && cell->value < val) {
            temp = cell;
            cell = cell->next;
        }
        if (temp == NULL) {
            insert->next = list->head[niv];
            list->head[niv] = insert;
        }
        else{
            insert->next = temp->next;
            temp->next = insert;
        }
        niv=niv-1;
    }
    return list;
}

t_d_list* Listlevel(t_d_list* list) {
    int n=1;
    for (int i = 1; i <= list->max_level; i++) {
        n *= 2;
    }
    int level[n-1];
    for (int j=0;j<n-1;j++) {
        level[j] = 0;
    }
    int step=2;
    for (int i=0;i<(list->max_level)-1;i++) {
        for (int j = -1; j < n - 1;) {
            if (j + step > n - 1) {
                break;
            }
            else {
                j = j + step;
                level[j] = level[j] + 1;
            }
        }
        step=step*2;
    }
    for (int i = 0; i <n-1; i++){
        int a = level[i];
        list = InsertionList(list, i + 1, a);
    }
    return list;
}

void displaylist(t_d_list* list, int niv){
    if ((niv >= 0)&&(niv<list->max_level)) {
        printf("[list head_%d @-]--> ",niv);
        t_d_cell* p= list->head[niv];
        while (p!=NULL){
            printf("[%d|@-]--> ",p->value);
            p=p->next;
        }
        printf("NULL\n");
    }
    else{
        printf("ERROR\n");
    }
    return;
}

void displaylistaligne(t_d_list* list, int niv){
    if ((niv >= 0)&&(niv<list->max_level)) {
        if (niv==0) { //affichage niveau 0
            printf("[list head_%d @-]--> ", niv);
            t_d_cell *p = list->head[niv];
            while (p != NULL) {
                printf("[%d|@-]--> ", p->value);
                p = p->next;
            }
            printf("NULL\n");
        }
        else{
            printf("[list head_%d @-]--", niv);
            t_d_cell *p = list->head[niv];
            t_d_cell *p0= list->head[0];
            while (p != NULL) {
                if(p->value==p0->value) {//on affiche si la valeur est dans la même cellule
                    printf("> [%d|@-]--", p->value);
                    p = p->next;
                    p0 = p0->next;
                }
                else{ //on remplace par des tirets s'il n'y a pas de valeurs
                    if (p0->value<10){
                        printf("----------");
                    }
                    else {
                        printf("-----------");
                    }
                    p0 = p0->next;
                }
            }
            while(p0!=NULL){
                if (p0->value<10){
                    printf("----------");
                }
                else {
                    printf("-----------");
                }
                p0 = p0->next;
            }
            printf("> NULL\n");

        }
    }
    else{
        printf("ERROR\n");
    }
    return;
}

void rechercheclassic(t_d_list* list, int val){
    t_d_cell* cell = list->head[0];
    while((cell!=NULL)&&(cell->value!=val)){
        cell = cell->next;
    }
    if ((cell!=NULL)&&(cell->value==val)){
        printf("PRESENT au niveau 0\n");
    }
    return;
}

void recherchehigh(t_d_list* list, int val){
    int niv=(list->max_level)-1;
    int presence=0;
    while (niv>=0 && presence==0) {
        t_d_cell* cell = list->head[niv];
        while ((cell!=NULL)&&(cell->value<val)){
            cell=cell->next;
        }
        if ((cell!=NULL)&&(cell->value==val)) {
            printf("PRESENT dans les niveaux: %d\n",niv);
            presence=1;
            //for (int i=0;i<=niv;i++) {
            //    printf("%d ", i);
            //}
            //printf("\n");
        }
        niv=niv-1;
    }
    return;
}

