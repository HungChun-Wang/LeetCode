/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // priority queue, time O(nlogn), space O(k)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto num : nums) {
            if (pq.size() >= k) {
                if (num > pq.top()) {
                    pq.pop();
                    pq.push(num);
                }
            }
            else
                pq.push(num);
        }
        return pq.top();
    }

    // // sort, time O(nlogn), space O(1)
    // int findKthLargest(vector<int>& nums, int k) {
    //     sort(nums.begin(), nums.end(), greater<int>());
    //     return nums[k - 1];
    // }
};
// @lc code=end

