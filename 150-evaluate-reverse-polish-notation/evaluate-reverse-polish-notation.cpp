class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string& token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                if(token == "+") s.push(b+a);
                else if(token == "-") s.push(b-a);
                else if(token == "*") s.push(b*a);
                else if(token == "/") s.push(b/a);
            }else{
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};