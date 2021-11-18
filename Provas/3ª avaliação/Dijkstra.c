
#include <stdio.h>
#define VALOR_INFINITO 9999
#define MAX 10 // total maximo de vertices a ser inseridos


void dijkstra(int grafo[MAX][MAX], int n)
{
	int matriz_distancias[MAX][MAX], distancias[MAX], vertice_predecessor[MAX];
	int visitados[MAX], count, distancia_minima, proximo_vertice, i, j;

	int inicio = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (grafo[i][j] == 0)
				matriz_distancias[i][j] = VALOR_INFINITO;
			else
				matriz_distancias[i][j] = grafo[i][j];
		}

	}

	for (i = 0; i < n; i++)
	{
		distancias[i] = matriz_distancias[inicio][i];
		vertice_predecessor[i] = inicio;
		visitados[i] = 0;
	}

	distancias[inicio] = 0;
	visitados[inicio] = 1;

	count = 1;

	while (count < n - 1)
	{
		distancia_minima = VALOR_INFINITO;

		for (i = 0; i < n; i++)
		{
			if (distancias[i] < distancia_minima && !visitados[i])
			{
				distancia_minima = distancias[i];
				proximo_vertice = i;
			}
		}

		visitados[proximo_vertice] = 1;

		for (i = 0; i < n; i++)
		{
			if (!visitados[i])
			{
				if (distancia_minima + matriz_distancias[proximo_vertice][i] < distancias[i])
				{
					distancias[i] = distancia_minima + matriz_distancias[proximo_vertice][i];
					vertice_predecessor[i] = proximo_vertice;
				}
			}

		}

		count++;
	}

	//mostrar os vertices com suas distancias
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if (matriz_distancias[i][j] == VALOR_INFINITO)
				printf("~ ");
			else
				printf("%d ", matriz_distancias[i][j]);

		}
		printf("\n");
	}


	// mostrar as distancias
	for (i = 0; i < n; i++)
	{
		if (i != inicio)
		{
			printf("\nDistancia do vertice inicial para o Vertice %d: %d", i, distancias[i]);
		}
	}

	printf("\n\n");
}

void preencherGrafo(int grafo[MAX][MAX], int n)
{
	int i = 0, j = 0;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("> "); scanf("%d", &grafo[i][j]);
		}
	}
}

void menu()
{
	printf("0 - sair\n");
	printf("1 - rodar exemplo\n");
	printf("2 - preencher um grafo\n");
	printf(">> ");

}

void exemplo(int grafo[MAX][MAX], int n)
{
	/*
					0   1   2   3   4   5   6   7   8   9
					A   B   C   D   E   F   G   H   I   J
				a  00  60  54  42  00  00  00  00  00  00

				b  60  00  00  71  00  29  00  00  00  00

				c  54  00  00  56  67  00  00  00  00  00

				d  42  71  56  00  26  52  87  00  00  00

				e  00  00  67  26  00  00  70  00  73  00

				f  00  29  00  52  00  00  20  25  00  00

				g  00  00  00  87  70  20  00  36  59  32

				h  00  00  00  00  00  25  36  00  00  25

				i  00  00  00  00  73  00  59  00  00  26

				j  00  00  00  00  00  00  32  25  26  00

	*/


	//vertice a
	grafo[0][0] = 0;
	grafo[0][1] = 60;
	grafo[0][2] = 54; //distancias das arestas pra cada vertice
	grafo[0][3] = 42;
	grafo[0][4] = 0;
	grafo[0][5] = 0;
	grafo[0][6] = 0;
	grafo[0][7] = 0;
	grafo[0][8] = 0;
	grafo[0][9] = 0;

	//vartice b
	grafo[1][0] = 60;
	grafo[1][1] = 0;
	grafo[1][2] = 0;
	grafo[1][3] = 71;
	grafo[1][4] = 0;
	grafo[1][5] = 29;
	grafo[1][6] = 0;
	grafo[1][7] = 0;
	grafo[1][8] = 0;
	grafo[1][9] = 0;

	//vertice c
	grafo[2][0] = 54;
	grafo[2][1] = 0;
	grafo[2][2] = 0;
	grafo[2][3] = 56;
	grafo[2][4] = 67;
	grafo[2][5] = 0;
	grafo[2][6] = 0;
	grafo[2][7] = 0;
	grafo[2][8] = 0;
	grafo[2][9] = 0;

	//vertice d
	grafo[3][0] = 42;
	grafo[3][1] = 71;
	grafo[3][2] = 56;
	grafo[3][3] = 0;
	grafo[3][4] = 26;
	grafo[3][5] = 52;
	grafo[3][6] = 87;
	grafo[3][7] = 0;
	grafo[3][8] = 0;
	grafo[3][9] = 0;

	//vertice e
	grafo[4][0] = 0;
	grafo[4][1] = 0;
	grafo[4][2] = 67;
	grafo[4][3] = 26;
	grafo[4][4] = 0;
	grafo[4][5] = 0;
	grafo[4][6] = 70;
	grafo[4][7] = 0;
	grafo[4][8] = 73;
	grafo[4][9] = 0;

	//vertice f
	grafo[5][0] = 0;
	grafo[5][1] = 29;
	grafo[5][2] = 0;
	grafo[5][3] = 52;
	grafo[5][4] = 0;
	grafo[5][5] = 0;
	grafo[5][6] = 20;
	grafo[5][7] = 25;
	grafo[5][8] = 0;
	grafo[5][9] = 0;

	//vertice g
	grafo[6][0] = 0;
	grafo[6][1] = 0;
	grafo[6][2] = 0;
	grafo[6][3] = 87;
	grafo[6][4] = 70;
	grafo[6][5] = 20;
	grafo[6][6] = 0;
	grafo[6][7] = 36;
	grafo[6][8] = 59;
	grafo[6][9] = 32;

	//vertice h
	grafo[7][0] = 0;
	grafo[7][1] = 0;
	grafo[7][2] = 0;
	grafo[7][3] = 0;
	grafo[7][4] = 0;
	grafo[7][5] = 25;
	grafo[7][6] = 36;
	grafo[7][7] = 0;
	grafo[7][8] = 0;
	grafo[7][9] = 25;

	//vertice i
	grafo[8][0] = 0;
	grafo[8][1] = 0;
	grafo[8][2] = 0;
	grafo[8][3] = 0;
	grafo[8][4] = 73;
	grafo[8][5] = 0;
	grafo[8][6] = 59;
	grafo[8][7] = 0;
	grafo[8][8] = 0;
	grafo[8][9] = 26;

	//vertice j
	grafo[9][0] = 0;
	grafo[9][1] = 0;
	grafo[9][2] = 0;
	grafo[9][3] = 0;
	grafo[9][4] = 0;
	grafo[9][5] = 0;
	grafo[9][6] = 0;
	grafo[9][7] = 32;
	grafo[9][8] = 25;
	grafo[9][9] = 26;

	printf("\n");

	dijkstra(grafo, n);

}

int main()
{
	int grafo[MAX][MAX], total_vertices = 10;

	int op = -1;

	do
	{
		total_vertices = 10;
		menu();
		scanf("%d", &op);

		switch(op)
		{
		case 1:
			exemplo(grafo, total_vertices);
			break;
		case 2: 
			printf("\n Total de vertices: "); scanf("%d", &total_vertices);
			preencherGrafo(grafo, total_vertices);
			dijkstra(grafo, total_vertices);
		default:
			break;
		}
	}
	while(op != 0);


	return 0;
}
