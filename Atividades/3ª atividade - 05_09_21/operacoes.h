#ifndef _CADASTRO_H_
#define _CADASTRO_H_

#include <stdio.h>
#include <stdlib.h>

#include "serie/series.h"
#include "serie/temporadas/simple_linked_list.h"

void menu()
{
    printf("\n 1 - cadastrar serie");
    printf("\n 2 - cadastrar temporada na lista de serie");
    printf("\n 3 - cadastrar participante na arvore de participante");
    
    printf("\n\n a - Imprimir em ordem pelo código da série: o título, o número de temporadas");
    printf("\n b - Imprimir os dados de todas as temporadas de uma série, cujo o usuário informe o código da série");
    printf("\n c - Imprimir todos os personagens de uma determinada temporada de uma dada série, cujo o usuário informe o código da série e o número da temporada");
    printf("\n d - Imprimir o nome de todos os artistas que interpretaram um determinado personagem em todas as temporadas de uma dada série, cujo o usuário informe o código da série");
}

void cadastrarSerie(int codigo, char titulo[100], int numero_temporadas, Series arvore_de_serie)
{
    SerieNode serie; 
    serie = SerieNodeCreate(codigo, titulo, numero_temporadas);
    serie->lista_temporadas = listCreate();

    arvore_de_serie->root_node = SeriesInsert(arvore_de_serie->root_node, serie);

    printf("\n serie cadastrada com sucesso...\n");
}

void cadastrarTemporada(int codigo_serie, Series arvore_de_series)
{
    SerieNode serie = SeriesSeach(codigo_serie, arvore_de_series->root_node);

    if (serie != NULL)
    {
        printf("\n serie encontrada\n");
        Data temporada = dataCreate();
        temporada->participantes = abbCreate();

        printf("\nNumero: "); scanf("%d", &temporada->numero);
        printf("\ntitulo: "); scanf(" %[^\n]s", temporada->titulo);
        printf("\nquantidade de episodios: "); scanf("%d", &temporada->quantidade_episodios);
        printf("\nAno: "); scanf("%d", &temporada->ano);

        listInsertOrdered(arvore_de_series->root_node->lista_temporadas, temporada);
        printf("\n inserido com sucesso...");
    }
    else
    {
        printf("\n serie nao encontrada...");
    }
}

void cadastrarParticipante(int codigo_serie, Series arvore_de_series)
{
    SerieNode serie = SeriesSeach(codigo_serie, arvore_de_series->root_node);

    int numero_temporada;
    
    if (serie != NULL)
    {
        List temporadas = serie->lista_temporadas;

        printf("\nnumero da temporada: "); scanf("%d", &numero_temporada);

        Data temporada = ListSeach(temporadas, numero_temporada);
        
        if (temporada != NULL)
        {
            Abb participantes = temporada->participantes;
            AbbNode participante = AbbNodeCreate();

            printf("\n nome personagem: "); scanf("%[^\n]s", participante->nome_personagem);
            printf("\n nome artista: "); scanf("%[^\n]s", participante->nome_artista);
            printf("\n descricao: "); scanf("%[^\n]s", participante->descricao);

            abbInsert(participantes->root_node, participante);
        
        }
        else
            printf("\n temporada não encontrada");
    }
    else
        printf("\n serie nao encontrada");

}

void a(int codigo,  Series arvore_de_series)
{
    SerieNode serie = SeriesSeach(codigo, arvore_de_series->root_node);

    if (serie != NULL)
    {
        SerieNodePrint(serie);
    }
}

void b(int codigo,  Series arvore_de_series)
{
    SerieNode serie = SeriesSeach(codigo, arvore_de_series->root_node);

    if (serie != NULL)
    {
        listPrint(serie->lista_temporadas);
    }
    else
        printf("lista vazia...");
}

void c(int codigo_serie, int numero_temporada, Series arvore_de_series)
{
    SerieNode serie = SeriesSeach(codigo_serie, arvore_de_series->root_node);
    
    if (serie != NULL)
    {
        List temporadas = serie->lista_temporadas;

        printf("\nnumero da temporada: "); scanf("%d", &numero_temporada);

        Data temporada = ListSeach(temporadas, numero_temporada);
        
        if (temporada != NULL)
        {
            Abb participantes = temporada->participantes;
            abbShow(participantes->root_node);
        }
        else
            printf("\n temporada não encontrada");
    }
    else
        printf("\n serie nao encontrada");
}

void printArtistas(AbbNode root_node, char artista[100])
{
	if (root_node != NULL)
	{
		if (strcmp(artista, root_node->nome_artista) == 0)
        {
            AbbNodePrint(root_node);
        }

		printArtistas(root_node->left, artista);
		printArtistas(root_node->right, artista);
	}
}

void d(int codigo_serie, int numero_temporada, char nome_persogem[100], Series arvore_de_series)
{
     SerieNode serie = SeriesSeach(codigo_serie, arvore_de_series->root_node);
    
    if (serie != NULL)
    {
        List temporadas = serie->lista_temporadas;


        Data temporada = ListSeach(temporadas, numero_temporada);
        
        if (temporada != NULL)
        {
            Abb participantes = temporada->participantes;
            
            printArtistas(participantes->root_node, nome_persogem);

        }
        else
            printf("\n temporada não encontrada");
    }
    else
        printf("\n serie nao encontrada");
}

#endif