#include <stdio.h>
#include "util.h"
#include "helpers.h"

int main()
{
    char str[100];
    char func_name[20];
    Word params[3] = {"Geek", "Geeks", "Geekfor"};
    int i = 0, last_index, has_err = 0;

    while (get_line(str) == 0)
    {
        printf("\nline %d >>> %s\n", i, str);
        i++;
        
        last_index = get_command(str, func_name);
        if (last_index < 0)
            continue;
        slice(str, str, last_index);
        has_err = get_params(str, params);
        printf("\n\n");
        if (has_err)
            continue;
        printf("func name is: %s\nfirst param is: %s\n", func_name, params[0]);
    }

    return 0;
}