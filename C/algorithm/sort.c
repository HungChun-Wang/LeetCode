#include "common_def.h"
#include "data_struct/linked_list.h"
#include "sort.h"

void sort_test_list_input() {
    U32 i;
    listnode_S32_t p_node_src[SORT_TEST_LENGTH];
    listnode_S32_t *p_iter_src;
    listnode_S32_t *p_head_src;
    S32 p_arr[SORT_TEST_LENGTH] = {17, 78, 35, 34, 30, 63, 1, 12, 86, 38, 32};

    for (i = 0; i < SORT_TEST_LENGTH - 1; i++) {
        p_node_src[i].n_val = p_arr[i];
        p_node_src[i].p_next = &p_node_src[i + 1];
    }
    p_node_src[i].n_val = p_arr[i];
    p_node_src[i].p_next = NULL;

    p_head_src = sort_merge_list(p_node_src, SORT_TEST_LENGTH);

    printf(" in: ");
    for (i = 0; i < SORT_TEST_LENGTH; i++)
        printf("%2d ", p_node_src[i].n_val);
    printf("\nout: ");
    p_iter_src = p_head_src;
    while(p_iter_src) {
        printf("%2d ", p_iter_src->n_val);
        p_iter_src = p_iter_src->p_next;
    }
    printf("\n");
}

