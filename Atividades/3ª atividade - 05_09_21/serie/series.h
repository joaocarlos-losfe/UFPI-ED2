#ifndef _SERIES_H_
#define _SERIES_H_

#include "serie_node.h"

typedef struct Series* Series;

struct Series
{
	SerieNode root_node; //raiz da arvore ou primeiro elemento

	unsigned int number_of_nodes; // n�mero de dados (n�s) inseridos
	unsigned int number_of_leafs; // numero de folhas
	
};


Series SeriesCreate();
SerieNode SeriesInsert(SerieNode root_serie_node, SerieNode node);
SerieNode SeriesSeach(int value, SerieNode root_node);
void SeriesShow(SerieNode root_serie_node);
int SeriesCountNode(SerieNode root_serie_node);
SerieNode SeriesSeachNode(SerieNode root_serie_node, int codigo, SerieNode * dad);
SerieNode SeriesDelete(SerieNode root_serie_node, int codigo);
int SeriesCountLeaf(SerieNode root_serie_node);

#endif
