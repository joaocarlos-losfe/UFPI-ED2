#include "series.h"

Series SeriesCreate()
{
	Series serie = malloc(sizeof(struct Series));

	serie->root_node = NULL;
	serie->number_of_nodes = 0;
	serie->number_of_leafs = 0;

	return serie;
}

SerieNode SeriesInsert(SerieNode root_node, SerieNode node)
{
	if (root_node == NULL)
	{
		return node;
	}
	else
	{
		if (node->codigo < root_node->codigo)
		{
			root_node->left = SeriesInsert(root_node->left, node);
		}
		else if(node->codigo > root_node->codigo)
		{
			root_node->right = SeriesInsert(root_node->right, node);
		}
	}

	return root_node;
}

SerieNode SeriesSeach(int codigo, SerieNode root_node)
{
	if (root_node == NULL)
		return NULL;
	else if (root_node->codigo == codigo)
		return root_node;
	else if(root_node->codigo > codigo)
		return SeriesSeach(codigo, root_node->left); //esquerda
	else
		return SeriesSeach(codigo, root_node->right); // direita
}


//conta ate achar a raiz null e soma. tanto na esquerda quanto na direita
int SeriesCountNode(SerieNode root_node)
{
	if (root_node == NULL)
		return 0;
	else
	{
		return SeriesCountNode(root_node->left) + 1 + SeriesCountNode(root_node->right);
	}
}

void SeriesShow(SerieNode root_node)
{
	if (root_node != NULL)
	{
		SerieNodePrint(root_node);
		SeriesShow(root_node->left);
		SeriesShow(root_node->right);
	}
}

SerieNode SeriesSeachNode(SerieNode root_node, int codigo, SerieNode * dad)
{
	SerieNode current = root_node;
	*dad = NULL;

	while (current)
	{
		if(current->codigo == codigo)
			return current;

		*dad = current;

		if(codigo < current->codigo)
			current = current->left;
		else
			current = current->right;
	}
	return NULL;
}

SerieNode SeriesDelete(SerieNode root_node, int codigo)
{
	SerieNode dad, node, p, q;
	node = SeriesSeachNode(root_node, codigo, &dad);

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

	if(codigo < dad->codigo)
		dad->left = q;
	else
		dad->right = q;

	free(node);
	return (root_node);
}

int SeriesCountLeaf(SerieNode root_node)
{
	if(root_node != NULL)
	{
		if(SerieNodeIsLeaf(root_node))
			return 1 + SeriesCountLeaf(root_node->left) + SeriesCountLeaf(root_node->right);
		else
		{
			return SeriesCountLeaf(root_node->left) + SeriesCountLeaf(root_node->right);
		}
	}
	else
	{
		return 0;
	}
}


