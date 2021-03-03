#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int nombres [10] [10];
    int ligne,col;
    int pa1,pa2;

    srand((unsigned) time(NULL));

    for (ligne = 0; ligne<=9; ligne++) {
        for (col = 0; col<=9; col++) {
            nombres[ligne] [col] = 0;
        }
    }
    for (ligne = 0; ligne<=9; ligne++) {
        for (col = 0; col<=9; col++) {
            printf("%d",nombres[ligne][col]);
            if (col>=9){
                printf("\n");
            }
        }
    }
    pa1=1+rand()%9;
    pa2=1+rand()%9;
    nombres[pa1][pa2]=1;
    for (int i=0;i<=5;i++) {

    }

}
