class Solution {
    bool isPalin(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }

    void find(vector<string>& path, vector<vector<string>>& ans, string s) {
        if (s.size() == 0) {  
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1); 
            if (isPalin(part)) {
                path.push_back(part);
                find(path, ans, s.substr(i + 1));
                path.pop_back();   // backtrack
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;   
        find(path, ans, s);
        return ans;
    }
};
