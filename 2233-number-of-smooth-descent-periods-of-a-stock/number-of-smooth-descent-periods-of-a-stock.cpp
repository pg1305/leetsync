class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long tot = 0, str = 0;
        for(int i = 1; i < n; i++){
            if(prices[i] - prices[i - 1] == -1){
                str++;
                tot += str;
            }else{
                str = 0;
            }
        }
        return tot + n;
    }
};