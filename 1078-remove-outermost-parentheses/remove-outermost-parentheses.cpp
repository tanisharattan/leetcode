class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        string result;
        int count=0;
       
        for(int i=0;i<n;i++){
            if(s[i]=='(' && count++>0)result+=s[i];
            if(s[i]==')' && count-->1)result+=s[i];
        }
        return result;
    }
};