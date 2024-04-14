#pragma once

#define SORT_PERFORMANCE_EN (TRUE)

#define SORT_TEST_ROUND (1000)

#if SORT_PERFORMANCE_EN
#define SORT_TEST_LENGTH    (1 << 10)   // 1 << 10
#define SORT_VAL_LOWER      (0)
#define SORT_VAL_UPPER      (10000)   // INT_MAX
#else
#define SORT_TEST_LENGTH    (11)
#define SORT_VAL_LOWER      (0)
#define SORT_VAL_UPPER      (100)
#endif

void sort_radix(S32 *p_arr, U32 n_size);

void sort_bucket(U32 *p_arr, U32 n_size, U32 n_val_max, U32 n_num_bucket);

void sort_counting_stable(U32 *p_arr, U32 n_size, U32 n_val_max);

void sort_counting(U32 *p_arr, U32 n_size, U32 n_val_max);

listnode_S32_t* sort_merge_list(listnode_S32_t *p_head, U32 n_len);

listnode_S32_t* sort_insertion_list(listnode_S32_t *p_head);

void sort_merge(S32 *p_arr, U32 n_size);

void sort_quick(S32 *p_arr, U32 n_size);

void sort_shell(S32 *p_arr, U32 n_size);

void sort_shaker(S32 *p_arr, U32 n_size);

void sort_insertion(S32 *p_arr, U32 n_size);

void sort_selection(S32 *p_arr, U32 n_size);

void sort_bubble(S32 *p_arr, U32 n_size);
