#ifndef headers
	#define headers
	
	#include <stdio.h>
	#include<stdlib.h>
    #include<string.h>
typedef struct _recup{ // struct donnée récuperer
    int id;
    char* villed;
    char* villef;
    int eta;
}Recup;

typedef struct _idc{ // arbre id
    int id;
    struct _idc* ng; 
    struct _idc* nd;
    int eq;
}idc;

typedef struct _Ville{ // arbre ville
    char* city;
    int countsta;
    int countid;
    struct _idc* arbc;
    struct _Ville* vd;
    struct _Ville* vg;
    struct _Ville* next;
    int equi;

}Ville;
#endif