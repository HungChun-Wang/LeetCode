#pragma once

#define INVALID_VAL (__INT_MAX__)

typedef struct tree_node_t {
    void *p_data;
    size_t unit;
    struct tree_node_t *p_left;
    struct tree_node_t *p_right;
} tree_node_t;

typedef struct tree_t {
    tree_node_t *p_root;
    U32 u32_depth;
} tree_t;

typedef struct heap_t {
    S32 *ps32_arr;
    U32 u32_size;
    U32 u32_size_max;
    U32 u32_depth;
} heap_t;

bool tree_traversal_preorder(tree_t *p_tree);

bool tree_traversal_inorder(tree_t *p_tree);

bool tree_traversal_postorder(tree_t *p_tree);

bool heapify_max(heap_t *p_heap);

bool max_heap_insert(heap_t *p_heap, S32 s32_val);

S32 max_heap_delete(heap_t *p_heap, U32 u32_idx);

S32 max_heap_extract(heap_t *p_heap);

static bool heapify_forward_max(heap_t *p_heap, U32 u32_idx);

static bool heapify_backward_max(heap_t *p_heap, U32 u32_idx);
