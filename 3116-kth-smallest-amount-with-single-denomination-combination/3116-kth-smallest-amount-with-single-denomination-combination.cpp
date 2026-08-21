class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        long long lo = 1, hi = (long long)*min_element(coins.begin(), coins.end()) * k;
        
        auto countUpTo = [&](long long x) -> long long {
            long long total = 0;
           
            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                int bits = 0;
                bool overflow = false;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        l = lcm(l, (long long)coins[i]);
                        bits++;
                        if (l > hi) { overflow = true; break; }
                    }
                }
                if (overflow) continue;
                if (bits % 2 == 1) total += x / l;
                else total -= x / l;
            }
            return total;
        };
        
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countUpTo(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        
        return lo;
    }
};