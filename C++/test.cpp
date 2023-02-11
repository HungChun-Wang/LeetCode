#include <string>
#include <iostream>
// #include "1.two-sum.cpp"
#include "3.longest-substring-without-repeating-characters.cpp"

void test_3() {
    string s = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    Solution *p_subject = new Solution();

    printf("%d\n", p_subject->lengthOfLongestSubstring(s));
}

// void test_1() {
//     vector<int> vec_input;
//     vector<int> vec_output;
//     vec_input.push_back(3);
//     vec_input.push_back(2);
//     vec_input.push_back(3);

//     Solution *p_subject = new Solution();
//     vec_output = p_subject->twoSum(vec_input, 6);

//     for (int i : vec_output)
//         printf("%d ", i);
//     printf("\n");
// }

int main(void) {
    test_3();
    return 0;
}
