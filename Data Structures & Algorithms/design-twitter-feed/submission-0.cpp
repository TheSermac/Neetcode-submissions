class Twitter {
private:
// UserId -> tweetId
map<int, std::vector<int>> user_to_post;
// tweetId -> time
map<int, int> post_to_time;
// follower -> set of followees
map<int, std::set<int>> user_follows;
// At most 10 tweets may be added to a feed
const int MAX_TWEETS = 10;
int time;

public:
    Twitter() : time(0) {}
    
    void postTweet(int userId, int tweetId) {
        user_to_post[userId].push_back(tweetId);
        post_to_time[tweetId] = time;
        time++;
    }
    
    void follow(int followerId, int followeeId) {
        user_follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(user_follows.find(followerId) != user_follows.end()){
            user_follows[followerId].erase(followeeId);
        }
    }

    vector<int> getNewsFeed(int userId) {
        //Keep the most "competitive times"
        priority_queue<int,std::vector<int>, std::greater<int>> feed_tweets;
        // Time is unique
        map<int,int> time_to_post;

        //Include itself
        user_follows[userId].insert(userId);

        //Go through all posts
        for(int followee : user_follows[userId]){
            for(int tweet : user_to_post[followee]){
                if(feed_tweets.size() < 10){
                    feed_tweets.push(post_to_time[tweet]);
                    time_to_post[post_to_time[tweet]] = tweet;
                }
                else{
                    if(feed_tweets.top() < post_to_time[tweet]){
                        feed_tweets.pop();
                        feed_tweets.push(post_to_time[tweet]);
                        time_to_post[post_to_time[tweet]] = tweet;
                    }
                }
            }
        }

        //Save the solution vector
        std::vector<int> sol;
        while(!feed_tweets.empty()){
            sol.push_back(time_to_post[feed_tweets.top()]);
            feed_tweets.pop();
        }

        std::reverse(sol.begin(), sol.end());

        return sol;
    }
    
};
