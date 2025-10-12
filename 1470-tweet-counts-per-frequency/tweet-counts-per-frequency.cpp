class TweetCounts {
public:
unordered_map<string, vector<int>> mp;
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int size = 0;
        if(freq == "minute") size = 60;
        else if(freq == "hour") size = 3600;
        else if(freq == "day") size = 86400;

        vector<int> &times = mp[tweetName];
        sort(times.begin(), times.end());
        int portions = (endTime - startTime)/size + 1;
        vector<int> res(portions, 0);
        for (int t : times) {
            if (t < startTime || t > endTime) continue;
            int idx = (t - startTime) / size;
            res[idx]++;
        }
        return res; 
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */