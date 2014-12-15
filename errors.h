// Matricola:
// Nome:

#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>

#define MALLOC_ERR 1
#define FOPEN_ERR 2
#define FOPEN_W_ERR 3
#define FOPEN_R_ERR 4
#define INVALID_ACCESS 5

int handleError(int err);
void exitWithError(int err);

#endif
