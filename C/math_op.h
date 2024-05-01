#pragma once

#define M_IS_POW2(x) (!((x) & ((x) - 1)))

U32 log_ceil(U32 x);
