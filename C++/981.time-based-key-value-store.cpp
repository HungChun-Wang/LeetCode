/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class TimeMap {
public:
    TimeMap() {
        
    }

    // umap + binary search, time O(logn), space O(k)    
    void set(string key, string value, int timestamp) {
        umap[key].push_back(pair<int, string>(timestamp, value));
    }

    string get(string key, int timestamp) {
        vector<pair<int, string>> &vec_pair = umap[key];
        int l_mid = 0;
        int l_left = 0;
        int l_right = vec_pair.size() - 1;
        string s_value;

        while (l_left <= l_right) {
            l_mid = (l_right + l_left) >> 1;
            pair<int, string> &pair_str = vec_pair[l_mid];

            if (pair_str.first == timestamp)
                return pair_str.second;
            else if (pair_str.first < timestamp) {
                s_value = pair_str.second;
                l_left = l_mid + 1;
            }
            else
                l_right = l_mid - 1;
        }
        return s_value;
    }

private:
    unordered_map<string, vector<pair<int, string>>> umap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

