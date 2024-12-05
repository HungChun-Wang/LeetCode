/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */

#include <stack>
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
    // iteration, time O(n), space O(logn)
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int l_max_depth = 0;
        stack<pair<TreeNode*, int>> stack_node;
        stack_node.push(pair<TreeNode*, int>(root, 1));
        
        while (!stack_node.empty()) {
            auto [p_curr, l_depth] = stack_node.top();
            stack_node.pop();

            l_max_depth = max(l_max_depth, l_depth);
            if (p_curr->left) stack_node.push(pair<TreeNode*, int>(p_curr->left, l_depth + 1));
            if (p_curr->right) stack_node.push(pair<TreeNode*, int>(p_curr->right, l_depth + 1));
        }
        return l_max_depth;
    }

    // // recursion, time O(n), space O(logn)
    // int maxDepth(TreeNode* root) {
    //     if (!root) return 0;

    //     int l_depth_left = maxDepth(root->left);
    //     int l_depth_right = maxDepth(root->right);

    //     return 1 + max(l_depth_left, l_depth_right);
    // }
};
// @lc code=end

