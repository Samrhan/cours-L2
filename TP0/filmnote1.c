#include <stdio.h>
#include <stdlib.h>

int main() {
    printf(" votre note du film parasite sur 20 :\n");
    int note;
    scanf("%d",&note);
    printf(" votre note du  sur 5 :%d\n",(note/20*5));
    printf(" votre note du  sur 100 :%d\n",(note/20*100));

    return 0;
}