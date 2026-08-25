class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end());

        int x = k;

        while (st.find(x) != st.end()) {
            x += k;
        }

        return x;
    }
};