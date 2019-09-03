#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {

    int nbticket;
    int nblot;
    int* ticket;
    int i=0;
    int nb_aleatoire;


    printf("[LOTTERIE] \n ");
    printf("Nombre de ticket mis en jeu :\n ");
    scanf("%d",&nbticket);

    do {
        printf("Nombre de lot :\n ");
        scanf("%d", &nblot);
        if (nblot > nbticket) {
            printf("le nombre de lots de peux pas etre supérieur au nombre de tickets\n ");
        }
    }while(nblot > nbticket);

    ticket = malloc(nbticket * sizeof(int));

    printf("Entrer les ticket mis en jeu les un apres les autres :\n ");

    for(int i=0;i<nbticket;i++){
        printf("%d:\n ",i+1);
        scanf("%d",&ticket[i]);
    }


    while(nblot<0){
        nb_aleatoire = rand()%nblot;
        if(ticket[nb_aleatoire]!=0){
            i++;
            printf("Lot %d: %d \n ",(i),ticket[nb_aleatoire]);
            ticket[nb_aleatoire]=0;
            nblot-1;
        }
    }

    free(ticket);
    return 0;
}