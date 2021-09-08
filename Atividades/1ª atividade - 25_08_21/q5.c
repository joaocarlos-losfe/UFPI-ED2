#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#include "simple_linked_list_library\questao_5\data.h"
#include "simple_linked_list_library\questao_5\simple_linked_list.h"

void a(Data person_header, Data eldest_person)
{
    if (person_header != NULL)
    {
        if(person_header->AnoNascimento < eldest_person->AnoNascimento)
        {
            eldest_person->Id = person_header->Id;
            strcpy(eldest_person->Nome, person_header->Nome);
            eldest_person->AnoNascimento = person_header->AnoNascimento;
            eldest_person->Altura = person_header->Altura;
        }

        person_header = person_header->next;
        a(person_header, eldest_person);
    }
    
}

void b(Data person_header, int *greater_height, int *shorter_height)
{
    if (person_header != NULL)
    {
        if(person_header->Altura > *greater_height)
            *greater_height = person_header->Altura;
        else if (person_header->Altura < *shorter_height)
            *shorter_height = person_header->Altura;

        person_header = person_header->next;
        b(person_header, greater_height, shorter_height);
    }
}

void c(Data person_header, int* count, int mediana)
{
    if (person_header != NULL)
    {
        if(person_header->Altura == mediana)
            *count = *count + 1;

        person_header = person_header->next;

        c(person_header, count, mediana);
    }
}



void d(Data person_header, int *count, int mediana)
{
    if(person_header!=NULL)
    {
        if((2021 - person_header->AnoNascimento) < 40 && person_header->Altura > mediana)
            *count = *count + 1;
        
        person_header = person_header->next;

        d(person_header, count, mediana);
    }
}

void menu()
{
    printf("\n 0 - sair");
    printf("\n 1 - inserir pessoas");
    printf("\n a - devolver o nome da pessoa mais velha da lista, caso exista mais de uma devolva um vetor com os nomes.");
    printf("\n b - devolver a menor e a maior altura.");
    printf("\n c - devolver o numero de pessoas com a altura mediana");
    printf("\n d - devolver o numero de pessoas abaixo de 40 anos com a altura maior do que a altura mediana");
}

int main()
{
    
    List persons; persons = listCreate();
    Data person; 

    person = dataCreate(1, "joao", 1970, 170);
    listInsertOrdered(persons, person);

    person = dataCreate(4, "jose", 1980, 160);
    listInsertOrdered(persons, person);

    person = dataCreate(2, "marcos", 1960, 172);
    listInsertOrdered(persons, person);

    person = dataCreate(3, "antonio", 1942, 154);
    listInsertOrdered(persons, person);

    char op;

    int id = 0; char nome[100]; int ano_nascimento = 0; int altura = 0;
    Data temp_person;
    Data new_person;

    int maior_altura = 0;
    int menor_altura = 0;

    int count = 0;

    do
    {
        menu();
        printf("\n>> ");
        scanf("%c", &op);

        switch (op)
        {
        
        case '1':

            printf("\nid: "); scanf("%d", &id);
            setbuf(stdin, NULL);
            printf("\nnome: "); scanf(" %s", nome);
            printf("\nano nascimento: ", ano_nascimento);
            printf("\naltura: ", altura);

            person = dataCreate(id, nome, ano_nascimento, altura);
            listInsertOrdered(persons, person);

            break;

        case 'a':
            temp_person = persons->head;
            new_person = persons->head;
            a(temp_person, new_person);
            printf("\n");
            dataPrint(new_person);
            
            break;
        
        case 'b':
            maior_altura = persons->head->AnoNascimento;
            menor_altura = persons->head->AnoNascimento;
            temp_person = persons->head;
            b(temp_person, &maior_altura, &menor_altura);
            
            printf("\n maior altura: %d  menor altura: %d", maior_altura, menor_altura);

            break;

        case 'c':
            temp_person = persons->head;
            c(temp_person, &count, (maior_altura + menor_altura)/2);

            printf("\ntotal: %d", count);

            break;
        
        case 'd':
            count = 0;
            temp_person = persons->head;
            d(temp_person, &count, (maior_altura + menor_altura)/2);

            printf("\ntotal: %d", count);
            break;
        
        default:
            break;
        }

    } while (op != '0');
    

    return 0;
}