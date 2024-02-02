#ifndef headers_l
	#define headers_l
	
	#include <stdio.h>
	#include<stdlib.h>
	#include<string.h>


typedef struct _avl {
	int id;
    float value;
    int equilibre;
    struct _avl* pL;
    struct _avl* pR;
} Avl;

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

Avl* addAvl(Avl* p, float v,int *h, int id);

void displayInfixe(Avl* p);

void delAvl(Avl* p);




#endif
