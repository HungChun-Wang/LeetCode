#include "common_def.h"
#include "math_op.h"
#include "stack.h"
#include "tree.h"

#define HEAP_TEST_ROUND     (10000)
#define HEAP_TEST_NODE_NUM  (10)
#define HEAP_TEST_VAL_UPPER (100)

void heap_test() {
    U8 is_wrong;
    U32 i, j, k;
    S32 arr_src[HEAP_TEST_NODE_NUM];
    S32 arr_dst[HEAP_TEST_NODE_NUM];
    heap_t heap_dst = {arr_dst, 0, HEAP_TEST_NODE_NUM, 0};

    srand(time(NULL));
    for (k = 0; k < HEAP_TEST_ROUND; k++) {
        is_wrong = false;
        for (i = 0; i < HEAP_TEST_NODE_NUM; i++) {
            arr_src[i] = rand() % HEAP_TEST_VAL_UPPER;
            max_heap_insert(&heap_dst, arr_src[i]);
        }

        for (i = 0; i < rand() % HEAP_TEST_NODE_NUM; i++) {
            max_heap_delete(&heap_dst, rand() % (HEAP_TEST_NODE_NUM - i));
            // max_heap_extract(&heap_dst);
        }

        for (i = 0; i < heap_dst.u32_size; i++) {
            U32 u32_left = (i << 1) + 1;
            U32 u32_right = (i << 1) + 2;
            if ((u32_left < heap_dst.u32_size && arr_dst[i] < arr_dst[u32_left])
                || (u32_right < heap_dst.u32_size && arr_dst[i] < arr_dst[u32_right]))
                is_wrong = true;
        }

        if (is_wrong) {
            printf("insert/delete wrong, src:\n");
            for (i = 0, j = 0; i < heap_dst.u32_size; i++) {
                printf("%d ", arr_src[j++]);
                if (M_IS_POW2(j + 1))
                    printf("\n");
            }
            printf("\ndst:\n");
            for (i = 0, j = 0; i < heap_dst.u32_size; i++) {
                printf("%d ", heap_dst.ps32_arr[j++]);
                if (M_IS_POW2(j + 1))
                    printf("\n");
            }
            printf("\n");
            break;
        }

        heap_dst = (heap_t){arr_dst, HEAP_TEST_NODE_NUM, HEAP_TEST_NODE_NUM, log_ceil(HEAP_TEST_NODE_NUM)};

        for (i = 0; i < HEAP_TEST_NODE_NUM; i++)
            arr_dst[i] = arr_src[i];

        heapify_max(&heap_dst);

        for (i = 0; i < heap_dst.u32_size; i++) {
            U32 u32_left = (i << 1) + 1;
            U32 u32_right = (i << 1) + 2;
            if ((u32_left < heap_dst.u32_size && arr_dst[i] < arr_dst[u32_left])
                || (u32_right < heap_dst.u32_size && arr_dst[i] < arr_dst[u32_right]))
                is_wrong = true;
        }

        if (is_wrong) {
            printf("heapify wrong, src:\n");
            for (i = 0, j = 0; i < heap_dst.u32_size; i++) {
                printf("%d ", arr_src[j++]);
                if (M_IS_POW2(j + 1))
                    printf("\n");
            }
            printf("\ndst:\n");
            for (i = 0, j = 0; i < heap_dst.u32_size; i++) {
                printf("%d ", heap_dst.ps32_arr[j++]);
                if (M_IS_POW2(j + 1))
                    printf("\n");
            }
            printf("\n");
            break;
        }
    }
}

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
        tree_node_src[i].p_data = &tree_data_src[i];
        tree_node_src[i].unit = sizeof(tree_data_src[i]);
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

bool heapify_max(heap_t *p_heap) {
    if (!p_heap || !p_heap->ps32_arr) return false;

    for (U32 i = (p_heap->u32_size - 1) >> 1; i != __UINT32_MAX__; i--)
        heapify_forward_max(p_heap, i);

    return true;
}

bool max_heap_insert(heap_t *p_heap, S32 s32_val) {
    if (!p_heap || !p_heap->ps32_arr) return false;
    if (p_heap->u32_size == p_heap->u32_size_max) return false;

    if (M_IS_POW2(p_heap->u32_size))
        p_heap->u32_depth++;
    p_heap->ps32_arr[p_heap->u32_size++] = s32_val;
    
    heapify_backward_max(p_heap, p_heap->u32_size - 1);
    return true;
}

S32 max_heap_delete(heap_t *p_heap, U32 u32_idx) {
    if (!p_heap || !p_heap->ps32_arr) return false;
    if (u32_idx >= p_heap->u32_size) return false;

    U32 i = u32_idx;
    U32 u32_mid = (u32_idx - 1) >> 1;
    S32 s32_val = p_heap->ps32_arr[u32_idx];
    p_heap->ps32_arr[u32_idx] = p_heap->ps32_arr[--p_heap->u32_size];

    if (M_IS_POW2(p_heap->u32_size))
        p_heap->u32_depth--;

    if ((u32_mid < p_heap->u32_size) && (p_heap->ps32_arr[u32_idx] > p_heap->ps32_arr[u32_mid]))
        heapify_backward_max(p_heap, u32_idx);
    else
        heapify_forward_max(p_heap, u32_idx);

    return s32_val;
}

S32 max_heap_extract(heap_t *p_heap) {
    if (!p_heap || !p_heap->ps32_arr || !p_heap->u32_size) return INVALID_VAL;

    S32 s32_val = p_heap->ps32_arr[0];
    p_heap->ps32_arr[0] = p_heap->ps32_arr[--p_heap->u32_size];

    if (M_IS_POW2(p_heap->u32_size))
        p_heap->u32_depth--;

    heapify_forward_max(p_heap, 0);

    return s32_val;
}

static bool heapify_forward_max(heap_t *p_heap, U32 u32_idx) {
    if (!p_heap || !p_heap->ps32_arr) return false;
    if (u32_idx >= p_heap->u32_size) return false;

    U32 u32_left;
    U32 u32_right;
    S32 s32_buffer;
    U32 i = u32_idx;
    U32 u32_large = i;

    while (1) {
        u32_left = (i << 1) + 1;
        u32_right = u32_left + 1;

        if ((u32_left < p_heap->u32_size) && (p_heap->ps32_arr[u32_large] < p_heap->ps32_arr[u32_left]))
            u32_large = u32_left;
        if ((u32_right < p_heap->u32_size) && (p_heap->ps32_arr[u32_large] < p_heap->ps32_arr[u32_right]))
            u32_large = u32_right;
        if (i != u32_large) {
            M_SWAP(p_heap->ps32_arr[i], p_heap->ps32_arr[u32_large], s32_buffer)
            i = u32_large;
        }
        else
            break;
    }
    return true;
}

static bool heapify_backward_max(heap_t *p_heap, U32 u32_idx) {
    if (!p_heap || !p_heap->ps32_arr) return false;
    if (u32_idx >= p_heap->u32_size) return false;

    S32 s32_temp;
    U32 i = u32_idx;
    U32 u32_mid = (i - 1) >> 1;

    while (u32_mid < p_heap->u32_size) {
        if (p_heap->ps32_arr[i] > p_heap->ps32_arr[u32_mid]) {
            M_SWAP(p_heap->ps32_arr[i], p_heap->ps32_arr[u32_mid], s32_temp)
            i = u32_mid;
            u32_mid = (i - 1) >> 1;
        }
        else
            break;
    }
}
