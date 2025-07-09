class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2);
        int n = numbers.size();
        int l = 0;
        int r = n - 1;
        while(l < r){
            int a = numbers[l] + numbers[r];
            if(a==target){
                return {l+1,r+1};
            }else if(a < target){
                l++;
            }else{
                r--;
            }

        }
        return result;
    }
};