#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "helpers.h"
#include "exceptions.h"

/*
Gets a line into string reference
return -1 if has issue to allocate sapce
return 1 if get to EOF
return 0 if has no issues

@param **line - reference to string variable
*/
int get_line(char **line)
{
    char c;
    int i = 0, line_size = 0;

    line_size = ENLARGE_LINE_SIZE(line_size);
    *line = (char *)malloc(line_size * sizeof(char));
    if (*line == NULL)
        return -1;

    /* run until reached new line or end of file*/
    while ((c = getchar()) != '\n' && c != EOF)
    {

        if (i == line_size)
        {
            line_size = ENLARGE_LINE_SIZE(line_size);
            CHAR_REALLOC(*line, line_size);
        }

        (*line)[i] = c;
        i++;
    }

    /* if gets to EOF prints exception */
    if (c == EOF)
    {
        EOF_EXC;
        return 1;
    }

    (*line)[i] = '\0';
    line_size = i + 1;
    CHAR_REALLOC(*line, line_size);

    return 0;
}

/*
Finds the command name in a given line string
returns -1 if has an issues otherwise returns the index of the last char

@param *line - the string
@param *p_command_name - the string to allocate the command name
*/
int get_command(char *line, char *p_command_name)
{
    int i = 0;
    /* run until reached white space or end of the string*/
    while (!isspace(line[i]) && line[i] != '\0')
    {
        if (i == MAX_CMD_LENGTH)
        {
            UNDEFINED_CMD;
            return -1;
        }
        if (line[i] == ',')
        {
            ILLEGAL_COMMA;
            return -1;
        }
        p_command_name[i] = line[i];
        i++;
    }
    p_command_name[i] = '\0';
    return i;
}

/*
Finds the given params in a given line string
returns -1 if has an issues otherwise returns the param arrray length

@param *line - the string
@param **p_prms - reference to array to allocate the params
*/
int get_params(char *line, char **p_prms)
{
    int i = 0, prm_size = 0, prm_counter = 0, prm_idx = 0;
    int is_first_char = TRUE, is_last_comma = TRUE, is_last_space = FALSE;

    while (line[i] != '\0')
    {
        /* if its the first char in the string allocate a space */
        if (prm_idx == 0)
        {
            prm_size = ENLARGE_LINE_SIZE(0);
            p_prms[prm_counter] = (char *)malloc(prm_size * sizeof(char));
        }
        /* if reached the max size realloc a space */
        if (prm_idx == prm_size)
        {
            prm_size = ENLARGE_LINE_SIZE(prm_size);
            CHAR_REALLOC(p_prms[prm_counter], prm_size);
        }
        /* if reached a comma move the next param =*/
        if (line[i] == ',')
        {
            if (is_first_char)
            {
                ILLEGAL_COMMA;
                return -1;
            }
            else if (is_last_comma)
            {
                MULTI_COMMA;
                return -1;
            }
            else if (prm_counter > MAX_PARAMS)
            {
                EXTRA_TEXT;
                return -1;
            }
            p_prms[prm_counter][prm_idx] = '\0';
            CHAR_REALLOC(p_prms[prm_counter], prm_idx);
            prm_idx = 0;
            prm_counter++;
            is_last_comma = TRUE;
            is_last_space = FALSE;
            i++;
            continue;
        }
        /* skip  white space */
        if (isspace(line[i]))
        {
            is_last_space = TRUE;
            i++;
            continue;
        }
        if (is_last_space && !is_last_comma)
        {
            MISS_COMMA;
            return -1;
        }
        is_first_char = FALSE;
        is_last_comma = FALSE;
        is_last_space = FALSE;
        p_prms[prm_counter][prm_idx] = line[i];
        prm_idx++;
        i++;
    }

    if (line[i - 1] == ',')
    {
        EXTRA_TEXT;
        return -1;
    }

    p_prms[prm_counter][prm_idx] = line[i];
    if (prm_idx > 0)
        prm_counter++;

    return prm_counter;
}


