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

/*
Gets a line into string reference
return -1 if has issue to allocate sapce
return 1 if get to EOF
return 0 if has no issues

@param **line - reference to string variable
*/
int get_line(char **line);

/*
Finds the command name in a given line string
returns -1 if has an issues otherwise returns the index of the last char

@param *line - the string 
@param *p_command_name - the string to allocate the command name
*/
int get_command(char *line, char *p_command_name);
int get_params(char *line, char *p_prms[]);
Complex *get_complex(char *comp_name, Complex *nums);
int run_cmd(char *cmd_name, char **prms, int prm_length, Complex *nums);

/* utils */
void trim(char *s);
void slice(char *str, char *result, size_t start);
int is_num(char *str);
