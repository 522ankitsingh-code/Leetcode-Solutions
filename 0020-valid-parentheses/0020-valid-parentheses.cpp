class Solution {
public:
    bool isValid(string s) {
        stack<int> sk;
        for(int i=0; i< s.length(); i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]== '{')
            {
                sk.push(s[i]);
            }

            else
            {
                if (sk.empty()) return false;
                
                if((s[i]==')' && sk.top()=='(') ||(s[i]==']' && sk.top()=='[') || (s[i]=='}' && sk.top()=='{'))
                    sk.pop();
                else return false;

            }

        }
        if(sk.empty()) return true;

        return false;
        
    }
};