#include "data.h"
#include "string.h"

Data dataCreate() 
{
    Data data = malloc(sizeof(struct Data));
    strcpy(data->str_value, "");
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
    printf("%s\n", data->str_value);
}

