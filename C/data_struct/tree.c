#include "common_def.h"
#include "math_op.h"
#include "stack.h"
#include "tree.h"

#define TREE_TEST_NODE_NUM  (10)

void AVL_test() {
    AVL_node_t tree_node_src[TREE_TEST_NODE_NUM] = {0};
    tree_key_t tree_key_src[TREE_TEST_NODE_NUM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    AVL_node_t *p_root = &tree_node_src[0];
    
    for (U32 i = 0; i < TREE_TEST_NODE_NUM; i++) {
        // U32 u32_idx_left = (i << 1) + 1;
        // U32 u32_idx_right = u32_idx_left + 1;
        // tree_node_src[i].p_left = (u32_idx_left < TREE_TEST_NODE_NUM) ? &tree_node_src[u32_idx_left] : NULL;
        // tree_node_src[i].p_right = (u32_idx_right < TREE_TEST_NODE_NUM) ? &tree_node_src[u32_idx_right] : NULL;
        tree_node_src[i].key = tree_key_src[i];
    }

    for (U32 i = 1; i < TREE_TEST_NODE_NUM; i++) {
        p_root = AVL_insert(p_root, &tree_node_src[i]);
        AVL_traversal_inoder(p_root);
    }

    AVL_node_t *p_node;
    for (U32 i = 0; i < TREE_TEST_NODE_NUM; i++) {
        p_node = AVL_peek(p_root, i);
        p_root = AVL_delete(p_node);
        AVL_traversal_inoder(p_root);
    }
}

void tree_test() {
    tree_t tree_src = {0};
    tree_node_t tree_node_src[TREE_TEST_NODE_NUM];
    S32 tree_data_src[TREE_TEST_NODE_NUM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    tree_src.p_root = tree_node_src;
    
    tree_src.u32_depth = log_ceil(TREE_TEST_NODE_NUM);
    
    for (U32 i = 0; i < TREE_TEST_NODE_NUM; i++) {
        U32 u32_idx_left = (i << 1) + 1;
        U32 u32_idx_right = u32_idx_left + 1;
        tree_node_src[i].p_left = (u32_idx_left < TREE_TEST_NODE_NUM) ? &tree_node_src[u32_idx_left] : NULL;
        tree_node_src[i].p_right = (u32_idx_right < TREE_TEST_NODE_NUM) ? &tree_node_src[u32_idx_right] : NULL;    
        tree_node_src[i].key = tree_data_src[i];
    }

    // tree_traversal_preorder(&tree_src);
    // tree_traversal_inorder(&tree_src);
    tree_traversal_postorder(&tree_src);
}

bool tree_traversal_preorder(tree_t *p_tree) {
    if (!p_tree) return false;
    if (!p_tree->p_root) return false;
    
    tree_node_t *p_node = p_tree->p_root;

    U64 *p_node_adr = malloc(p_tree->u32_depth * sizeof(U64));
    stack_t stack = {-1, p_tree->u32_depth, p_node_adr};

    while (1) {
        printf("%d ", p_node->key);
        
        if (p_node->p_right)
            STACK_PUSH(U64, stack, (U64)p_node->p_right)

        if (p_node->p_left)
            p_node = p_node->p_left;
        else if (STACK_IS_NOT_EMPTY(stack))
            p_node = (tree_node_t*)STACK_POP(U64, stack);
        else
            break;
            
    }

    free(p_node_adr);
    return true;
}

bool tree_traversal_inorder(tree_t *p_tree) {
    if (!p_tree) return false;
    if (!p_tree->p_root) return false;
    
    tree_node_t *p_node = p_tree->p_root;
    tree_node_t **p_node_adr = malloc(p_tree->u32_depth * sizeof(tree_node_t*));
    stack_t stack = {-1, p_tree->u32_depth, p_node_adr};

    while (1) {
        if (p_node) {
            STACK_PUSH(U64, stack, (U64)p_node)
            p_node = p_node->p_left;
        }
        else if (STACK_IS_NOT_EMPTY(stack)) {
            p_node = (tree_node_t*)STACK_POP(U64, stack);
            printf("%d ", p_node->key);
            p_node = p_node->p_right;
        }
        else
            break;
    }

    free(p_node_adr);
    return true;
}

bool tree_traversal_postorder(tree_t *p_tree) {
    if (!p_tree) return false;
    if (!p_tree->p_root) return false;
    
    tree_node_t *p_node = p_tree->p_root;
    tree_node_t *p_node_top;
    tree_node_t **p_node_adr = malloc((p_tree->u32_depth << 1) * sizeof(tree_node_t*));
    stack_t stack = {-1, p_tree->u32_depth, p_node_adr};

    do {
        while (p_node) {
            if (p_node->p_right)
                STACK_PUSH(U64, stack, (U64)p_node->p_right)
            STACK_PUSH(U64, stack, (U64)p_node)
            p_node = p_node->p_left;
        }

        p_node = (tree_node_t*)STACK_POP(U64, stack);
        p_node_top = (tree_node_t*)STACK_PEEK(U64, stack);

        if (p_node->p_right && (p_node->p_right == p_node_top)) {
            p_node_top = (tree_node_t*)STACK_POP(U64, stack);
            STACK_PUSH(U64, stack, (U64)p_node)
            p_node = p_node->p_right;
        }
        else {
            printf("%d ", p_node->key);
            p_node = NULL;
        }
    } while (STACK_IS_NOT_EMPTY(stack));

    free(p_node_adr);
    return true;
}

bool BST_insert(tree_t *p_tree, tree_node_t *p_node) {
    if (!p_tree || !p_node) return false;

    if (!p_tree->p_root) {
        p_tree->p_root = p_node;
        return true;
    }

    U8 u8_is_left = false;
    tree_node_t *p_curr = p_tree->p_root;
    tree_node_t *p_prev;

    while (1) {
        p_prev = p_curr;
        if (p_curr->key >= p_node->key) {
            p_curr = p_curr->p_left;
            u8_is_left = true;
        }
        else {
            p_curr = p_curr->p_right;
            u8_is_left = false;
        }

        if (!p_curr) {
            if (u8_is_left)
                p_prev->p_left = p_node;
            else
                p_prev->p_right = p_node;
            break;
        }
    }
}

bool BST_deletion(tree_t *p_tree, tree_key_t key) {
    if (!p_tree) return false;

    tree_node_t *p_prev;
    tree_node_t *p_curr = p_tree->p_root;

    while (p_curr) {
        if (p_curr->key > key) {
            p_prev = p_curr;
            p_curr = p_curr->p_left;
        }
        else if (p_curr->key < key) {
            p_prev = p_curr;
            p_curr = p_curr->p_right;
        }
        else
            // hit value
            break;
    }

    // not found
    if (!p_curr)
        return false;

    if (p_curr->p_left && p_curr->p_right) {
        tree_node_t *p_curr_ex = p_curr->p_right;
        while (1) {
            if (p_curr_ex->p_left)
                p_curr_ex = p_curr_ex->p_left;
            else if (p_curr->p_right)
                p_curr_ex = p_curr_ex->p_right;
            else {
                if (p_prev->p_left == p_curr)
                    p_prev->p_left = p_curr_ex;
                else
                    p_prev->p_right = p_curr_ex;
                p_curr_ex->p_left = p_curr->p_left;
                p_curr_ex->p_right = p_curr->p_right;
                break;
            }
        }
    }
    else if (!p_curr->p_left && !p_curr->p_right) {
        // no child, set parent's leaf to null
        if (p_prev->p_left == p_curr)
            p_prev->p_left = NULL;
        else
            p_prev->p_right = NULL;
    }
    else if (p_curr->p_left && !p_curr->p_right) {
        if (p_prev->p_left == p_curr)
            p_prev->p_left = p_curr->p_left;
        else
            p_prev->p_right = p_curr->p_left;
    }
    else if (!p_curr->p_left && p_curr->p_right) {
        if (p_prev->p_left == p_curr)
            p_prev->p_left = p_curr->p_right;
        else
            p_prev->p_right = p_curr->p_right;
    }
    else {
        // undefined
        return false;
    }
    return true;
}

AVL_node_t *AVL_insert(AVL_node_t *p_root, AVL_node_t *p_node) {
    if (!p_root || !p_node) return NULL;

    U8 u8_check_balance;
    S32 S32_balance;
    AVL_node_t *p_parent;
    AVL_node_t *p_curr = p_root;

    // BST insertion
    while (1) {
        p_parent = p_curr;
        p_curr = (p_curr->key >= p_node->key) ? p_curr->p_left : p_curr->p_right;
        
        if (!p_curr) {
            p_node->p_parent = p_parent;
            u8_check_balance = (!p_parent->p_left && !p_parent->p_right);
            if (p_parent->key >= p_node->key)
                p_parent->p_left = p_node;
            else
                p_parent->p_right = p_node;
            break;
        }
    }

    if (!u8_check_balance) return p_root;

    return AVL_balance(p_parent);
}

AVL_node_t *AVL_peek(AVL_node_t *p_root, tree_key_t key) {
    if (!p_root) return NULL;

    AVL_node_t *p_curr = p_root;

    while (p_curr) {
        if (p_curr->key == key)
            return p_curr;
        else if (p_curr->key > key)
            p_curr = p_curr->p_left;
        else
            p_curr = p_curr->p_right;
    }
    return NULL;
}

AVL_node_t *AVL_delete(AVL_node_t *p_node) {
    if (!p_node) return NULL;

    AVL_node_t *p_parent = p_node->p_parent;

    if (p_node->p_left && p_node->p_right) {
        AVL_node_t *p_curr = p_node->p_right;
        while (1) {
            if (p_curr->p_left)
                p_curr = p_curr->p_left;
            else if (p_curr->p_right)
                p_curr = p_curr->p_right;
            else
                break;
        }
        p_curr->p_parent = p_parent;
        if (p_parent) {
            if (p_parent->p_left == p_node)
                p_parent->p_left = p_curr;
            else if (p_parent->p_right == p_node)
                p_parent->p_right = p_curr;
            else {
                // undefined
            }
        }
        p_node = p_curr;
    }
    else if (p_node->p_left && !p_node->p_right) {
        p_node->p_left->p_parent = p_parent;
        if (p_parent) {
            if (p_parent->p_left == p_node)
                p_parent->p_left = p_node->p_left;
            else if (p_parent->p_right == p_node)
                p_parent->p_right = p_node->p_left;
            else {
                // undefined
            }
        }
        p_node = p_node->p_left;
    }
    else if (!p_node->p_left && p_node->p_right) {
        p_node->p_right->p_parent = p_parent;
        if (p_parent) {
            if (p_parent->p_left == p_node)
                p_parent->p_left = p_node->p_right;
            else if (p_parent->p_right == p_node)
                p_parent->p_right = p_node->p_right;
            else {
                // undefined
            }
        }
        p_node = p_node->p_right;
    }
    else if (!p_node->p_left && !p_node->p_right) {
        if (p_parent) {
            if (p_parent->p_left == p_node)
                p_parent->p_left = NULL;
            else if (p_parent->p_right == p_node)
                p_parent->p_right = NULL;
            else {
                // undefined
            }
            p_node = p_parent;
        }
        else
            return NULL;
    }
    else {
        // undefined
    }

    return AVL_balance(p_node);
}

bool AVL_traversal_inoder(AVL_node_t *p_root) {
    if (!p_root) return false;
    
    AVL_node_t *p_node = p_root;
    AVL_node_t **p_node_adr = malloc(p_root->height * sizeof(AVL_node_t*));
    stack_t stack = {-1, p_root->height, p_node_adr};

    while (1) {
        if (p_node) {
            STACK_PUSH(U64, stack, (U64)p_node)
            p_node = p_node->p_left;
        }
        else if (STACK_IS_NOT_EMPTY(stack)) {
            p_node = (AVL_node_t*)STACK_POP(U64, stack);
            printf("%d ", p_node->key);

            if (abs(tree_cal_balance(p_node)) > 1) {
                printf("\n%d, unbalenced\n", p_node->key);
                while(1);
            }
            p_node = p_node->p_right;
        }
        else
            break;
    }
    printf("\n");

    free(p_node_adr);
    return true;
}

static inline S32 tree_cal_height(AVL_node_t *p_node) {
    return (p_node ? p_node->height : HEIGHT_OF_NULL_CHILD);
}

static inline S32 tree_cal_balance(AVL_node_t *p_node) {
    // if (!p_node) return INVALID_BALANCE;
    return tree_cal_height(p_node->p_left) - tree_cal_height(p_node->p_right);
}

static AVL_node_t *AVL_balance(AVL_node_t *p_node) {
    // if (!p_node) return NULL;

    S32 S32_balance;

    while (1) {
        // update height
        p_node->height = 1 + M_MAX(tree_cal_height(p_node->p_left), tree_cal_height(p_node->p_right));

        // check balence and rotate
        S32_balance = tree_cal_balance(p_node);
        if (S32_balance > 1) { // L type
            if (tree_cal_balance(p_node->p_left) < 1) // L-R type
                tree_rotate_left(p_node->p_left);
            tree_rotate_right(p_node);
            p_node = p_node->p_parent;
        }
        else if (S32_balance < -1) { // R type
            if (tree_cal_balance(p_node->p_right) > 1) // R-L type
                tree_rotate_right(p_node->p_right);
            tree_rotate_left(p_node);
            p_node = p_node->p_parent;
        }

        if (p_node->p_parent)
            p_node = p_node->p_parent;
        else
            break;
    }
    return p_node;
}

static inline bool tree_rotate_left(AVL_node_t *p_node) {
    // if (!p_node || !p_node->p_right) return false;
    AVL_node_t *p_child = p_node->p_right;
    if (p_node->p_parent) {
        if (p_node->p_parent->p_left == p_node)
            p_node->p_parent->p_left = p_child;
        else
            p_node->p_parent->p_right = p_child;
    }
    p_child->p_parent = p_node->p_parent;
    p_node->p_parent = p_child;
    p_node->p_right = p_child->p_left;
    if (p_child->p_left)
        p_child->p_left->p_parent = p_node;
    p_child->p_left = p_node;
    p_node->height = 1 + M_MAX(tree_cal_height(p_node->p_left), tree_cal_height(p_node->p_right));
    p_child->height = 1 + M_MAX(tree_cal_height(p_child->p_left), tree_cal_height(p_child->p_right));
    return true;
}

static inline bool tree_rotate_right(AVL_node_t *p_node) {
    // if (!p_node || !p_node->p_left) return false;
    AVL_node_t *p_child = p_node->p_left;
    if (p_node->p_parent) {
        if (p_node->p_parent->p_left == p_node)
            p_node->p_parent->p_left = p_child;
        else
            p_node->p_parent->p_right = p_child;
    }
    p_child->p_parent = p_node->p_parent;
    p_node->p_parent = p_child;
    p_node->p_left = p_child->p_right;
    if (p_child->p_right)
        p_child->p_right->p_parent = p_node;
    p_child->p_right = p_node;
    p_node->height = 1 + M_MAX(tree_cal_height(p_node->p_left), tree_cal_height(p_node->p_right));
    p_child->height = 1 + M_MAX(tree_cal_height(p_child->p_left), tree_cal_height(p_child->p_right));
    return true;
}
