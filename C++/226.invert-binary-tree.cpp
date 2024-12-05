/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 */

#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    // iteration, time O(n), space O(logn)
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode *p_curr;
        TreeNode *p_temp;
        stack<TreeNode *> stack_node;
        stack_node.push(root);

        while (!stack_node.empty()) {
            p_curr = stack_node.top();
            stack_node.pop();

            p_temp = p_curr->left;
            p_curr->left = p_curr->right;
            p_curr->right = p_temp;
            if (p_curr->left)
                stack_node.push(p_curr->left);
            if (p_curr->right)
                stack_node.push(p_curr->right);
        }
        return root;
    }

    // // recursion, time O(n), space O(logn)
    // TreeNode* invertTree(TreeNode* root) {
    //     if (!root) return nullptr;

    //     TreeNode *p_temp = root->left;
    //     root->left = root->right;
    //     root->right = p_temp;

    //     invertTree(root->left);
    //     invertTree(root->right);
    //     return root;
    // }
};
// @lc code=end

