/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class KthLargest {
// priority queue, time O(nlogn), space O(k)
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (auto num : nums)
            add(num);
    }
    
    int add(int val) {
        if (pq.size() >= this->k) {
            if (pq.top() < val) {
                pq.pop();
                pq.push(val);
            }
        }
        else
            pq.push(val);
        return pq.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

