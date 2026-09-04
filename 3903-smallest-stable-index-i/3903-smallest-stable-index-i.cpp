class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int mn = nums[n - 1];

        vector<int> suf(n);
        suf[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            mn = min(mn, nums[i]);
            suf[i] = mn;
        }

        int mx = nums[0];

        for (int i = 0; i < n; ++i) {
            mx = max(mx, nums[i]);

            if (mx - suf[i] <= k)
                return i;
        }

        return -1;
    }
};