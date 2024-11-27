/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // // map, time O(n), space O(n)
    // Node* copyRandomList(Node* head) {
    //     unordered_map<Node*, Node*> umap;
    //     Node *p_curr = head;
    //     Node *p_new;

    //     while (p_curr) {
    //         p_new = new Node(p_curr->val);
    //         umap[p_curr] = p_new;
    //         p_curr = p_curr->next;
    //     }

    //     p_curr = head;
    //     while (p_curr) {
    //         p_new = umap[p_curr];
    //         p_new->next = umap[p_curr->next];
    //         p_new->random = umap[p_curr->random];
    //         p_curr = p_curr->next;
    //     }
    //     return umap[head];
    // }

    // Interweave, time O(n), space O(1)
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        Node *p_new;
        Node *p_head_new;
        Node *p_next;
        Node *p_curr = head;
        
        while (p_curr) {
            p_new = new Node(p_curr->val);
            p_next = p_curr->next;
            p_new->next = p_next;
            p_curr->next = p_new;
            p_curr = p_next;
        }

        p_curr = head;
        while (p_curr) {
            p_new = p_curr->next;
            if (!p_curr->random)
                p_new->random = nullptr;
            else
                p_new->random = p_curr->random->next;
            p_curr = p_new->next;
        }

        p_head_new = head->next;
        p_curr = head;
        while (p_curr && p_curr->next) {
            p_next = p_curr->next;
            p_curr->next = p_next->next;
            p_curr = p_next;
        }

        return p_head_new;
    }
};
// @lc code=end

