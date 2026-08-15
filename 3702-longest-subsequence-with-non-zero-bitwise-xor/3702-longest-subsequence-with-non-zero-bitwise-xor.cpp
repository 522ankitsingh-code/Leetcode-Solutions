class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
      int n = nums.size();
      int xr = 0;
      int zeroes = 0;
      for (int x : nums) {
        xr ^= x;
        if (x == 0)
        zeroes++;
      }
      if(xr != 0)
      return n;

      if(zeroes == n)
      return 0;
      return n - 1;

    }
};