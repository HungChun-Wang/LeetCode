#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <time.h>

typedef char                S8;
typedef short               S16;
typedef int                 S32;
typedef long long           S64;
typedef unsigned char       U8;
typedef unsigned short      U16;
typedef unsigned int        U32;
typedef unsigned long long  U64;

#define M_SWAP(x, y, buffer) {(buffer) = (x); (x) = (y); (y) = (buffer);}
#define M_MAX(x, y) (((x) > (y)) ? (x) : (y))
#define M_MIN(x, y) (((x) < (y)) ? (x) : (y))
#define BIT(x)      (1 << (x))
#define BIT_NUM_32  (32)

#define PASS    (0)
#define FAIL    (1)
