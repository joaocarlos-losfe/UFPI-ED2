#ifndef _DATA_H_
#define _DATA_H_


#include <stdio.h>
#include <stdlib.h>

typedef struct Data* Data;

#include "participantes/abb_main.h"

struct Data{
    int numero;
    char titulo[100];
    int quantidade_episodios;
    int ano;
    Abb participantes;
    
    Data next;
};

Data dataCreate();
Data dataDelete(Data data);
void dataPrint(Data data);

#endif