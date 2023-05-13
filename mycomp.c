#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int main()
{

    char *line, *prms[3], cmd_name[MAX_CMD_LENGTH];
    int i = 0, last_index, prm_length;
    Complex A = {0, 0}, B = {0, 0}, C = {0, 0}, D = {0, 0}, E = {0, 0}, F = {0, 0};
    Complex complex_nums[6];
    complex_nums[0] = A;
    complex_nums[1] = B;
    complex_nums[2] = C;
    complex_nums[3] = D;
    complex_nums[6] = E;
    complex_nums[6] = F;

    printf("please enter CMD");
    /* gets user input*/
    while (get_line(&line) == 0)
    {
        printf("\nline %d >>> %s\n", i, line);
        i++;
        /* analyze the line */
        last_index = get_command(line, cmd_name);
        if (last_index < 0)
            continue;
        slice(line, line, last_index);
        prm_length = get_params(line, prms);
        if (prm_length < 0)
            continue;
        /*
                printf("\nrun cmd %s with\n", cmd_name);
                printf("\nparam 1  %s\n", prms[0]);
                printf("\nparam 2  %s\n", prms[1]);
                printf("\nparam 3  %s\n", prms[2]);
        */
        /* run the command */
        run_cmd(cmd_name, prms, prm_length, complex_nums);
    }
    printf("\nEXIT!\n");

    free(line);
    free(prms[0]);
    free(prms[1]);
    free(prms[2]);

    return 0;
}
