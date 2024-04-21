#pragma once

typedef struct stack_t {
    S32 s32_top;
    U32 u32_size;
    U32 u32_height;
    void *p_data;
} stack_t;

bool stack_init(stack_t *p_stack, U32 u32_size, U32 u32_height, void *p_data);

bool stack_is_full(stack_t *p_stack);

bool stack_is_empty(stack_t *p_stack);

bool stack_push(stack_t *p_stack, void *p_val);

bool stack_pop(stack_t *p_stack, void *p_val);

bool stack_peek(stack_t *p_stack, void *p_val);
