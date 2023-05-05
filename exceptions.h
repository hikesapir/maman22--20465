#include <stdio.h>
#define UNDEFINED_VAR printf("\nUndefined complex variable\n")
#define UNDEFINED_CMD printf("\nUndefined command name\n")
#define INVALID_PRM printf("\nInvalid parameter – not a number\n")
#define MISS_PRM printf("\nMissing parameter \n")
//TODO: better name
#define EXTRA_TEXT printf("\nExtraneous text after end of command\n")
#define MULTI_COMMA printf("\nMultiple consecutive commas\n")
#define ILLEGAL_COMMA printf("\nIllegal comma\n")
#define END_EXC printf("\nReached EOF before stop command\n")