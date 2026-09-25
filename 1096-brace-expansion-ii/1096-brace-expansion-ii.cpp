class Solution {
public:
    set<string> dfs(string &s, int &i) {
        set<string> ans, cur;
        cur.insert("");

        while (i < s.size() && s[i] != '}') {
            if (s[i] == '{') {
                i++;
                set<string> temp = dfs(s, i);
                i++;

                set<string> next;
                for (auto &a : cur) {
                    for (auto &b : temp) {
                        next.insert(a + b);
                    }
                }
                cur = next;
            }
            else if (s[i] == ',') {
                for (auto &x : cur)
                    ans.insert(x);

                cur.clear();
                cur.insert("");
                i++;
            }
            else {
                set<string> next;
                for (auto &x : cur) {
                    next.insert(x + s[i]);
                }
                cur = next;
                i++;
            }
        }

        for (auto &x : cur)
            ans.insert(x);

        return ans;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> result = dfs(expression, i);
        return vector<string>(result.begin(), result.end());
    }
};