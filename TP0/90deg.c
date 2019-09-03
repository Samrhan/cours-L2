#include <stdio.h>
#include <stdlib.h>



int main() {

    int tailletab;
    char ***tab;
    int a,b;


    printf(" array's size :\n ");
    scanf("%d",&tailletab);
    tab = (char ***) malloc (sizeof(char ***)*tailletab);
    for (int h = 0; h < tailletab; h++) {
        tab[h] = (char **) malloc(sizeof(char*)*tailletab);
        for (int r = 0; r < tailletab; r++) {
            tab[h][r] = (char *) malloc(sizeof(char)*tailletab);
        }
    }


    for (int h = 0; h < tailletab; h++) {
        for (int r = 0; r < tailletab; r++) {
            printf ("Enter Array Element [%d][%d] : ", h, r);
            scanf ("%s", tab[h][r]);

        }
    }



    // affichetab(tab,tailletab,0);
    for(int i=0;i<tailletab;i++){
        for(int j=0;j<tailletab;j++){
            printf(" %s ",tab[i][j]);}
        printf("\n");
    }
    printf("\n");


    for(int i=0;i<tailletab;i++){
        for(int j=0;j<tailletab;j++){

            printf(" %s ",tab[tailletab-1-j][i]);}
        printf("\n");
    }
    printf("\n");


    printf("test");
    for (int h = 0; h < tailletab; h++) {
        for (int r = 0; r < tailletab; r++) {
            free(tab[h][r]);
        }
        free(tab[h]);
    }
    free(tab);
    return 0;
}
