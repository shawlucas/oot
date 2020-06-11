/* adex.c
 * -glank
 */

#include <ultra64.h>
#include <global.h>

const char* adexErrorName[] =
{
    "success",
    "out of memory",
    "syntax error",
    "arithmetic error",
    "address unavailable",
};

#define ID_MAX 0x20

typedef enum
{
    TOK_CONST,
    TOK_ID,
    TOK_OP,
    TOK_BRACK_L,
    TOK_BRACK_R,
} TokType;

typedef enum
{
  OP_B,
  OP_BZ,
  OP_H,
  OP_HZ,
  OP_W,
  OP_MUL,
  OP_DIV,
  OP_REM,
  OP_ADD,
  OP_SUB,
  OP_MAX,
} Op;

typedef enum
{
    BRACK_PAREN,
    BRACK_SQUARE,
} Brack;

typedef struct Tok
{
    TokType type;
    union
    {
        u32 value;
        char id[ID_MAX];
        Op op;
        Brack brack;
    };
} Tok;

static const char *op_s[] =
{
  "b.", "bz.", "h.", "hz.", "w.",
  "*", "/", "%",
  "+", "-"
};

static int op_prec[] =
{
  /* modes */
  0, 0, 0, 0, 0,
  /* mul, div, rem */
  1, 1, 1,
  /* add, sub */
  2, 2,
};

static int op_ar[] =
{
  /* modes */
  1, 1, 1, 1, 1,
  /* mul, div, rem */
  2, 2, 2,
  /* add, sub */
  2, 2,
};

typedef struct sym
{
  const char *id;
  void       *addr;
} sym;

static struct sym syms[] =
{
    {
        "globalCtx",
        &globalCtx,
    },
    
    {
        "file",
        &Zelda_File,
    },
    {
        "link",
        &Zelda_Link,
    },
};

static u8 Make_Tok(Tok* )