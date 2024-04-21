#include "common_def.h"
#include "stack.h"

bool stack_init(stack_t *p_stack, U32 u32_size, U32 u32_height, void *p_data) {
    p_stack->s32_top = -1;
    p_stack->u32_size = u32_size;
    p_stack->u32_height = u32_height;
    p_stack->p_data = p_data;
}

bool stack_is_full(stack_t *p_stack) {
    return p_stack->s32_top == p_stack->u32_height - 1;
}

bool stack_is_empty(stack_t *p_stack) {
    return p_stack->s32_top == -1;
}

bool stack_push(stack_t *p_stack, void *p_val) {
    if (stack_is_full(p_stack)) return false;

    memcpy(p_stack->p_data + p_stack->u32_size * (++p_stack->s32_top), p_val, p_stack->u32_size);
    return true;
}

bool stack_pop(stack_t *p_stack, void *p_val) {
    if (stack_is_empty(p_stack)) return false;

    memcpy(p_val, p_stack->p_data + p_stack->u32_size * (p_stack->s32_top--), p_stack->u32_size);
    return true;
}

bool stack_peek(stack_t *p_stack, void *p_val) {
    if (stack_is_empty(p_stack)) return false;

    memcpy(p_val, p_stack->p_data + p_stack->u32_size * p_stack->s32_top, p_stack->u32_size);
    return true;
}
