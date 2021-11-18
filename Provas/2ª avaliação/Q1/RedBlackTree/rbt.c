#include "rbt.h"

RBT rbtStart()
{
	RBT new_tree = malloc(sizeof(struct RBT));

	new_tree->root_node = NULL;
	new_tree->count_leaf = 0;
	new_tree->height = 0;

	return new_tree;
}

RBTNode rotateToLeft(RBTNode node)
{
	RBTNode temp = node->right; // direita
	node->right = temp->left; // esquerda
	temp->left = node;
	temp->color = node->color;
	node->color = RED;

	return temp;
}

RBTNode rotateToRight(RBTNode node)
{
	RBTNode temp = node->left; // esquerda
	node->left = temp->right; // direita
	temp->right = node;
	temp->color = node->color;
	node->color = RED;

	return temp;
}

void changeColor(RBTNode node)
{
	node->color = !node->color; // inverte a cor. red � 1 e !color fica 0
	if(node->left)
		node->left->color = !node->right->color;
	if(node->right)
		node->right->color = !node->right->color;
}

int getColor(RBTNode node)
{
	if(node)
		return node->color;

	return BLACK;
}

RBTNode move2LeftRED(RBTNode node)
{
	changeColor(node);

	if(getColor(node->right->left) == RED)
	{
		node->right = rotateToRight(node->right);
		node = rotateToLeft(node);
		changeColor(node);
	}

	return node;
}

RBTNode move2RightRED(RBTNode node)
{
	changeColor(node);

	if(getColor(node->left->left) == RED)
	{
		node = rotateToRight(node);
		changeColor(node);
	}

	return node;
}

RBTNode searchMin(RBTNode node)
{
	RBTNode min = node;
	RBTNode temp = node->right;

	while(temp)
	{
		min = temp;
		temp = temp->right;
	}

	return min;
}



RBTNode balanceNode(RBTNode node)
{
	if(getColor(node->right) == RED)
		node = rotateToLeft(node);

	if( (node->left && getColor(node->right) == RED) && (getColor(node->right->right) == RED))
		node = rotateToRight(node);

	if((getColor(node->left) == RED) && (getColor(node->right) == RED))
		changeColor(node);

	return node;
}

RBTNode removeMin(RBTNode node)
{
	if(!node->left)
	{
		free(node);
		return NULL;
	}

	if((getColor(node->left) == BLACK) && (getColor(node->left->left) == BLACK))
		node = move2LeftRED(node);

	node->left = removeMin(node->left);

	return balanceNode(node);
}

RBTNode fixInsertion(RBTNode node)
{
	if((getColor(node->right) == RED) && (getColor(node->left) == BLACK))
		node = rotateToLeft(node);

	if((getColor(node->left) == RED) && (getColor(node->left->left) == RED))
		node = rotateToRight(node);

	if((getColor(node->left) == RED) && (getColor(node->right) == RED))
		changeColor(node);

	return node;
}

RBTNode rbtInsert(RBTNode node, char *palavra)
{
	if(node == NULL)
	{
		RBTNode new_node = rbtNodeCreate(palavra);

		return new_node;
	}

	if(strcmp(palavra, node->palavra)  < 0)
		node->left = rbtInsert(node->left, palavra);
	else if (strcmp(palavra, node->palavra)  > 0)
		node->right = rbtInsert(node->right, palavra);

	node = fixInsertion(node);

	return node;
}

RBTNode rbtNodeSearch(RBTNode root, char *palavra)
{
	if(root == NULL)
		return NULL;
	else if(strcmp(palavra, root->palavra) == 0)
		return root;

	else if(strcmp(palavra, root->palavra) < 0)
		return rbtNodeSearch(root->left, palavra);
	else if (strcmp(palavra, root->palavra) > 0)
		return rbtNodeSearch(root->right, palavra);
}

RBTNode rbtNodeRemove(RBTNode node, char *palavra)
{
	if(strcmp(palavra, node->palavra) < 0)
	{
		if((getColor(node->left) == BLACK) && (getColor(node->left->left) == BLACK))
			node = move2LeftRED(node);

		node->left = rbtNodeRemove(node->left, palavra);
	}
	else
	{
		if(getColor(node->left) == RED)
			node = rotateToRight(node);

		if((strcmp(palavra, node->palavra) == 0) && (!node->right))
		{
			free(node);
			return NULL;
		}

		if((getColor(node->right) == BLACK) && (getColor(node->right->left) == BLACK))
			node = move2RightRED(node);

		if(strcmp(palavra, node->palavra) == 0)
		{
			RBTNode aux = searchMin(node->right);
			node->linhas = aux->linhas;
			node->right = removeMin(node->right);
		}
		else
			node->right = rbtNodeRemove(node->right, palavra);
		
	}
	
	return balanceNode(node);
}

bool rbtRemove(RBTNode *node, char *palavra)
{
	if(rbtNodeSearch(*node, palavra))
	{
		RBTNode temp = *node;
		*node = rbtNodeRemove(temp, palavra);
		
		if(*node)
			(*node)->color = BLACK;
		return true;
	}
	else
		return false;
}

void rbtPrint(RBTNode root)
{
	if(root != NULL)
	{
		rbtNodePrint(root);
		printf("\n");
		rbtPrint(root->left);
		rbtPrint(root->right);
	}
}