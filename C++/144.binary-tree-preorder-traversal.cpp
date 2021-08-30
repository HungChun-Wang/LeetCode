/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

#include <vector>

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        preorder_morris( root, ans );

        return ans;
    }

    void preorder_recur( TreeNode *p_node, vector<int> &vec ) {
        if( !p_node ) return;

        vec.push_back( p_node->val );

        preorder_recur( p_node->left, vec );

        preorder_recur( p_node->right, vec );
    }

    void preorder_morris( TreeNode *p_root, vector<int> &vec ) {
        TreeNode *p_curr = p_root;
        TreeNode *p_prev;

        while( p_curr ) {
            if( p_curr->left ) {
                p_prev = p_curr->left;
                
                while( p_prev->right && p_prev->right != p_curr )
                    p_prev = p_prev->right;

                if( p_prev->right ) {
                    p_prev->right = NULL;
                    p_curr = p_curr->right;
                }
                else {
                    vec.push_back( p_curr->val );
                    p_prev->right = p_curr;
                    p_curr = p_curr->left;
                }
            }
            else {
                vec.push_back( p_curr->val );
                p_curr = p_curr->right;
            }
        }
    }
};
// @lc code=end

