#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 1e9+7;

ll fastExp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a*a % mod;

        b >>= 1LL;
    }

    return ans;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;

        cout << fastExp(2, a+b-1) << "\n";
    }

}