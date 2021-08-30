/*
 * @lc app=leetcode id=563 lang=c
 *
 * [563] Binary Tree Tilt
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int findTilt(struct TreeNode* root){
    if( !root ) return 0;

    int n_tilt = 0;
    int n_sum;

    tilt_and_sum( root, &n_tilt, &n_sum );

    return n_tilt;
}

void tilt_and_sum( struct TreeNode *p_node, int *p_tilt, int *p_sum )
{
    if( !p_node ) return;

    int n_left_sum = 0;
    int n_right_sum = 0;

    tilt_and_sum( p_node->left, p_tilt, &n_left_sum );
    tilt_and_sum( p_node->right, p_tilt, &n_right_sum );

    n_left_sum += p_node->left ? p_node->left->val : 0;
    n_right_sum += p_node->right ? p_node->right->val : 0;
    *p_sum = n_left_sum + n_right_sum;
    *p_tilt += abs( n_left_sum - n_right_sum );
}
// @lc code=end

