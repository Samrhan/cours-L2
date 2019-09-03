#include <stdio.h>
#include <stdlib.h>



int main() {
    int choix = 0;
    int a = 0;
    int b = 0;
   do{
       printf("[Menu] \n 1. Addition \n 2. Soustraction \n 3. Multiplication \n 4. Division \n 5. Quitter le programme \n  Choix :");
       scanf("%d",&choix);
       if(choix==1){
           printf("[ADDITION]\n");
           printf("a :");
           scanf("%d",&a);
           printf("\nb :");
           scanf("%d",&b);
           printf("\na + b = : %d\n",(a+b));
       }
       else if(choix==2){
           printf("[SOUSTRACTION]\n");
           printf("a :");
           scanf("%d",&a);
           printf("\nb :");
           scanf("%d",&b);
           printf("\na - b = : %d\n",(a-b));
       }
       else if(choix==3){
           printf("[MULTILICATION]\n");
           printf("a :");
           scanf("%d",&a);
           printf("\nb :");
           scanf("%d",&b);
           printf("\na * b = : %d\n",(a*b));
       }else if(choix==4){
           printf("[DIVISION]\n");
           printf("a :");
           scanf("%d",&a);
           printf("\nb :");
           scanf("%d",&b);
           if(b!=0){
               printf("\na * b = : %d\n",(a/b));
           }
           else{
               printf("b ne doit pas etre egal a 0\n");
           }
       }
   }while(choix!=5);

}