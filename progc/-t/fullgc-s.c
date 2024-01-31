#include "headers.h"






Statc* initStatc(int id,float dist){
    Statc* pSta = NULL;

    pSta = malloc(sizeof(Statc));
    if(pSta == NULL){
        printf("error 12");
        exit(1);
    }
    pSta->id = id;
    pSta->max = dist;
    pSta->min = dist;
    pSta->all = dist;
    pSta->divi = 1;
    pSta->eq = 0;
    pSta->ng = NULL;
    pSta->nd = NULL;
return pSta;
}

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

Statc * Rotaid_G(Statc * pTree){
    if(pTree==NULL||pTree->nd == NULL){
        printf("reeor");
        return 0;
    }
    Statc * Pivot = pTree->nd;
    
    pTree->nd = Pivot->ng;
    Pivot->ng = pTree;
    
    //verif equilibrageid
    int eq_Ptree = pTree->eq, eq_Pivot = Pivot->eq;
    pTree->eq = eq_Ptree - max(eq_Pivot,0) - 1; 
    Pivot->eq = min(eq_Ptree -2 ,min(eq_Ptree +eq_Pivot -2,eq_Pivot-1));
    pTree = Pivot;
    return pTree;    
}

Statc * Rotaid_D(Statc * pTree){
    if(pTree==NULL||pTree->ng == NULL){
        printf("reeor");
        return 0;
    }
    Statc * Pivot = pTree->ng;
    pTree ->ng = Pivot->nd;
    Pivot->nd = pTree;
    
    //verif equilibrageid
    int eq_Ptree = pTree->eq, eq_Pivot = Pivot->eq;
    pTree->eq = eq_Ptree - min(eq_Pivot,0) + 1; 
    Pivot->eq = max(eq_Ptree + eq_Pivot + 2,max(eq_Ptree + 2,eq_Pivot+1));
    
    pTree = Pivot;
    return pTree;    
}

Statc * RotaDoubleid_G(Statc * pTree){
    if(pTree==NULL){
        return 0;
    }
    pTree->nd = Rotaid_D(pTree->nd);
    return Rotaid_G(pTree);
}

Statc * RotaDoubleid_D(Statc * pTree){
    if(pTree==NULL){
        return 0;
    }
    pTree->ng = Rotaid_G(pTree->ng);
    return Rotaid_D(pTree);
}

Statc * equilibrageid(Statc * pTree){
    if(pTree==NULL){
        return pTree;
    }
    else if(pTree->eq >=2){
        if(pTree->nd==NULL){
            printf("error 13");
            exit(1);
        }
        if(pTree->nd->eq >= 0){
            return Rotaid_G(pTree);
        }
        else{
            return RotaDoubleid_G(pTree);
        }
    }
    else if(pTree->eq <=-2){
        if(pTree->ng==NULL){
            printf("error 14");
            exit(1);
        }
        if(pTree->ng->eq <= 0){
            return Rotaid_D(pTree);
        }
        else{
            return RotaDoubleid_D(pTree);
        }
    }
    return pTree;
}



void delStatc(Statc* p){
	if(p != NULL){
        delStatc(p->ng);
		delStatc(p->nd);
		free(p);
	}
}

Statc* addStatc(Statc* p, int id,int *h,float dist){
    if(p == NULL){
        // found the place to create new node
        *h = 1;
        return initStatc(id,dist);
    }
    else if(id < p->id){ 
        // look into the left subtree
        p->ng = addStatc(p->ng, id,h, dist);
        *h = -*h;
    }
    else if(id > p->id){
        // look into the right subtree
        //h reste le mm
        p->nd = addStatc(p->nd, id,h, dist);
    }
    else{
		//Nom identique : ajout de la distance de trajet à la personne
        p->min = min(p->min,dist);
        p->max = max(p->max,dist);
        p->all = p->all + dist;
        p->divi = p->divi +1;
        *h = 0;
        return p;
    }   
    if(*h != 0){
        p->eq = p->eq+*h;
        p = equilibrageid(p);
        if(p->eq==0){
            *h = 0;
        }
        else{
            *h = 1;
        }
    }
    return p;
}

Statc * triStatc(Statc * p,int *h, Statc* trie){
    if(p == NULL){
        // found the place to create new node
        *h = 1;
        trie->ng = NULL;
        trie->nd = NULL;
        trie->eq = 0;
        return trie;
    }
    else if((trie->divi) < (p->max - p->min)){ 
        // look into the left subtree
        p->ng = triStatc(p->ng,h,trie );
        *h = -*h;
    }
    else if((trie->divi) > ( p->max - p->min)){
        // look into the right subtree
        //h reste le mm
        p->nd = triStatc(p->nd,h,trie);
    }
    else{
        p->ng = triStatc(p->ng,h,trie);
		//Nom identique : ajout de trajet a la Statce
        // pas possible en float
        return p;
    }   
    if(*h != 0){
        p->eq = p->eq+*h;
        p = equilibrageid(p);
        if(p->eq==0){
            *h = 0;
        }
        else{
            *h = 1;
        }
    }
    return p;

}
void displayInfixe(Statc* p){
    if(p != NULL){

        displayInfixe(p->nd);
        //printf("\n%d %d",p->id,p->eq);
        printf("%d;%f;%f;%f\n",p->id,p->max,p->all,p->min);
        displayInfixe(p->ng);
    }
}

Statc* triinfix(Statc* trie,Statc* rV,int*h){
    if(trie != NULL){
        Statc* Nd = trie->nd;
        rV =triinfix(trie->ng,rV,h);
        trie->all =  trie->all/trie->divi;
        trie->divi = trie->max - trie->min;
        rV = triStatc(rV,h,trie);
         //displayInfixe(rV);
        //printf("\ndfdfdf\n");
        *h = 0;      
        rV =triinfix(Nd,rV,h);
    
    }
return rV;
}

Statc* cutnext(Statc*p,Statc*rV,int*h){
    if(*h<50){
        if(rV == NULL){
            return p;
        }
        else if(p == NULL){
            p = rV;
            *h =*h+1;
            rV->nd = NULL;
            rV->ng = NULL;
        }
        else{
            *h=*h+1;
            rV->nd = NULL;
            rV->ng =NULL;
            rV->nd = p;
            return rV;
        }
        return p;}
    else{
        
        free(rV);
        rV = NULL;
    
    return p;
    }
}
Statc* cutvi(Statc* p,Statc* rV,int* h){
if(rV != NULL){
    p = cutvi(p,rV->nd,h);
        Statc* d = rV->ng;
        p = cutnext(p,rV,h);
    p = cutvi(p,d,h);
    }
return p;
}

void disend(Statc* end){
    if(end != NULL){
        disend(end->nd);
        printf("%d;%f;%f;%f\n",end->id,end->min,end->all,end->max);
        free(end);
    }
}



int main(){

int idtemp;
float distance;
int h = 0;
Statc* stat= NULL;
Statc* trista = NULL;
    while(scanf("%d;%f\n",&idtemp,&distance) == 2){; // boucle verif argument
        stat = addStatc(stat,idtemp,&h,distance);
        h =0;

    }
    //displayInfixe(stat);
//trista = triStatc(trista,&h,stat);
trista = triinfix(stat,trista,&h);
stat =NULL;
h = 0;
stat = cutvi(stat,trista,&h);
disend(stat);
return 0;}