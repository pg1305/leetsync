class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<pair<long long, long long>> enemies;
        for (int i = 0; i < n; i++) {
            long long time = (health[i] + power - 1) / power;
            enemies.push_back({damage[i], time});
        }  
        sort(enemies.begin(), enemies.end(), [](auto &a, auto &b) { //sort by damage/time descending
            return a.first * b.second > b.first * a.second;
        });
        long long totalDPS = 0;
        for (auto &e : enemies) totalDPS += e.first;
        long long totalDamage = 0;
        for (auto &e : enemies) {
            long long dmg = e.first;
            long long time = e.second;
            totalDamage += totalDPS * time;
            totalDPS -= dmg;
        }
        return totalDamage;
    }
};
