/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

#include <vector>
#include <queue>

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
    // queue WFS, time O(n), space O(n/2)
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec2d_all_level;
        if (!root) return vec2d_all_level;
        
        int idx;
        int l_size;
        TreeNode *p_curr;
        queue<TreeNode*> queue_BFS;
        queue_BFS.push(root);

        vector<int> vec_single_level;

        while (!queue_BFS.empty()) {
            l_size = queue_BFS.size();
            for (idx = 0; idx < l_size; idx++) {
                p_curr = queue_BFS.front();
                queue_BFS.pop();
                if (p_curr->left) queue_BFS.push(p_curr->left);
                if (p_curr->right) queue_BFS.push(p_curr->right);
                vec_single_level.push_back(p_curr->val);
            }
            vec2d_all_level.push_back(vec_single_level);
            vec_single_level.clear();
        }
        return vec2d_all_level;
    }
};
// @lc code=end

