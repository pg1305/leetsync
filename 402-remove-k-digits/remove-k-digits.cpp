class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==1) return "0";
        vector<char> stack;
        for(char c : num ){
            while(!stack.empty() && stack.back()>c && k!=0){

                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }
        while(k>0 && !stack.empty()){
            stack.pop_back();
            k--;
        }
        string ans = "";
        bool leading = true;
        for(char c : stack){
            if(leading && c == '0') continue;
            leading = false;
            ans+=c;
        }
        return ans.empty() ? "0" : ans;

    }
}; 