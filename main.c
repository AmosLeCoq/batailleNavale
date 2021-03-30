//Auteur: Amos Le Coq
//Projet: Bataille Navale
//version: 0.1
//Date: 29.03.21


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

int score=0;
char nom[20];
char nom1[8] ="name/";
FILE *fp;
char nombres2[10][10];              // Tableau secondaire tableau du joeur (case touchée)
int r;



/**
 * affiche le tableau nombres2
 */
void tableau(){

    int ligne,col;

    if(r!=1){
        for (ligne = 0; ligne <= 9; ligne++) {
            for (col = 0; col <= 9; col++) {
                nombres2[ligne][col] = ' ';
            }
            r=1;
        }
    }
    printf(" ╔═════╗\n");
    printf(" ║JOUER║\n");
    printf(" ╚═════╝\n");

    for (int i=0;i<=9;i++) {
        if (i==0){
            printf("╔═══");
        }
        printf("╦════");
    }
    printf("╗\n");
    printf("║   ║ A  ║ B  ║ C  ║ D  ║ E  ║ F  ║ G  ║ H  ║ I  ║ J  ║\n");
    for (int i=0;i<=9;i++) {
        if (i==0){
            printf("╠═══");
        }
        printf("╬════");
    }
    printf("╣\n║");
    for (ligne = 0; ligne <= 9; ligne++) {
        printf("%3d",ligne+1);
        for (col = 0; col <= 9; col++) {
            printf("║%3c ", nombres2[ligne][col]);
            if (col >= 9) {
                printf("║\n");
            }
        }
        if (ligne!=9){
            for (int i=0;i<=9;i++) {
                if (i==0){
                    printf("╠═══");
                }
                printf("╬════");
            }
            printf("╣\n║");
        }else{
            for (int i=0;i<=9;i++) {
                if (i==0){
                    printf("╚═══");
                }
                printf("╩════");
            }
            printf("╝\n");
        }
    }
}

