#include <stdio.h>
#include <stdlib.h>

#include "serie/series.h"
#include <string.h>

#include "serie/temporadas/participantes/abb_main.h"

#include "operacoes.h"
#include <locale.h>

int main()
{
    Series arvore_de_serie = SeriesCreate();

    setlocale(LC_ALL,"");

    /*
    SerieNode serie; 
    Data temporada;
    AbbNode participante;

    // criacao da arvore de serie
    serie = SerieNodeCreate(333, "serie 1", 7);
    serie->lista_temporadas = listCreate();
    temporada = dataCreate();
    temporada->participantes = abbCreate();

    temporada->numero = 1;
    strcpy(temporada->titulo, "helboi");
    listInsertOrdered(serie->lista_temporadas, temporada);
    temporada->participantes = abbCreate();
    participante = AbbNodeCreate();
    strcpy(participante->nome_personagem, "helio");

    arvore_de_serie->root_node = SeriesInsert(arvore_de_serie->root_node, serie);

    temporada = dataCreate();
    temporada->numero = 2;
    strcpy(temporada->titulo, "helboi 2");
    listInsertOrdered(serie->lista_temporadas, temporada);

    //_______________________________________________________________
    
    */

    char op = 'a';

    int codigo; 
    char titulo[100];
    int numero_temporada;
    char nome_personagem[100];
    do
    {   
        menu();
        printf("\n>> ");
        scanf("%c", &op);
        switch (op)
        {
        case '1':
            printf("\ncodigo da serie: "); scanf("%d", &codigo);
            setbuf(stdin, NULL);
            printf("\ntitulo: "); scanf(" %[^\n]s", titulo);
            printf("\nnumero de temporadas: "); scanf("%d", &numero_temporada);
            cadastrarSerie(codigo, titulo, numero_temporada, arvore_de_serie);
            //SeriesShow(arvore_de_serie->root_node);

            break;
        
        case '2':
            printf("\ncodigo da serie: "); scanf("%d", &codigo);
            cadastrarTemporada(codigo, arvore_de_serie);
        
        case '3':
            break;
        
        case 'a':
            printf("\ncodigo da serie: "); scanf("%d", &codigo); 
            a(codigo, arvore_de_serie);
        
        case 'b':
            printf("\ncodigo da serie: "); scanf("%d", &codigo); 
            b(codigo, arvore_de_serie);

        case 'c':
            printf("\ncodigo da serie: "); scanf("%d", &codigo); 
            printf("\nnumero da temporada: "); scanf("%d", &numero_temporada); 
            c(codigo, numero_temporada, arvore_de_serie);
            
        
        case 'd':
            printf("\ncodigo da serie: "); scanf("%d", &codigo); 
            printf("\nnumero da temporada: "); scanf("%d", &numero_temporada); 
            printf("\nnome do persogem: "); scanf("%[^\n]s", nome_personagem);
            d(codigo, numero_temporada, nome_personagem, arvore_de_serie);
            
        default:
            printf("\nopcao invalida");

            break;
        }

    } while (op != '0');
    
    return 0;
}