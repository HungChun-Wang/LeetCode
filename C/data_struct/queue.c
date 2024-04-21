#include "common_def.h"
#include "queue.h"

bool queue_init(queue_t *p_queue, U32 u32_size, U32 u32_depth, void *p_data) {
    p_queue->u32_head = 0;
    p_queue->u32_tail = 0;
    p_queue->u32_size = u32_size;
    p_queue->u32_depth = u32_depth;
    p_queue->p_data = p_data;
}

bool queue_insert(queue_t *p_queue, void *p_data) {
    if (queue_is_full(p_queue)) return false;
    
    memcpy(p_queue->p_data + p_queue->u32_size * (p_queue->u32_tail++), p_data, p_queue->u32_size);

    if (p_queue->u32_tail >= p_queue->u32_depth)
        p_queue->u32_tail %= p_queue->u32_depth;
}

bool queue_remove(queue_t *p_queue, void *p_data) {
    if (queue_is_empty(p_queue)) return false;

    memcpy(p_data, p_queue->p_data + p_queue->u32_size * (p_queue->u32_head++), p_queue->u32_size);

    if (p_queue->u32_head >= p_queue->u32_depth)
        p_queue->u32_head %= p_queue->u32_depth;
}

bool queue_is_full(queue_t *p_queue) {
    return p_queue->u32_head == ((p_queue->u32_tail + 1) % p_queue->u32_depth);
}

bool queue_is_empty(queue_t *p_queue) {
    return p_queue->u32_head == p_queue->u32_tail;
}