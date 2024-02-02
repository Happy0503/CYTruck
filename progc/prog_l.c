#include "headers_l.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Avl * createAvl(int id, float v){
    Avl* pNew = malloc(sizeof(Avl));
    if(pNew == NULL){
        exit(1);
    }
    pNew->value = v;
    pNew->equilibre = 0;
    pNew->pL = NULL;
    pNew->pR = NULL;
	pNew->id = id;
    return pNew;
} 

int AvlNULL(Avl* pTree){
    return pTree == NULL;
}
int AvlLeftExist(Avl * pTree){
    return !AvlNULL(pTree) && !AvlNULL(pTree->pL);
}
int AvlRightExist(Avl * pTree){
    return !AvlNULL(pTree) && !AvlNULL(pTree->pR);
}

#define MAX(a,b) (((a)>(b))?(a):(b)) //fct max

int high(Avl * pTree){ //hauteur
    int comptL=0,comptR=0;
    if(pTree==NULL){
        return 0;
    }
    if(!AvlLeftExist(pTree) && !AvlLeftExist(pTree)){
        return 1;
    }
    else{
        if(AvlLeftExist(pTree)){
            comptL = high(pTree->pL);
        }
        if(AvlRightExist(pTree)){
            comptR = high(pTree->pR); 
        }
    }
    return MAX(comptL,comptR)+1;
}

Avl * equilibrage(Avl * pTree);


#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

Avl * Rota_G(Avl * pTree){
    if(pTree==NULL||pTree->pR == NULL){
        return 0;
    }
    Avl * Pivot = pTree->pR;
    
    pTree->pR = Pivot->pL;
    Pivot->pL = pTree;
    
    //verif equilibrage
    int eq_Ptree = pTree->equilibre, eq_Pivot = Pivot->equilibre;
    pTree->equilibre = eq_Ptree - max(eq_Pivot,0) - 1; 
    Pivot->equilibre = min(eq_Ptree + eq_Pivot - 2,min(eq_Ptree - 2,eq_Pivot-1));
    
    pTree = Pivot;
    return pTree;
}

Avl * Rota_D(Avl * pTree){
    if(pTree==NULL||pTree->pL == NULL){
        return 0;
    }
    Avl * Pivot = pTree->pL;
    pTree ->pL = Pivot->pR;
    Pivot->pR = pTree;
    
    //verif equilibrage
    int eq_Ptree = pTree->equilibre, eq_Pivot = Pivot->equilibre;
    pTree->equilibre = eq_Ptree - min(eq_Pivot,0) + 1; 
    Pivot->equilibre = max(eq_Ptree + eq_Pivot + 2,max(eq_Ptree + 2,eq_Pivot+1));
    
    pTree = Pivot;
    return pTree;    
}

Avl * RotaDouble_G(Avl * pTree){
    if(pTree==NULL){
        return 0;
    }
    pTree->pR = Rota_D(pTree->pR);
    return Rota_G(pTree);
}

Avl * RotaDouble_D(Avl * pTree){
    if(pTree==NULL){
        return 0;
    }
    pTree->pL = Rota_G(pTree->pL);
    return Rota_D(pTree);
}

Avl * equilibrage(Avl * pTree){
    if(pTree==NULL){
        return pTree;
    }
    else if(pTree->equilibre >=2){
        if(pTree->pR==NULL){
            exit(1);
        }
        if(pTree->pR->equilibre >= 0){
            return Rota_G(pTree);
        }
        else{
            return RotaDouble_G(pTree);
        }
    }
    else if(pTree->equilibre <=-2){
        if(pTree->pL==NULL){
            exit(1);
        }
        if(pTree->pL->equilibre <= 0){
            return Rota_D(pTree);
        }
        else{
            return RotaDouble_D(pTree);
        }
    }
    return pTree;
}

Avl* addAvl(Avl* p, float v,int *h, int id){
    if(p == NULL){
        // found the place to create new node
        *h = 1;
        return createAvl(id, v);
    }
    else if(p->id > id){
        // look into the left subtree
        p->pL = addAvl(p->pL, v,h, id);
        *h = -*h;
    }
    else if(p->id < id){
        // look into the right subtree
        //h reste le mm
        p->pR = addAvl(p->pR, v,h, id);
    }
    else{
		//Route ID identique : ajout de la distance supplémentaire au trajet
        *h = 0;
		p->value = p->value + v;
        return p;
    }   
    if(*h != 0){
        p->equilibre = p->equilibre+*h;
        p = equilibrage(p);
        if(p->equilibre==0){
            *h = 0;
        }
        else{
            *h = 1;
        }
    }
    return p;
}

void displayInfixe(Avl* p){
    if(p != NULL){
        displayInfixe(p->pL);
        printf("%.3f;%d\n",p->value,p->id);
        displayInfixe(p->pR);
    }
}

void delAvl(Avl* p){
	if(p != NULL){
		delAvl(p->pL);
		delAvl(p->pR);
		free(p);
	}
}



int main(){

	Avl* trajetsTot = NULL;
	float distance;
	int route_id;
	int h=0;

	while( scanf("%d;%f\n", &route_id, &distance) == 2 ){
		
		trajetsTot = addAvl(trajetsTot, distance, &h, route_id);
		
	}
	
	displayInfixe(trajetsTot);
	delAvl(trajetsTot);
	
	return 0;
	
}
