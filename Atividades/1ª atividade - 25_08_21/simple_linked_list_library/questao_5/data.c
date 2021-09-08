#include "data.h"
#include "string.h"

Data dataCreate(int Id, char Nome[100], int AnoNascimento, int Altura) 
{
    Data data = malloc(sizeof(struct Data));

    data->Id = Id;
    strcpy(data->Nome, Nome);
    data->AnoNascimento = AnoNascimento;
    data->Altura = Altura;

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
    printf("%d %s %d %d\n", data->Id, data->Nome, data->AnoNascimento, data->Altura);
}

