#define arr_length(arr) = sizeof(arr) / sizeof(arr[0])
#define MAX_PARAMS 3
typedef char Word[50];
typedef struct
{
    Word func_name;
    Word *params;
} user_input;

int get_command(char *line, char *p_command_name);
int get_params(char *line, Word *p_prms);