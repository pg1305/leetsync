class Solution {
public:
    static int maximumLength(vector<int>& nums, int k) {
        //let dp[i] denote len for subsequence ending at i(mod k)
        short ans=0;
        for (int i=0; i<k; i++){
            short dp[1000]={0};
            for (int x : nums){
                int j=x%k;
                dp[j]=max(dp[j], short(dp[(i+k-j)%k]+1));
            }
            ans=max(ans, *max_element(dp, dp+k));
        }
        return ans;
        
    }
};