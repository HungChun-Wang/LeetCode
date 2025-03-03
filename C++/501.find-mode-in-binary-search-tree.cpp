/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 */

#include <stack>
#include <vector>
#include <unordered_map>
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
    // BFS
    // time O(n)
    // space O(logn + t), v = value type
    vector<int> findMode(TreeNode* root) {
        int freq_max = 0;
        unordered_map<int, int> umap_freq;
        vector<int> rst;
        TreeNode *p_node;
        stack<TreeNode*> stk;
        stk.push(root);

        while (stk.size()) {
            p_node = stk.top(); stk.pop();
            if (p_node->left) stk.push(p_node->left);
            if (p_node->right) stk.push(p_node->right);

            umap_freq[p_node->val]++;
            freq_max = max(umap_freq[p_node->val], freq_max);
        }

        for (auto it_map : umap_freq)
            if (it_map.second == freq_max)
                rst.push_back(it_map.first);
        return rst;
    }

};
// @lc code=end

