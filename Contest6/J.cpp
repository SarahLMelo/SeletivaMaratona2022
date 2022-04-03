#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fastExp(ll a, ll p){
    ll ans = 1;
    unsigned long long mod = 1e9 + 7;

    while(p){
      if(p&1) ans = ans*a % mod;
      a = a*a % mod;
      p >>= 1;
    }
  return ans;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        ll ans = 0;

        int count = 0;
        int temp = 1;

        while(temp <= k){
            count++;
            temp = temp << 1;
        }

        //cout << count << "\n";

        for(int i=0; i<count; i++){
            if(k%2){
                //cout << i << " HERE\n";
                ans = (ans + fastExp(n, i)) % ((ll)1e9 + 7);
            }
            k = k >> 1;
        }

        cout << ans << "\n";
    }

    return 0;
}

// 100