#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "exceptions.h"

#define arr_length(arr) = sizeof(arr) / sizeof(arr[0])
#define MAX_PARAMS 3

typedef char Word[20];

typedef struct
{
    Word func_name;
    Word *params;
} user_input;

int get_line(char *line);

int main()
{

    char str[60];
    int i = 0;
    char *words;
    while (get_line(str) == 0)
    {
        printf("line %d >>> %s\n", i, str);
        i++;
    }

    printf("%s", str);

    return 0;
}

int get_line(char *line)
{
    char c;
    int i = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // if (c == EOF)
        //     return 1;
        // if (isspace(c))
        //     continue;
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return 0;
}

int get_formatted_user_input(char *line, user_input *input)
{
    int i = 0;
    int word_idx = 0;
    int param_idx = 0;
    int is_func_name = 1;
    Word word;

    while (line[i] != '\0')
    {
        if (param_idx > MAX_PARAMS)
        {
            EXTRA_TEXT;
            return 1;
        }
        if (isspace(line[i]))
        {
            // get func name
            if (is_func_name)
            {
                word[word_idx] = '\0';
                word_idx = 0;
                strcpy(input->func_name, word);
            }
            continue;
        }
        else if (line[i] == ',')
        {
            if (is_func_name)
            {
                return 1;
            }
            word[word_idx] = '\0';
            word_idx = 0;
            strcpy(input->params[param_idx], word);
            param_idx++;
            continue;
        }
        word[word_idx] = line[i];
        i++;
    }
    word[word_idx] = '\0';
    strcpy(input->params[param_idx], word);
    return 0;
}