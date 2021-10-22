#include "file.h"

char array_str[100][100];
int array_count = 0;

bool contains(char *str1, char *frase)
{
    int i = 0;
    int j = 0;
    char temp_str[20];

    for(i=0; i<strlen(frase); i++)
    {
        if(!invalidChar(frase[i]))
        {
            temp_str[j] = frase[i];
            j++;
        }
        else
        {
            temp_str[j] = '\0';
            j = 0;

            if(temp_str[0] != ' ' && temp_str[0] != '\0')
            {
                if (strcmp(temp_str, str1) == 0)
                {   
                    return true;
                }
                
            }
        }
    }

    return false;
}

void addLines(char *str, RBTNode node)
{
    int i = 0;
    
    for (i = 0; i < array_count; i++)
    {   
        if (contains(str, array_str[i]))
        {
            Data linha = dataCreate();
            linha->linha = i+1;
            
            Data search = ListSeach(node->linhas, i+1); //checa pra evitar duplicação de linha
            if (search == NULL)
                listInsertOrdered(node->linhas, linha); // insere as linhas 
        }
        
    }

}

bool invalidChar(char ch)
{
    switch (ch)
    {
    case ' ':
    case ',':
    case ':':
    case '.':
    case '\n':
    case '\0':
        return true;
    }

    return false;
}

void toWord(char *line_str, RBT tree)
{
    char temp_str [20];
    int i = 0;
    int j = 0;
    
    for(i = 0; i< strlen(line_str); i++)
    {
        if(!invalidChar(line_str[i]))
        {
            temp_str[j] = line_str[i];
            j++;
        }
        else
        {
            temp_str[j] = '\0';
            j = 0;

            if(temp_str[0] != ' ' && temp_str[0] != '\0')
            {
                tree->root_node = rbtInsert(tree->root_node, temp_str); // insere na arvore
                
                RBTNode node = rbtNodeSearch(tree->root_node, temp_str); // pega o no recetemente inserido
                
                addLines(temp_str, node); // adiciona as linhas correpontes naquele nó
            }
                
        }
    }

   
}

void processFile(char *file_path, RBT *tree)
{
    FILE *file;
    int chapter = -1;

    file = fopen(file_path, "r");

    char line_str[100];

    if (file != NULL)
    {
        while (!feof(file))
        {
            if(fgets(line_str, 100, file)) // se a linha for lida com sucesso
            {
                if(strcmp(line_str, "\n") != 0)
                {
                    //printf("\n%s", line_str);

                    strcpy(array_str[array_count], line_str);
                    array_count++;

                    toWord(line_str,  (*tree)); // divide a frase da linha em palavras e insere na arvore
                }
            }
        }
        
    }
    else
        printf("erro ao processar arquivo. verifique o diretorio");
    
}