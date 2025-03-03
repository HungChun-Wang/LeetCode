/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 */

#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    // hash table, O(n^2), space O(n)
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int num_boomerangs = 0;
        int ic, ia;
        unordered_map<int, int> umap_dist_freq;

        for (ic = 0; ic < points.size(); ic++) {
            for (ia = 0; ia < points.size(); ia++)
                if (ic != ia)
                    umap_dist_freq[dist_square(points[ic], points[ia])]++;

            for (auto val : umap_dist_freq)
                num_boomerangs += val.second * (val.second - 1);
            
            umap_dist_freq.clear();
        }
        return num_boomerangs;
    }

    // // brute force, O(n^3), space O(1)
    // int numberOfBoomerangs(vector<vector<int>>& points) {
    //     int num_boomerangs = 0;
    //     int i, j, k;

    //     for (i = 0; i < points.size(); i++)
    //         for (j = 0; j < points.size() - 1; j++)
    //             for (k = j + 1; k < points.size(); k++)
    //                 if ((i != j) && (i != k) && (dist_square(points[i], points[j]) == dist_square(points[i], points[k])))
    //                     num_boomerangs += 2;
    //     return num_boomerangs;
    // }

    inline int dist_square(vector<int>& point0, vector<int>& point1) {
        int diff0 = point0[0] - point1[0];
        int diff1 = point0[1] - point1[1];
        return diff0 * diff0 + diff1 * diff1;
    }
};
// @lc code=end

