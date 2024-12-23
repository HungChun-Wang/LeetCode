/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */

#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    // greedy, time O(n), space O(1)
    bool checkValidString(string s) {
        int l_left_min = 0;
        int l_left_max = 0;

        for (auto c : s) {
            if (c == '(') {
                l_left_min++;
                l_left_max++;
            }
            else if (c == '*') {
                l_left_min--;
                l_left_max++;
            }
            else if (c == ')') {
                l_left_min--;
                l_left_max--;
            }

            if (l_left_max < 0)
                return false;

            if (l_left_min < 0)
                l_left_min = 0;
        }

        return l_left_min == 0;
    }

    // // stack, time O(n), space O(n)
    // bool checkValidString(string s) {
    //     stack<int> stack_left;
    //     stack<int> stack_star;

    //     for (int idx = 0; idx < s.size(); idx++) {
    //         if (s[idx] == '(')
    //             stack_left.push(idx);
    //         else if (s[idx] == '*')
    //             stack_star.push(idx);
    //         else if (s[idx] == ')') {
    //             if (stack_left.size())
    //                 stack_left.pop();
    //             else if (stack_star.size())
    //                 stack_star.pop();
    //             else
    //                 return false;
    //         }
    //     }

    //     while (stack_left.size() && stack_star.size()) {
    //         if (stack_left.top() > stack_star.top())
    //             return false;
    //         stack_left.pop();
    //         stack_star.pop();
    //     }

    //     return stack_left.empty();
    // }
};
// @lc code=end

