#ifndef __FILES__
#define __FILES__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "./2_3Tree/dtt.h"


bool invalidChar(char ch); // verifica se é um caractere invalido
void toWord(char *line_str, DTT root); //divide a frase em palavras e adiciona cada palavra na arvore
void processFile(char *file_path, DTT *tree);

#endif