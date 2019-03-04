#include<iostream>
#include<vector>
using namespace std;

class RLEIterator {
public:
    RLEIterator(vector<int> A) {
        coding = A;
    }
    
    int next(int n) {
        for (int i = 0; i < coding.size(); i+=2) {
            if (coding[i] >= n) {
                coding[i] -= n;
                return coding[i + 1];
            }
            n -= coding[i];
            coding[i] = 0;
        }
        return -1;
    }
private:
    vector<int> coding;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */