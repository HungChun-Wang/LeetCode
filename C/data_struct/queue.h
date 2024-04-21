#pragma once

typedef struct queue_t {
    U32 u32_head;
    U32 u32_tail;
    U32 u32_size;
    U32 u32_depth;
    void *p_data;
} queue_t;

bool queue_init(queue_t *p_queue, U32 u32_size, U32 u32_depth, void *p_data);

bool queue_insert(queue_t *p_queue, void *p_data);

bool queue_remove(queue_t *p_queue, void *p_data);

bool queue_is_full(queue_t *p_queue);

bool queue_is_empty(queue_t *p_queue);

