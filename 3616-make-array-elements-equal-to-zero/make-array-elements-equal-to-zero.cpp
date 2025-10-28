class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]!= 0)continue;
            for (int dir : {-1, 1}) {
                vector<int> temp = nums;  
                int curr = i;
                int d = dir;

                while (curr >= 0 && curr < nums.size()) {
                    if (temp[curr] == 0) {
                        curr += d;  
                    } else {
                        temp[curr]--;  
                        d = -d;        
                        curr += d;     
                    }
                }
                bool allZero = true;
                for (int val : temp) {
                    if (val != 0) {
                        allZero = false;
                        break;
                    }
                }
                if (allZero) res++;
            }
        }
        return res;
    }
};