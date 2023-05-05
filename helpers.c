#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "exceptions.h"
#include "util.h"
#include "helpers.h"

/*get line and search for the command if find a potnsional valid command returns the index of the last char otherwise returns -1*/
int get_command(char *line, char *p_command_name)
{
    int i = 0;
    while (!isspace(line[i]))
    {
        if (line[i] == ',')
        {
            printf("\nIllegal comma\n");
            return -1;
        }
        printf("%c", line[i]);
        p_command_name[i] = line[i];
        i++;
    }
    p_command_name[i] = "\0";
    return i;
}

int get_params(char *line, Word *p_prms)
{
    int i = 0, is_last_comma = 1;
    int prm_counter = 0, prm_idx = 0;
    Word prm;
    trim(line);
    while (line[i] != '\0')
    {
        if (line[i] == ',')
        {
            if (i == 0)
            {
                ILLEGAL_COMMA;
                return 1;
            }
            else if (is_last_comma)
            {
                MULTI_COMMA;
                return 1;
            }
            if (prm_counter > MAX_PARAMS)
            {
                EXTRA_TEXT;
                return 1;
            }
            prm[prm_idx] = '\0';
            strcpy(p_prms[prm_counter], prm);
            prm_idx = 0;
            prm_counter++;
            is_last_comma = 1;
            i++;
            printf("\n");
            continue;
        }
        is_last_comma = 0;
        prm[prm_idx] = line[i];
        printf("%c", line[i]);
        prm_idx++;
        i++;
    }

    if (line[i - 1] == ',')
    {
        EXTRA_TEXT;
        return 1;
    }

    return 0;
}
