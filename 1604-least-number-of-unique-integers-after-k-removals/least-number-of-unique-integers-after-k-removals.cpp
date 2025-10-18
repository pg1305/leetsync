class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for(int num:arr)freq[num]++;
        vector<int> freqArr;
        int count = 0;
        for(auto it:freq)freqArr.push_back(it.second);
        sort(freqArr.begin(), freqArr.end());
        for(int i = 0; i<freqArr.size(); i++){
            if(k > freqArr[i]){
                k-=freqArr[i];
                freqArr[i] = 0;
            }else{
                freqArr[i] -= k;
                k = 0;
            }
            if(freqArr[i]!=0)count++;
        }
        return count;
    }
};