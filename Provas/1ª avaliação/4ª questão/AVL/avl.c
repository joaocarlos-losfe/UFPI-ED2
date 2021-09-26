#include "avl.h"

AVL avlStart()
{
	AVL abb = malloc(sizeof(struct AVL));

	abb->root_node = NULL;
	abb->number_of_nodes = 0;
	abb->number_of_leafs = 0;

	return abb;
}


int avlHeight(AVLNode node)
{
	if(node == NULL) 
		return -1;
	return node->height;
}


int max(int x, int y)
{
	if(x > y)
		return x;
	else
		return y;
}

AVLNode avlRotateToRight(AVLNode node)
{

	AVLNode temp; 
	temp = node->left;
	node->left = temp->right;
	temp->right = node;

	node->height = max(avlHeight(node->right), avlHeight(node->left)) + 1;
	temp->height = max(avlHeight(temp->left), node->height) + 1;

	return temp;
}

AVLNode avlRotateToLeft(AVLNode node)
{
	AVLNode temp;
	temp = node->right;
	node->right = temp->left;
	temp->left = node;

	node->height = max(avlHeight(node->right), avlHeight(node->left)) + 1; 
	temp->height = max(avlHeight(temp->right), node->height) + 1;

	return temp;
}

AVLNode avlRotateLeftToRight(AVLNode node)
{
	node->left = avlRotateToLeft(node->left);
	return avlRotateToRight(node);
}

AVLNode avlRotateRightToLeft(AVLNode node)
{
	node->right = avlRotateToRight(node->right);
	return avlRotateToLeft(node);
}

AVLNode avlInsert(AVLNode root_node, char *key)
{
	if (root_node == NULL)
	{
		AVLNode new_node;
		new_node = avlNodeCreate(key);
		return new_node;
	}

	if( strcmp(key, root_node->key) < 0)
	{
		root_node->left = avlInsert(root_node->left, key);

		if ((avlHeight(root_node->left)) - (avlHeight(root_node->right)) == 2)
		{
			if (strcmp(key, root_node->left->key) < 0)
				root_node = avlRotateToRight(root_node);
			else
				root_node = avlRotateLeftToRight(root_node);
		}
	}
	else if(strcmp(key, root_node->key) > 0)
	{
		root_node->right = avlInsert(root_node->right, key);

		if ((avlHeight(root_node->right)) - (avlHeight(root_node->left)) == 2)
		{
			if (strcmp(key, root_node->right->key) > 0)
				root_node = avlRotateToLeft(root_node);
			else
				root_node = avlRotateRightToLeft(root_node);
		}
	}

	root_node->height = max(avlHeight(root_node->left), avlHeight(root_node->right)) + 1;
	
	return root_node;
}

AVLNode avlSeach(AVLNode root_node, char *key)
{
	if (root_node == NULL)
		return NULL;
	else if (strcmp(root_node->key, key) == 0)
		return root_node;
	else if(strcmp(root_node->key, key) > 0)
		return avlSeach(root_node->left, key); //esquerda
	else
		return avlSeach(root_node->right, key); // direita
}


//conta ate achar a raiz null e soma. tanto na esquerda quanto na direita
int avlCountNodes(AVLNode root_node)
{
	if (root_node == NULL)
		return 0;
	else
	{
		return avlCountNodes(root_node->left) + 1 + avlCountNodes(root_node->right);
	}
}

void avlPrint(AVLNode root_node)
{
	if (root_node != NULL)
	{
		avlNodePrint(root_node);
		avlPrint(root_node->left);
		avlPrint(root_node->right);
	}
}

AVLNode avlSeachDad(AVLNode node, char *key, AVLNode * dad)
{
	AVLNode current = node;
	*dad = NULL;

	while (current)
	{
		if(strcmp(current->key, key) == 0)
			return current;

		*dad = current;

		if(strcmp(key, current->key) < 0)
			current = current->left;
		else
			current = current->right;
	}
	return NULL;
}

AVLNode avlDelete(AVLNode root_node, char *key)
{
	AVLNode dad, node, p, q;
	node = avlSeachDad(root_node, key, &dad);

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

	if(strcmp(key, dad->key) < 0)
		dad->left = q;
	else
		dad->right = q;

	free(node);
	return (root_node);
}

int avlCountSheets(AVLNode node)
{
	if(node != NULL)
	{
		if(avlNodeIsLeaf(node))
			return 1 + avlCountSheets(node->left) + avlCountSheets(node->right);
		else
		{
			return avlCountSheets(node->left) + avlCountSheets(node->right);
		}
	}
	else
	{
		return 0;
	}
}


int avlDephNode(AVLNode root_node, char *key)
{
	AVLNode current = root_node;

	bool achou = false;
	int count = 0;

	while (current && !achou )
	{
		if(strcmp(current->key, key) == 0)
			achou = true;
			
		if(strcmp(key, current->key) < 0)
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

AVLNode avlDestroy(AVLNode root_node)
{
	if (root_node != NULL)
	{
		root_node->left = avlDestroy(root_node->left);
		root_node->right = avlDestroy(root_node->right);
		free(root_node);
		root_node = NULL;
	}

	return root_node;	
}


void bstMinDepth(AVLNode root_node, int count, int *less_depth_result)
{
	if (root_node != NULL)
	{
		if(avlNodeIsLeaf(root_node))
		{
			if (count < *less_depth_result)
				*less_depth_result = count;	
		}
		else
			count++;
		
		bstMinDepth(root_node->left, count,  less_depth_result);
		bstMinDepth(root_node->right, count, less_depth_result);
	}	
}
