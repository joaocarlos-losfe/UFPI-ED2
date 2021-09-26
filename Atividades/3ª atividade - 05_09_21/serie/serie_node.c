#include "string.h"
#include "serie_node.h"


SerieNode SerieNodeCreate(int codigo, string titulo, int numero_temporadas)
{
    SerieNode serie_node = malloc(sizeof(struct SerieNode));

    serie_node->codigo = codigo;
    strcpy(serie_node->titulo, titulo);
    serie_node->numero_temporadas = numero_temporadas;

    serie_node->left = NULL;
    serie_node->right = NULL;

    return serie_node;
}

SerieNode SerieNodeDestroy(SerieNode serie_node)
{
    free(serie_node);
    serie_node = NULL;
    return serie_node;
}

void SerieNodePrint(SerieNode serie_node)
{
    printf("\n");
    printf("\ntitulo: %s", serie_node->titulo);
    printf("\nnumero de temporadas: %d", serie_node->numero_temporadas);

    printf("\n lista de temporadas: ");
    listPrint(serie_node->lista_temporadas);
}

bool SerieNodeIsLeaf(SerieNode serie_node)
{   
    bool is_leaf = false;

    if (serie_node->left == NULL && serie_node->right == NULL)
    {
        is_leaf = true;
    }
    return is_leaf;
}