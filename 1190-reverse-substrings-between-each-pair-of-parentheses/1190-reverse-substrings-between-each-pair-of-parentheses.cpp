class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for(char c : s) {
            if(c != ')') {
                st.push(c);
            } else {
                string temp;

                while(st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }

                st.pop();

                for(char x : temp)
                    st.push(x);
            }
        }

        string ans;

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};