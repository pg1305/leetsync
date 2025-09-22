class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxF = 0;
        int totF = 0;
        for(int num: nums){ 
            freq[num]++;
            int frequency = freq[num];
            if(frequency > maxF){
                maxF = frequency;
                totF = frequency;
            }else if(frequency == maxF){
                totF += frequency;
            }
        }
        return totF;
        
    }
};