bool cmp(int a,int b){
    return to_string(a)+to_string(b) > to_string(b) + to_string(a);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(),nums.end(),cmp);
        for(auto &num : nums){
            ans += to_string(num);
        }
        if(ans[0]=='0') return "0"; 
        return ans;
    }
};