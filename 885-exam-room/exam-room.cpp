class ExamRoom {
    int N;
    set<int> seats;
public:
    ExamRoom(int n) {
        N = n;
    }
    
    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }
         int bestSeat = 0;
        int maxDist = *seats.begin();  // distance from 0 to first occupied seat

        int prev = -1;
        for (int s : seats) {
            if (prev != -1) {
                int dist = (s - prev) / 2;
                if (dist > maxDist) {
                    maxDist = dist;
                    bestSeat = prev + dist;
                }
            }
            prev = s;
        }

        if ((N - 1) - *seats.rbegin() > maxDist) {
            bestSeat = N - 1;
        }

        seats.insert(bestSeat);
        return bestSeat;
    }
    void leave(int p) {
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */