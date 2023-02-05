#include <iostream>
#include "1.two-sum.cpp"

int test_1() {
    vector<int> vec_input;
    vector<int> vec_output;
    vec_input.push_back(3);
    vec_input.push_back(2);
    vec_input.push_back(3);

    Solution *p_subject = new Solution();
    vec_output = p_subject->twoSum(vec_input, 6);

    for (int i : vec_output)
        printf("%d ", i);
    printf("\n");
}

int main(void) {
    test_1();
    return 0;
}
