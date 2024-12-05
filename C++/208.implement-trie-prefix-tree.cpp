/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

#include <string>
#include <cstring>

using namespace std;

// @lc code=start
struct TrieNode{
public:
    TrieNode *p_child[26];
    bool is_end;
};

class Trie {
public:
    Trie() {
        memset(&root, 0, sizeof(TrieNode));
    }
    
    void insert(string word) {
        char c_idx;
        TrieNode* p_curr = &root;
        
        for(auto c : word) {
            c_idx = c - 'a';
            if (p_curr->p_child[c_idx] == nullptr)
                p_curr->p_child[c_idx] = new TrieNode();
            p_curr = p_curr->p_child[c_idx];
        }
        p_curr->is_end = true;
    }
    
    bool search(string word) {
        char c_idx;
        TrieNode* p_curr = &root;

        for (auto c : word) {
            c_idx = c - 'a';
            if (p_curr->p_child[c_idx])
                p_curr = p_curr->p_child[c_idx];
            else
                return false;
        }
        return p_curr->is_end;
    }
    
    bool startsWith(string prefix) {
        char c_idx;
        TrieNode* p_curr = &root;

        for (auto c : prefix) {
            c_idx = c - 'a';
            if (p_curr->p_child[c_idx])
                p_curr = p_curr->p_child[c_idx];
            else
                return false;
        }
        return true;
    }

private:
    TrieNode root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

