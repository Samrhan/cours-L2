#include <stdlib.h>
#include <stdio.h>
#include "structs.h"
#include "pile.h"

int compter(t_Node*);

void afficher_arbres(t_Node* arbre);

t_Node * creer_noeud(int data);

int searchnb(t_Node*, int);

void doubler(t_Node*);

void supprimer_arbres(t_Node* arbre);

t_Node* gen_tree(int n);

int paire_feuille(t_Node* arbre);

int profondeur(t_Node* arbre);


int main(int argc, char* argv[])
{
    t_Node* michel = creer_noeud(0);
    michel->gauche = creer_noeud(1);
    michel->droit = creer_noeud(2);
    michel->gauche->droit = creer_noeud(3);
    afficher_arbres(michel);
    int n = compter(michel);
    printf("\n%d\n", n);
    printf("%d\n", searchnb(michel, 2));
    doubler(michel);
    afficher_arbres(michel);
    supprimer_arbres(michel);
    michel = NULL;
    n = compter(michel);
    printf("\n%d\n", n);
    michel = creer_noeud(0);
    michel->gauche = creer_noeud(1);
    michel->droit = creer_noeud(2);
    michel->gauche->droit = creer_noeud(3);
    printf("PARCOURS EN PROFONDEUR\n");
    affichage_prefix(michel);
    supprimer_arbres(michel);
    printf("\n");
    michel = NULL;
    michel = gen_tree(16);
    affichage_prefix(michel);
    printf("\n");
    supprimer_arbres(michel);
    michel = gen_tree(16);
    affichage_largeur(michel);
    supprimer_arbres(michel);
    michel = creer_noeud(0);
    michel->gauche = creer_noeud(1);
    michel->droit = creer_noeud(2);
    printf("\n");
    printf("%d\n", paire_feuille(michel));
    printf("%d\n", profondeur(michel));
    return 0;

}

int compter(t_Node* arbre)
{
    if (!arbre)
        return 0;
    else
        return 1 + compter(arbre->gauche) + compter(arbre->droit);
}

void afficher_arbres(t_Node* arbre)
{
    if(arbre) {

        afficher_arbres(arbre->gauche);
        afficher_arbres(arbre->droit);
        printf("%d=>",arbre->info);

    }
}
t_Node * creer_noeud(int data)
{
    t_Node * nouv = malloc(sizeof(t_Node));
    nouv->info = data;
    nouv->droit = NULL;
    nouv->gauche = NULL;
    return nouv;
}

int searchnb(t_Node* arbre, int data)
{
    if(!arbre)
        return 0;
    else if (arbre->info == data)
        return 1;
    else
        return searchnb(arbre->gauche, data)+ searchnb(arbre->droit, data);

}

void doubler(t_Node* arbre)
{
    if(arbre) {
        arbre->info *= 2;
        doubler(arbre->droit);
        doubler(arbre->gauche);
    }
}

void supprimer_arbres(t_Node* arbre)
{
    if(arbre) {
        supprimer_arbres(arbre->gauche);
        supprimer_arbres(arbre->droit);
        free(arbre);
    }
}

t_Node* gen_tree(int n)
{
    if(n == 0)
    {
        return NULL;
    }
    else
    {
        t_Node* node = creer_noeud(n);
        node -> gauche = gen_tree((n-1) / 2 + (n - 1) % 2);
        node -> droit = gen_tree((n-1) / 2);
        return node;
    }
}
int paire_feuille(t_Node* arbre){
    if(!arbre)
        return 0;
    else{
        if(!arbre->droit && !arbre->gauche)
            return 1;
        else
            return (paire_feuille(arbre->droit)+paire_feuille(arbre->gauche)+1)%2;
    }
}

int profondeur(t_Node* arbre){
    if(!arbre)
        return 0;
    else{
        int a = profondeur(arbre->droit);
        int b = profondeur(arbre->gauche);
        if(a>b)
            return a+1;
        else return b+1;
    }
}
