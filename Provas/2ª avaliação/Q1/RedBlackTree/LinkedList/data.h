#ifndef _DATA_H_
#define _DATA_H_


#include <stdio.h>
#include <stdlib.h>

typedef struct Data* Data;


struct Data
{
    int linha;
    Data next;
};

Data dataCreate();
Data dataDelete(Data data);
void dataPrint(Data data);

#endif