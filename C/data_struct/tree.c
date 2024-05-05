#include "common_def.h"
#include "math_op.h"
#include "stack.h"
#include "tree.h"

#define TREE_TEST_NODE_NUM  (10)

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
        tree_node_src[i].s32_val = tree_data_src[i];
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
        printf("%d ", p_node->s32_val);
        
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
            printf("%d ", p_node->s32_val);
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
            printf("%d ", p_node->s32_val);
            p_node = NULL;
        }
    } while (STACK_IS_NOT_EMPTY(stack));

    free(p_node_adr);
    return true;
}
