/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // iteration, time O(n), space O(1)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *p_curr = root;

        while (p_curr) {
            if ((p_curr->val > p->val) && (p_curr->val > q->val))
                p_curr = p_curr->left;
            else if ((p_curr->val < p->val) && (p_curr->val < q->val))
                p_curr = p_curr->right;
            else
                break;
        }
        return p_curr;
    }
};
// @lc code=end

