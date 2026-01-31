class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = letters[0];
        int flag = 0;
        for(char &c:letters){
            if(!flag){
                if(c > target){
                    res = c;
                    flag = 1;
                }
            }else{
                if(c > target && c< res) res = c;
            }
        }
        return res;
    }
};