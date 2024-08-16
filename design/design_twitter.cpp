#include <bits/stdc++.h>
using namespace std;
class Twitter
{
public:
    unordered_map<int, unordered_set<int>> fol;
    unordered_map<int, vector<pair<int, int>>> tweet; // u id- tid-time;
    int time;
    Twitter()
    {
        time = 1;
    }

    void postTweet(int userId, int tweetId)
    {
        tweet[userId].push_back({tweetId, time});
        time++;
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>> pq; // time-tid
        for (auto i : tweet[userId])
        {
            pq.push({i.second, i.first});
        }
        for (auto f : fol[userId])
        {
            for (auto i : tweet[f])
            {
                pq.push({i.second, i.first});
            }
        }
        vector<int> ans;
        for (int i = 0; i < 10 && !pq.empty(); i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        fol[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        fol[followerId].erase(followeeId);
    }
};
void print(vector<int> a)
{
    for(auto i:a)cout<<i<<" ";
    cout<<endl;
}
int main()
{
    Twitter* twitter = new Twitter();
    twitter->postTweet(1, 5); // User 1 posts a new tweet (id = 5).
    vector<int> a=twitter->getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
    print(a);
    twitter->follow(1, 2);    // User 1 follows user 2.
    twitter->postTweet(2, 6); // User 2 posts a new tweet (id = 6).
    a=twitter->getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    print(a);
    twitter->unfollow(1, 2);  // User 1 unfollows user 2.
    a=twitter->getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
    print(a);
}