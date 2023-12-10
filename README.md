# projetenC
 Création d'un agenda

Nous avons essayé de nous entenir au consigne assigné à ce projet.
Malgrés quelque incompréhension, nous avons réussi à faire tout la partie 1 et 2.
Dans la partie 3, une erreur persiste (je crois que c'est du aux allocations dynamiques).
Néanmoins, nous avons fait notre maximum afin de vous présenter notre projet.

Toutes les fonctions sont utilisables sauf:
- fonction addRDV (c'est dans cette fonction que l'erreur persiste)

# Guide d'utilisation des fonctions
Ce programme met en œuvre une liste à niveaux multiples où chaque niveau est une liste chaînée.

## Fonctions disponibles
- `createCell`
 Crée une cellule avec une valeur stockée.
 **Utilisation :**
 t_d_cell* createCell(int val);
- `createList`
 Crée une liste avec un nombre spécifié de niveaux.
 **Utilisation :**
 t_d_list* createList(int max_niv);
- `InsertionListentete`
 Insère un élément en tête de la liste à un niveau spécifié.
 **Utilisation :**
 t_d_list* InsertionListentete(t_d_list* list, int val, int niv);
- `InsertionList`
 Permet d'insérer n'importe où dans la liste, à un niveau spécifié (dans tout les niveaux inférieurs)
 **Utilisation :**
 t_d_list* InsertionList(t_d_list* list, int val, int niv);
- `Listlevel`
 Organise les éléments dans la liste en fonction des niveaux (2n-1).
 **Utilisation :**
 t_d_list* Listlevel(t_d_list* list);
- `displaylist`
 Affiche les éléments d'un niveau spécifié dans la liste.
 **Utilisation :**
 void displaylist(t_d_list* list, int niv);
- `displaylistaligne`
 Affiche les éléments de la liste alignés selon les niveaux.
 **Utilisation :**
 void displaylistaligne(t_d_list* list, int niv);
- `rechercheclassic`
 Recherche un élément dans le niveau 0 de la liste.
 **Utilisation :**
 void rechercheclassic(t_d_list* list, int val);
- `recherchehigh`
 Recherche un élément dans les niveaux supérieurs de la liste.
 **Utilisation :**
 void recherchehigh(t_d_list* list, int val);
### Exemple d'utilisation
int main() {
    t_d_list* list = createList(5); // Crée une liste à 5 niveaux
    list = InsertionListentete(list, 10, 0); // Insère l'élément 10 dans le niveau 0
    Listlevel(list); // Organise les éléments par niveaux
    displaylist(list, 0); // Affiche les éléments du niveau 0
    displaylistaligne(list, 2); // Affiche les éléments du niveau 2 alignés
    return 0;
}

