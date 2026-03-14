class Solution {
public:
    string getHappyString(int n, int k) {
        int size = pow(2, n - 1);
        if(3 * size < k) return "";
        string res = "";
        if(k <= size) res += 'a';
        else if(k <= 2*size){
            res += 'b';
            k -= size;
        }
        else{
            res += 'c';
            k -= 2*size;
        }
        string options[]= {"bc", "ac", "ab"};
        for(int i = 1; i < n; i++){
            size /= 2;
            string &ch = options[res.back() - 'a'];
            if(k <= size) res += ch[0];
            else{
                res += ch[1];
                k -= size;
            }
        }
        return res;
    }
};