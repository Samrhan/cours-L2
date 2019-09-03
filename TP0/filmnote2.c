#include <stdio.h>
#include <stdlib.h>

int main() {

    int note[5];
    int moy =0;
    for(int i = 0;i<5;i++){
        printf("Note du film %d :\n",i+1);
        scanf("%d",&note[i]);
    }
    for(int i = 0;i<5;i++){
        moy+=note[i];
    }
    moy=moy/5;
    printf("moyenne : %d",moy);

    return 0;

}