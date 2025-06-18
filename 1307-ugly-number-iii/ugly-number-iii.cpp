#define ll long long
class Solution {
public:

    ll lcm(ll a,ll b){
        return (1ll*a/__gcd(a,b))*b;
    }
    ll count(ll mid,ll a,ll b,ll c){
        return mid/a+mid/b+mid/c-mid/lcm(a,b)-mid/lcm(b,c)-mid/lcm(a,c)+mid/lcm(a,lcm(b,c));
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        ll low=0;
        ll high=2*1e9;
        ll ans=high;
        while(low<=high){
            ll mid=low+(high-low)/2;
            ll ugly=count(mid,a,b,c);
            if(ugly>=n){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return (int)ans;
    }
};