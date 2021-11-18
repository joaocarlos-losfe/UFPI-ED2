#include "file.h"

char array_str[100][100];
int array_count = 0;


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

bool str_contains(char *str1, char *frase)
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

void insertLines(DTNode node)
{
    int i = 0;

    if (node != NULL)
    {
        for (i = 0; i < array_count; i++)
        {
            if (str_contains(node->palavra_left, array_str[i]))
            {
                Data linha = dataCreate();
                linha->linha = i+1;

                Data search = ListSeach(node->linhasPalavraLeft, i+1); //checa pra evitar duplicação de linha
                if (search == NULL)
                    listInsertOrdered(node->linhasPalavraLeft, linha);
            }

            if (strcmp(node->palavra_right, "") != 0 && str_contains(node->palavra_right, array_str[i]))
            {
                Data linha = dataCreate();
                linha->linha = i+1;

                Data search = ListSeach(node->linhasPalavraRight, i+1); //checa pra evitar duplicação de linha
                if (search == NULL)
                    listInsertOrdered(node->linhasPalavraRight, linha);
            }
            
        }
        
    }
}

void selectNode(DTNode root)
{
    int i = 0;

    if (root != NULL)
    {
        insertLines(root);

        selectNode(root->left);
        selectNode(root->cen);
        selectNode(root->right);
    }
    
}

void toWord(char *line_str, DTT tree)
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

            char var_temp[20];

            if(temp_str[0] != ' ' && temp_str[0] != '\0')
            {
                ddtInsert(NULL, &tree->root, temp_str, var_temp);
            }
                
        }
    }

}

void processFile(char *file_path, DTT *tree)
{
    FILE *file;
    int chapter = -1;
    time_t elapsed_search_time; // guarda o tempo inial
    double time; // guarda o tempo final

    file = fopen(file_path, "r");

    char line_str[100];

    if (file != NULL)
    {   
        elapsed_search_time = clock();

        while (!feof(file))
        {
            if(fgets(line_str, 100, file)) // se a linha for lida com sucesso
            {
                if(strcmp(line_str, "\n") != 0)
                {
                    strcpy(array_str[array_count], line_str);
                    array_count++;
                    toWord(line_str,  (*tree)); // divide a frase da linha em palavras e insere na arvore
                }
            }
        }
        
    }
    else
        printf("erro ao processar arquivo. verifique o diretorio");
    
    time = ((double)elapsed_search_time)*1000/CLOCKS_PER_SEC;
    printf("\ntempo de inserção: %.0f ns. \n", time);

    selectNode((*tree)->root);
    
}