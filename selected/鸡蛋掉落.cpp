#include<vector>
using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int> > times(K + 1);
        for (int i = 0; i <= K; i++) {
            times[i].resize(N + 1);
            times[i][0] = 0;
        }
        for (int i = 0; i <= N; i++) {
            times[0][i] = 0;
            times[1][i] = i;
        }
    }
};