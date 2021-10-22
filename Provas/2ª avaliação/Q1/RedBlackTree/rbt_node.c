#include "rbt_node.h"

RBTNode rbtNodeCreate(char *palavra)
{
	RBTNode new_node = malloc(sizeof(struct RBTNode));
	strcpy(new_node->palavra, palavra);
	
	new_node->linhas = listCreate();

	new_node->color = RED;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->dad_node = NULL;
	
	return new_node;
}

bool rbtNodeIsLeaf(RBTNode node)
{
	if(node->left == NULL && node->right == NULL)
		return true;
	
	return false;
}

void rbtNodePrint(RBTNode node)
{
	printf("%s: ", node->palavra);
	listPrint(node->linhas);
}