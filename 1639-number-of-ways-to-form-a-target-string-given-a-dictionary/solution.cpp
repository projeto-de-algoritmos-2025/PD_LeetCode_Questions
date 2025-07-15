#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long dp(int i, int k, vector<string>& words, string& target, vector<vector<long long>>& memo, vector<vector<int>>& counter) {
        if (i == target.size())
            return 1;
        if (k == words[0].size())
            return 0;
        if (memo[i][k] != -1)
            return memo[i][k];

        int c = target[i] - 'a';
        memo[i][k] = dp(i, k+1, words, target, memo, counter);
        memo[i][k] += counter[k][c] * dp(i+1, k+1, words, target, memo, counter);

        return memo[i][k] % 1000000007;
    }

    int numWays(vector<string>& words, string target) {
        int w_size = words[0].size();
        int t_size = target.size();

        vector<vector<int>> count(w_size, vector<int>(26, 0));
        for (auto& w : words) {
            for (int i = 0; i < w_size; i++) {
                count[i][w[i] - 'a'] += 1;
            }
        }

        vector<vector<long long>> memo(t_size+1, vector<long long>(w_size+1, -1));
        
        return dp(0, 0, words, target, memo, count);
    }
};

int main() {
    Solution sol;
    vector<string> words = {
        "abba",
        "baab"
    };
    string target = "bab";

    cout << sol.numWays(words, target) << "\n";
                        

    return 0;
}
