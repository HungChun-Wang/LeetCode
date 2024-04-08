#include "common_def.h"
#include "data_struct/linked_list.h"

void sort_radix(S32 *p_arr, U32 n_size) {

}

typedef struct bucket_t {
    U32 n_num;
} bucket_t;

void sort_bucket(U32 *p_arr, U32 n_size, U32 n_val_max) {
    U32 *p_arr_bin = calloc(n_val_max >> 10, sizeof(U32));
    U32 i;

    for (i = 0; i < n_size; i++)
        p_arr_bin[p_arr[i] >> 10];
    
    free(p_arr_bin);
}

void sort_counting_stable(U32 *p_arr, U32 n_size, U32 n_val_max) {
    U32 *p_arr_cnt = calloc(n_val_max, sizeof(U32));
    U32 *p_arr_buf = calloc(n_size, sizeof(U32));
    U32 i, k;
    U32 n_base;

    for (i = 0; i < n_size; i++)
        p_arr_cnt[p_arr[i]]++;

    for (i = 1; i < n_val_max; i++)
        p_arr_cnt[i] += p_arr_cnt[i - 1];

    for (i = n_size - 1; i < n_size; i--)
        p_arr_buf[p_arr_cnt[p_arr[i]]--] = p_arr[i];

    memcpy(p_arr, p_arr_buf, sizeof(U32) * n_size);

    free(p_arr_cnt);
}

void sort_counting(U32 *p_arr, U32 n_size, U32 n_val_max) {
    U32 *p_arr_cnt = calloc(n_val_max, sizeof(S32));
    U32 i, k;
    U32 n_base;

    for (i = 0; i < n_size; i++)
        p_arr_cnt[p_arr[i]]++;

    i = 0;
    for (k = 0; k < n_val_max; k++) {
        n_base = i;
        for (; i < n_base + p_arr_cnt[k]; i++)
            p_arr[i] = k;
    }

    free(p_arr_cnt);
}

void sort_merge_list(list_S32_t *p_list, U32 n_size) {
    U32 n_size_seg;
    U32 n_step_cnt;
    U32 n_remain_node;
    listnode_S32_t dummy;
    listnode_S32_t *p_node_A;
    listnode_S32_t *p_node_B;
    listnode_S32_t *p_node_seg;
    listnode_S32_t *p_head_next_seg;
    listnode_S32_t *p_tail_last_seg;

    for (n_size_seg = 1; n_size_seg < n_size; n_size_seg <<= 1) {
        n_remain_node = n_size;
        p_head_next_seg = p_list->p_head;
        p_tail_last_seg = NULL;
        while (n_remain_node <= n_size) {
            dummy.p_next = p_head_next_seg;
            p_node_A = &dummy;
            p_node_B = &dummy;

            // find A tail and B tail
            n_step_cnt = n_size_seg;
            while (n_step_cnt) {
                if (p_node_A->p_next)
                    p_node_A = p_node_A->p_next;
                if (p_node_B->p_next)
                    p_node_B = p_node_B->p_next;
                if (p_node_B->p_next)
                    p_node_B = p_node_B->p_next;
                n_step_cnt--;
            }

            // set A head, B head. record head of next seg
            p_node_seg = p_head_next_seg;
            p_head_next_seg = p_node_B->p_next;
            p_node_B->p_next = NULL;
            p_node_B = p_node_A->p_next;
            p_node_A->p_next = NULL;
            p_node_A = p_node_seg;

            // merge A and B
            p_node_seg = &dummy;
            while (p_node_A && p_node_B) {
                if (p_node_A->n_val >= p_node_B->n_val) {
                    p_node_seg->p_next = p_node_B;
                    p_node_B = p_node_B->p_next;
                }
                else {
                    p_node_seg->p_next = p_node_A;
                    p_node_A = p_node_A->p_next;
                }
                p_node_seg = p_node_seg->p_next;
            }
            p_node_seg->p_next = p_node_A ? p_node_A : p_node_B;

            while (p_node_seg->p_next)
                p_node_seg = p_node_seg->p_next;

            p_node_seg->p_next = p_head_next_seg;

            if (p_tail_last_seg)
                p_tail_last_seg->p_next = dummy.p_next;

            if (n_remain_node == n_size)
                p_list->p_head = dummy.p_next;

            p_tail_last_seg = p_node_seg;

            n_remain_node -= (n_size_seg << 1);
        }
    }
}

