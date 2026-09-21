class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k);
        vector<long long> dp(k);

        for (int num : nums) {
            int x = num % k;
            vector<long long> ndp(k);

            ndp[x] = 1;

            for (int r = 0; r < k; r++) {
                ndp[(r * x) % k] += dp[r];
            }

            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }

            dp = ndp;
        }

        return ans;
    }
};