#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
    struct AvailComp {
        bool operator()(const tuple<int,int,int>& a, const tuple<int,int,int>& b) const {
            // compare by price, then shop
            if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
            return get<1>(a) < get<1>(b);
        }
    };

    struct RentComp {
        bool operator()(const tuple<int,int,int>& a, const tuple<int,int,int>& b) const {
            // compare by price, then shop, then movie
            if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
            if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
            return get<2>(a) < get<2>(b);
        }
    };

    // (shop, movie) -> price
    unordered_map<int, unordered_map<int, int>> price;

    // for each movie -> set of available shops
    unordered_map<int, set<tuple<int,int,int>, AvailComp>> available;

    // global rented movies
    set<tuple<int,int,int>, RentComp> rented;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], p = e[2];
            price[shop][movie] = p;
            available[movie].insert({p, shop, movie});
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        if (!available.count(movie)) return res;
        auto &s = available[movie];
        int cnt = 0;
        for (auto it = s.begin(); it != s.end() && cnt < 5; ++it, ++cnt) {
            res.push_back(get<1>(*it));
        }
        return res;
    }

    void rent(int shop, int movie) {
        int p = price[shop][movie];
        available[movie].erase({p, shop, movie});
        rented.insert({p, shop, movie});
    }

    void drop(int shop, int movie) {
        int p = price[shop][movie];
        rented.erase({p, shop, movie});
        available[movie].insert({p, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for (auto it = rented.begin(); it != rented.end() && cnt < 5; ++it, ++cnt) {
            res.push_back({get<1>(*it), get<2>(*it)});
        }
        return res;
    }
};
