#ifndef _RBTN_H_
#define _RBTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "LinkedList/simple_linked_list.h"

typedef struct RBTNode * RBTNode;

#define RED 1

#define BLACK 0

struct RBTNode
{
    char palavra[50];
	
	List linhas;
    int color;
   	RBTNode left;
   	RBTNode right;
   	RBTNode dad_node; 
};

RBTNode rbtNodeCreate(char *palavra);
bool rbtNodeIsLeaf(RBTNode node);
void rbtNodePrint(RBTNode node);


#endif