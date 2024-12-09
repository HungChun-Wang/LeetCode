/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> vec_freq(26, 0);
        vector<int> vec_temp;
        priority_queue<int> pq;
        int l_idle;
        int l_time = 0;

        for (auto task : tasks)
            vec_freq[task - 'A']++;

        for (auto freq : vec_freq)
            if (freq)
                pq.push(freq);

        while (!pq.empty()) {
            l_idle = n + 1;
            while (l_idle && !pq.empty()) {
                if (pq.top() > 1)
                    vec_temp.push_back(pq.top() - 1);
                pq.pop();
                l_time++;
                l_idle--;
            }

            for(auto freq : vec_temp)
                pq.push(freq);

            vec_temp.clear();

            if (!pq.empty())
                l_time += l_idle;
        }
        return l_time;
    }
};
// @lc code=end