void sort_merge(S32 *p_arr, U32 n_size) {
    U32 n_left, n_mid;
    U32 n_len_A, n_len_B;
    U32 n_size_seg, n_size_left;
    U32 i, j, k;
    S32 *p_arr_A;
    S32 *p_arr_B;

    // find max size of sub-array size
    for (i = 0; i < BIT_NUM_32; i++)
        if (!(n_size >> i))
            break;

    p_arr_A = calloc(BIT(i), sizeof(S32));
    p_arr_B = calloc(BIT(i), sizeof(S32));

    for (n_size_seg = 1; n_size_seg < n_size; n_size_seg <<= 1) {
        for (n_left = 0; n_left < n_size; n_left += n_len_A << 1) {
            n_mid = n_left + n_size_seg;

            // calculate length of sub-array
            if (n_mid + n_size_seg < n_size) {
                n_len_A = n_size_seg;
                n_len_B = n_size_seg;
            }
            else if (n_mid < n_size) {
                n_len_A = n_size_seg;
                n_len_B = n_size - n_mid;
            }
            else {
                n_len_A = n_size - n_left;
                n_len_B = 0;
            }

            // copy data to sub-array
            for (i = 0; i < n_len_B; i++) {
                p_arr_A[i] = p_arr[i + n_left];
                p_arr_B[i] = p_arr[i + n_mid];
            }
            for (; i < n_len_A; i++)
                p_arr_A[i] = p_arr[i + n_left];

            // merge sub-array
            i = n_left;
            j = 0;
            k = 0;
            while(j < n_len_A && k < n_len_B) {
                if (p_arr_A[j] <= p_arr_B[k])
                    p_arr[i++] = p_arr_A[j++];
                else
                    p_arr[i++] = p_arr_B[k++];
            }
            while (j < n_len_A)
                p_arr[i++] = p_arr_A[j++];
            while (k < n_len_B)
                p_arr[i++] = p_arr_B[k++];
        }
    }
    free(p_arr_A);
    free(p_arr_B);
}

void sort_quick(S32 *p_arr, U32 n_size) {
    U32 i, j;
    U32 n_left, n_right, n_pivot;
    U32 n_stack[n_size];
    U32 n_top = 0;
    S32 n_temp;

    n_stack[n_top++] = 0;           // even stack index as left
    n_stack[n_top++] = n_size - 1;  // odd stack index as right

    while (n_top > 0) {
        n_right = n_stack[--n_top];
        n_left = n_stack[--n_top];
        j = n_left;
        n_pivot = p_arr[n_left];

        for (i = n_left + 1; i <= n_right; i++) {
            if (p_arr[i] < n_pivot) {
                j++;
                M_SWAP(p_arr[i], p_arr[j], n_temp);
            }
        }
        M_SWAP(p_arr[j], p_arr[n_left], n_temp);

        if (j < n_right - 1) {
            n_stack[n_top++] = j + 1;
            n_stack[n_top++] = n_right;
        }
        if (j > n_left + 1) { // j - 1 > n_left, j - 1 may underflow
            n_stack[n_top++] = n_left;
            n_stack[n_top++] = j - 1;
        }
    }
}

void sort_shell(S32 *p_arr, U32 n_size) {
    U32 n_step, n_group;
    U32 i, j;
    S32 n_temp;

    for (n_step = n_size >> 1; n_step > 0; n_step >>= 1) {
        for (n_group = 0; n_group < n_step; n_group++) {
            for (i = n_step + n_group; i < n_size; i += n_step) {
                n_temp = p_arr[i];
                j = i - n_step;
                while ((j < n_size) && (p_arr[j] > n_temp)) {
                    p_arr[j + n_step] =  p_arr[j];
                    j -= n_step;
                }
                p_arr[j + n_step] = n_temp;
            }
        }
    }
}

void sort_shaker(S32 *p_arr, U32 n_size) {
    U32 i, j, n_temp;
    U32 n_round = 0;
    U32 n_left = 0;
    U32 n_right = n_size - 1;

    while (n_left < n_right) {
        for (i = n_left; i < n_right; i++)
            if (p_arr[i] > p_arr[i + 1])
                M_SWAP(p_arr[i], p_arr[i + 1], n_temp);
        n_right--;
        for (i = n_right; i > n_left; i--)
            if (p_arr[i] < p_arr[i - 1])
                M_SWAP(p_arr[i], p_arr[i - 1], n_temp);
        n_left++;
    }
}

void sort_insertion(S32 *p_arr, U32 n_size) {
    U32 i, j;
    S32 n_temp;
    
    for (i = 1; i < n_size; i++) {
        n_temp = p_arr[i];
        j = i - 1;
        while ((j < n_size) && (p_arr[j] > n_temp)) {
            p_arr[j + 1] = p_arr[j];
            j--;
        }
        p_arr[j + 1] = n_temp;
    }
}

void sort_selection(S32 *p_arr, U32 n_size) {
    U32 i, j, n_temp, n_min_idx;

    for (i = 0; i < n_size - 1; i++) {
        n_min_idx = i;
        for (j = i + 1; j < n_size; j++)
            if (p_arr[j] < p_arr[n_min_idx])
                n_min_idx = j;

        if (n_min_idx != i)
            M_SWAP(p_arr[i], p_arr[n_min_idx], n_temp);
    }
}