void jeu(){
    int nombres[10][10][10];                // Tableau principale
    int ligne, col;                     // Pour definire le tableau
    int i;                              // Pour des boucles for
    int co1, co2;                       // Les coordonnée ex. nombres[co2][co1]=1;
    char lettre='s';                    // Variable pour l'entrée d'une coordonnée orientalement
    int d=0;                            // Nombre de case toucher
    int coup=0;                         // Nombre de coup
    int pr;
    int rand1;
    int bateau2;
    int bateau30,bateau31;
    int bateau4;
    int bateau5;

    srand((unsigned)time(NULL));

    rand1=rand()%9;

     //<editor-fold desc="Mise à zero des 2 tableaux">
     /**
      * Défini le tableau1 à 0
      */
    for (pr=0;pr<=9;pr++) {
        for (ligne = 0; ligne <= 9; ligne++) {
            for (col = 0; col <= 9; col++) {
                nombres[ligne][col][pr] = 0;
            }
        }
    }
    /**
     * Défini le tableau2 à 'O'
     */
    for (ligne = 0; ligne <= 9; ligne++) {
        for (col = 0; col <= 9; col++) {
            nombres2[ligne][col] = 'O';
        }
    }
    //</editor-fold>

    //<editor-fold desc="affichage du tableau de départ">
    /**
     * Affiche le tableau 2 (char pour l'affichage)
     */
    tableau();

    //</editor-fold>

        //<editor-fold desc="code en random (mise en place des bateaux)">
    /**
    * positionne les bateaux sur le tableau 1
    */

    for (int j=0;j<=9;j++) {
        bateau5=rand()%2;
        if(bateau5==0){
            for (i=0;i<5;i++) {           //bateau 5
                nombres[0][i][j]=1;
            }
        }else{
            for (i=0;i<5;i++) {
                nombres[i][0][j]=1;
            }
        }
        bateau4=rand()%2;
        if(bateau4==0){
            for (i=6;i<10;i++) {           //bateau 4
                nombres[5][i][j]=1;
            }
        }else{
            for (i=5;i<9;i++) {
                nombres[i][6][j]=1;
            }
        }
        bateau30=rand()%2;
        if(bateau30==0){
            for (i=1;i<4;i++) {           //bateau 30
                nombres[7][i][j]=1;
            }
        }else{
            for (i=7;i<10;i++) {
                nombres[i][1][j]=1;
            }
        }
        bateau31=rand()%2;
        if(bateau31==0){
            for (i=7;i<10;i++) {           //bateau 31
                nombres[1][i][j]=1;
            }
        }else{
            for (i=1;i<4;i++) {
                nombres[i][7][j]=1;
            }
        }
        bateau2=rand()%2;
        if(bateau2==0){
            for (i=3;i<5;i++) {           //bateau 2
                nombres[2][i][j]=1;
            }
        }else{
            for (i=3;i<5;i++) {
                nombres[i][3][j]=1;
            }
        }
    }

    pr=rand1;


    //</editor-fold> l

    do {
        //<editor-fold desc="entrées des coordonnées">
        /**
         * entrée des données pour la colonne(co1)  et la ligne(co2)
         */
        do {
            printf("\nEntrer une lettre entre 'a' et 'j' : \n"
                   "M :menu\n: ");

            fflush(stdin);
            scanf("%c",&lettre);

            //<editor-fold desc="entrées des lettres">
            /**
             * fait correspondre une lettre a un chiffre tableau 1
             */
            switch (lettre) {
                case 'a':
                case 'A':
                    co1 = 1;
                    break;
                case 'b':
                case 'B':
                    co1 = 2;
                    break;
                case 'c':
                case 'C':
                    co1 = 3;
                    break;
                case 'd':
                case 'D':
                    co1 = 4;
                    break;
                case 'e':
                case 'E':
                    co1 = 5;
                    break;
                case 'f':
                case 'F':
                    co1 = 6;
                    break;
                case 'g':
                case 'G':
                    co1 = 7;
                    break;
                case 'h':
                case 'H':
                    co1 = 8;
                    break;
                case 'i':
                case 'I':
                    co1 = 9;
                    break;
                case 'j':
                case 'J':
                    co1 = 10;
                    break;
                case 'm':
                case 'M':
                    r=0;
                    system("cls");
                    return;
                case 'p':
                    for (int a=0;a<=9;a++) {
                        printf("\n--------------JOUER---------------\n\n");
                        printf("    A  B  C  D  E  F  G  H  I  J\n");
                        for (ligne = 0; ligne <= 9; ligne++) {
                            printf("%2d",ligne+1);
                            for (col = 0; col <= 9; col++) {
                                printf("%3d", nombres[ligne][col][a]);
                                if (col >= 9) {
                                    printf("\n");
                                }
                            }
                        }
                        printf("\ntableau numero:%d\n",a);
                    }
                    system("Pause\n");
                    system("cls");
                default: co1=11;
                    break;
            }
            //</editor-fold>
        }while (co1==11);
        fflush(stdin);
        //<editor-fold desc="entrées des nombres">
        /**
         *      Entre un nombre entre 1 et 10 dans la variable co2 (coordonnée n°2)
         */
        do {
            printf("Entrer un nombre entre 1 et 10 : ");
            scanf("%d",&co2);
            fflush(stdin);
        } while ((co2 < 1) || (co2 > 10));
        //</editor-fold>

        co2--;
        co1--;

        //<editor-fold desc="reponse des coordonnées si elle a toucher ou pas un bateau">
        /**
         * met à jour les tableaux 1 et 2
         */
        switch (nombres[co2][co1][pr]) {
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

        nombres[co2][co1][pr] = 2;                                      //pour définir la case comme déja touchée

        //<editor-fold desc="Actualisation et affichage du tableau">
        /**
         * Affiche le tableau2 (Char)
         */
        system("Pause\n");
        system("cls");
        printf("\n");
        tableau();

        //</editor-fold>
    }while (d!=17);

    score=coup;
    fp=fopen(nom1,"r+");
    fprintf(fp,"%d",coup);                                                 //enregistre le score
    fclose(fp);

    printf("\nVotre Score :%d\n\n",score);                                 //donne le score (nombre de coup)
    system("Pause");
    r=0;
}

void regle(){
    printf("\n  ╔═══════════╗\n");
    printf("  ║  Règles   ║\n");
    printf("  ╚═══════════╝\n\n\n");
    printf(" ╔══════════════════════════════════════════════════════════════════════════════════╗\n");
    printf(" ║ Le but :                                                                         ║\n"
           " ║         Couler tout les bateaux adverses                                         ║\n"
           " ╠══════════════════════════════════════════════════════════════════════════════════╣\n"
           " ║ Le fonctionnement :                                                              ║\n"
           " ║                    Entrer des coordonnees et voir si sa touche un bateau         ║\n"
           " ║                    si un bateau est toucher il faut detruire                     ║\n"
           " ║                    toute les cases sur les quelle est le bateau pour le couler   ║\n"
           " ║──────────────────────────────────────────────────────────────────────────────────║\n"
           " ║  il y a :                                                                        ║\n"
           " ║          1 Porte-avions (5 cases)                                                ║\n"
           " ║          1 Croiseur (4 cases)                                                    ║\n"
           " ║          2 Contre-torpilleurs (3 cases)                                          ║\n"
           " ║          1 Torpilleur (2 cases)                                                  ║\n"
           " ╚══════════════════════════════════════════════════════════════════════════════════╝\n\n  ");
    system("Pause");
}

void aide(){
    printf("\n  ╔═══════════╗\n");
    printf("  ║   Aide    ║\n");
    printf("  ╚═══════════╝\n\n\n");
    printf(" ╔══════════════════════════════════════════════════════════════════════════════════╗\n"
           " ║ Pour entrer les lettres: si il y a plusieurs lettres que, la premiere            ║\n"
           " ║                          sera prise en compte.                                   ║\n"
           " ║                                                                                  ║\n"
           " ║ Pour entrer un chiffre : il faut entrer un chiffre et non une lettre.            ║\n"
           " ║                                                                                  ║\n"
           " ║         X = Bateau toucher                                                       ║\n"
           " ║         ? = Pas toucher de bateau                                                ║\n"
           " ╚══════════════════════════════════════════════════════════════════════════════════╝\n\n");
    system("Pause");
}

/**
 * premet de crée un fichier .txt dans le "name" "nom.txt"
 */
void creer(){
    system("cls");

    printf("\n  ╔═══════════╗\n"
           "  ║  Ton Nom  ║\n"
           "  ╚═══════════╝\n\n"
           "   ►  ");

    scanf("%s",nom);

    strcat(nom,".txt");

    strcat(nom1,nom);

    fp=fopen(nom1,"w+");

    fclose(fp);
}

/**
 * Permet de voir le fichier grace au nom de la personne dans le "name"  nom.txt
 */
void connecter(){

    int d=0;
    system("cls");
    printf("\n  ╔═══════════╗\n"
           "  ║  Ton Nom  ║\n"
           "  ╚═══════════╝\n\n"
           "   ►  ");

    scanf("%s",nom);

    strcat(nom,".txt");

    strcat(nom1,nom);


    fp=fopen(nom1,"r");

    if(fp==NULL){
        printf("Erreur votre nom est pas valable\n\n");
        return;
    }

    fscanf(fp,"%d",&d);

    printf("\nVotre meilleur score: %d",d);

    fclose(fp);
    printf("\n");
}

/**
 * Connexion appelle créer ou connecter
 */
void connexion(){

    int i=0;

    printf("\n  ╔════════════╗\n");
    printf("  ║  Connexion ║\n");
    printf("  ╚════════════╝\n\n\n");
    printf("    ╔═══════════╗\n");
    printf("  ► ║  1: Créer ║\n");
    printf("    ╚═══════════╝\n");
    printf("    ╔═══════════════╗\n");
    printf("  ► ║  2: Connecter ║\n");
    printf("    ╚═══════════════╝\n");
    printf("    ╔═══════════════╗\n");
    printf("  ► ║  3: Quitter   ║\n");
    printf("    ╚═══════════════╝\n\n:");

    scanf("%d",&i);
    switch (i) {
        case 1:
            creer();
            break;
        case 2:
            connecter();
            break;
        case 3:
            return;
    }
    system("Pause");
}

/**
 *
 */
void date(){

    int h, min, s, day, mois, an;
    time_t now;

    // Renvoie l'heure actuelle
    time(&now);
    // Convertir au format heure locale
    printf("Aujourd'hui est : %s", ctime(&now));
    struct tm *local = localtime(&now);
    h = local->tm_hour;
    min = local->tm_min;
    s = local->tm_sec;
    day = local->tm_mday;
    mois = local->tm_mon + 1;
    an = local->tm_year + 1900;

    fprintf(fp,"\nL'heure : %02d:%02d:%02d\n", h, min, s);
    // Afficher la date courante
    fprintf(fp,"La date : %02d/%02d/%d\n", day, mois, an);
}

/**
 * permet d'afficher la date et l'action dans le log (log.txt)
 * @param a
 * @return
 */
int log(int a) {

    fp=fopen("log.txt","a");

    switch (a) {
        case 1:
            fprintf(fp,"\n\nJoue:\n");
            date();
            break;
        case 2:
            fprintf(fp,"\n\nOuverture des règles:\n");
            date();
            break;
        case 3:
            fprintf(fp,"\n\nOuverture de l'aide:\n");
            date();
            break;
        case 4:
            fprintf(fp,"\n\nConnection:\n");
            date();
            break;
        case 5:
            fprintf(fp,"\n\nQuitte le programe:\n");
            date();
            fprintf(fp,"\n---------------------------------------------------------------------------");
            break;
    }
    fclose(fp);
}

int main() {
    SetConsoleOutputCP(65001);
    int menu;
    int fin;

    do{
        system("cls");
        printf("\n  ╔═══════════════════╗\n");
        printf("  ║  Bataille Navale  ║\n");
        printf("  ╚═══════════════════╝\n\n");
        printf("    ╔═══════════╗\n");
        printf("  ► ║  1: Jouer ║\n");
        printf("    ╚═══════════╝\n");
        printf("    ╔═══════════╗\n");
        printf("  ► ║  2: Règle ║\n");
        printf("    ╚═══════════╝\n");
        printf("    ╔═══════════╗\n");
        printf("  ► ║  3: Aide  ║\n");
        printf("    ╚═══════════╝\n");
        printf("    ╔═══════════════╗\n");
        printf("  ► ║  4: connexion ║\n");
        printf("    ╚═══════════════╝\n");
        printf("    ╔════════════╗\n");
        printf("  ► ║ 5: Quitter ║\n");
        printf("    ╚════════════╝\n\n:");

        scanf("%d",&menu);
        switch (menu) {
            case 1:
                system("cls");
                printf("\n");
                log(1);
                jeu();
                break;
            case 2:
                system("cls");
                log(2);
                regle();
                break;
            case 3:
                system("cls");
                log(3);
                aide();
                break;
            case 4:
                system("cls");
                log(4);
                connexion();
                break;
            case 5:
                fin=5;
                log(5);
                break;
        }
    }while (fin!=5);
}

