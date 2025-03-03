/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// @lc code=start
// umap + dfs, time O(V + E), space O(V + E), V = num of courses, E = num of prerequisites
// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         unordered_map<int, vector<int>> umap_prerequisites;
//         unordered_map<int, bool> umap_cycle;

//         for (auto prerequisite : prerequisites)
//             umap_prerequisites[prerequisite[0]].push_back(prerequisite[1]);
        
//         for (int l_course = 0; l_course < numCourses; l_course++)
//             if (!checkCourseSeries(umap_prerequisites, umap_cycle, l_course))
//                 return false;

//         return true;
//     }
// private:
//     bool checkCourseSeries(unordered_map<int, vector<int>>& umap_prerequisites, unordered_map<int, bool>& umap_cycle, int l_course) {
//         if (!umap_prerequisites.count(l_course))
//             return true;

//         if (umap_cycle.count(l_course))
//             return false;

//         umap_cycle[l_course] = true;

//         for (auto prerequisite : umap_prerequisites[l_course])
//             if (!checkCourseSeries(umap_prerequisites, umap_cycle, prerequisite))
//                 return false;

//         // umap_cycle.erase(l_course);
//         umap_prerequisites.erase(l_course);
//         return true;
//     }
// };
// @lc code=end

