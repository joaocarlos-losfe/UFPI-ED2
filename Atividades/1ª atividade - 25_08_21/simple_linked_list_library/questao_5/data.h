#ifndef _DATA_H_
#define _DATA_H_


#include <stdio.h>
#include <stdlib.h>

typedef struct Data* Data;

struct Data{
    int Id; 
    char Nome[100]; 
    int AnoNascimento;
    int Altura;

    Data next;
};

Data dataCreate(int Id, char Nome[100], int AnoNascimento, int Altura);
Data dataDelete(Data data);
void dataPrint(Data data);

#endif