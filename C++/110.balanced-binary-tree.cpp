/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

#include <algorithm>

using namespace std;

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
    // recursion, time O(n), space(1)
    bool isBalanced(TreeNode* root) {
        bool is_balance = true;
        is_balanced_recur(root, is_balance);
        return is_balance;
    }
private:
    int is_balanced_recur(TreeNode* p_node, bool &is_balance) {
        if (!p_node) return 0;

        int l_hei_left = is_balanced_recur(p_node->left, is_balance);
        int l_hei_right = is_balanced_recur(p_node->right, is_balance);
        if (max(l_hei_left, l_hei_right) - min(l_hei_left, l_hei_right) > 1)
            is_balance = false;
        
        return max(l_hei_left, l_hei_right) + 1;
    }
};
// @lc code=end

