/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // heap
    // time O(nlogn + n)
    // space O(n), except output
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> vec_rst(score.size());
        vector<string> vec_medal = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        priority_queue<pair<int, int>> pq;
        pair<int, int> pr;
        int rank = 0;

        for (int i = 0; i < score.size(); i++)
            pq.push({score[i], i});

        while(pq.size() && rank < 3) {
            pr = pq.top(); pq.pop();
            vec_rst[pr.second] = vec_medal[rank++];
        }

        while(pq.size()) {
            pr = pq.top(); pq.pop();
            vec_rst[pr.second] = to_string(++rank);
        }
        return vec_rst;
    }

    // // sort + hash
    // // time O(nlogn + 2n)
    // // space O(2n), except output
    // vector<string> findRelativeRanks(vector<int>& score) {
    //     vector<string> rst(score.size());
    //     vector<int> score_sort = score;
    //     unordered_map<int, int> score_to_rank;
    //     vector<string> vec_medal = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    //     int rank;

    //     sort(score_sort.begin(), score_sort.end(), greater<int>());

    //     for (rank = 0; rank < score.size(); rank++)
    //         score_to_rank[score_sort[rank]] = rank;
        
    //     for (int i = 0; i < score.size(); i++) {
    //         rank = score_to_rank[score[i]];
    //         if (rank < 3)
    //             rst[i] = vec_medal[rank];
    //         else
    //             rst[i] = to_string(rank + 1);
    //     }
    //     return rst;
    // }
};
// @lc code=end

