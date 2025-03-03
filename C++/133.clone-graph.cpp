/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // umap, time O(V + E), space O(V)
    Node* cloneGraph(Node* p_node) {
        unordered_map<Node*, Node*> umap;
        return cloneGraph_dfs(p_node, umap);
    }

    Node* cloneGraph_dfs(Node* p_node, unordered_map<Node*, Node*>& umap) {
        if (p_node == nullptr) return nullptr;
        if (umap.count(p_node)) return umap[p_node];

        Node *p_copy = new Node(p_node->val);
        umap[p_node] = p_copy;

        for (Node* neighbor : p_node->neighbors)
            p_copy->neighbors.push_back(cloneGraph_dfs(neighbor, umap));

        return p_copy;
    }
};
// @lc code=end

