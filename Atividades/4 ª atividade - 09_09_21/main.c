#include <stdio.h>
#include <stdlib.h>

#include "abb_main.h"

void menu()
{
	printf("\n 0 - sair\n");
	printf("\n 1 - Inserir elementos na arvore");
	printf("\n 2 - mostrar elementos da arvore");
	printf("\n 3 - devolver o numero de nos e de ramos");
	printf("\n 4 - devolver a profundidade de um elemento na arvore");
	printf("\n 5 - devolver a altura de um elemento na arvore");
	printf("\n 6 - devolva o numero de descendentes de um elemento da arvore");
	printf("\n>> ");
}

int main()
{
	Abb abb;
	abb = abbCreate();
	AbbNode Node;

	/*
	Node = AbbNodeCreate(10);
	abb->root_node = abbInsert(abb->root_node, Node);
	
	Node = AbbNodeCreate(12);
	abb->root_node = abbInsert(abb->root_node, Node);
	
	Node = AbbNodeCreate(15);
	abb->root_node = abbInsert(abb->root_node, Node);
	
	Node = AbbNodeCreate(9);
	abb->root_node = abbInsert(abb->root_node, Node);
	
	Node = AbbNodeCreate(16);
	abb->root_node = abbInsert(abb->root_node, Node);
	
	abb->number_of_nodes = abbCountNodes(abb->root_node);
	abb->number_of_leafs = abbCountLeaf(abb->root_node);
	
	abbShow(abb->root_node);
	
	printf("\n numero de nos: %d", abb->number_of_nodes);
	printf("\n numero de folhas: %d", abb->number_of_leafs);

	int altura_arvore = abbHeigt(abb->root_node);

	printf("\n altura da arvore: %d", altura_arvore);

	AbbNode n = abbSeach(15, abb->root_node);

	int altura_no = abbHeigt(n);

	printf("\n altura do no: %d", altura_no);
	
	printf("\nok");
	*/

	int op;
	int elemento = 0;
	int altura_elemento = 0;
	int profundidade_elemeto = 0;
	int numero_descendentes = 0;
	AbbNode n;

	do
	{
		menu();
		scanf("%d", &op);

		switch (op)
		{

		case 1:
			printf("\n Adicionar Elemento: "); scanf("%d", &elemento);
			Node = AbbNodeCreate(elemento);
			abb->root_node = abbInsert(abb->root_node, Node);
			printf("\ninserido...\n");
			break;
		
		case 2:
			printf("\n");
			abbShow(abb->root_node);
			printf("\n");
			break;

		case 3:
			abb->number_of_nodes = abbCountNodes(abb->root_node);
			printf("\n Numero de nos da arvore: %d. Numero de ramos: %d\n", abb->number_of_nodes, abb->number_of_nodes - 1); 
			break;

		case 4:
			printf("\n Elemento para buscar profundidade: "); scanf("%d", &elemento);
			n = abbSeach(elemento, abb->root_node);

			if(n!= NULL)
			{
				profundidade_elemeto = abbNodeDeph(abb->root_node, elemento);
				printf("\n Profundidade %d\n", profundidade_elemeto - 1);
			}
			break;

		case 5:
			printf("\n Elemento para buscar sua altura: "); scanf("%d", &elemento);
			n = abbSeach(elemento, abb->root_node);

			if (n != NULL)
			{
				altura_elemento = abbHeigt(abb->root_node);
				printf("\n Altura do elemento: %d", altura_elemento -1);
			}
			break;
		
		case 6:
			printf("\n Elemento: "); scanf("%d", &elemento);
			n = abbSeach(elemento, abb->root_node);

			if(n !=NULL )
			{
				numero_descendentes = abbCountNodes(n);
				printf("\n numero de decendentes: %d", numero_descendentes - 1);
			}

			break;
		}

	}while(op != 0);

	return 0;
}
