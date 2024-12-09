/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// @lc code=start
class Twitter {
public:
    Twitter() {l_time = 0;}
    
    void postTweet(int userId, int tweetId) {
        umap_tweet[userId].push({l_time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq_limit = umap_tweet[userId];
        priority_queue<pair<int, int>> pq_temp;
        vector<int> vec_rst;

        if (umap_tweet.find(userId) == umap_tweet.end())
            return vec_rst;

        for (auto follow: umap_follow[userId]) {
            pq_temp = umap_tweet[follow];
            while (!pq_temp.empty()) {
                pq_limit.push(pq_temp.top());
                pq_temp.pop();
            }
        }

        while (!pq_temp.empty() && vec_rst.size() < 10) {
            vec_rst.push_back(pq_limit.top().second);
            pq_limit.pop();
        }
        return vec_rst;
    }
    
    void follow(int followerId, int followeeId) {
        umap_follow[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        umap_follow[followerId].erase(followeeId);
    }
private:
    // pair<time, tweetID>
    unordered_map<int, priority_queue<pair<int, int>>> umap_tweet;

    // userID, set<tweetID>
    unordered_map<int, unordered_set<int>> umap_follow; 

    int l_time;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

