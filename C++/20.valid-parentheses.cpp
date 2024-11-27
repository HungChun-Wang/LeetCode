/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    // stack, time O(n), space O(n)
    bool isValid(string s) {
        stack<char> stack_c;
        char top;

        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{')
                stack_c.push(c);
            else {
                if (stack_c.empty())
                    return false;

                top = stack_c.top();
                stack_c.pop();                

                if ((top != '(' && c == ')') ||
                    (top != '[' && c == ']') ||
                    (top != '{' && c == '}'))
                    return false;
            }
        }
        return stack_c.size() == 0;
    }
};
// @lc code=end

