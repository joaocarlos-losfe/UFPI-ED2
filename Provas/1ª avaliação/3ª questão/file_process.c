#include "file_process.h"

bool InvalidChar(char ch)
{
    bool is_invalid = false;
    switch (ch)
    {
    case ' ':
    case ',':
    case ':':
    case '\n':
    case '\0':
        is_invalid = true;
        break;
    }

    return is_invalid;
}

void separateWords(int *i, char *str_wolds, char *save_wold)
{
    int c = 0;

    do
    {  
        if (!InvalidChar(str_wolds[*i]))
        {
            save_wold[c] = str_wolds[*i];
            c++;
        }
            
        *i += 1;

    } while (str_wolds[*i] != '\0' && str_wolds[*i] != ',' && str_wolds[*i] != ':'); // é uma nova palavra quando encontra ao final \0 , ou :

    save_wold[c] = '\0';
}

bool isChapter(char *str)
{
    if(str[0] == '%')
        return true;
    else
        return false;
}

int processFile(char *path, BST *chapter_tree)
{
    FILE *file;
    int chapter = -1;

    file = fopen(path, "r");

    char str[200];
    char captured_wold[100];
    char *is_load;
    int i = 0;
    bool is_english_wold = true;
    Data data;
    BSTNode node;

    char EN[100];

    if(file == NULL)
        printf("Erro ao processar arquivo. O caminho para o arquivo foi indicado corretamente ?");
    else
    {
        while (!feof(file)) // para quando encontra o fim do arquivo
        {
            
            if (fgets(str, 100, file)) // salva a linha do arquivo em str
            {
               if(strcmp(str, "\n") != 0)
               {
                    if(isChapter(str))
                    {
                        chapter+=1; // contador de capitulo
                        chapter_tree[chapter] = bstStart(); // inicia um novo capitulo na posição do array
                    }
                    else
                    {   
                        while (i < strlen(str)) // repete ate chegar no fim da frase
                        {
                            separateWords(&i, str, captured_wold); // separa palavra por palavra
                            
                            if(is_english_wold) // primeira palavra da frase sempre é ingles
                            {
                                chapter_tree[chapter]->root_node = bstInsert(chapter_tree[chapter]->root_node, captured_wold); // insere a chave ao nó
                                is_english_wold = false; // reverte. as proximas palavras são em ingles
                                strcpy(EN, captured_wold);

                                node = bstSeach(chapter_tree[chapter]->root_node, EN); // pega um ultimo nó inserido para acesso a sua lista
                            }
                            else // 
                            { 
                                if(node!=NULL)
                                {
                                    data = dataCreate(captured_wold); // cria um novo nó para a lista
                                    listInsertOrdered(node->list, data); // insere o novo no a lista de maneira ordenada
                                }
                            }
                            
                        }

                        is_english_wold = true;
                        i = 0;
                    }  

               }
            }
        }
    }

    fclose(file);

    return chapter + 1;
}