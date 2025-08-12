class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        char curr;
        for(char c :s){
            if(c=='('||c=='['||c=='{'){
                st.push(c);
            }
            else{
                if(st.empty())return false;
            
            curr=st.top();
            st.pop();
            if(curr=='('&& c!=')')return false;
            else if(curr=='['&& c!=']')return false;
            else if(curr=='{' && c!='}')return false;
        }
    }
  
      return st.empty();
    }
};