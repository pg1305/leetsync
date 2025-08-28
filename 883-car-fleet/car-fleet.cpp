class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;
        for(int i = 0; i < n; i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());
        stack<double> st;
        for(auto &car: cars){
            int posn = car.first;
            int speed = car.second;
            double time = (double)(target - posn)/speed;
            if(st.empty() || time > st.top()) st.push(time);
            
        }
        return st.size();
    }
};