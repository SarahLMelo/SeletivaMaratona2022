#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

vector <ll> memoFat;

ll fat(int n){
    if(memoFat[n]) return memoFat[n];
    return memoFat[n] = ((fat(n-1)*n)%mod);
}

ll fExp(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans = ans*a % mod;
		a = a*a % mod;
		b >>= 1LL;
	}

	return ans;
}

ll inv(ll n){
    return fExp(n, mod-2);
}

ll c(ll n, ll k){
    return (mod+((((fat(n) * inv(fat(k)))%mod) * inv(fat(n-k))%mod)))%mod;
}


int main(){
    memoFat.assign(1e+5, 0);
    memoFat[0] = 1;

    int n;
    ll ans = 0;
    cin >> n;

    n--;
    for(int i=0; i<=n; i++){
        int a;
        cin >> a;

        ans += (a*c(n, i));
        ans %= mod;
    }

    cout << ans << "\n";

    return 0;
}