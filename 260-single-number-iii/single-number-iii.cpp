class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        uint x = 0;
        for(int &num : nums){
            x ^= num;
        }
        int y = x & (-x);
        int a = 0, b = 0;
        for(int &num : nums){
            if(num & y){
                a ^= num;
            }else{
                b ^= num;
            }
        }
        return {a ,b};
    }
};