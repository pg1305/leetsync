class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;

        int curr = 0;
        int count = 0;
        string s = "";

        while (curr < nums.size() - 1) {
            if (count == 0) {
                s += to_string(nums[curr]);
                count++;
            }

            if (nums[curr] + 1 == nums[curr + 1]) {
            } else {
                if (stoi(s) == nums[curr]) {
                    ans.push_back(s);  
                } else {
                    ans.push_back(s + "->" + to_string(nums[curr])); 
                }
                s.clear();
                count = 0;
            }
            curr++;
        }
        if (!s.empty()) {
            if (stoi(s) == nums.back()) {
                ans.push_back(s);
            } else {
                ans.push_back(s + "->" + to_string(nums.back()));
            }
        } else {
            ans.push_back(to_string(nums.back()));
        }

        return ans;
    }
};