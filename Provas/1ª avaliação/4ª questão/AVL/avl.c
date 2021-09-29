#include "avl.h"

AVL avlStart()
{
	AVL abb = malloc(sizeof(struct AVL));

	abb->root_node = NULL;
	abb->number_of_nodes = 0;
	abb->number_of_leafs = 0;

	return abb;
}


int avlNodeHeight(AVLNode node)
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

	node->height = max(avlNodeHeight(node->right), avlNodeHeight(node->left)) + 1;
	temp->height = max(avlNodeHeight(temp->left), node->height) + 1;

	return temp;
}

AVLNode avlRotateToLeft(AVLNode node)
{
	AVLNode temp;
	temp = node->right;
	node->right = temp->left;
	temp->left = node;

	node->height = max(avlNodeHeight(node->right), avlNodeHeight(node->left)) + 1; 
	temp->height = max(avlNodeHeight(temp->right), node->height) + 1;

	return temp;
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


AVLNode minValueNode(AVLNode node) // ultimo no da esquerda
{
	AVLNode current = node;

	while (current->left != NULL)
	{
		current = current->left;
	}

	return current;
	
}

int avlNodeBalance(AVLNode node)
{
	if (node == NULL )
		return 0;
	else
		return avlNodeHeight(node->left) - avlNodeHeight(node->right);
	
}


AVLNode avlInsert(AVLNode root_node, char *key)
{
	if (root_node == NULL)
	{
		AVLNode new_node;
		new_node = avlNodeCreate(key);
		return new_node;
	}

	if (strcmp(key, root_node->key) < 0)
		root_node->left = avlInsert(root_node->left, key);
	else if(strcmp(key, root_node->key) > 0)
		root_node->right = avlInsert(root_node->right, key);
	else
		return root_node;
	
	//atulizar a altura dos nós
	root_node->height = 1 + max(avlNodeHeight(root_node->left), avlNodeHeight(root_node->right));

	int node_balance = avlNodeBalance(root_node);

	// rotacao unica

	if (node_balance > 1 && strcmp(key, root_node->key) < 0)
		return avlRotateToRight(root_node);

	if(node_balance < -1 && strcmp(key, root_node->key) > 0)
		return avlRotateToLeft(root_node);

	// rotacao dupla
	if (node_balance > 1 && strcmp(key, root_node->key) > 0)
	{
		root_node->left = avlRotateToLeft(root_node->left);
		return avlRotateToRight(root_node);
	}

	if (node_balance < -1 && strcmp(key, root_node->key) < 0)
	{
		root_node->right = avlRotateToRight(root_node->right);
		return avlRotateToLeft(root_node);
	}

	return root_node;
	
}

AVLNode avlNodeDelete(AVLNode root_node, char *key)
{
	if (root_node == NULL)
		return root_node;
	
	if (strcmp(key, root_node->key) < 0)
	{
		root_node->left = avlNodeDelete(root_node->left, key);
	}
	else if(strcmp(key, root_node->key) > 0)
	{
		root_node->right = avlNodeDelete(root_node->right, key);
	}
	else
	{
		if ( (root_node->left) == NULL || (root_node->right) == NULL  )
		{
			AVLNode temp_node = root_node->left ? root_node->left : root_node->right;

			if (temp_node == NULL)
			{
				temp_node = root_node;
				root_node = NULL;
			}
			else
			{
				*root_node = *temp_node; 
			}

			free(temp_node);
		}
		else
		{
			AVLNode temp_node = minValueNode(root_node->right);

			strcpy(root_node->key, temp_node->key);	
		
			root_node->right = avlNodeDelete(root_node->right, temp_node->key);
		}
	}

	int node_balance = avlNodeBalance(root_node);

	if (node_balance > 1 && avlNodeBalance(root_node->left) >= 0)
		return avlRotateToRight(root_node);
	
	if (node_balance > 1 && avlNodeBalance(root_node->left) < 0)
	{
		root_node->left = avlRotateToLeft(root_node->left);
		return avlRotateToRight(root_node);
	}

	if (node_balance < -1 && avlNodeBalance(root_node->right) <= 0)
		return avlRotateToLeft(root_node);
	
	if (node_balance < -1 && avlNodeBalance(root_node->right) > 0)
	{
		root_node->right = avlRotateToRight(root_node->right);

		return avlRotateToLeft(root_node);
	}

	return root_node;
	
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
