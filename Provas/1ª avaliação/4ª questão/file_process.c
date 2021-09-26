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

    } while (str_wolds[*i] != '\0' && str_wolds[*i] != ',' && str_wolds[*i] != ':');

    save_wold[c] = '\0';
}

bool isChapter(char *str)
{
    if(str[0] == '%')
        return true;
    else
        return false;
}

int processFile(char *path, AVL *chapter_tree)
{
    FILE *file;
    int chapter = -1;

    file = fopen(path, "r");

    char str[200];
    char captured_wold[100];

    int i = 0;
    bool is_english_wold = true;
    Data data;
    AVLNode node;

    char EN[100];

    if(file == NULL)
        printf("Erro ao processar arquivo. O caminho para o arquivo foi indicado corretamente ?");
    else
    {
        while (!feof(file))
        {
        
            if (fgets(str, 100, file))
            {
               if(strcmp(str, "\n") != 0)
               {
                    if(isChapter(str))
                    {
                        chapter+=1;
                        chapter_tree[chapter] = avlStart();
                    }
                    else
                    {   
                        while (i < strlen(str))
                        {
                            separateWords(&i, str, captured_wold);
                            
                            if(is_english_wold)
                            {
                                chapter_tree[chapter]->root_node = avlInsert(chapter_tree[chapter]->root_node, captured_wold);
                                is_english_wold = false;
                                strcpy(EN, captured_wold);

                                node = avlSeach(chapter_tree[chapter]->root_node, EN);
                            }
                            else
                            {
                                if(node!=NULL)
                                {
                                    data = dataCreate(captured_wold);
                                    listInsertOrdered(node->list, data);
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