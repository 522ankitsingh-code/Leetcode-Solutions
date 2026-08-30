class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0, maxIdx = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        int l = min(minIdx, maxIdx);
        int r = max(minIdx, maxIdx);

        int fromFront = r + 1;
        int fromBack = n - l;
        int bothSides = (l + 1) + (n - r);

        return min({fromFront, fromBack, bothSides});
    }
};