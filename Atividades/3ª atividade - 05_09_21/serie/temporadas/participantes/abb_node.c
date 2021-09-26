#include "abb_Node.h"
#include "string.h"


AbbNode AbbNodeCreate() 
{
    AbbNode AbbNode = malloc(sizeof(struct AbbNode));

    AbbNode->left = NULL;
    AbbNode->right = NULL;

    return AbbNode;
}

AbbNode AbbNodeDestroy(AbbNode node) 
{
    free(node);
    node = NULL;
    return node;
}

void AbbNodePrint(AbbNode node) 
{
    printf("\n artistas participantes: ");
    printf("\n%s", node->nome_artista);
    printf("\n%s", node->nome_personagem);
    printf("\n%s", node->descricao);
}

bool AbbNodeIsLeaf(AbbNode node)
{   
    bool is_leaf = false;

    if (node->left == NULL && node->right == NULL)
    {
        is_leaf = true;
    }
    return is_leaf;
}