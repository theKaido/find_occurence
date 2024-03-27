#include "struct.h"
#ifndef _INITIALIZATION
#define _INITIALIZATION


char *fillTab(int n,char tab[]);
void printTab(char *tab);
occ *findOcc(char *tab, int OCCSIZE);
int count(char *s);
char *saveOcc(int debut,int fin,char *tab);
void printTabOcc(occ *tab);
int findm(int pos,char *tab);
int finda(int pos,char *tab);
int findLastM(int start ,int end,char *tab);
void selection_sort(occ *tab, int OCCSIZE);
void  bubble_sort(occ *tab, int OCCSIZE);
int  time_bubble_sort(occ *tab, int OCCSIZE);
int time_selection_sort(occ *tab, int OCCSIZE);
int GetSize(occ *tab);
#endif