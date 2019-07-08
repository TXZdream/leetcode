#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            dp[i] = false;
            for (int j = 0; j < i; j++) {
                if (dp[j] && has(s.substr(j, i - j), wordDict)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
private:
    bool has(string s, vector<string>& wordDict) {
        for (int i = 0; i < wordDict.size(); i++) {
            if (s == wordDict[i]) {
                return true;
            }
        }
        return false;
    }
};