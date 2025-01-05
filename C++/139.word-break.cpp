/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start

// Trie and dp, time O(l * t * t + n), space O(l + t)
// l = len of s, t = max string len of wordDict, n = len of wordDict
class TrieNode {
public:
    TrieNode *p_children[26];
    bool is_end;
};

class Trie {
public:
    Trie() : m_root{0}, ml_len_max(0) {};

    void insert(string str) {
        TrieNode *p_node = &m_root;
        int idx;
        int l_len = 0;
        for (auto c : str) {
            l_len++;
            idx = c - 'a';
            if (p_node->p_children[idx] == nullptr) {
                p_node->p_children[idx] = new TrieNode();
                ml_len_max = max(ml_len_max, l_len);
            }
            p_node = p_node->p_children[idx];
        }
        p_node->is_end = true;
    }

    bool search(string s, int idx_st, int idx_end) {
        TrieNode *p_node = &m_root;
        int idx_char;
        for (int idx = idx_st; idx <= idx_end; idx++) {
            idx_char = s[idx] - 'a';
            if (p_node->p_children[idx_char] == nullptr)
                return false;
            p_node = p_node->p_children[idx_char];
        }
        return p_node->is_end;
    }

    int get_max_len() {
        return ml_len_max;
    }

private:
    TrieNode m_root;

    int ml_len_max;
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int l_len = s.size();
        int idx_st;
        int idx_end;
        int l_len_max_dict;
        Trie trie;
        vector<bool> vec_dp(l_len + 1, false);

        vec_dp[l_len] = true;

        for (auto s : wordDict)
            trie.insert(s);

        l_len_max_dict = trie.get_max_len();

        for (idx_st = l_len - 1; idx_st >= 0; idx_st--) {
            for (idx_end = idx_st; idx_end < min(idx_st + l_len_max_dict, l_len); idx_end++) {
                if (vec_dp[idx_end + 1] && trie.search(s, idx_st, idx_end)) {
                    vec_dp[idx_st] = true;
                    break;
                }
            }
        }

        return vec_dp[0];
    }
};
// @lc code=end

