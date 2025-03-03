/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// @lc code=start
// topology sort(Kahn's algorithm), time O(V + E), space (V + E), V = num of courses, E = num of prerequisites
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> vec2d_adj(numCourses);
        vector<int> vec_outdegree(numCourses, 0);
        vector<int> vec_rst(numCourses);
        queue<int> q_bfs;
        int l_course;
        int l_finish = 0;

        for (auto prerequisite : prerequisites) {
            vec2d_adj[prerequisite[0]].push_back(prerequisite[1]);
            vec_outdegree[prerequisite[1]]++;
        }

        for (l_course = 0; l_course < numCourses; l_course++)
            if (!vec_outdegree[l_course])
                q_bfs.push(l_course);

        while (q_bfs.size()) {
            l_course = q_bfs.front();
            q_bfs.pop();
            vec_rst[numCourses - l_finish - 1] = l_course;
            l_finish++;

            for (auto nei : vec2d_adj[l_course]) {
                vec_outdegree[nei]--;
                if (!vec_outdegree[nei])
                    q_bfs.push(nei);
            }
        }

        return l_finish == numCourses ? vec_rst : vector<int>{};
    }
};

// // topology sort dfs(Kahn's algorithm), time O(V + E), space (V + E), V = num of courses, E = num of prerequisites
// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         vec2d_adj = vector<vector<int>>(numCourses);
//         vec_indegree = vector<int>(numCourses, 0);
//         vec_rst = vector<int>(numCourses);
//         l_finish = 0;
//         int l_course;
        
//         for (auto prerequisite : prerequisites) {
//             vec2d_adj[prerequisite[1]].push_back(prerequisite[0]);
//             vec_indegree[prerequisite[0]]++;
//         }

//         for (l_course = 0; l_course < numCourses; l_course++)
//             if (!vec_indegree[l_course])
//                 dfs(l_course);

//         return l_finish == numCourses ? vec_rst : vector<int>{};
//     }
// private:
//     void dfs(int l_course) {
//         vec_rst[l_finish++] = l_course;

//         // dfs should do this to prevent repeat, case [1, 0]
//         vec_indegree[l_course]--;

//         for (auto nei : vec2d_adj[l_course]) {
//             vec_indegree[nei]--;
//             if (!vec_indegree[nei])
//                 dfs(nei);
//         }
//     }

//     vector<vector<int>> vec2d_adj;
//     vector<int> vec_indegree;
//     vector<int> vec_rst;
//     int l_finish;
// };

// umap + dfs, time O(V + E), space O(V + E), V = num of courses, E = num of prerequisites
// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         unordered_map<int, vector<int>> umap_prerequisites;
//         unordered_map<int, bool> umap_cycle;
//         unordered_map<int, bool> umap_finished;
//         vector<int> vec_order;

//         for (auto prerequisite : prerequisites)
//             umap_prerequisites[prerequisite[0]].push_back(prerequisite[1]);

//         for (int l_course = 0; l_course < numCourses; l_course++)
//             if (!checkCourseSeries(umap_prerequisites, umap_cycle, umap_finished, vec_order, l_course))
//                 return {};

//         return vec_order;
//     }

// private:
//     bool checkCourseSeries(unordered_map<int, vector<int>>& umap_prerequisites, unordered_map<int, bool>& umap_cycle, unordered_map<int, bool>& umap_finished, vector<int>& vec_order, int l_course) {
//         if (umap_cycle.count(l_course))
//             return false;

//         if (umap_finished.count(l_course))
//             return true;

//         umap_cycle[l_course] = true;

//         for (auto prerequisite : umap_prerequisites[l_course])
//             if (!checkCourseSeries(umap_prerequisites, umap_cycle, umap_finished, vec_order, prerequisite))
//                 return false;

//         umap_cycle.erase(l_course);
//         umap_finished[l_course] = true;
//         vec_order.push_back(l_course);
//         return true;
//     }
// };
// @lc code=end

