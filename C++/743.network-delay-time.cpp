/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    // Dijkstra's algorithm, time O(ElogV), space O(V+E)
    // V = vertex num, E = total edge num.
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> vec2d_edges(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq_min_heap;
        vector<bool> vec_visited(n + 1, 0);
        pair<int, int> pr_curr;
        int l_time_diff;
        int l_vertex;
        int l_time;
        int l_cnt_visited = 0;

        for (auto time : times)
            vec2d_edges[time[0]].emplace_back(time[1], time[2]);
            // vec2d_edges[time[0]].push_back({time[1], time[2]});
        
        pq_min_heap.push({k, 0});

        while (pq_min_heap.size()) {
            pr_curr = pq_min_heap.top();
            pq_min_heap.pop();

            l_vertex = pr_curr.first;

            if (vec_visited[l_vertex])
                continue;

            vec_visited[l_vertex] = true;
            l_cnt_visited++;
            l_time = pr_curr.second;

            for (auto edge : vec2d_edges[l_vertex])
                if (!vec_visited[edge.first])
                    pq_min_heap.push({edge.first, l_time + edge.second});
        }

        return (l_cnt_visited == n) ? l_time : -1;
    }
};
// @lc code=end

