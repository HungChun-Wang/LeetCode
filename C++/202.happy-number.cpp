/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> uset_visited;
        int l_sum = n;
        int l_cur;
        int l_digit;

        while (1) {
            l_cur = l_sum;
            l_sum = 0;
            while (l_cur != 0) {
                l_digit = l_cur % 10;
                l_sum += l_digit * l_digit;
                l_cur /= 10;
            }

            if (l_sum == 1)
                return true;
            if (uset_visited.count(l_sum))
                return false;
            
            uset_visited.insert(l_sum);
        }
        return false;
    }
};
// @lc code=end

