#include <bits/stdc++.h>

using namespace std;

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

bool check(int size, string &s){
    int ans = false;

    for(int i=1; i+size<s.size()-1 && !ans; i++){
        //cout << s.substr(0, size+1) << " " << s.substr(i, size+1) << endl;
        if(key(0, size) == key(i, i+size)) ans = true;
    }

    //cout << ans << "\n";

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    rk(s);

    vector <int> matchSize;

    for(int i=0; i<s.size(); i++){
        if(key(0, i) == key(s.size()-1 - i, s.size()-1)) matchSize.push_back(i);
        //else{
            //cout << key(0, i) << " " << key(s.size()-1 - i, s.size()-1) << "\n";
            //cout << s.substr(0, i+1) << " " << i << " " << s.substr(s.size()-1 - i, s.size()) << "\n" << endl;
        //}
    }

    int l=0, r = matchSize.size();

    //cout << matchSize.size() << "\n";

    while(l<r){
        int mid = (l+r)/2;

        if(check(matchSize[mid], s)){
            //cout << matchSize[mid] << " HERE\n";
            l = mid+1;
        }
        else{
            r = mid;
        }
    }

    l--;

    if(l==-1) cout << "Just a legend\n";
    else cout << s.substr(0, matchSize[l]+1) << "\n";

    return 0;
}

//aaaaaa