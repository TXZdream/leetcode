#include<iostream>
#include<vector>
using namespace std;

class ExamRoom {
public:
    ExamRoom(int N) {
        seats = vector<int>(N);
        for (int i = 0; i < N; i++) {
            seats[i] = 0;
        }
    }
    
    int seat() {
        int max = 0;
        int maxSeat;
        int currZeros = 0;
        int front, end;
        bool flag = true;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i]) {
                flag = false;
                currZeros = 0;
                continue;
            } else {
                if (currZeros++ == 0) {
                    front = i;
                }
                end = i;
            }
            if (front == 0) {
                if (end - front + 1 > max) {
                    maxSeat = 0;
                    max = end - front + 1;
                }
            } else if (i == seats.size() - 1) {
                if (end - front + 1 > max) {
                    maxSeat = i;
                }
            } else {
                int curr = (end - front + 1) / 2 + (end - front + 1) % 2;
                if (curr > max) {
                    max = curr;
                    maxSeat = (front + end) / 2;
                }
            }
        }
        if (flag) {
            maxSeat = 0;
        }
        seats[maxSeat] = 1;
        return maxSeat;
    }
    
    void leave(int p) {
        seats[p] = 0;
    }
private:
    vector<int> seats;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */