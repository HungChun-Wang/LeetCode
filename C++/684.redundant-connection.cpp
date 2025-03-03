/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> vec_parents(edges.size() + 1);

        for (int idx = 0; idx < vec_parents.size(); idx++)
            vec_parents[idx] = idx;

        for (auto edge : edges) {
            if (!union_set(vec_parents, edge[0], edge[1]))
                return {edge[0], edge[1]};
        }
        return {};
    }

private:
    int find_parent(vector<int>& vec_parents, int l_vertex) {
        if (vec_parents[l_vertex] != l_vertex)
            vec_parents[l_vertex] = find_parent(vec_parents, vec_parents[l_vertex]);
        
        return vec_parents[l_vertex];

        // int l_parent = vec_parents[l_vertex];

        // while (l_parent != vec_parents[l_parent]) {
        //     vec_parents[l_parent] = vec_parents[vec_parents[l_parent]];
        //     l_parent = vec_parents[l_parent];
        // }

        // return l_parent;
    }

    bool union_set(vector<int>& vec_parents, int l_vertex_0, int l_vertex_1) {
        int l_parent_0 = find_parent(vec_parents, l_vertex_0);
        int l_parent_1 = find_parent(vec_parents, l_vertex_1);

        if (l_parent_0 == l_parent_1)
            return false;
        
        if (l_parent_0 > l_parent_1)
            vec_parents[l_parent_0] = l_parent_1;
        else
            vec_parents[l_parent_1] = l_parent_0;

        return true;
    }
};
// @lc code=end

