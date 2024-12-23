/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // // sort and unordered map, time O(nlogn), space O(n)
    // bool isNStraightHand(vector<int>& hands, int groupSize) {
    //     unordered_map<int, int> umap_freq;
        
    //     for (auto hand : hands)
    //         umap_freq[hand]++;

    //     sort(hands.begin(), hands.end());

    //     for (auto hand : hands) {
    //         if (umap_freq[hand] == 0)
    //             continue;
            
    //         for (int l_num = hand; l_num < hand + groupSize; l_num++) {
    //             if (umap_freq[l_num] == 0)
    //                 return false;
    //             umap_freq[l_num]--;
    //         }
    //     }
    //     return true;
    // }

    // unordered map, time O(n), space O(n)
    bool isNStraightHand(vector<int>& hands, int groupSize) {
        int l_num_start;
        unordered_map<int, int> umap_freq;
        
        for (auto hand : hands)
            umap_freq[hand]++;

        for (auto hand : hands) {
            if (umap_freq[hand] == 0)
                continue;

            l_num_start = hand;
            while (umap_freq[l_num_start - 1] > 0)
                l_num_start--;

            while (l_num_start <= hand) {
                while (umap_freq[l_num_start]) {
                    for (int l_num = l_num_start; l_num < l_num_start + groupSize; l_num++) {
                        if (umap_freq[l_num] == 0)
                            return false;
                        umap_freq[l_num]--;
                    }
                }
                l_num_start++;
            }
        }
        return true;
    }
};
// @lc code=end

