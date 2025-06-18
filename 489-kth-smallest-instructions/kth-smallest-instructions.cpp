using ll = long long;
class Solution {
private:
    // variables for calculations later
    ll total_combinations;
    ll base_rank = 0;
    // combination calculation
    ll combination(ll a, ll b) {
        if(b > a-b) b = a-b;
        ll ret = 1;
        for(ll higher = a-b+1, lower = 1; higher <= a; ++higher, ++lower)
            ret *= higher, ret /= lower;
        return ret;
    }
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        // init starting combinations
        total_combinations = combination(destination[0]+destination[1],destination[1]);
        string ret = "";
        solve(k,ret,destination[1],destination[0]);
        return ret;
    }

    void solve(const int& k, string& ret, ll H_count, ll V_count) {
        // base case, can't add any more
        if(!H_count && !V_count) return;
        // if you can't add H, add V
        if(!H_count) {
            ret.push_back('V');
            solve(k,ret,H_count,V_count-1);
            return;
        // if you can't add V, add H
        } else if(!V_count) {
            ret.push_back('H');
            solve(k,ret,H_count-1,V_count);
            return;
        }
        // calculate string rank if V is inserted here
        ll V_rank = total_combinations - combination(H_count+V_count-1,H_count) + 1;
        // if new rank is out of bounds, add H to preserve old rank
        // update number of possible combinations
        if(V_rank > k) {
            ret.push_back('H');
            total_combinations = base_rank + combination(H_count+V_count-1,H_count-1);
            solve(k,ret,H_count-1,V_count);
        // if new rank is within bounds, add V to increase rank
        // update base rank for future operations
        } else if(V_rank <= k) {
            ret.push_back('V');
            base_rank = V_rank - 1;
            solve(k,ret,H_count,V_count-1);
        }
    }
};