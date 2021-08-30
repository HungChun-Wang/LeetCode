/*
 * @lc app=leetcode id=226 lang=c
 *
 * [226] Invert Binary Tree
 */

#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    if( root == NULL ) return root;

    invertTree( root->left );
    invertTree( root->right );

    struct TreeNode *p_temp;
    p_temp = root->left;
    root->left = root->right;
    root->right = p_temp;

    return root;
}
// @lc code=end

