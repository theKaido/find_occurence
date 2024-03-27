/**
* Nom : Mathanaruban
* Prénom : Jonny
* Numéro étudiant : 16702706
* mail : jonnymthdev@gmail.com
*/

/** Comme mentionner dans le fichier ReadME.txt
- Pour compiler : make
- Exécuter : ./algo
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "initialization.h"
#include "struct.h"
//MOTIF : mt*h+a
int main(int argc, char *argv[]) {
  srand(time(NULL));
  //ETAPE 0 
  int size_tab = 0;//initialisation taille tableau
  int BubbleTime = 0;// initialisation de la variable
  int SelectionTime = 0;//initialisation de la variable temps de boucle de la fonction tri quick sort
  char tab[150] = 
"mthamhaaaaaaamhhhhhaaammmmmmmmhhhamttttttamttttttthhhhatmmmtmththhatmmamtmtmtmmttmtmhamamhtmmhtahtmhhtttmmthahhathamthamtthhaatmaatmtmthamahthmhmttmam";
  printf("\n\n ------- ETAPE 0:---------\n");
  printf("%s\n",tab);
  printf("---------- \n\n (PS il n'y a pas d'étape 2) ETAPE 1 & 3 occurences:--------------\n");
  occ *test = (occ *)malloc(150*sizeof(occ));
  test = findOcc(tab,150);
  printTabOcc(test);
  free(test);

  char tab2[8000];
  fillTab(8000,tab2); 
  printf("\n \nETAPE 4  - TABLEAU 8000 caractères de 4 lettres :\n\n ");
  printTab(tab2);

  printf("\n\n\t\t--- ETAPE 5 & 6 - occurences et leurs tailles: ---\t\t\n\n");

  
  occ *test2 = (occ *)malloc(8000*sizeof(occ));
  test2 = findOcc(tab2,8000);
  size_tab = GetSize(test2);//on donne la taille des occurences trouvées
  printf("Il y a %d occurences trouvées \n\n ",size_tab);
  printTabOcc(test2);
  printf("---------- \n\n ETAPE 7 & 8- Tri par sélection et à bulles & Regrouper les occurences par longueur:\n\n-------------");
  bubble_sort(test2, size_tab);
  selection_sort(test2, size_tab);
  printTabOcc(test2);
  BubbleTime = time_bubble_sort(test2,size_tab);
  SelectionTime = time_selection_sort(test2,size_tab);
  printf("Tri à Bulle = %d, Tri par Sélection = %d \n", BubbleTime,SelectionTime);
  printf("---------- \n\n On Remarque par la même occasion que le tri à Sélection est plus rapide \n\n-------------");

  free(test2);
  return 0;
}
