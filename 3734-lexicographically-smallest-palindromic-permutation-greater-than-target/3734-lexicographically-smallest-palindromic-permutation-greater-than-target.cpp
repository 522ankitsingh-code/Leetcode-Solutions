class Solution {
public:
    string makePalindrome(string left, int mid) {
        string ans = left;

        if (mid != -1)
            ans += char('a' + mid);

        string rev = left;
        reverse(rev.begin(), rev.end());
        ans += rev;

        return ans;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        int mid = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                if (mid != -1)
                    return "";
                mid = i;
            }
        }

        vector<int> half(26);

        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        int k = n / 2;

       
        vector<int> rem = half;
        string left = "";
        bool possible = true;

        for (int i = 0; i < k; i++) {
            int x = target[i] - 'a';

            if (rem[x] == 0) {
                possible = false;
                break;
            }

            rem[x]--;
            left += target[i];
        }

        if (possible) {
            string candidate = makePalindrome(left, mid);

            if (candidate > target)
                return candidate;
        }

       
        for (int i = k - 1; i >= 0; i--) {
            vector<int> cur = half;
            bool ok = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (cur[x] == 0) {
                    ok = false;
                    break;
                }

                cur[x]--;
            }

            if (!ok)
                continue;

            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (cur[c] == 0)
                    continue;

                string newLeft = target.substr(0, i);
                newLeft += char('a' + c);

                cur[c]--;

                for (int j = 0; j < 26; j++)
                    newLeft.append(cur[j], char('a' + j));

                string candidate = makePalindrome(newLeft, mid);

                if (candidate > target)
                    return candidate;

                cur[c]++;
            }
        }

        return "";
    }
};