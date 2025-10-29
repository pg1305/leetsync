class Solution {
public:
    int smallestNumber(int n) {
        string bin = "";
        int i = n;
        while(i > 0){
            int bit = i % 2;
            bin += to_string(bit);
            i /= 2;
        }
        int k = bin.size();
        return pow(2,k) - 1;
    }
};