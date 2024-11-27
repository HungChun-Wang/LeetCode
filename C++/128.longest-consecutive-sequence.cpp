/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // // set, time O(n), space O(n)
    // int longestConsecutive(vector<int>& nums) {
    //     unordered_set<int> uset;
    //     int len_seq_max = 0;
    //     int len_seq_cur;

    //     for (auto num : nums)
    //         uset.insert(num);
        
    //     for (auto it_set : uset) {
    //         if (uset.count(it_set - 1))
    //             continue;
            
    //         len_seq_cur = 1;
    //         while (uset.count(it_set + len_seq_cur))
    //             len_seq_cur++;

    //         if (len_seq_max < len_seq_cur)
    //             len_seq_max = len_seq_cur;
    //     }
    //     return len_seq_max;
    // }

    // sort, time O(nlogn), space O(1)
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int last_num = nums[0]; 
        int len_seq_max = 0;
        int len_seq_cur = 1;

        for (int idx = 1; idx < nums.size(); idx++) {
            if (last_num == nums[idx])
                continue;

            if (last_num == nums[idx] - 1) {
                len_seq_cur++;
            }
            else {
                if (len_seq_max < len_seq_cur) {
                    len_seq_max = len_seq_cur;
                }
                len_seq_cur = 1;
            }
            last_num = nums[idx];
        }
        
        if (len_seq_max < len_seq_cur) {
            len_seq_max = len_seq_cur;
        }

        return len_seq_max;
    }
};
// @lc code=end

