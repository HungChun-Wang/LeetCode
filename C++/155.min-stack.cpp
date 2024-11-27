/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        if (vec_pair.empty())
            vec_pair.push_back(pair(val, val));
        else {
            vec_pair.push_back(pair(val, min(vec_pair.back().second, val)));
        }
    }
    
    void pop() {
        vec_pair.pop_back();
    }
    
    int top() {
        return vec_pair.back().first;
    }
    
    int getMin() {
        return vec_pair.back().second;
    }
private:
    vector<pair<int, int>> vec_pair;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

