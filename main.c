#include "stdlib.h"
#include "stdio.h"
#include "fichier.h"
#include "timer.h"
#include "fichier.h"
#include "application.h"

int main() {
    Agenda *agenda = createAgenda(5);
    Contact *contact = createContact(agenda);
    displaycontact(agenda);
    displayRDV(agenda);
    agenda=addRDV(agenda);
    displaycontact(agenda);
    displayRDV(agenda);
    freeAgenda(agenda);
    return 0;
}
/*
int main() {

    t_d_list* list= createList(5);
    displaylist(list,0);
    displaylist(list,1);
    displaylist(list,2);
    displaylist(list,3);
    displaylist(list,4);
    InsertionList(list, 25, 0);
    InsertionList(list, 31, 1);
    InsertionList(list, 56, 2);
    InsertionList(list, 18, 3);
    InsertionList(list, 32, 4);
    displaylist(list,0);
    displaylist(list,1);
    displaylist(list,2);
    displaylist(list,3);
    displaylist(list,4);
    displaylistaligne(list,0);
    displaylistaligne(list,1);
    displaylistaligne(list,2);
    displaylistaligne(list,3);
    displaylistaligne(list,4);

    t_d_list* mylist= createList(3);
    mylist=Listlevel(mylist);
    displaylist(mylist,0);
    displaylist(mylist,1);
    displaylist(mylist,2);
    displaylistaligne(mylist,0);
    displaylistaligne(mylist,1);
    displaylistaligne(mylist,2);
    rechercheclassic(mylist, 4);
    recherchehigh(mylist,6);


    int initial_level = 7;
    int final_level = 16;
    int max_value = 10000;
    char *time_lvl0;
    char *time_all_levels;
    FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    srand(time(NULL));
    t_d_list *myList = createList(final_level);
    myList=Listlevel(myList);
    for (int level = initial_level; level <= final_level; level++) {
        //printf("Niveau testé : %d\n", level);
        //displaylist(myList,level);
        startTimer();
        for (int i = 0; i < max_value; i++) {
            rechercheclassic(myList, (rand()%max_value));
        }
        stopTimer();
        time_lvl0 = getTimeAsString();

        startTimer();
        for (int i = 0; i < max_value; i++) {
            recherchehigh(myList, rand() % max_value);
        }
        stopTimer();
        time_all_levels = getTimeAsString();

        fprintf(log_file,format,level,time_lvl0, time_all_levels);
    }
    fclose(log_file);

    return 0;
}
*/