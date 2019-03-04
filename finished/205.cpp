#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> charMap1;
        map<char, char> charMap2;
        for (int i = 0; i < s.size(); i++) {
            if (!charMap1.count(s[i])) {
                if (charMap2.count(t[i])) {
                    return false;
                } 
                charMap1[s[i]] = t[i];
                charMap2[t[i]] = s[i];
                continue;
            }
            if (charMap1[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};