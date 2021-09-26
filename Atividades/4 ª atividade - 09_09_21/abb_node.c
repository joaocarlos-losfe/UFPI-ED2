#include "abb_Node.h"
#include "string.h"


AbbNode AbbNodeCreate(int value) 
{
    AbbNode AbbNode = malloc(sizeof(struct AbbNode));

    AbbNode->value = value;

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
    printf("%d", node->value);
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