void sort_test_list() {
    srand(time(NULL));

    U32 i;
    U8 is_wrong = false;
    clock_t tic;
    U32 total_time = 0;

    listnode_S32_t p_node_src[SORT_TEST_LENGTH];
    listnode_S32_t p_node_dst[SORT_TEST_LENGTH];
    listnode_S32_t *p_iter_src, *p_head_src;
    listnode_S32_t *p_iter_dst, *p_head_dst;

    for (U32 n_round = 0; n_round < SORT_TEST_ROUND; n_round++) {
        for (i = 0; i < SORT_TEST_LENGTH - 1; i++) {
            p_node_src[i].n_val = rand() % (SORT_VAL_UPPER - SORT_VAL_LOWER) + SORT_VAL_LOWER;
            p_node_src[i].p_next = &p_node_src[i + 1];
            p_node_dst[i].n_val = p_node_src[i].n_val;
            p_node_dst[i].p_next = &p_node_dst[i + 1];
        }
        p_node_src[i].n_val = rand() % (SORT_VAL_UPPER - SORT_VAL_LOWER) + SORT_VAL_LOWER;
        p_node_src[i].p_next = NULL;
        p_node_dst[i].n_val = p_node_src[i].n_val;
        p_node_dst[i].p_next = NULL;

        tic = clock();

        p_head_src = sort_insertion_list(p_node_src);

        total_time += (U32)(clock() - tic);

        p_head_dst = sort_merge_list(p_node_dst, SORT_TEST_LENGTH);

        p_iter_src = p_head_src;
        p_iter_dst = p_head_dst;
        while(p_iter_src && p_iter_dst) {
            if (p_iter_src->n_val != p_iter_dst->n_val) {
                is_wrong = true;
                break;
            }
            p_iter_src = p_iter_src->p_next;
            p_iter_dst = p_iter_dst->p_next;
        }

        if (is_wrong) {
            printf(" in: ");
            for (i = 0; i < SORT_TEST_LENGTH; i++)
                printf("%2d ", p_node_src[i].n_val);
            printf("\nout: ");
            p_iter_src = p_head_src;
            while(p_iter_src) {
                printf("%2d ", p_iter_src->n_val);
                p_iter_src = p_iter_src->p_next;
            }
            printf("\nref: ");
            p_iter_dst = p_head_dst;
            while(p_iter_dst) {
                printf("%2d ", p_iter_dst->n_val);
                p_iter_dst = p_iter_dst->p_next;
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
    U32 total_time = 0;

    for (U32 n_round = 0; n_round < SORT_TEST_ROUND; n_round++) {
        for (i = 0; i < SORT_TEST_LENGTH; i++) {
            p_arr[i] = rand() % (SORT_VAL_UPPER - SORT_VAL_LOWER) + SORT_VAL_LOWER;
            p_arr_src[i] = p_arr[i];
            p_arr_ref[i] = p_arr[i];
        }

        tic = clock();
        // sort_merge(p_arr, SORT_TEST_LENGTH);         // ~45 ms
        // sort_quick(p_arr, SORT_TEST_LENGTH);         // ~90 ms
        // sort_shell(p_arr, SORT_TEST_LENGTH);         // ~140 ms
        // sort_insertion(p_arr, SORT_TEST_LENGTH);     // ~570 ms
        // sort_selection(p_arr, SORT_TEST_LENGTH);     // ~1250 ms
        // sort_shaker(p_arr, SORT_TEST_LENGTH);        // ~1800 ms
        // sort_bubble(p_arr, SORT_TEST_LENGTH);        // ~1800 ms
        
        // value depended sorting
        // sort_counting(p_arr, SORT_TEST_LENGTH, SORT_VAL_UPPER);
        // sort_counting_stable(p_arr, SORT_TEST_LENGTH, SORT_VAL_UPPER);
        // sort_bucket(p_arr, SORT_TEST_LENGTH, SORT_VAL_UPPER, 100);
        sort_radix(p_arr, SORT_TEST_LENGTH);

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

void sort_radix(S32 *p_arr, U32 n_size) {
    if (!p_arr) return;
    
    U8 is_empty = false;
    U32 i, k;
    U32 n_digit = 0;
    U32 n_radix = 16;
    U32 n_mask = n_radix - 1;
    U32 n_val_shift;
    list_S32_t *p_bins = calloc(n_radix, sizeof(list_S32_t));
    list_S32_t *p_bin;
    listnode_S32_t *p_node;

    while (!is_empty && n_digit < 8) {
        is_empty = true;
        
        for (i = 0; i < n_size; i++) {
            n_val_shift = p_arr[i] >> (n_digit << 2);
            p_bin = &p_bins[n_val_shift & n_mask];
            p_node = malloc(sizeof(listnode_S32_t));
            p_node->n_val = p_arr[i];
            p_node->p_next = p_bin->p_head;
            p_bin->p_head = p_node;
            
            if (n_val_shift >= n_radix)
                is_empty = false;
        }

        i = n_size;
        for (k = n_radix - 1; k < n_radix; k--) {
            p_bin = &p_bins[k];
            while (p_bin->p_head) {
                p_arr[--i] = p_bin->p_head->n_val;
                p_node = p_bin->p_head->p_next;
                free(p_bin->p_head);
                p_bin->p_head = p_node;
            }
        }
        n_digit++;
    }
}

void sort_bucket(U32 *p_arr, U32 n_size, U32 n_val_max, U32 n_num_bucket) {
    if (!p_arr) return;
    
    U32 i, k;
    list_S32_t *p_buckets = calloc(n_num_bucket, sizeof(list_S32_t));
    list_S32_t *p_bucket;
    listnode_S32_t *p_node;
    U32 n_interval = n_val_max / n_num_bucket + 1;

    for (i = 0; i < n_size; i++) {
        p_bucket = &p_buckets[p_arr[i] / n_interval];
        p_node = malloc(sizeof(listnode_S32_t));
        p_node->n_val = p_arr[i];
        p_node->p_next = p_bucket->p_head;
        p_bucket->p_head = p_node;
        p_bucket->n_len++;
    }
    
    i = 0;
    for (k = 0; k < n_num_bucket; k++) {
        p_bucket = &p_buckets[k];
        p_bucket->p_head = sort_insertion_list(p_bucket->p_head);
        while (p_bucket->p_head) {
            p_arr[i++] = p_bucket->p_head->n_val;
            p_node = p_bucket->p_head->p_next;
            free(p_bucket->p_head);
            p_bucket->p_head = p_node;
        }
    }

    free(p_buckets);
}

void sort_counting_stable(U32 *p_arr, U32 n_size, U32 n_val_max) {
    if (!p_arr) return;
    
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
    free(p_arr_buf);
}

void sort_counting(U32 *p_arr, U32 n_size, U32 n_val_max) {
    if (!p_arr) return;
    
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

listnode_S32_t* sort_merge_list(listnode_S32_t *p_head, U32 n_len) {
    if (!p_head) return p_head;
    
    U32 n_size_seg;
    U32 n_step_cnt;
    U32 n_remain_node;
    listnode_S32_t dummy;
    listnode_S32_t *p_node_A;
    listnode_S32_t *p_node_B;
    listnode_S32_t *p_node_seg;
    listnode_S32_t *p_head_next_seg;
    listnode_S32_t *p_tail_last_seg;

    for (n_size_seg = 1; n_size_seg < n_len; n_size_seg <<= 1) {
        n_remain_node = n_len;
        p_head_next_seg = p_head;
        p_tail_last_seg = NULL;
        while (n_remain_node <= n_len) {
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

            if (n_remain_node == n_len)
                p_head = dummy.p_next;

            p_tail_last_seg = p_node_seg;

            n_remain_node -= (n_size_seg << 1);
        }
    }
    return p_head;
}

listnode_S32_t* sort_insertion_list(listnode_S32_t *p_head) {
    if (!p_head) return p_head;

    U8 is_wap;
    listnode_S32_t dummy = {0, p_head};
    listnode_S32_t *p_curr = dummy.p_next;
    listnode_S32_t *p_next = dummy.p_next;
    listnode_S32_t *p_back;

    while (p_curr->p_next != NULL) {
        p_back = &dummy;
        is_wap = false;
        while (p_back != p_curr) {
            if (p_curr->p_next->n_val < p_back->p_next->n_val) {
                p_next = p_curr->p_next->p_next;
                p_curr->p_next->p_next = p_back->p_next;
                p_back->p_next = p_curr->p_next;
                p_curr->p_next = p_next;
                is_wap = true;
                break;
            }
            p_back = p_back->p_next;
        }
        if (!is_wap) {
            p_curr = p_curr->p_next;
        }
    }
    return dummy.p_next;
}

void sort_merge(S32 *p_arr, U32 n_size) {
    if (!p_arr) return;

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
    if (!p_arr) return;
    
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
    if (!p_arr) return;
    
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
    if (!p_arr) return;
    
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
    if (!p_arr) return;
    
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
    if (!p_arr) return;
    
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
    if (!p_arr) return;
    
    U32 i, j;
    S32 n_temp;

    for (i = 0; i < n_size - 1; i++)
        for (j = 0; j < n_size - i - 1; j++)
            if (p_arr[j] > p_arr[j + 1])
                M_SWAP(p_arr[j] ,p_arr[j + 1], n_temp);
}
