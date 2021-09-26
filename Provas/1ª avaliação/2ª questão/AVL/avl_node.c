#include "avl_node.h"
#include "string.h"


AVLNode avlNodeCreate(int key) 
{
    AVLNode node = malloc(sizeof(struct AVLNode));

    node->key = key;
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
    printf("%d", node->key);
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