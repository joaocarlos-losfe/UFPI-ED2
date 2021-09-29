#ifndef _AVL_H_
#define _AVL_H_

#include "avl_node.h"

typedef struct AVL* AVL;

struct AVL
{
	AVLNode root_node; //raiz da arvore ou primeiro elemento

	unsigned int number_of_nodes; // n�mero de dados (n�s) inseridos
	unsigned int number_of_leafs; // numero de folhas
	
};


AVL avlStart();
int avlNodeHeight(AVLNode node);
int avlBalancingFactor(AVLNode node);
int max(int x, int y);
AVLNode avlRotateToRight(AVLNode node);
AVLNode avlRotateToLeft(AVLNode node);

AVLNode avlRotateLeftToRight(AVLNode node); // rotacao (dupla) da esquerda para a direita
AVLNode avlRotateRightToLeft(AVLNode node); // rotacao (dupla) da direita para a esquerda

AVLNode avlInsert(AVLNode root_node, int key); //insere um nó a arvore
AVLNode avlSeach(AVLNode root_node, int key); // procura um elemento da arvore e retorna o seu nó
void avlPrint(AVLNode root_node); // exibe a arvore inteira
int avlCountNodes(AVLNode root_node); // conta o numero de nos da arvore
AVLNode avlSeachDad(AVLNode node, int key, AVLNode * dad); // procura um elemento da arvore para delecao
AVLNode avlDelete(AVLNode root_node, int key); // deleta um elemento da arvore
int avlCountSheets(AVLNode node); //conta o numero de folhas da aarvore
int avlDephNode(AVLNode node, int key); //busca a profudidadade dado um elemento
AVLNode avlDestroy(AVLNode root_node); // destruir a arvore inteira
void avlShallower(AVLNode root_node, int count, int *less_depth_result); // menor profundidade das folhas
void avlMinDepth(AVLNode root_node, int count, int *less_depth_result);

#endif
