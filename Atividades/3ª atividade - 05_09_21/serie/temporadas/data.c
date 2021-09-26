#include "data.h"
#include "string.h"

Data dataCreate() 
{
    Data data = malloc(sizeof(struct Data));
    data->next = NULL;
    return data;
}

Data dataDelete(Data data) 
{
    free(data);
    data = NULL;
    return data;
}

void dataPrint(Data data) 
{
    if(data != NULL)
    {
        printf("\n%s", data->titulo);
    }
}

