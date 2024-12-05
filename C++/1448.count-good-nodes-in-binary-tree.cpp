/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
 */

#include <climits>

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // recursion, time O(n), space O(logn)
    void good_node_recur(TreeNode* p_curr, int l_val_max, int &l_num_good_node) {
        if (!p_curr) return;

        if (p_curr->val >= l_val_max) {
            l_val_max = p_curr->val;
            l_num_good_node++;
        }
        good_node_recur(p_curr->left, l_val_max, l_num_good_node);
        good_node_recur(p_curr->right, l_val_max, l_num_good_node);
    }

    int goodNodes(TreeNode* root) {
        int l_val_max = INT_MIN;
        int l_num_good_node = 0;
        good_node_recur(root, l_val_max, l_num_good_node);
        return l_num_good_node;
    }
};
// @lc code=end

