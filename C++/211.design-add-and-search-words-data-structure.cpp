/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class TrieNode {
public:
    TrieNode() : p_child{0}, is_end(0) {}
    TrieNode *p_child[26];
    bool is_end;
};

class WordDictionary {

public:
    WordDictionary() {}

    void addWord(string word) {
        char c_idx;
        TrieNode* p_curr = &root;

        for (auto c : word) {
            c_idx = c - 'a';
            if (!p_curr->p_child[c_idx])
                p_curr->p_child[c_idx] = new TrieNode();
            p_curr = p_curr->p_child[c_idx];
        }
        p_curr->is_end = true;
    }

    bool search(string word) {
        return search_recur(word, 0, &root);
    }

    bool search_recur(string &word, int l_idx, TrieNode* p_curr) {
        if (l_idx == word.size())
            return p_curr->is_end;
        
        if (word[l_idx] == '.') {
            for (char c_idx = 0; c_idx < 26; c_idx++) {
                if (p_curr->p_child[c_idx] && search_recur(word, l_idx + 1, p_curr->p_child[c_idx]))
                    return true;
            }
            return false;
        }
        else {
            char c_idx = word[l_idx] - 'a';
            return p_curr->p_child[c_idx] && search_recur(word, l_idx + 1, p_curr->p_child[c_idx]);
        }
        return true;
    }

private:
    TrieNode root;

// // vector + map, time O(n*l), space O(n)
// public:
//     WordDictionary() {}
    
//     void addWord(string word) {
//         umap[word.size()].push_back(word);
//     }
    
//     bool search(string word) {
//         int l_idx;
//         int l_size = word.size();
//         for (auto s : umap[l_size]) {
//             for (l_idx = 0; l_idx < l_size; l_idx++) {
//                 if (word[l_idx] == '.')
//                     continue;
//                 if (word[l_idx] != s[l_idx])
//                     break;
//             }

//             if (l_idx == l_size)
//                 return true;
//         }
//         return false;
//     }
// private:
//     unordered_map<int, vector<string>> umap;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

