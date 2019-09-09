#include <stdio.h>
#include <stdlib.h>

typedef struct element element;

struct element {
    int data;
    element *next;
};

element *creer_maillon(int);

element *ajouter_maillon(element *, element *, int);

void afficher_liste(element *);

int compter(element *);

int croissant(element *);

element *suppr(element *, int);

void inverse(element **);

int main() {
    element *liste = creer_maillon(10);
    element *temp = creer_maillon(15);
    liste = ajouter_maillon(temp, liste, -1);
    temp = creer_maillon(20);
    liste = ajouter_maillon(temp, liste, -1);
    temp = creer_maillon(25);
    liste = ajouter_maillon(temp, liste, -1);
    temp = creer_maillon(30);
    liste = ajouter_maillon(temp, liste, -1);
    temp = creer_maillon(35);
    liste = ajouter_maillon(temp, liste, -1);
    temp = creer_maillon(45);
    liste = ajouter_maillon(temp, liste, -1);
    afficher_liste(liste);
    int taille = compter(liste);
    printf("La liste contient %d elements\n", taille);
    printf("La liste est dans l'ordre croissant : %d\n", croissant(liste));
    liste = suppr(liste, 2);
    taille = compter(liste);
    afficher_liste(liste);
    printf("La liste contient %d elements\n", taille);
    inverse(&liste);
    afficher_liste(liste);
    return 0;
}

element *ajouter_maillon(element *maillon, element *debut, int position) {
    if (position != 0) {
        int i = 0;
        element *temp = debut;
        while (temp->next != NULL) {
            i++;
            if (i == position - 1)
                break;

            temp = temp->next;

        }
        maillon->next = temp->next;
        temp->next = maillon;
    } else {
        maillon->next = debut;
        debut = maillon;
    }
    return debut;
}

element *creer_maillon(int _data) {
    element *maillon = NULL;
    maillon = malloc(sizeof(element));
    maillon->data = _data;
    maillon->next = NULL;
    return maillon;
}

void afficher_liste(element *liste) {
    if (liste == NULL) {
        printf("X\n");
    } else {
        printf("%d->", liste->data);
        afficher_liste(liste->next);
    }
}

int compter(element *maillon) {
    int i = 1;
    if (maillon == NULL) {
        return 0;
    } else {
        element *temp = maillon;
        while (temp->next != NULL) {
            temp = temp->next;
            i++;
        }

    }
    return i;
}

int croissant(element *maillon) {
    if (maillon == NULL)
        return 0;
    else {
        element *temp = NULL;
        temp = maillon;
        while (temp->next) {
            if (temp->data > temp->next->data)
                return 0;
            temp = temp->next;
        }

    }
    return 1;

}

element *suppr(element *debut, int position) {
    if (position != 0) {
        int i = 0;
        element *temp = debut;
        while (temp->next != NULL) {
            i++;
            if (i == position)
                break;

            temp = temp->next;

        }
        temp->next = temp->next->next;

    } else {
        element *temp = debut;
        debut = debut->next;
        free(temp);
    }
    return debut;

}

void inverse(element **debut) {
    element *precedent = NULL;
    element *actuel = NULL;
    actuel = *debut;
    while (actuel != NULL) {
        element *suivant = actuel->next;
        actuel->next = precedent;
        precedent = actuel;
        actuel = suivant;
    }
    *debut = precedent;
}

int doublons(element* liste){
    element *liste_tri = creer_maillon(liste->data);
    element *temp = liste;
    element *temp_2 = liste_tri;
    while(temp->next != NULL){
        while(temp->data < temp_2->data){
            temp_2 = temp_2->next;
            if (temp->data == temp_2->data)
                return 1;
        }

    }

}
