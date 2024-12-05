/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
public:
    // iteration, time O(n), space O(1)
    bool isSameTree(TreeNode* p, TreeNode* q) {        
        TreeNode *p_curr_p;
        TreeNode *p_curr_q;
        stack<TreeNode*> stack_node_p;
        stack<TreeNode*> stack_node_q;
        stack_node_p.push(p);
        stack_node_q.push(q);

        while (!stack_node_p.empty()) {
            p_curr_p = stack_node_p.top();
            p_curr_q = stack_node_q.top();
            stack_node_p.pop();
            stack_node_q.pop();

            if (!p_curr_p && !p_curr_q)
                break;
            if (!p_curr_p || !p_curr_q)
                return false;
            if (p_curr_p->val != p_curr_q->val)
                return false;
            if (p_curr_p->right || p_curr_q->right) {
                stack_node_p.push(p_curr_p->right);
                stack_node_q.push(p_curr_q->right);
            }
            if (p_curr_p->left || p_curr_q->left) {
                stack_node_p.push(p_curr_p->left);
                stack_node_q.push(p_curr_q->left);
            }
        }
        return true;
    }

    // // recursion, time O(n), space O(1)
    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     if (!p && !q) return true;
    //     if (!p || !q) return false;
    //     if (p->val != q->val) return false;
    //     return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    // }
};
// @lc code=end

