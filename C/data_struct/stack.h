#pragma once

#define STACK_INVALID_VAL   (__UINT32_MAX__)

#define STACK_IS_FULL(stack)    ((stack).s32_top == (stack).u32_len_max - 1)
#define STACK_IS_EMPTY(stack)   ((stack).s32_top == -1)
#define STACK_IS_NOT_FULL(stack)    ((stack).s32_top != (stack).u32_len_max - 1)
#define STACK_IS_NOT_EMPTY(stack)   ((stack).s32_top != -1)
#define STACK_PUSH(type, stack, data)   {((type*)((stack).p_data))[++stack.s32_top] = data;}
#define STACK_PEEK(type, stack)         (((type*)((stack).p_data))[stack.s32_top])
#define STACK_POP(type, stack)          (((type*)((stack).p_data))[stack.s32_top--])
// #define STACK_PUSH(type, stack, data)   (STACK_IS_FULL(stack) ? STACK_INVALID_VAL : ((type*)((stack).p_data))[s32_top++] = data)
// #define STACK_PEEK(type, stack, data)   (STACK_IS_EMPTY(stack) ? STACK_INVALID_VAL : ((type*)((stack).p_data))[s32_top])
// #define STACK_POP(type, stack, data)    (STACK_IS_EMPTY(stack) ? STACK_INVALID_VAL : ((type*)((stack).p_data))[--s32_top])

typedef struct stack_t {
    S32 s32_top;
    U32 u32_len_max;
    void *p_data;
} stack_t;
