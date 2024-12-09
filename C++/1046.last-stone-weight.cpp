/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // priority queue, time O(nlogn), space O(n)
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int l_stone_a;
        int l_stone_b;
        int l_stone_diff;
        
        for (auto stone : stones)
            pq.push(stone);
        
        while (pq.size() > 1) {
            l_stone_a = pq.top();
            pq.pop();
            l_stone_b = pq.top();
            pq.pop();

            l_stone_diff = (l_stone_a > l_stone_b) ? 
                            (l_stone_a - l_stone_b) :
                            (l_stone_b - l_stone_a);

            if (l_stone_diff)
                pq.push(l_stone_diff);
        }

        if (pq.size())
            return pq.top();
        return 0;
    }
};
// @lc code=end

