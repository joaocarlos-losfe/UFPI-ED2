#include "avl_node.h"
#include "string.h"


AVLNode avlNodeCreate(char *key) 
{
    AVLNode node = malloc(sizeof(struct AVLNode));

    strcpy(node->key, key);
    node->list = listCreate();

    node->left = NULL;
    node->right = NULL;
    node->height = 0; //todo novo nó será uma folha

    return node;
}

AVLNode avlNodeDestroy(AVLNode node) 
{
    free(node);
    node = NULL;
    return node;
}

void avlNodePrint(AVLNode node) 
{
    printf("%s: ", node->key);
    listPrint(node->list);
    printf("\n");
}

bool avlNodeIsLeaf(AVLNode node)
{   
    bool is_leaf = false;

    if (node->left == NULL && node->right == NULL)
    {
        is_leaf = true;
    }
    return is_leaf;
}