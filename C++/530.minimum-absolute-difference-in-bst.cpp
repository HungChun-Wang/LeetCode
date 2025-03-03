/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 */

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

// DFS by recursion
// time O(n)
// space O(logn)
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        this->diff_min = INT_MAX;
        this->val_last;
        this->valid_last = false;
        getMinDiffRecur(root);
        return this->diff_min;
    }
private:
    void getMinDiffRecur(TreeNode *p_curr) {
        if (p_curr == nullptr) return;

        getMinDiffRecur(p_curr->left);

        int diff;

        if (valid_last) {
            if (this->val_last > p_curr->val)
                diff = this->val_last - p_curr->val;
            else
                diff = p_curr->val - this->val_last;
            
            if (diff < this->diff_min)
                this->diff_min = diff;
        }
        else
            valid_last = true;
        this->val_last = p_curr->val;

        getMinDiffRecur(p_curr->right);
    }
    
    int diff_min;
    int val_last;
    bool valid_last;
};
// @lc code=end

