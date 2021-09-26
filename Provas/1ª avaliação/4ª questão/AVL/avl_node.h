#ifndef _AVLNODE_H_
#define _AVLNODE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AVLNode* AVLNode;

#include "../linked_list/simple_linked_list.h"

struct AVLNode
{
    char key[100];
    List list;

    AVLNode left;
    AVLNode right;
    int height;
};

AVLNode avlNodeCreate(char *key);
AVLNode avlNodeDestroy(AVLNode node);
void avlNodePrint(AVLNode node);
bool avlNodeIsLeaf(AVLNode node);

#endif