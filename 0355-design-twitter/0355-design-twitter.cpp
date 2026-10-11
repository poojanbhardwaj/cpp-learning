
class Twitter {
public:
    unordered_map<int, unordered_set<int>> friends;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int cur = 0;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({cur++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        // {timestamp, tweetId, userId, index}
        priority_queue<vector<int>> pq;

        unordered_set<int> users = friends[userId];
        users.insert(userId);

        // Push the latest tweet of every relevant user
        for (int id : users) {
            if (tweets[id].empty()) continue;

            int idx = tweets[id].size() - 1;

            pq.push({
                tweets[id][idx].first,
                tweets[id][idx].second,
                id,
                idx
            });
        }

        // Extract at most 10 recent tweets
        while (!pq.empty() && ans.size() < 10) {
            auto top = pq.top();
            pq.pop();

            int tweetId = top[1];
            int id = top[2];
            int idx = top[3];

            ans.push_back(tweetId);

            // Push the previous tweet from the same user
            if (idx > 0) {
                idx--;

                pq.push({
                    tweets[id][idx].first,
                    tweets[id][idx].second,
                    id,
                    idx
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        friends[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};
