#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fastExp(ll a, ll p){
    ll ans = 1;
    unsigned long long mod = 1.8446744e+19;

    while(p){
      if(p&1) ans = ans*a % mod;
      a = a*a % mod;
      p >>= 1;
    }
  return ans;
}

ll findN(int p, int q){
    ll ans;
    ll delta = p*p - 4*q;

    if(delta >= 0) return ((p + (ll) sqrt(delta))/2);
    else return ((-p - (ll) sqrt(-delta))/2); 
}

int main(){
    int t;
    cin >> t;

    for(int i=1; i<=t; i++){
        int p, q, n;
        ll ans, a, b;
        cin >> p >> q >> n;

        a = findN(p, q);
        b = p - a;

        //cout << a << " " << b << "\n";

        ans = fastExp(a, n);
        //cout << ans << "\n";
        ans = (ans + fastExp(b, n))%((unsigned long long)1.8446744e+19);

        cout << "Case " << i << ": " << ans << "\n";
    }

    return 0;
}

/*

a + b = p
a*b = q;

a (p-a) = q;
a^2 - pa + q = 0

delta = p^2 - 4*q
(p + raiz(p^2 - 4*q)) / 2; -> A

*/