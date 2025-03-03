/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // time O(l), l = max length of num
    // space O(1), except output
    string addStrings(string num1, string num2) {
        int i1 = num1.size() - 1;
        int i2 = num2.size() - 1;
        int digit1;
        int digit2;
        int digit_sum;
        int carry = 0;
        string str;

        while (i1 >= 0 || i2 >= 0 || carry) {
            digit1 = i1 >= 0 ? num1[i1] - '0' : 0;
            digit2 = i2 >= 0 ? num2[i2] - '0' : 0;
            digit_sum = digit1 + digit2 + carry;
            str += (digit_sum % 10) + '0';
            carry = digit_sum / 10;
            i1--;
            i2--;
        }
        reverse(str.begin(), str.end());
        return str;
    } 
};
// @lc code=end

