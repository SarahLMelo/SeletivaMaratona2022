#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

ll base = 997;
ll mod = 1e9+7;

vector <ll> potencias;
vector <ll> has;

void build(string &s){
    potencias[0] = 1;
    has[0] = s[0];

    for(int i = 1; i<s.size(); i++){
        potencias[i] = (potencias[i-1] * base)%mod;
        has[i] = ((has[i-1]*base) + s[i])%mod;
    }

    return;
}

void rk(string &s){
    ll size = s.size();
    potencias.resize(size + 1);
    has.resize(size + 1);

    build(s);
}

ll key(int l, int r){
    ll ans = has[r];
    if(l>0) ans = ((ans - potencias[r-l+1]*has[l-1]) % mod + mod) % mod;

    return ans;
}

int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--){
        string s, pattern;
        cin >> s >> pattern;
        
        rk(pattern);
        int comp = key(0, pattern.size()-1);

        rk(s);
        vector <int> ans;

        for(int i=0; i+pattern.size()-1 < s.size(); i++){
            if(key(i, i+pattern.size()-1) == comp) ans.push_back(i);
        }

        if(ans.size() == 0) cout << "Not Found\n";
        else{
            cout << ans.size() << "\n";
            for(int i=0; i<ans.size(); i++){
                if(i!=0) cout << " ";
                cout << ans[i]+1;
            }
            cout << "\n";
        }

        cout << "\n";
  }

  return 0;
}