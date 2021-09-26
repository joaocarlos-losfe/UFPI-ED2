#include "abb_main.h"

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
		if (node->value < root_node->value)
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

AbbNode abbSeach(int value, AbbNode root_node)
{
	if (root_node == NULL)
		return NULL;
	else if (root_node->value == value)
		return root_node;
	else if(root_node->value > value)
		return abbSeach(value, root_node->left); //esquerda
	else
		return abbSeach(value, root_node->right); // direita
}


//conta ate achar a raiz null e soma. tanto na esquerda quanto na direita
int abbCountNodes(AbbNode root_node)
{
	if (root_node == NULL)
		return 0;
	else
	{
		return abbCountNodes(root_node->left) + 1 + abbCountNodes(root_node->right);
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

AbbNode abbSeachNode(AbbNode root_node, int value, AbbNode * dad)
{
	AbbNode current = root_node;
	*dad = NULL;

	while (current)
	{
		if(current->value == value)
			return current;

		*dad = current;

		if(value < current->value)
			current = current->left;
		else
			current = current->right;
	}
	return NULL;
}

AbbNode abbDelete(AbbNode root_node, int value)
{
	AbbNode dad, node, p, q;
	node = abbSeachNode(root_node, value, &dad);

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

	if(value < dad->value)
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

int abbHeigt(AbbNode root_node)
{
	if (root_node == NULL && AbbNodeIsLeaf(root_node))
		return - 1;
	else
	{
		int HLeft = abbHeigt(root_node->left);
		int HRight = abbHeigt(root_node->right);

		if(HLeft < HRight)
			return HRight + 1;
		else
			return HLeft + 1;
	}
}

int abbNodeDeph(AbbNode root_node, int elemento)
{
	AbbNode current = root_node;

	bool achou = false;
	int count = 0;

	while (current && !achou )
	{
		if(current->value == elemento)
			achou = true;
			
		if(elemento < current->value)
		{
			count++;
			current = current->left;
		}
		else
		{
			count++;
			current = current->right;
		}
	}

	return count;
}