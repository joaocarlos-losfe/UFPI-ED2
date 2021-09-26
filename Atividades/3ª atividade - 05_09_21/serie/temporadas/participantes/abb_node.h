#ifndef _ABBAbbNode_H_
#define _ABBAbbNode_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AbbNode* AbbNode;

struct AbbNode
{
    char nome_artista[100];
    char nome_personagem[100];
    char descricao[100];

    AbbNode left;
    AbbNode right;
};

AbbNode AbbNodeCreate();
AbbNode AbbNodeDestroy(AbbNode node);
void AbbNodePrint(AbbNode node);
bool AbbNodeIsLeaf(AbbNode node);

#endif