/*
returns NULL if has an issues otherwise returns the reference to the required complex number

@param *comp_name - the complex's name
@param *nums - array of complex numbers
*/
Complex *get_complex(char *comp_name, Complex *nums)
{
    size_t length = strlen(comp_name);

    /* if the length of the complex name is biger then 1 prints exception */
    if (length > 1)
    {
        UNDEFINED_VAR;
        return NULL;
    }

    switch (comp_name[0])
    {
    case 'A':
        return &nums[0];
    case 'B':
        return &nums[1];
    case 'C':
        return &nums[2];
    case 'D':
        return &nums[3];
    case 'E':
        return &nums[4];
    case 'F':
        return &nums[5];

    default:
        UNDEFINED_VAR;
        return NULL;
    }
}

/*
Execute the command with the given params
returns 1 if has an issues
returns -1 if the command is stop
returns 0 if successfully Executed

@param *cmd_name - the command's name
@param **prms - the params
@param *prm_length - the length of params array
@param *nums - array of complex numbers
*/
int run_cmd(char *cmd_name, char **prms, int prm_length, Complex *nums)
{
    /* initialization */
    int i;
    Complex *c1, *c2;
    double d1, d2;

    CMD commands[] = {
        {"read_comp", read_comp, 3, COMP_DOUBLE_DOUBLE},
        {"print_comp", print_comp, 1, COMP},
        {"add_comp", add_comp, 2, COMP_COMP},
        {"sub_comp", sub_comp, 2, COMP_COMP},
        {"mult_comp_real", mult_comp_real, 2, COMP_DOUBLE},
        {"mult_comp_img", mult_comp_img, 2, COMP_DOUBLE},
        {"mult_comp_comp", mult_comp_comp, 2, COMP_COMP},
        {"abs_comp", abs_comp, 1, COMP},
        {"stop", NULL, 0, NONE},
        {"not_valid", NULL, -1, -1}};

    /* search for command */
    for (i = 0; commands[i].arg_length >= 0; i++)
    {
        if (!strcmp(cmd_name, commands[i].name))
        {
            break;
        }
    }
    /* if the arg length is kess then 0 its not valid command */
    if (commands[i].arg_length < 0)
    {
        UNDEFINED_CMD;
        return 1;
    }
    /* validate the params */
    if (commands[i].arg_length < prm_length)
    {
        EXTRA_TEXT;
        return 1;
    }
    if (commands[i].arg_length > prm_length)
    {
        MISS_PRM;
        return 1;
    }

    switch (commands[i].arg_type)
    {
    case COMP_DOUBLE_DOUBLE:
        if (!is_num(prms[1]) || !is_num(prms[2]))
        {
            INVALID_PRM;
            return 1;
        }
        c1 = get_complex(prms[0], nums);
        if (c1 == NULL)
        {
            return 1;
        }
        d1 = atof(prms[1]);
        d2 = atof(prms[2]);

        commands[i].func(c1, d1, d2);
        break;
    case COMP:
        c1 = get_complex(prms[0], nums);
        if (c1 == NULL)
        {
            return 1;
        }
        commands[i].func(*c1);
        break;
    case COMP_COMP:
        c1 = get_complex(prms[0], nums);
        c2 = get_complex(prms[1], nums);
        if (c1 == NULL || c2 == NULL)
        {
            return 1;
        }
        commands[i].func(*c1, *c2);
        break;
    case COMP_DOUBLE:
        if (!is_num(prms[1]))
        {
            INVALID_PRM;
            return 1;
        }
        d1 = atof(prms[1]);
        c1 = get_complex(prms[0], nums);
        if (c1 == NULL)
        {
            return 1;
        }
        commands[i].func(*c1, d1);
        break;
    case NONE:
        return -1;
    default:
        UNDEFINED_CMD;
        break;
    }

    return 0;
}

/* utils */

/* copies the string pointed by source to the destination from specific index*/
void slice(char *str, char *result, size_t start)
{
    strcpy(result, str + start);
}

/* checks a given string is a number */
int is_num(char *str)
{
    int len;
    float ignore;
    int ret = sscanf(str, "%f %n", &ignore, &len);
    return ret && len == strlen(str);
}

