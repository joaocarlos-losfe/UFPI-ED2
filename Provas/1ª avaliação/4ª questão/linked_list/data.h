#ifndef _DATA_H_
#define _DATA_H_


#include <stdio.h>
#include <stdlib.h>

typedef struct Data* Data;

struct Data{
    char str_value[100];
    Data next;
};

Data dataCreate(char *wold);
Data dataDelete(Data data);
void dataPrint(Data data);

#endif