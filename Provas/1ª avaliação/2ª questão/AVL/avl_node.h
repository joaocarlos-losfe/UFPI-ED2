#ifndef _AVLNODE_H_
#define _AVLNODE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AVLNode* AVLNode;

struct AVLNode
{
    int key;
    AVLNode left;
    AVLNode right;
    int height;
};

AVLNode avlNodeCreate(int key);
AVLNode avlNodeDestroy(AVLNode node);
void avlNodePrint(AVLNode node);
bool avlNodeIsLeaf(AVLNode node);

#endif