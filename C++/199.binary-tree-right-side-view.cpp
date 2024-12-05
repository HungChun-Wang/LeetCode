/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    // queue BFS, time O(n), space O(n/2)
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec_rst;

        if (!root) return vec_rst;

        int l_idx;
        int l_size_level;
        bool is_val_record;
        TreeNode *p_curr;
        queue<TreeNode*> queue_BFS;
        queue_BFS.push(root);

        while (!queue_BFS.empty()) {
            l_size_level = queue_BFS.size();
            is_val_record = false;
            for (l_idx = 0; l_idx < l_size_level; l_idx++) {
                p_curr = queue_BFS.front();
                queue_BFS.pop();

                if (!is_val_record) {
                    vec_rst.push_back(p_curr->val);
                    is_val_record = true;
                }
                if (p_curr->right) queue_BFS.push(p_curr->right);
                if (p_curr->left) queue_BFS.push(p_curr->left);
            }
        }
        return vec_rst;
    }
};
// @lc code=end

