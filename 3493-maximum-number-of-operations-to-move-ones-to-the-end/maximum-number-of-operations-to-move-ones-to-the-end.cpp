class Solution {
public:
    int maxOperations(string s) {
        int oneCount = 0, res = 0;
        bool canAdd = true;
        for(char c : s){
            if(c == '1'){
                oneCount++;
                canAdd = true;
            }
            else{
                if(canAdd) res += oneCount;
                canAdd = false; 
            }
        }
        return res;
    }
};