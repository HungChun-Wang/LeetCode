/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // priority queue, time O(nlogn), space O(k)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, int>> pq;
        vector<vector<int>> vec2d_rst;
        float f_dist;

        for (int l_idx = 0; l_idx < points.size(); l_idx++) {
            f_dist = points[l_idx][0] * points[l_idx][0] + points[l_idx][1] * points[l_idx][1];
            if (pq.size() >= k) {
                if (pq.top().first > f_dist) {
                    pq.pop();
                    pq.push({f_dist, l_idx});
                }
            }
            else
                pq.push({f_dist, l_idx});
        }

        int l_size = pq.size();
        for (int i = 0; i < l_size; i++) {
            vec2d_rst.push_back(points[pq.top().second]);
            pq.pop();
        }
        return vec2d_rst;
    }
};
// @lc code=end

