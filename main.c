#include <stdio.h>
#include <stdlib.h>


void jeu(){
    int nombres[10][10];                // Tableau principale
    char nombres2[10][10];              // Tableau secondaire (case touchée)
    int ligne, col;                     // Pour definire le tableau
    int i;                              // Pour des boucles for
    int co1, co2;                       // Les coordonnée ex. nombres[co2][co1]=1; ligne 123
    char lettre='s';                    // Variable pour l'entrée d'une coordonnée orientalement
    int d=0;                            // Nombre de case toucher
    int coup=0;                         // Nombre de coup

    //<editor-fold desc="Mise à zero des tableaux">
    for (ligne = 0; ligne <= 9; ligne++) {
        for (col = 0; col <= 9; col++) {
            nombres[ligne][col] = 0;
        }
    }

    for (ligne = 0; ligne <= 9; ligne++) {
        for (col = 0; col <= 9; col++) {
            nombres2[ligne][col] = 'O';
        }
    }
    //</editor-fold>

    //<editor-fold desc="affichage du tableau de départ">
    printf("--------------JOUER---------------\n\n");
    printf("    A  B  C  D  E  F  G  H  I  J\n");
    for (ligne = 0; ligne <= 9; ligne++) {
        printf("%2d",ligne+1);
        for (col = 0; col <= 9; col++) {
            printf("%3c", nombres2[ligne][col]);
            if (col >= 9) {
                printf("\n");
            }
        }
    }
    //</editor-fold>

        //<editor-fold desc="code à remplacer en random (mise en place des bateaux)">
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
    //</editor-fold> l

    do {

        //<editor-fold desc="entrées des coordonnées">
        do {
            printf("\nEntrer une lettre entre 'a' et 'j' : \n"
                   "M :menu\n: ");
            scanf("%c",&lettre);

            //<editor-fold desc="Vide le buffer">


           /* do {
                lettre = getchar();
            } while (lettre != '\n' && lettre != EOF);*/
            //</editor-fold>

            //<editor-fold desc="entrées des lettres">
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
                case 'm':
                    system("cls");
                    return;
                default: co1=111;
                    break;
            }
            //</editor-fold>

        }while (co1==111);

        //<editor-fold desc="entrées des nombres">
        do {
            printf("Entrer un nombre entre 1 et 10 : ");
            scanf("%d",&co2);
        } while ((co2 < 1) || (co2 > 10));
        //</editor-fold>

        co2--;
        co1--;

        //<editor-fold desc="reponse des coordonnées si elle a toucher ou pas un bateau">
        switch (nombres[co2][co1]) {
            case 0:
                printf("\nPlouf\n\n");
                coup++;
                nombres2[co2][co1] = '?';
                break;
            case 1:
                printf("\nToucher\n\n");
                coup++;
                d++;
                nombres2[co2][co1] = 'X';
                break;
            case 2:
                printf("\nDeja fait\n\n");
                break;
        }
        //</editor-fold>
        //</editor-fold>

        nombres[co2][co1] = 2;                                      //pour définir la case comme déja touchée

        //<editor-fold desc="Voir les bateaux">
        /*printf("    A  B  C  D  E  F  G  H  I  J\n");
        for (ligne = 0; ligne <= 9; ligne++) {
            printf("%2d",ligne+1);
            for (col = 0; col <= 9; col++) {
                printf("%3d", nombres[ligne][col]);
                if (col >= 9) {
                    printf("\n");
                }
            }
        }
         */
        //</editor-fold>

        //<editor-fold desc="Actualisation et affichage du tableau">
        system("Pause\n");
        system("cls");
        printf("\n--------------JOUER---------------\n\n");
        printf("    A  B  C  D  E  F  G  H  I  J\n");
        for (ligne = 0; ligne <= 9; ligne++) {
            printf("%2d", ligne + 1);
            for (col = 0; col <= 9; col++) {
                printf("%3c", nombres2[ligne][col]);
                if (col >= 9) {
                    printf("\n");
                }
            }
        }
        //</editor-fold>
    }while (d!=17);

    printf("Votre Score :%d",coup);                                 //donne le score (nombre de coup)
    system("Pause");
}

void regle(){
    printf("-------------Regle---------------\n\n");
    printf("Le but :  couler tout les bateaux adverses\n\n"
           "Fonctionnement :entrer des coordonnees et voir si sa touche un bateau\n\t\tsi un bateau est toucher detruire toute les cases sur les quelle est le bateau pour le couler\n"
           "\n"
           "il y a :"
           "\n\t1 Porte-avions (5 cases)\n"
           "\t1 Croiseur (4 cases)\n"
           "\t2 Contre-torpilleurs (3 cases)\n"
           "\t1 Torpilleur (2 cases)");
    printf("\n");
    system("Pause");
}

int main() {
    int a;
    int fin;

    do{
        system("cls");
        printf("Bataille Navale\n\n");
        printf("1 Jouer\n");
        printf("2 regle\n");
        printf("3 Quitter\n");
        scanf("%d",&a);
        switch (a) {
            case 1:
                system("cls");
                printf("\n");
                jeu();
                break;
            case 2:
                system("cls");
                regle();
                break;
            case 3:
                fin=5;
            default:
                break;
        }
    }while (fin!=5);
}

