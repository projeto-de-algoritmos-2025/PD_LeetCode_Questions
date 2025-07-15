#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dp(int i, int j, string& s, string& p, vector<vector<int>>& memo) {
        if (memo[i][j] != -1)
            return memo[i][j];
        
        bool ans;
        if (i >= s.size() && j >= p.size())
            ans = true;
        else if (j >= p.size())
            ans = false;
        else {
            bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');

            if ((j+1) < p.size() && p[j+1] == '*')
                ans = dp(i, j+2, s, p, memo) || (match && dp(i+1, j, s, p, memo));
            else if (match)
                ans = dp(i+1, j+1, s, p, memo);
            else
                ans = false;
        }

        return memo[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> memo;
        memo.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dp(0, 0, s, p, memo);
    }
};

int main() {
    Solution sol;
    string s = "ab", p = ".*";

    cout << sol.isMatch(s, p) << "\n";
}
