/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    // iteration, time O(n), time O(1)
    // int maxDepth(TreeNode* root) {
    //     if (!root) return 0;

    //     int l_max_depth = 0;
    //     stack<pair<TreeNode*, int>> stack_node;
    //     stack_node.push(pair<TreeNode*, int>(root, 1));
        
    //     while (!stack_node.empty()) {
    //         auto [p_curr, l_depth] = stack_node.top();
    //         stack_node.pop();

    //         l_max_depth = max(l_max_depth, l_depth);
    //         if (p_curr->left) stack_node.push(pair<TreeNode*, int>(p_curr->left, l_depth + 1));
    //         if (p_curr->right) stack_node.push(pair<TreeNode*, int>(p_curr->right, l_depth + 1));
    //     }
    //     return l_max_depth;
    // }

    // int diameterOfBinaryTree(TreeNode* root) {
    //     if (!root) return 0;
    //     int l_hei_left = maxDepth(root->left);
    //     int l_hei_right = maxDepth(root->right);
    //     return l_hei_left + l_hei_right;
    // }

    // recursion, time O(n), time O(1)
    int diameter_of_binary_tree_recur(TreeNode *p_node, int &l_dia_max) {
        if (!p_node) return 0;

        int l_hei_left = diameter_of_binary_tree_recur(p_node->left, l_dia_max);
        int l_hei_right = diameter_of_binary_tree_recur(p_node->right, l_dia_max);
        l_dia_max = max(l_dia_max, l_hei_left + l_hei_right);

        return 1 + max(l_hei_left, l_hei_right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int l_dia_max = 0;
        diameter_of_binary_tree_recur(root, l_dia_max);
        return l_dia_max;
    }
};
// @lc code=end

