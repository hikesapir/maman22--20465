#include "complex.h"
#define MAX_PARAMS 3
#define MAX_CMD_LENGTH 20
#define ENLARGE_LINE_SIZE(SIZE) (SIZE) + 20
#define CHAR_REALLOC(PTR, SIZE)                            \
    (PTR) = (char *)realloc((PTR), (SIZE) * sizeof(char)); \
    if ((PTR) == NULL)                                     \
    {                                                      \
        printf("No space\n");                              \
        return -1;                                         \
    }

int get_line(char **line);
int get_command(char *line, char *p_command_name);
int get_params(char *line, char *p_prms[]);
Complex *get_complex(char *comp_name, Complex *nums);
int run_cmd(char *cmd_name, char **prms, int prm_length, Complex *nums);

void trim(char *s);
void slice(char *str, char *result, size_t start);
int is_num(char *str);
