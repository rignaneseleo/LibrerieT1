#include <stdio.h>

#ifndef ERROR_H
#define ERROR_H


#define MALLOC_ERR 1
#define FOPEN_W_ERR 2
#define FOPEN_R_ERR 3
#define INVALID_ACCESS 4

int handleError(int err);
int exitWithError(int err);



#endif /* defined(__LibrerieT1__errors__) */