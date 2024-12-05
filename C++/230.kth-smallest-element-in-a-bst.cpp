/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
class Solution {

// iterative in-order traversal, time O(n), space(O(logn))
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stack_DFS;
        TreeNode* p_curr = root;
        int l_cnt = 0;

        while (p_curr || !stack_DFS.empty()) {
            if (p_curr) {
                stack_DFS.push(p_curr);
                p_curr = p_curr->left;
            }
            else {
                p_curr = stack_DFS.top();
                stack_DFS.pop();
                if (++l_cnt == k)
                    return p_curr->val;
                p_curr = p_curr->right;
            }
        }
        return -1;
    }

// // recursive in-order traversal, time O(n), space(O(logn))
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         int l_val;
//         int l_cnt = 0;
//         kth_smallest_recur(root, k, l_cnt, l_val);
//         return l_val;
//     }
// private:
//     void kth_smallest_recur(TreeNode *p_curr, int k, int& l_cnt, int& l_val) {
//         if (!p_curr) return;

//         if (p_curr->left) kth_smallest_recur(p_curr->left, k, l_cnt, l_val);
//         if (++l_cnt == k) {
//             l_val = p_curr->val;
//             return;
//         }
//         if (p_curr->right) kth_smallest_recur(p_curr->right, k, l_cnt, l_val);
//     }
};
// @lc code=end

