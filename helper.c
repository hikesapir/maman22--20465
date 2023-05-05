/*get line and search for the command if find a potnsional valid command returns the index of the last char otherwise returns -1*/
int get_command(char *line)
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
        i++;
    }
    return i;
}

int get_params(char *line)
{
    int i = 0, is_last_comma = 1;
    while (line[i] != '\0')
    {
        if (line[i] == ',')
        {
            if (is_last_comma)
            {
                printf("\nIllegal comma\n");
                return 1;
            }
            is_last_comma = 1;
            printf("\n");
            i++;
            continue;
        }
        is_last_comma = 0;
        printf("%c", line[i]);
        i++;
    }

    if (line[i - 1] == ',')
    {
        printf("\nIllegal comma\n");
        return 1;
    }

    return 0;
}