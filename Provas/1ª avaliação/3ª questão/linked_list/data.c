#include "data.h"
#include "string.h"

Data dataCreate(char *wold) 
{
    Data data = malloc(sizeof(struct Data));
    strcpy(data->str_value, wold);
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
    printf("%s ", data->str_value);
}

