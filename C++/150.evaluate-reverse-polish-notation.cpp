/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

#include <vector>
#include <stack>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    // stack, time O(n), space O(n)
    int evalRPN(vector<string>& tokens) {
        stack<int> stack_token;
        int l_num_a, l_num_b;
        
        for (auto token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                l_num_a = stack_token.top();
                stack_token.pop();
                l_num_b = stack_token.top();
                stack_token.pop();

                if (token == "+")
                    stack_token.push(l_num_b + l_num_a);
                else if (token == "-")
                    stack_token.push(l_num_b - l_num_a);
                else if (token == "*")
                    stack_token.push(l_num_b * l_num_a);
                else if (token == "/")
                    stack_token.push(l_num_b / l_num_a);
                else {} // assert
            }
            else {
                stack_token.push(stoi(token));
            }
        }
        return stack_token.top();
    }
};
// @lc code=end

