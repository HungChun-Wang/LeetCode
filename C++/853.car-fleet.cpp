/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // sort, time O(nlogn), space O(n)
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> vec_cars; // position, time

        for (int idx = 0; idx < position.size(); idx++)
            vec_cars.push_back(pair(position[idx], float(target - position[idx]) / speed[idx]));
        
        sort(vec_cars.begin(), vec_cars.end(), greater<pair<int, float>>());

        int l_num_fleet = 0;
        float f_time_curr = 0;

        for (auto it_vec : vec_cars) {
            if (it_vec.second > f_time_curr) {
                f_time_curr = it_vec.second;
                l_num_fleet++;
            }
        }
        return l_num_fleet;
    }
};
// @lc code=end

