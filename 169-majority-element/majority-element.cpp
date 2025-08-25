class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        // int el;
        // int count=0;
        // for(int i=0;i<n;i++){
        //     if(count==0){
        //         count++;
        //         el=nums[i];
        //     }
        //     else if(nums[i]==el) count++;
        //     else count--;
        // }
        // int count1=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==el) count1++;
        // }
        // if(count1>n/2) return el;
        // return -1;
        unordered_map<int, int> freq;
        int majority = 0;
        for(int &num: nums) {
            freq[num]++;
        }
        for(auto x:freq){
            if(x.second > n/2) return x.first;
        }
        return -1;
    }
};