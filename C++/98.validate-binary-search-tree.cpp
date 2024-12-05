/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

#include <climits>
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

// iteration, time O(n), space O(logn)
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        stack<BST_judge> stack_BFS;
        stack_BFS.push({root, LONG_MIN, LONG_MAX});

        while (!stack_BFS.empty()) {
            auto [p_curr, l_min, l_max] = stack_BFS.top();
            stack_BFS.pop();

            if ((l_min >= p_curr->val) || (p_curr->val >= l_max))
                return false;
            if (p_curr->left) stack_BFS.push({p_curr->left, l_min, p_curr->val});
            if (p_curr->right) stack_BFS.push({p_curr->right, p_curr->val, l_max});
        }
        return true;
    }
private:
    struct BST_judge {
      TreeNode* p_curr;
      long l_min;
      long l_max;
    };

// // recursion, time O(n), space O(logn)
// public:
//     // recursion, time O(n), space O(logn)
//     bool isValidBST(TreeNode* root) {
//         return is_valid_BST_recur(root, LONG_MIN, LONG_MAX);
//     }
// private:
//     bool is_valid_BST_recur(TreeNode *p_curr, long l_min, long l_max) {
//         if (!p_curr) return true;
//         if ((l_min >= p_curr->val) || (p_curr->val >= l_max)) return false;
//         return is_valid_BST_recur(p_curr->left, l_min, p_curr->val) && is_valid_BST_recur(p_curr->right, p_curr->val, l_max);
//     }
};
// @lc code=end

