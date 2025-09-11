class Solution {
public:
    string sortVowels(string s) {
        vector<int> lower(26,0),upper(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                lower[s[i]-'a']++;
                s[i]='0';
            }
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                upper[s[i]-'A']++;
                s[i]='0';
            }
        }
        string ans;
        for(int i=0;i<26;i++){
            char c='A'+i;
            while(upper[i]){
                ans+=c;
                upper[i]--;
            }
        }
        for(int i=0;i<26;i++){
            char c='a'+i;
            while(lower[i]){
                ans+=c;
                lower[i]--;
            }
        }
        int first = 0,second= 0;
        while(second<ans.size()){
            if(s[first]=='0'){
                s[first]=ans[second];
                second++;
            }
            first++;
        }
        return s;
    }
};