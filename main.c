#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int jeu(){
    int nombres[10][10];
    int ligne, col;
    int pa1, pa2;
    int bi;
    int i;
    int co1, co2;
    char lettre='s';
    int d=0;
    int coup=0;

    srand((unsigned) time(NULL));


    for (ligne = 0; ligne <= 9; ligne++) {
        for (col = 0; col <= 9; col++) {
            nombres[ligne][col] = 0;
        }
    }
    printf("    A  B  C  D  E  F  G  H  I  J\n");
    for (ligne = 0; ligne <= 9; ligne++) {
        printf("%2d",ligne+1);
        for (col = 0; col <= 9; col++) {
            printf("%3d", nombres[ligne][col]);
            if (col >= 9) {
                printf("\n");
            }
        }
    }
    do {
        //<editor-fold desc="code à remplacer en random (bateaux)">
        for (i = 0; i < 5; i++) { //bateau 5
            nombres[0][i] = 1;
        }
        for (i = 0; i < 4; i++) { //bateau 4
            nombres[3][i] = 1;
        }
        for (int j = 6; j < 8; j++) { //bateau 3
            for (i = 0; i < 3; i++) {
                nombres[j][i] = 1;
            }
        }
        for (i = 5; i < 7; i++) { //bateau 2
            nombres[9][i] = 1;
        }

    //-------------------------------------------------------------
    //</editor-fold> l
        do {
            printf("\nentrer une lettre entre a et j : ");
            scanf("%c",&lettre);

            //<editor-fold desc="Vide le buffer">
            while (lettre == '\n' && lettre != EOF)
            {
                lettre = getchar();
            }
            //</editor-fold>

            //<editor-fold desc="De A à 0 ou B à 1 ...">
            switch (lettre) {
                case 'a':
                    co1 = 1;
                    break;
                case 'b':
                    co1 = 2;
                    break;
                case 'c':
                    co1 = 3;
                    break;
                case 'd':
                    co1 = 4;
                    break;
                case 'e':
                    co1 = 5;
                    break;
                case 'f':
                    co1 = 6;
                    break;
                case 'g':
                    co1 = 7;
                    break;
                case 'h':
                    co1 = 8;
                    break;
                case 'i':
                    co1 = 9;
                    break;
                case 'j':
                    co1 = 10;
                    break;
                default: co1=111;
            }
            //</editor-fold>

        }while (co1==111);

        do{
            printf("entrer un nombre entre 1 et 10 : ");
            scanf("%d", &co2);
        }
        while ((co2<1)||(co2>10));
        co2--;
        co1--;

        /*                                          //voir les bateaux
        for (ligne = 0; ligne <= 9; ligne++) {
            for (col = 0; col <= 9; col++) {
                printf("%d  ", nombres[ligne][col]);
                if (col >= 9) {
                    printf("\n");
                }
            }
        }*/

        if (nombres[co2][co1] == 1) {
            printf("toucher");
            d++;
        } else {
            printf("plouf\n");
        }
        coup++;
    }while (d!=17);

    //<editor-fold desc="Bateau de 2 random à finir">
    /*
    pa1=1+rand()%9;
    pa2=1+rand()%9;
    bi=1+rand()%2;
    nombres[pa1][pa2]=1;
    for (int i=0;i<=1;i++) {
        if (bi==1){
            nombres[pa1++][pa2]=1;
        } else{
            nombres[pa1][pa2++]=1;
        }
    }
     */
//</editor-fold>

    printf("%d",coup);

}

int regle(){
    printf("Le but :  couler tout les bateaux adverses\n"
           "Fonctionnement :entrer des coordonnées et voir si sa touche un bateau\n\t\tsi un bateau est toucher detruire toute les cases sur les quelle est le bateau pour le couler\n"
           "\n"
           "il y a :"
           "\n\t1 Porte-avions (5 cases)\n"
           "\t1 Croiseur (4 cases)\n"
           "\t2 Contre-torpilleurs (3 cases)\n"
           "\t1 Torpilleur (2 cases)");
}

int main() {
    int a;

    printf("Jouer 1\n");
    printf("regle 4\n");
    scanf("%d",&a);
    switch (a) {
        case 1:
            jeu();
            break;
        case 4:
            regle();
            break;
    }
}

