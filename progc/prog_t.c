#include "headers_t_s.h"

char* strincop(char* tempor){ //copy taille definie
int lenght;
char* tempod;
    tempod = malloc(strlen(tempor)+1); 
    if(tempod == NULL){
        printf("error 15");
        exit(1);
        }
    strcpy(tempod,tempor);
return tempod;
}

idc* initidc(int id,char* name){
    idc* pid = NULL;

    pid = malloc(sizeof(idc));
    if(pid == NULL){
        printf("error 12");
        exit(1);
    }
    pid->city =strincop(name);
    pid->id = id;
    pid->eq = 0;
    pid->ng = NULL;
    pid->nd = NULL;
return pid;
}

int idcNULL(idc* pTree){
    return pTree == NULL;
}
int idcLeftExist(idc * pTree){
    return !idcNULL(pTree) && !idcNULL(pTree->ng);
}
int idcRightExist(idc * pTree){
    return !idcNULL(pTree) && !idcNULL(pTree->nd);
}

#define MAX(a,b) (((a)>(b))?(a):(b)) //fct max

int high(idc * pTree){ //hauteur
    int comptL=0,comptR=0;
    if(pTree==NULL){
        return 0;
    }
    if(!idcLeftExist(pTree) && !idcLeftExist(pTree)){
        return 1;
    }
    else{
        if(idcLeftExist(pTree)){
            comptL = high(pTree->ng);
        }
        if(idcRightExist(pTree)){
            comptR = high(pTree->nd); 
        }
    }
    return MAX(comptL,comptR)+1;
}



#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

idc * Rotaid_G(idc * pTree){
    if(pTree==NULL||pTree->nd == NULL){
        printf("reeor");
        return 0;
    }
    idc * Pivot = pTree->nd;
    
    pTree->nd = Pivot->ng;
    Pivot->ng = pTree;
    
    //verif equilibrageid
    int eq_Ptree = pTree->eq, eq_Pivot = Pivot->eq;
    pTree->eq = eq_Ptree - max(eq_Pivot,0) - 1; 
    Pivot->eq = min(eq_Ptree -2 ,min(eq_Ptree +eq_Pivot -2,eq_Pivot-1));
    pTree = Pivot;
    return pTree;    
}

idc * Rotaid_D(idc * pTree){
    if(pTree==NULL||pTree->ng == NULL){
        printf("reeor");
        return 0;
    }
    idc * Pivot = pTree->ng;
    pTree ->ng = Pivot->nd;
    Pivot->nd = pTree;
    
    //verif equilibrageid
    int eq_Ptree = pTree->eq, eq_Pivot = Pivot->eq;
    pTree->eq = eq_Ptree - min(eq_Pivot,0) + 1; 
    Pivot->eq = max(eq_Ptree + eq_Pivot + 2,max(eq_Ptree + 2,eq_Pivot+1));
    
    pTree = Pivot;
    return pTree;    
}

idc * RotaDoubleid_G(idc * pTree){
    if(pTree==NULL){
        return 0;
    }
    pTree->nd = Rotaid_D(pTree->nd);
    return Rotaid_G(pTree);
}

idc * RotaDoubleid_D(idc * pTree){
    if(pTree==NULL){
        return 0;
    }
    pTree->ng = Rotaid_G(pTree->ng);
    return Rotaid_D(pTree);
}

