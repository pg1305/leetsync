class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> numer;
        for(string num:nums) numer.insert(stoi(num, 0 , 2));
        int n = nums.size();
        for(int num = 0; num <= n; num++){
            if(numer.find(num) == numer.end()){
                string res = bitset<16>(num).to_string();
                return res.substr(16-n);
            }
        }
        return "";
    }
};