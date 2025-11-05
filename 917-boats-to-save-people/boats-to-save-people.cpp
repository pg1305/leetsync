class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        int n = people.size();
        int l = 0, r = n - 1;
        sort(people.begin(), people.end());
        while(l <= r){
            int sum = people[l] + people[r];
            if(sum <= limit){
                count++;
                l++;
                r--;
            }else{
                count++;
                r--;
            }
        }
        return count;
    }
};