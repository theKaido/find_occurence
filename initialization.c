#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "math.h"
#include "initialization.h"
#include "struct.h"

char alphabet[MAX] = { 'a','h','t','m'};


int count(char *tab){
	int n = 0;
	while(tab[n]!='\0')
		n++;
	return n;
}

char *fillTab(int n,char tab[])
{ 
    for (int i = 0; i < n; i++)
        tab[i] = alphabet[rand() % MAX];
    return tab;

}

void printTab(char *tab){
	printf("|\t");
	for(int i =0; i < strlen(tab);++i){
		printf("%c",tab[i]);
	}
	printf("\t|\n");
}

// Trouver un m et garder sa pos de début
int findm(int pos,char *tab){

	for(int i = pos; i < strlen(tab); ++i){
		if(tab[i] == 'm' && tab[i+1] != 'm')
			return i;
	}
	return pos;
}
//Se met à la position du dernier m trouvé
int findLastM(int start, int end,char *tab){
	int pos = 0;
	for(int i = start; i < end; ++i){
		if(tab[i] =='m')
			pos = i;
	}
	return pos;
}
//Trouve le dernier t et affiche
int findLastT(int start, int end,char *tab){
	int pos = 0;
	for(int i = start; i < end; ++i){
		if(tab[i] =='t')
			pos = i;
	}
	return pos;
}

// Trouver un a et garder sa position de fin où après il y une lettre différente
int finda(int pos,char *tab){
	for(int i = pos; i < strlen(tab); ++i){
		if((tab[i] =='a' && tab[i+1] =='a') ||(tab[i] =='a' && tab[i+1] =='\0')||(tab[i] =='a' && tab[i+1] !='a'))
			return i;
	}
	return 0;
}
//Trouver un h et retourn sa postion
int findh(int pos,char *tab){

	for(int i = pos; i < strlen(tab); ++i){
		if(tab[i] =='h') 
			return i;
	}
	return 0;
}

//Récupère l'occurence
char *saveOcc(int debut,int fin,char *tab){

int pos = 0;
char *res = malloc(sizeof(char));
	for(int i = debut; i <= fin; ++i,++pos){
		res[pos] = tab[i];
	}
return res;
}


/*De type struct occurence c'est un tableau de string ou tableau de mots si tu veux
elle va trouver les occurences*/
occ *findOcc(char *tab, int OCCSIZE){
	occ *res = (occ *)malloc(OCCSIZE*sizeof(occ));

	int debut = 0;
	int pos_lastm = 0;
	int pos_lasta = 0;
	int pos_lastT = 0;
	int pos_h = 0;
	int n = 0;

		for(int i = 0; i < strlen(tab) - 1 ;i++){
			debut = findm(i,tab);//on se met au premier m que l'on croise

			pos_lasta = finda(debut,tab);//en suite on cherche le premier a qui passe
			pos_h = findh(debut,tab);//On cherche le premier h
			pos_lastm = findLastM(debut,pos_lasta,tab);//Ici on se place a la position du dernier m
			pos_lastT = findLastT(debut,pos_lasta,tab);// ici on se place a la position du dernier t

			if(debut>0){//on commence si seulement le m est en premiere position
				i = debut; // i prends la positiob de m
				if((pos_lastm < pos_lasta) && 
					(pos_h > pos_lastm && pos_h <pos_lasta) &&
					(pos_lastT <  pos_h)){// ici on verifier la position des lettres par rapport a la position des occurence tester
					if(strlen(saveOcc(pos_lastm,pos_lasta,tab))>0){//ici on verifie si la fonction saveOcc reçoit bien une valeur
						res[n].v = malloc(sizeof(char));
						strcpy(res[n].v,saveOcc(pos_lastm,pos_lasta,tab));//on copie la chaine dans le tableau de structure
						res[n].length = strlen(res[n].v);//on affiche la longueur ici
						n++;						
					}
					i = pos_lasta;//on recuper la position de a est on repete la boucle
					printf("\t| Position de %s est %d\t|",saveOcc(pos_lastm,pos_lasta,tab),pos_lastm);//on affiche la position de loccurence
				}
			}
		}
		return res;//retourner le tableau de structure -> vecteur doccurence
}


//Prends un tableau de structure et l'affiche
void printTabOcc(occ *tab){
	for(int i =0;tab[i+1].v != NULL;++i){
		printf("|%s- longueur = %ld\t|",tab[i].v,tab[i].length);
	}
}
//Retourner la taille du tableau d'occurence trouvé
int GetSize(occ *tab){
	int i = 0;
	for(i =0;tab[i+1].v != NULL;++i);

	return i;
}
//fonction de trie par quick sort
void selection_sort(occ *tab, int OCCSIZE){
	int i,j;
	occ tmp;
	for(i=0;i<OCCSIZE-1;i++)
	    for(j=i+1;j<OCCSIZE;j++){
	        if ( tab[i].length < tab[j].length ) {
	            tmp = tab[i];
	            tab[i] = tab[j];
	            tab[j] = tmp;
	        }
		}
}
//fonction de trie par bulle
void  bubble_sort(occ *tab, int OCCSIZE){
    int i,j;
    occ tmp;
    for(j=1;j<=OCCSIZE;j++)
        for(i=0;i<OCCSIZE-1;i++){
            if ( tab[i].length < tab[i+1].length ) {
                    tmp = tab[i];
                    tab[i] = tab[i+1];
                    tab[i+1] = tmp;
            }
    }
}
// les deux time permettent retourner le nombre de tour de la boucle
int time_selection_sort(occ *tab, int OCCSIZE){
	int i,j;
	int count = 0;
	occ tmp;
	for(i=0;i<OCCSIZE-1;i++)
	    for(j=i+1;j<OCCSIZE;j++){
	        if ( tab[i].length < tab[j].length ) {
	            tmp = tab[i];
	            tab[i] = tab[j];
	            tab[j] = tmp;
	        }
	    	count++;
		}
	return count;
}



int  time_bubble_sort(occ *tab, int OCCSIZE){
	int i,j;
	int count = 0;
	occ tmp;
	for(j=1;j<=OCCSIZE;j++) 
	    for(i=0;i<OCCSIZE-1;i++){
	        if ( tab[i].length < tab[i+1].length ) {
	                tmp = tab[i];
	                tab[i] = tab[i+1];
	                tab[i+1] = tmp;
	        }     
	    	count++;
	}
	return count;
}

