#include "common_def.h"

void sort_radix(S32 *p_arr, U32 n_size) {

}

void sort_bucket(U32 *p_arr, U32 n_size, U32 n_val_max) {

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

void sort_merge(S32 *p_arr, U32 n_size) {
    U32 n_left, n_mid, n_right;
    U32 n_size_seg, n_size_left;
    U32 i, j, k;
    S32 p_arr_A[(n_size >> 1)];
    S32 p_arr_B[(n_size >> 1)];

    for (n_size_seg = 1; n_size_seg < n_size; n_size_seg <<= 1) {
        for (n_left = 0; n_left < n_size - n_size_seg; n_left += n_size_seg << 1) {
            n_mid = n_left + n_size_seg;
            n_right = n_mid + n_size_seg;

            if (n_right >= n_size)
                n_right = n_size - 1; 

            for (i = 0; i < n_size_seg; i++) {
                p_arr_A[i] = p_arr[i + n_left];
                p_arr_A[i] = p_arr[i + n_mid];
            }
            j = 0;
            k = 0;
            for (i = 0; i < n_size_seg << 1; i++) {
                if (p_arr_A[j] <= p_arr_B[k])
                    p_arr[n_left + i] = p_arr_A[j++];
                else
                    p_arr[n_left + i] = p_arr_B[k++];
            }

        }
    }
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
                M_SWAP(p_arr[i], p_arr[j], n_temp);
                j++;
            }
        }
        p_arr[j] = n_pivot;

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

#define SORT_ARR_LENGTH (1 << 10)   // 1 << 10
#define SORT_VAL_LOWER  (0)
#define SORT_VAL_UPPER  (10000)   // INT_MAX
// #define SORT_ARR_LENGTH (11)
// #define SORT_VAL_LOWER  (0)
// #define SORT_VAL_UPPER  (100)

void sort_test() {
    srand(time(NULL));

    U32 i;
    S32 p_arr[SORT_ARR_LENGTH];
    U32 p_arr_src[SORT_ARR_LENGTH];
    U8 is_wrong = false;
    clock_t tic;
    U32 total_time;

    for (U32 n_round = 0; n_round < SORT_TEST_ROUND; n_round++) {
        for (i = 0; i < SORT_ARR_LENGTH; i++) {
            p_arr[i] = rand() % (SORT_VAL_UPPER - SORT_VAL_LOWER) + SORT_VAL_LOWER;
            p_arr_src[i] = p_arr[i];
        }

        tic = clock();
        // sort_merge(p_arr, SORT_ARR_LENGTH);         // ~45 ms
        // sort_quick(p_arr, SORT_ARR_LENGTH);         // ~90 ms
        // sort_shell(p_arr, SORT_ARR_LENGTH);         // ~140 ms
        // sort_insertion(p_arr, SORT_ARR_LENGTH);     // ~570 ms
        // sort_selection(p_arr, SORT_ARR_LENGTH);     // ~1250 ms
        // sort_shaker(p_arr, SORT_ARR_LENGTH);        // ~1800 ms
        // sort_bubble(p_arr, SORT_ARR_LENGTH);        // ~1800 ms
        
        // value depended sorting
        // sort_counting(p_arr, SORT_ARR_LENGTH, SORT_VAL_UPPER);
        // sort_counting_stable(p_arr, SORT_ARR_LENGTH, SORT_VAL_UPPER);
        sort_bucket(p_arr, SORT_ARR_LENGTH, SORT_VAL_UPPER);

        total_time += (U32)(clock() - tic);

        for (i = 0; i < SORT_ARR_LENGTH - 1; i++)
            if (p_arr[i] > p_arr[i + 1])
                is_wrong = true;

        if (is_wrong) {
            printf(" input: ");
            for (i = 0; i < SORT_ARR_LENGTH; i++)
                printf("%2d ", p_arr_src[i]);
            printf("\noutput: ");
            for (i = 0; i < SORT_ARR_LENGTH; i++)
                printf("%2d ", p_arr[i]);
            printf("\n");
            break;
        }
    }
    printf("time: %d us\n", total_time);
}