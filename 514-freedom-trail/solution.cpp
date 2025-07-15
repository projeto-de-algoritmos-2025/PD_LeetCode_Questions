#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp(int ri, int ki, string& ring, string& key, vector<vector<int>>& memo) {
        if (memo[ri][ki] != -1)
            return memo[ri][ki];

        if (ki == key.size())
            return 0;

        int ans = INT_MAX, min_dist;
        for (int i = 0; i < ring.size(); ++i) {
            if (ring[i] == key[ki]) {
                min_dist = min(abs(ri-i), (int) ring.size() - abs(ri-i));
                ans = min(ans, min_dist + 1 + dp(i, ki+1, ring, key, memo));
            }
        }
        return memo[ri][ki] = ans;
    }

    int findRotateSteps(string ring, string key) {
        vector<vector<int>> memo;
        memo.assign(ring.size() + 1, vector<int>(key.size() + 1, -1));
        return dp(0, 0, ring, key, memo);
    }
};

int main() {
    Solution sol;
    string ring = "godding", key = "godding";

    cout << sol.findRotateSteps(ring, key) << "\n";

    return 0;
}
