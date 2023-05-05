#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "util.h"

void slice(const char *str, char *result, size_t start)
{
    strcpy(result, str + start);
}

void trim(char *s)
{
    int i = 0, j = 0;
    char ptr[200];

    while (s[i] != '\0')
    {
        if (!isspace(s[i]))
        {
            ptr[j] = s[i];
            j++;
        }
        i++;
    }
    ptr[j] = '\0';
    strcpy(s, ptr);
}

int get_line(char *line)
{
    char c;
    int i = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    if (c == EOF)
        return 1;
    return 0;
}
