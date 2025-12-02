class Solution {
private:
    long long powerAvailable(const std::vector<int>& batteries, long long mid) {
        if(mid == 0) return 0;
        long long totalPower = 0;
        for(int b : batteries) 
            totalPower += min(1LL*b, mid);
        
        return totalPower;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long start = 0, end = accumulate(batteries.begin(), batteries.end(), 0LL);
        while(start <= end) {
            long long mid = start + (end-start) / 2;
            (powerAvailable(batteries, mid) >= n*mid) ? start = mid+1 : end = mid-1;
        }
        return end;
    }
};