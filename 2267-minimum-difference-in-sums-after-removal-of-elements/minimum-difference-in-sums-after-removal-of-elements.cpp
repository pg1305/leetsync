class Solution {
public:
typedef long long ll;
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size();
        n/=3;
        ll left_sum=0;
        priority_queue<ll> pq;
        for(int i=0;i<n;i++) {pq.push(nums[i]); left_sum+=nums[i];}

        vector<ll> left_min_sum(3*n);

        left_min_sum[n-1]=left_sum;
        for(int i=n;i<2*n;i++){
            if(nums[i]<pq.top()){
                left_sum+=(nums[i]-pq.top());
                pq.pop();
                pq.push(nums[i]);
            }
            left_min_sum[i]=left_sum;
        }

        ll right_sum=0;
        pq=priority_queue<ll>();

        for(int i=3*n-1;i>=2*n;i--){pq.push(-nums[i]); right_sum+=nums[i];}

        vector<ll> right_max_sum(3*n);
        right_max_sum[2*n]=right_sum;
        for(int i=2*n-1;i>=n;i--){
            if(nums[i]>-pq.top()){
                right_sum+=(nums[i]+pq.top());
                pq.pop();
                pq.push(-nums[i]);
            }
            right_max_sum[i]=right_sum;
        }

        ll ans=1e18;
        for(int i=n-1;i<2*n;i++){
            ans=min(ans,left_min_sum[i]-right_max_sum[i+1]);
        }
        return ans;
    }
};