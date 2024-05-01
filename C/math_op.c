#include "common_def.h"
#include "math.h"

U32 log_ceil(U32 x) {
    U32 y = 0;
    while ((x - 1) >> y) y++;
    return y;
}
