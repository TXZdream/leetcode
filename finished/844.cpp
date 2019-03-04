#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int SIndex = S.length() - 1;
        int TIndex = T.length() - 1;
        int SSharpCount = 0;
        int TSharpCount = 0;
        while (1) {
            if (SIndex < 0 && TIndex < 0) {
                return true;
            }
            
            if (SIndex >= 0) {
                if (S[SIndex] == '#') {
                    SSharpCount++;
                    SIndex--;
                    continue;
                } else if (SSharpCount != 0) {
                    SIndex--;
                    SSharpCount--;
                    continue;
                } else if (TIndex < 0) {
                    return false;
                }
            }

            if (TIndex >= 0) {
                if (T[TIndex] == '#') {
                    TIndex--;
                    TSharpCount++;
                    continue;
                } else if (TSharpCount != 0) {
                    TIndex--;
                    TSharpCount--;
                    continue;
                } else if (SIndex < 0) {
                    return false;
                }
            }

            if (SIndex >= 0 && TIndex >= 0) {
                if (S[SIndex] == T[TIndex]) {
                    SIndex--;
                    TIndex--;
                    continue;
                } else {
                    return false;
                }
            }
        }
    }
};