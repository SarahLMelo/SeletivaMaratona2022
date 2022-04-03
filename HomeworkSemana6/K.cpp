#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

ll gdc(ll a, ll b){
  while(b){
    a %= b;
    swap(a, b);
  }

  return a;
}

ll fastExp(ll a, ll p){
    ll ans = 1;
    ll mod = 1e18;
    while(p){
      if(p&1) ans = ans*a % mod;
      a = a*a % mod;
      p >>= 1;
    }
  //cout << ans << "\n";
  return ans;
}

ll primes(ll n){
  ll ans = 0;
  vector <int> v(40, 1);
  if(!(n%2)){
    int exp = 0;
    while(!(n%2)){
      exp++;
      n /=2;
    }

    if(exp>1) v[exp] = v[exp] *= fastExp(2, exp);
  }

  for(ll i=3; i*i<=n; i++){
    int exp = 0;
    while(!(n%i)){
      exp++;
      n /= i;
    }

    if(exp>1) v[exp] = v[exp] *= fastExp(i, exp);
  }

  ans = *max_element(v.begin(), v.end());

  return ans;
}

int main(){
  int n;
  cin >> n;

  vector <ll> v(n);
  for(int i=0; i<n; i++) cin >> v[i];

  if(n>1) v[0] = __gcd(v[0], v[1]);
  for(ll i = 2; i<n; i++) v[0] = __gcd(v[0], v[i]);

  if(v[0] > 1){
    ll ans = primes(v[0]);
    if(ans > 1) cout << v[0] << "\n";
    else cout << "NO CIVIL WAR\n";
  }

  else cout << "NO CIVIL WAR\n";

}