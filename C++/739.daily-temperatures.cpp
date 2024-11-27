/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

#include <stack>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // stack, time O(n), space O(n)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stack_day;
        vector<int> vec_rst(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!stack_day.empty() && temperatures[i] > temperatures[stack_day.top()]) {
                vec_rst[stack_day.top()] = i - stack_day.top();
                stack_day.pop();
            }
            stack_day.push(i);
        }
        return vec_rst;
    }
};
// @lc code=end

