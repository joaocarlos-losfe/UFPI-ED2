#ifndef _ABB_H_
#define _ABB_H_

#include "abb_node.h"

typedef struct Abb* Abb;

struct Abb
{
	AbbNode root_node; //raiz da arvore ou primeiro elemento

	unsigned int number_of_nodes; // n�mero de dados (n�s) inseridos
	unsigned int number_of_leafs; // numero de folhas
	
};


Abb abbCreate();
AbbNode abbInsert(AbbNode root_node, AbbNode node);
AbbNode abbSeach(int value, AbbNode root_node);
void abbShow(AbbNode root_node);
int abbCountNodes(AbbNode root_node);
AbbNode abbSeachNode(AbbNode root_node, int value, AbbNode * dad);
AbbNode abbDelete(AbbNode root_node, int value);
int abbCountLeaf(AbbNode root_node);
int abbHeigt(AbbNode root_node);
int abbNodeDeph(AbbNode root_node, int elemeto);

#endif
