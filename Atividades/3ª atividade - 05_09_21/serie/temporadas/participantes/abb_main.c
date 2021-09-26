#include "abb_main.h"
#include <string.h>

Abb abbCreate()
{
	Abb abb = malloc(sizeof(struct Abb));

	abb->root_node = NULL;
	abb->number_of_nodes = 0;
	abb->number_of_leafs = 0;

	return abb;
}


AbbNode abbInsert(AbbNode root_node, AbbNode node)
{
	if (root_node == NULL)
	{
		return node;
	}
	else
	{
		if (strcmp(node->nome_personagem, root_node->nome_personagem) < 0)
		{
			root_node->left = abbInsert(root_node->left, node);
		}
		else
		{
			root_node->right = abbInsert(root_node->right, node);
		}
	}

	return root_node;
}

AbbNode abbSeach(char nome_personagem[100], AbbNode root_node)
{
	if (root_node == NULL)
		return NULL;
	else if (strcmp(root_node->nome_personagem, nome_personagem) == 0)
		return root_node;
	else if(strcmp(root_node->nome_personagem, nome_personagem) < 0)
		return abbSeach(nome_personagem, root_node->left); //esquerda
	else
		return abbSeach(nome_personagem, root_node->right); // direita
}


//conta ate achar a raiz null e soma. tanto na esquerda quanto na direita
int abbCountNode(AbbNode root_node)
{
	if (root_node == NULL)
		return 0;
	else
	{
		return abbCountNode(root_node->left) + 1 + abbCountNode(root_node->right);
	}
}

void abbShow(AbbNode root_node)
{
	if (root_node != NULL)
	{
		printf("(");
		AbbNodePrint(root_node);
		abbShow(root_node->left);
		abbShow(root_node->right);
		printf(")");
	}
}

AbbNode abbSeachNode(AbbNode root_node, char nome_personagem[100], AbbNode * dad)
{
	AbbNode current = root_node;
	*dad = NULL;

	while (current)
	{
		if( strcpy(current->nome_personagem, nome_personagem) == 0)
			return current;

		*dad = current;

		if(strcmp(nome_personagem, current->nome_personagem) < 0)
			current = current->left;
		else
			current = current->right;
	}
	return NULL;
}

AbbNode abbDelete(AbbNode root_node, char nome_personagem[100])
{
	AbbNode dad, node, p, q;
	node = abbSeachNode(root_node, nome_personagem, &dad);

	if (node == NULL)
		return (root_node);

	if(!node->left || !node->right)
	{
		if(!node->left)
			q = node->right; //direita
		else
			q = node->left;  // esquerda
	}
	else
	{
		p = node;
		q = node->left;

		while (q->right)
		{
			p = q;
			q = q->right;
		}

		if (p != node)
		{
			p->right = q->left;
			q->left = node->left;
		}

		q->right = node->right;
	}

	if(!dad)
	{
		free(node);
		return (q);
	}

	if(strcmp(nome_personagem, dad->nome_personagem) < 0)
		dad->left = q;
	else
		dad->right = q;

	free(node);
	return (root_node);
}

int abbCountLeaf(AbbNode root_node)
{
	if(root_node != NULL)
	{
		if(AbbNodeIsLeaf(root_node))
			return 1 + abbCountLeaf(root_node->left) + abbCountLeaf(root_node->right);
		else
		{
			return abbCountLeaf(root_node->left) + abbCountLeaf(root_node->right);
		}
	}
	else
	{
		return 0;
	}
}


