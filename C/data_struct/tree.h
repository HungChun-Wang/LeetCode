#pragma once

typedef struct tree_node_t {
    void *p_data;
    size_t size;
    struct tree_node_t *p_left;
    struct tree_node_t *p_right;
} tree_node_t;

typedef struct tree_t {
    tree_node_t *p_root;
    U32 u32_depth;
} tree_t;

bool tree_traversal_preorder(tree_t *p_tree);

bool tree_traversal_inorder(tree_t *p_tree);

bool tree_traversal_postorder(tree_t *p_tree);
