#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_livre {
    char titre[100];
    char auteur[100];
    int date;
    float prix;
} t_livre;

int main(int argc, char *argv[]) {
    t_livre *livre = NULL;
    int n = 0, nn = 0, c = 0;
    FILE *psave = NULL;
    FILE *bsave = NULL;
    psave = fopen("save.txt", "r");
    char line[256];
    if (psave != NULL) {
        while ((c = getc(psave)) != EOF){
            if (c == '\n')
                ++n;
        }
        fclose(psave);
        bsave = fopen("save.txt", "r");
        livre = malloc(n*sizeof(t_livre));
        while (fgets(line, sizeof line, bsave) != NULL)
        {
            strcpy(livre[nn].titre, line);
            nn++;
        }

        fclose(bsave);
    }
    nn = 0;
    while (nn != n + 1) {
        for (int i = 0; i < n; i++) {
            printf("%d. %s\n", i + 1, livre[i].titre);
        }
        printf("%d. Nouvelle Entree\n", n + 1);
        printf("%d. Quitter\n", n + 2);
        printf("Votre choix : \n");
        scanf(" %d", &nn);
        if (nn <n+1) {
            printf("Titre : %s\n", livre[nn-1].titre);
            printf("Auteur : %s\n", livre[nn-1].auteur);
            printf("Date de parution : %d\n", livre[nn-1].date);
            printf("Prix : %.2f\n", livre[nn-1].prix);
        }
        else if (nn == n+1){
            n += 1;
            livre = realloc(livre, n*sizeof(t_livre));
            printf("Saisissez le titre : \n");
            scanf(" %s", livre[n-1].titre);
            printf("Saisissez l'auteur : \n");
            scanf(" %s", livre[n-1].auteur);
            printf("Saisissez la date de parution : \n");
            scanf(" %d", &livre[n-1].date);
            printf("Saisissez le prix: \n");
            scanf(" %f", &livre[n-1].prix);
        }
    }
    FILE *save = NULL;
    save = fopen("save.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(save, "%s,%s,%d,%f\n", livre[i].titre, livre[i].auteur, livre[i].date, livre[i].prix);
    }
    fclose(save);

    return 0;
}