idc * equilibrageid(idc * pTree){
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



void delidc(idc* p){
	if(p != NULL){
		free(p->city);
        delidc(p->ng);
		delidc(p->nd);
		free(p);
	}
}

idc* addidc(idc* p, int id,int *h,int *conf,char* name){
    if(p == NULL){
        // found the place to create new node
        *h = 1;
        *conf = 1;
        return initidc(id,name);
    }
    else if(id < p->id){ 
        // look into the left subtree
        p->ng = addidc(p->ng, id,h, conf,name);
        *h = -*h;
    }
    else if(id > p->id){
        // look into the right subtree
        //h reste le mm
        p->nd = addidc(p->nd, id,h, conf,name);
    }
    else{
		//Nom identique : ajout de la distance de trajet à la personne
        *h = 0;
        if(strcmp(name,p->city) == 0){
		*conf = 0;
        }
        else{
        *conf = 1;
        }
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

idc* iniaddidc(idc* p, int id,int* conf,char* name){
    idc* tempo = p;
    int a = 0;
    tempo = addidc(tempo,id,&a,conf,name);
return tempo;}



Ville* initVille(char* nom,int deb){
    Ville* tempo = NULL;
    tempo = malloc(sizeof(Ville));
    if (tempo == NULL){
        printf("error 17");
        exit(1);
    }
    int conf =0;
    tempo->countsta = deb;
    tempo->countid = 1;
    tempo->city = strincop(nom);
    tempo->equi = 0;
    tempo->vd = NULL;
    tempo->vg = NULL;
    tempo->equi = 0;
    tempo->next = NULL;
return tempo;
}
void freenext(Ville* frde){
    if(frde != NULL){
    free(frde->city);
    freenext(frde->next);
    free(frde);
    frde = NULL;
    }


}
void freer(Ville* frde){
    if(frde == NULL){
    
    }
    else{
    //freenext(frde->next);    
    free(frde->city);
    freer(frde->vd);
    freer(frde->vg);
    free(frde);
    frde = NULL;
}
}


int VilleNULL(Ville* pTree){
    return pTree == NULL;
}
int VilleLeftExist(Ville * pTree){
    return !VilleNULL(pTree) && !VilleNULL(pTree->vg);
}
int VilleRightExist(Ville * pTree){
    return !VilleNULL(pTree) && !VilleNULL(pTree->vd);
}
#define MAX(a,b) (((a)>(b))?(a):(b)) 


#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

Ville * Rota_G(Ville * pTree){
    if(pTree==NULL||pTree->vd == NULL){
        return 0;
    }
    Ville * Pivot = pTree->vd;
    
    pTree->vd = Pivot->vg;
    Pivot->vg = pTree;
    
    //verif equilibrage
    int eq_Ptree = pTree->equi, eq_Pivot = Pivot->equi;
    pTree->equi = eq_Ptree - max(eq_Pivot,0) - 1; 
    Pivot->equi = min(eq_Ptree -2 ,min(eq_Ptree +eq_Pivot -2,eq_Pivot-1));
    
    pTree = Pivot;
    return pTree;    
}

Ville * Rota_D(Ville * pTree){
    if(pTree==NULL||pTree->vg == NULL){
        return 0;
    }
    Ville * Pivot = pTree->vg;
    pTree ->vg = Pivot->vd;
    Pivot->vd = pTree;
    
    //verif equilibrage
    int eq_Ptree = pTree->equi, eq_Pivot = Pivot->equi;
    pTree->equi = eq_Ptree - min(eq_Pivot,0) + 1; 
    Pivot->equi = max(eq_Ptree + eq_Pivot + 2,max(eq_Ptree + 2,eq_Pivot+1));
    
    pTree = Pivot;
    return pTree;    
}

Ville * RotaDouble_G(Ville * pTree){
    if(pTree==NULL){
        return 0;
    }
    pTree->vd = Rota_D(pTree->vd);
    return Rota_G(pTree);
}

Ville * RotaDouble_D(Ville * pTree){
    if(pTree==NULL){
        return 0;
    }
    pTree->vg = Rota_G(pTree->vg);
    return Rota_D(pTree);
}

Ville * equilibrage(Ville * pTree){
    if(pTree==NULL){
        return pTree;
    }
    else if(pTree->equi >=2){
        if(pTree->vd==NULL){
            printf("error 18");
            exit(1);
        }
        if(pTree->vd->equi >= 0){
            return Rota_G(pTree);
        }
        else{
            return RotaDouble_G(pTree);
        }
    }
    else if(pTree->equi <=-2){
        if(pTree->vg==NULL){
            printf("error 19");
            exit(1);
        }
        if(pTree->vg->equi <= 0){
            return Rota_D(pTree);
        }
        else{
            return RotaDouble_D(pTree);
        }
    }
    return pTree;
}

void displayInfixe(Ville* p){
    if(p != NULL){
         printf("%s;%d;%d\n",p->city,p->countid,p->countsta);
        displayInfixe(p->vd);
        //printf("\n%s a été traverse par %d trajet et été départ %d fois",p->city,p->countid,p->countsta);
       
        displayInfixe(p->vg);
    }
}
void displayIdfixe(idc* p){
    if(p != NULL){
        printf("; %d equi %d ; ",p->id,p->eq);
        printf(" /ng ");
        displayIdfixe(p->ng);
        //printf("\n%s a été traverse par %d trajet et été départ %d fois",p->city,p->countid,p->countsta);
        printf(" /nd ");
        displayIdfixe(p->nd);
    }
}



Ville * addVil(Ville * p,int *h, char* nameville, int deb,int pres){
    if(p == NULL){
        // found the place to create new node
        *h = 1;
        return initVille(nameville,deb);
    }
    else if(strcmp(nameville,p->city) < 0){ //La 1e var de strcmp est l'ajout, la 2e celle du noeud
        // look into the left subtree
        p->vg = addVil(p->vg,h, nameville,deb,pres);
        *h = -*h;
    }
    else if(strcmp(nameville,p->city) > 0){
        // look into the right subtree
        //h reste le mm
        p->vd = addVil(p->vd,h, nameville,deb,pres);
    }
    else{
		//Nom identique : ajout de trajet a la ville
        *h = 0;
        int cont = 0;
        //p->arbc =iniaddidc(p->arbc,id,&cont);
        p->countid = p->countid + pres ;
        p->countsta = p->countsta + deb;
        return p;
    }   
    if(*h != 0){
        p->equi = p->equi+*h;
        p = equilibrage(p);
        if(p->equi==0){
            *h = 0;
        }
        else{
            *h = 1;
        }
    }
    return p;
}
Ville* addnext(Ville*p,Ville* trie){
    if(p == NULL){
        trie->vd = NULL;
        trie->vg = NULL;
        trie->equi = 0;
        return trie;
    }
    else{
        p->next = addnext(p->next,trie);
        return p;
    }

}
Ville * triVill(Ville * p,int *h, Ville* trie){
    if(p == NULL){
        // found the place to create new node
        *h = 1;
        return addnext(p,trie);
    }
    else if(trie->countid < p->countid){ //La 1e var de strcmp est l'ajout, la 2e celle du noeud
        // look into the left subtree
        p->vg = triVill(p->vg,h,trie );
        *h = -*h;
    }
    else if(trie->countid > p->countid){
        // look into the right subtree
        //h reste le mm
        p->vd = triVill(p->vd,h,trie);
    }
    else{
		//Nom identique : ajout de trajet a la ville
        *h = 0;
        p = addnext(p,trie);
        //displayIdfixe(p->arbc);
        return p;
    }   
    if(*h != 0){
        p->equi = p->equi+*h;
        p = equilibrage(p);
        if(p->equi==0){
            *h = 0;
        }
        else{
            *h = 1;
        }
    }
    return p;

}

Ville* triinfix(Ville* p,Ville* rV,int*h){
    if(p != NULL){
        Ville* vD = p->vd;
        rV =triinfix(p->vg,rV,h);
        rV = triVill(rV,h,p);
        *h = 0;      
        rV =triinfix(vD,rV,h);
    
    }
return rV;
}

void displaynext(Ville* p){
     if(p != NULL){
     printf("\n%s ; %d trajet; %d start 2",p->city,p->countid,p->countsta);
    displaynext(p->next);
     }

}
Ville* cutnext(Ville*p,Ville*rV,int*h){
    if(*h<10){
        if(rV == NULL){
            return p;
        }
        else if(p == NULL){
            p = rV;
            *h =*h+1;
            p->vd = rV->next;
            p->vg = NULL;
            p->next = NULL;
            p->next = cutnext(p->next,p->vd,h);
            p->vd = NULL;
        }
        else{
            p->next = cutnext(p->next,rV,h);
            return p;
        }
        return p;}
    else{
        freenext(rV);
        rV = NULL;
    
    return p;
    }
}
Ville* cutvi(Ville* p,Ville* rV,int* h){
if(rV != NULL){
    p = cutvi(p,rV->vd,h);
        Ville* d = rV->vg;
        p = cutnext(p,rV,h);
    p = cutvi(p,d,h);
    }
return p;
}


Ville * abcVille(Ville * p,Ville*rV){
    if(p == NULL){
        return rV;
    }
    else if(strcmp(rV->city,p->city) < 0 ){ //La 1e var de strcmp est l'ajout, la 2e celle du noeud rV < p
        rV->vd = p;
        return rV;
    }
    else if(strcmp(rV->city,p->city) > 0){ //rv>p
        // look into the right subtree
        //h reste le mm
        p->vd = abcVille(p->vd,rV);
        return p;
    }
}
Ville * abcV(Ville*p,Ville* rV){
    if(rV != NULL){
        p = abcVille(p,rV);
        //printf("\n %s ; %s",p->city,rV->city);
        p = abcV(p,rV->next);
    }
    return p;
}
Ville * main(){ //generation arbre
    Ville * rV = NULL;
    Ville * tris = NULL;
    Ville* cut = NULL;
    idc* presence = NULL;
    char villtemp1[100]; //recuperation en tempo
    char villetemp2[100];
    int idtemp;
    int numtemp;
    int h = 0;
    int pres =0;
    while(scanf("%d;%d;%[^\n^;];%[^\n^;]\n",&idtemp,&numtemp,villtemp1,villetemp2) == 4){; // boucle verif argument
    presence = iniaddidc(presence,idtemp,&pres,villetemp2);
    rV = addVil(rV,&h,villetemp2,0,pres);
    h = 0;
    if(numtemp == 1){
        presence = iniaddidc(presence,idtemp,&pres,villtemp1);
        rV = addVil(rV,&h,villtemp1,1,pres);
        h =0;

    }
    }

    tris = triinfix(rV,tris,&h);
    cut = cutvi(cut,tris,&h);
    tris = NULL;
    //printf("fdfdf");
    //displaynext(cut);
    tris = abcV(tris,cut);
    displayInfixe(tris);
    freer(tris);
    
 



return rV;}






