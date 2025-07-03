class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gi=0;
        int si=0;
        int gs = g.size();
        int ss = s.size();
        int count=0;
        while(si<ss && gi<gs){
            if(g[gi]<=s[si]){
                gi++;
                count++;
            }
            si++;
        }
        return count;
    }
};