#ifndef headers_d2
	#define headers_d2
	
	#include <stdio.h>
	#include<stdlib.h>
	#include<string.h>


typedef struct _avl {
	char* id;
    float value;
    int equilibre;
    struct _avl* pL;
    struct _avl* pR;
} Avl;

Avl * createAvl(float v, char* identite); 

int AvlNULL(Avl* pTree);

int AvlLeftExist(Avl * pTree);

int AvlRightExist(Avl * pTree);

int high(Avl * pTree);

Avl * equilibrage(Avl * pTree);

Avl * Rota_G(Avl * pTree);

Avl * Rota_D(Avl * pTree);

Avl * RotaDouble_G(Avl * pTree);

Avl * RotaDouble_D(Avl * pTree);

Avl * equilibrage(Avl * pTree);

Avl* addAvl(Avl* p, float v,int *h, char* identite);

void displayInfixe(Avl* p);

void delAvl(Avl* p);




#endif
