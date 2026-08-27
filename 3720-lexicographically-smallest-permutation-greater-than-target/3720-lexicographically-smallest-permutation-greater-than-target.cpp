class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26);

        for(char ch : s)
            freq[ch - 'a']++;

        int pos = 0;

        while(pos < target.size()) {
            int x = target[pos] - 'a';

            if(freq[x] == 0)
                break;

            freq[x]--;
            pos++;
        }

        while(pos >= 0) {
            if(pos < target.size()) {
                int need = target[pos] - 'a';

                for(int c = need + 1; c < 26; c++) {
                    if(freq[c] == 0)
                        continue;

                    string res = target.substr(0, pos);
                    res.push_back('a' + c);
                    freq[c]--;

                    for(int j = 0; j < 26; j++) {
                        while(freq[j]--)
                            res.push_back('a' + j);
                    }

                    return res;
                }
            }

            if(pos == 0)
                break;

            pos--;
            freq[target[pos] - 'a']++;
        }

        return "";
    }
};