#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1e9+7;

vector <ll> fat;

ll fastExp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans = ans*a % mod;
        a = a*a % mod;
        b >>= 1LL;
    }

    return ans;
}

ll inv(ll n){
    return fastExp(n, mod-2);
}

ll c(ll n, ll k){
    return (mod+((((fat[n] * inv(fat[k]))%mod) * inv(fat[n-k])%mod)))%mod;
}

int main(){
    fat.assign(2e5+5, 0);
    fat[0] = 1;
    for(int i=1; i<fat.size(); i++) fat[i] = (1LL*fat[i-1]*i)%mod;

    int t;
    cin >> t;

    while(t--){
        int n, k, x;
        cin >> n >> k >> x;

        ll ans = 1;
        if(k-(2*x) < 0 || n-x < 0 || n-x < k-(2*x)) ans = 0;
        else{
            ans = c(n, x);
            ans %= mod;
            ans *= (c(n-x, k-(2*x))*fastExp(2, k-(2*x)))%mod;
            ans %= mod;
        }

        cout << ans << "\n";
    }

}