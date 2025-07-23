class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int totalOnes = 0;
        for (int num : nums) {
            if (num == 1) totalOnes++;
        }

        int zerosLeft = 0, onesLeft = 0;
        int maxScore = INT_MIN;
        vector<int> result;

        for (int i = 0; i <= nums.size(); i++) {
            int score = zerosLeft + (totalOnes - onesLeft);
            if (score > maxScore) {
                maxScore = score;
                result = {i};
            } else if (score == maxScore) {
                result.push_back(i);
            }
            if (i < nums.size()) {
                if (nums[i] == 0) zerosLeft++;
                else onesLeft++;
            }
        }
        return result;
    }
};
