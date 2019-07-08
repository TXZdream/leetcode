#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
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
        vector<string> ret;
        if (!dp[s.size()]) {
            return ret;
        }
        return wordBreak(s, s.size(), dp, wordDict);
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
    vector<string> wordBreak(string& s, int end, vector<bool> dp, vector<string>& wordDict) {
        vector<string> ret;
        for (int i = end - 1; i >= 0; i--) {
            if (dp[i] && has(s.substr(i, end-i), wordDict)) {
                if (i == 0) {
                    ret.push_back(s.substr(i, end-i));
                    break;
                } else {
                    vector<string> tmp = wordBreak(s, i, dp, wordDict);
                    for (int j = 0; j < tmp.size(); j++) {
                        ret.push_back(tmp[j] + " " + s.substr(i, end-i));
                    }
                }
            }
        }
        return ret;
    }
};