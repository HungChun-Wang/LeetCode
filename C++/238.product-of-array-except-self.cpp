/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // one array, time O(n), space O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() == 0)
            return nums;

        vector<int> vec_product(nums.size(), 1);
        int i, l_product = 1;

        for (i = 1; i < nums.size(); i++) {
            l_product *= nums[i - 1];
            vec_product[i] = l_product;
        }
        
        l_product = 1;
        for (i = nums.size() - 2; i >= 0; i--) {
            l_product *= nums[i + 1];
            vec_product[i] *= l_product;
        }
        
        return vec_product;
    }

    // // two array, time O(n), space O(n)
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     vector<int> vec_rst;

    //     vector<int> vec_product_left(nums.size());
    //     vector<int> vec_product_right(nums.size());

    //     vec_product_left[0] = 1;
    //     vec_product_right[nums.size() - 1] = 1;
    //     for (int i = 1; i < nums.size(); i++)
    //         vec_product_left[i] = vec_product_left[i - 1] * nums[i - 1];
        
    //     for (int i = nums.size() - 2; i >= 0; i--)
    //         vec_product_right[i] = vec_product_right[i + 1] * nums[i + 1];

    //     for (int i = 0; i < nums.size(); i++)
    //         vec_rst.push_back(vec_product_left[i] * vec_product_right[i]);
        
    //     return vec_rst;
    // }

    // // brute forece, time O(n^2), space O(n)
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     int i, j, l_rst;
    //     vector<int> vec_rst;

    //     for (i = 0; i < nums.size(); i++) {
    //         l_rst = 1;
    //         for (j = 0; j < nums.size(); j++) {
    //             if (i == j) continue;
    //             l_rst *= nums[j];
    //         }
    //         vec_rst.push_back(l_rst);
    //     }

    //     return vec_rst;
    // }
};
// @lc code=end

