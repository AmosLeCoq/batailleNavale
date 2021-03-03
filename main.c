#include <stdio.h>

int main() {
    int nombres [10] [10];
    int ligne,col;

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
}


int porte-avions(){
    


}
