class Solution {
public:
    using P = pair<long long, vector<int>>;

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<int, 4>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        }

        sort(a.begin(), a.end());

        vector<int> starts(n);
        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];

        vector<vector<P>> dp(n + 1, vector<P>(5));

        auto better = [&](P x, P y) {
            if (x.first != y.first)
                return x.first > y.first;

            sort(x.second.begin(), x.second.end());
            sort(y.second.begin(), y.second.end());

            return x.second < y.second;
        };

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                P skip = dp[i + 1][k];

                int j = upper_bound(starts.begin() + i + 1, starts.end(), a[i][1])
                        - starts.begin();

                P take = dp[j][k - 1];
                take.first += a[i][2];
                take.second.push_back(a[i][3]);

                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        sort(dp[0][4].second.begin(), dp[0][4].second.end());
        return dp[0][4].second;
    }
};