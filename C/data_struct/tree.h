#pragma once

#define INVALID_BALANCE        (__INT_MAX__)
#define HEIGHT_OF_NULL_CHILD   (-1)

typedef S32 tree_key_t;
typedef U32 tree_height_t;

typedef struct tree_node_t {
    struct tree_node_t *p_left;
    struct tree_node_t *p_right;
    S32 key;
} tree_node_t;

typedef struct tree_t {
    tree_node_t *p_root;
    U32 u32_depth;
} tree_t;

typedef struct AVL_node_t {
    struct AVL_node_t *p_left;
    struct AVL_node_t *p_right;
    struct AVL_node_t *p_parent;
    tree_key_t key;
    tree_height_t height;
} AVL_node_t;

bool tree_traversal_preorder(tree_t *p_tree);

bool tree_traversal_inorder(tree_t *p_tree);

bool tree_traversal_postorder(tree_t *p_tree);

bool BST_insert(tree_t *p_tree, tree_node_t *p_node);

bool BST_deletion(tree_t *p_tree, tree_key_t key);

// return root
AVL_node_t *AVL_insert(AVL_node_t *p_root, AVL_node_t *p_node);

// return null if miss
AVL_node_t *AVL_peek(AVL_node_t *p_root, tree_key_t key);

// return root
AVL_node_t *AVL_delete(AVL_node_t *p_node);

bool AVL_traversal_inoder(AVL_node_t *p_root);

static AVL_node_t *AVL_balance(AVL_node_t *p_node);

static inline S32 tree_cal_height(AVL_node_t *p_node);

static inline S32 tree_cal_balance(AVL_node_t *p_node);

static inline bool tree_rotate_left(AVL_node_t *p_node);

static inline bool tree_rotate_right(AVL_node_t *p_node);
