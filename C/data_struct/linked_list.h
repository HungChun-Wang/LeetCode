#pragma once

typedef struct listnode_S32_t {
    S32 n_val;
    struct listnode_S32_t *p_next;
} listnode_S32_t;

typedef struct list_S32_t {
    U32 n_len;
    listnode_S32_t *p_head;
} list_S32_t;
