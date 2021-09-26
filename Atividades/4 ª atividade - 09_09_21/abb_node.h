#ifndef _ABBAbbNode_H_
#define _ABBAbbNode_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AbbNode* AbbNode;

struct AbbNode
{
    int value;
    AbbNode left;
    AbbNode right;
};

AbbNode AbbNodeCreate(int value);
AbbNode AbbNodeDestroy(AbbNode node);
void AbbNodePrint(AbbNode node);
bool AbbNodeIsLeaf(AbbNode node);

#endif