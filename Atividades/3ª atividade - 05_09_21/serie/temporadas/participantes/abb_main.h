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
AbbNode abbSeach(char nome_personagem[100], AbbNode root_node);
void abbShow(AbbNode root_node);
int abbCountNode(AbbNode root_node);
AbbNode abbSeachNode(AbbNode root_node, char nome_personagem[100], AbbNode * dad);
AbbNode abbDelete(AbbNode root_node, char nome_personagem[100]);
int abbCountLeaf(AbbNode root_node);

#endif