void sort_bubble(S32 *p_arr, U32 n_size) {
    U32 i, j;
    S32 n_temp;

    for (i = 0; i < n_size - 1; i++)
        for (j = 0; j < n_size - i - 1; j++)
            if (p_arr[j] > p_arr[j + 1])
                M_SWAP(p_arr[j] ,p_arr[j + 1], n_temp);
}

#define SORT_TEST_ROUND (1000)      // 1000

// #define SORT_TEST_LENGTH (1 << 10)   // 1 << 10
// #define SORT_VAL_LOWER  (0)
// #define SORT_VAL_UPPER  (10000)   // INT_MAX
#define SORT_TEST_LENGTH (11)
#define SORT_VAL_LOWER  (0)
#define SORT_VAL_UPPER  (100)

void sort_test_list() {
    srand(time(NULL));

    U32 i;
    U8 is_wrong = false;
    clock_t tic;
    U32 total_time;

    listnode_S32_t p_node[SORT_TEST_LENGTH];
    listnode_S32_t *p_curr;
    list_S32_t list = {0, p_node};

    for (U32 n_round = 0; n_round < SORT_TEST_ROUND; n_round++) {
        for (i = 0; i < SORT_TEST_LENGTH - 1; i++) {
            p_node[i].n_val = rand() % (SORT_VAL_UPPER - SORT_VAL_LOWER) + SORT_VAL_LOWER;
            p_node[i].p_next = &p_node[i + 1];
        }
        p_node[i].n_val = rand() % (SORT_VAL_UPPER - SORT_VAL_LOWER) + SORT_VAL_LOWER;
        p_node[i].p_next = NULL;

        tic = clock();
        sort_merge_list(&list, SORT_TEST_LENGTH);         // ~45 ms

        total_time += (U32)(clock() - tic);

        p_curr = list.p_head;
        while(p_curr && p_curr->p_next) {
            if (p_curr->n_val > p_curr->p_next->n_val)
                is_wrong = true;
            p_curr = p_curr->p_next;
        }

        if (is_wrong) {
            printf(" input: ");
            for (i = 0; i < SORT_TEST_LENGTH; i++)
                printf("%2d ", p_node[i].n_val);
            printf("\noutput: ");
            p_curr = list.p_head;
            while(p_curr) {
                printf("%2d ", p_curr->n_val);
                p_curr = p_curr->p_next;
            }
            printf("\n");
            break;
        }
    }
    printf("time: %d us\n", total_time);
}

void sort_test() {
    srand(time(NULL));

    U32 i;
    S32 p_arr[SORT_TEST_LENGTH];
    U32 p_arr_src[SORT_TEST_LENGTH];
    U32 p_arr_ref[SORT_TEST_LENGTH];
    U8 is_wrong = false;
    clock_t tic;
    U32 total_time;

    for (U32 n_round = 0; n_round < SORT_TEST_ROUND; n_round++) {
        for (i = 0; i < SORT_TEST_LENGTH; i++) {
            p_arr[i] = rand() % (SORT_VAL_UPPER - SORT_VAL_LOWER) + SORT_VAL_LOWER;
            p_arr_src[i] = p_arr[i];
            p_arr_ref[i] = p_arr[i];
        }

        tic = clock();
        // sort_merge(p_arr, SORT_TEST_LENGTH);         // ~45 ms
        sort_quick(p_arr, SORT_TEST_LENGTH);         // ~90 ms
        // sort_shell(p_arr, SORT_TEST_LENGTH);         // ~140 ms
        // sort_insertion(p_arr, SORT_TEST_LENGTH);     // ~570 ms
        // sort_selection(p_arr, SORT_TEST_LENGTH);     // ~1250 ms
        // sort_shaker(p_arr, SORT_TEST_LENGTH);        // ~1800 ms
        // sort_bubble(p_arr, SORT_TEST_LENGTH);        // ~1800 ms
        
        // value depended sorting
        // sort_counting(p_arr, SORT_TEST_LENGTH, SORT_VAL_UPPER);
        // sort_counting_stable(p_arr, SORT_TEST_LENGTH, SORT_VAL_UPPER);
        // sort_bucket(p_arr, SORT_TEST_LENGTH, SORT_VAL_UPPER);

        total_time += (U32)(clock() - tic);

        sort_merge(p_arr_ref, SORT_TEST_LENGTH);

        for (i = 0; i < SORT_TEST_LENGTH - 1; i++)
            if (p_arr[i] != p_arr_ref[i])
                is_wrong = true;

        if (is_wrong) {
            printf(" input: ");
            for (i = 0; i < SORT_TEST_LENGTH; i++)
                printf("%2d ", p_arr_src[i]);
            printf("\noutput: ");
            for (i = 0; i < SORT_TEST_LENGTH; i++)
                printf("%2d ", p_arr[i]);
            printf("\n   ref: ");
            for (i = 0; i < SORT_TEST_LENGTH; i++)
                printf("%2d ", p_arr_ref[i]);
            printf("\n");
            break;
        }
    }
    printf("time: %d us\n", total_time);
}