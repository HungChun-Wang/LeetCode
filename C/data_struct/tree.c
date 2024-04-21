#include "common_def.h"
#include "stack.h"
#include "tree.h"

#define TREE_TEST_NODE_NUM  (10)

void tree_test() {
    tree_t tree_src = {0};
    tree_node_t tree_node_src[TREE_TEST_NODE_NUM];
    S32 tree_data_src[TREE_TEST_NODE_NUM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    tree_src.p_root = tree_node_src;
    
    while ((TREE_TEST_NODE_NUM - 1) >> tree_src.u32_depth)
        tree_src.u32_depth++;
    
    for (U32 i = 0; i < TREE_TEST_NODE_NUM; i++) {
        U32 u32_idx_left = (i << 1) + 1;
        U32 u32_idx_right = u32_idx_left + 1;
        tree_node_src[i].p_left = (u32_idx_left < TREE_TEST_NODE_NUM) ? &tree_node_src[u32_idx_left] : NULL;
        tree_node_src[i].p_right = (u32_idx_right < TREE_TEST_NODE_NUM) ? &tree_node_src[u32_idx_right] : NULL;    
        tree_node_src[i].p_data = &tree_data_src[i];
        tree_node_src[i].size = sizeof(tree_data_src[i]);
    }

    // tree_traversal_preorder(&tree_src);
    // tree_traversal_inorder(&tree_src);
    tree_traversal_postorder(&tree_src);
}

bool tree_traversal_preorder(tree_t *p_tree) {
    if (!p_tree) return false;
    if (!p_tree->p_root) return false;
    
    tree_node_t *p_node = p_tree->p_root;

    stack_t stack;
    tree_node_t **p_node_adr = malloc(p_tree->u32_depth * sizeof(tree_node_t*));
    stack_init(&stack, sizeof(void*), p_tree->u32_depth, (tree_node_t*)p_node_adr);

    while (1) {
        printf("%d ", *(S32*)p_node->p_data);
        
        if (p_node->p_right)
            stack_push(&stack, (tree_node_t*)&p_node->p_right);

        if (p_node->p_left)
            p_node = p_node->p_left;
        else if (!stack_pop(&stack, (tree_node_t*)&p_node))
            break;
    }

    free(p_node_adr);
    return true;
}

bool tree_traversal_inorder(tree_t *p_tree) {
    if (!p_tree) return false;
    if (!p_tree->p_root) return false;
    
    tree_node_t *p_node = p_tree->p_root;

    stack_t stack;
    tree_node_t **p_node_adr = malloc(p_tree->u32_depth * sizeof(tree_node_t*));
    stack_init(&stack, sizeof(void*), p_tree->u32_depth, (tree_node_t*)p_node_adr);

    while (1) {
        if (p_node) {
            stack_push(&stack, (tree_node_t*)&p_node);
            p_node = p_node->p_left;
        }
        else if (stack_pop(&stack, (tree_node_t*)&p_node)) {
            printf("%d ", *(S32*)p_node->p_data);
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
    U32 u32_stack_height = p_tree->u32_depth << 1;

    stack_t stack;
    tree_node_t **p_node_adr = malloc(u32_stack_height * sizeof(tree_node_t*));
    stack_init(&stack, sizeof(void*), u32_stack_height, (tree_node_t*)p_node_adr);

    do {
        while (p_node) {
            if (p_node->p_right)
                stack_push(&stack, (tree_node_t*)&p_node->p_right);
            stack_push(&stack, (tree_node_t*)&p_node);
            p_node = p_node->p_left;
        }

        stack_pop(&stack, (tree_node_t*)&p_node);
        stack_peek(&stack, (tree_node_t*)&p_node_top);

        if (p_node->p_right && (p_node->p_right == p_node_top)) {
            stack_pop(&stack, (tree_node_t*)&p_node_top);
            stack_push(&stack, (tree_node_t*)&p_node);
            p_node = p_node->p_right;
        }
        else {
            printf("%d ", *(S32*)p_node->p_data);
            p_node = NULL;
        }
    } while (!stack_is_empty(&stack));

    free(p_node_adr);
    return true;
}
