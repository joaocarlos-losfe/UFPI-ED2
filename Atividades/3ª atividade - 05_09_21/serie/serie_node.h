#ifndef _SERIENODE_H_
#define _SERIENODE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SerieNode* SerieNode;

typedef char string[100];

#include "temporadas/simple_linked_list.h"

struct SerieNode
{
    int codigo;
    string titulo;
    int numero_temporadas;

    List lista_temporadas;
    
    SerieNode left;
    SerieNode right;
};

SerieNode SerieNodeCreate(int codigo, string titulo, int numero);
SerieNode SerieNodeDestroy(SerieNode serie_node);
void SerieNodePrint(SerieNode serie_node);
bool SerieNodeIsLeaf(SerieNode serie_node);

#endif