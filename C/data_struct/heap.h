#pragma once

#define HEAP_TEST_ROUND     (10000)
#define HEAP_TEST_NODE_NUM  (10)
#define HEAP_TEST_VAL_UPPER (100)
#define HEAP_INVALID_VAL    (__INT_MAX__)

#define M_GET_MID(idx)      ((idx - 1) >> 1)
#define M_GET_LEFT(idx)     ((idx << 1) + 1)
#define M_GET_RIGHT(idx)    ((idx << 1) + 2)

typedef struct heap_t {
    S32 *ps32_arr;
    U32 u32_size;
    U32 u32_size_max;
    U32 u32_depth;
} heap_t;

bool heapify_max(heap_t *p_heap);

bool max_heap_insert(heap_t *p_heap, S32 s32_val);

S32 max_heap_delete(heap_t *p_heap, U32 u32_idx);

S32 max_heap_extract(heap_t *p_heap);

static inline bool heapify_forward_max(heap_t *p_heap, U32 u32_idx);

static inline bool heapify_backward_max(heap_t *p_heap, U32 u32_idx);
