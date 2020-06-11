#ifndef _ADEX_H_
#define _ADEX_H_
#include <vector.h>

typedef enum
{
  ADEX_ERROR_SUCCESS,
  ADEX_ERROR_MEMORY,
  ADEX_ERROR_SYNTAX,
  ADEX_ERROR_ARITHMETIC,
  ADEX_ERROR_ADDRESS,
} AdexError;

typedef struct
{
    Vector expr;
} Adex;



#endif