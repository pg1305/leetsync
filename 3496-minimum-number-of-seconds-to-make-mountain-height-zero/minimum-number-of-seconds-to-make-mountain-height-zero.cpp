class Solution {
    using LL = long long;
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        LL low = 0;
        LL high = 1e16;
        LL res = high;
        while(low <= high){
            LL mid = low + ((high - low) >> 1);
            LL sum = 0;
            for(int i = 0; i < workerTimes.size(); i++) sum += (LL)(sqrt((double)mid/workerTimes[i] * 2 + 0.25)-0.5);
            if(sum >= mountainHeight){
                res = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return res;
    }
};