class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int min=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++){
            if(min>(arr[i]-arr[i-1])){
                min=arr[i]-arr[i-1];
            }
            
        }
        for(int i=1;i<arr.size();i++){
           if((arr[i]-arr[i-1])==min){
            res.push_back({arr[i-1],arr[i]});
           }
        }
        return res;
    }
};