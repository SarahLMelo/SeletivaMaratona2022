#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ii pair<ll, ll>

bool check(vector <ii> &v, ll k){
    int taken = 0;
    bool ansFound = false;

    for(ll i=0; i<v.size() && ansFound == false; i++){
        if(k - 1 - v[i].first <= taken && taken <= v[i].second) taken++;
        if(taken == k) ansFound = true;
    }

    return ansFound;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while(t--){
        ll n;
        cin >> n;

        vector <ii> v(n);
        for(ll i=0; i<n; i++) cin >> v[i].first >> v[i].second;

        ll l = 0, r = v.size()+1;
        while(l<r){
            ll m = (l+r)/2;
            if(check(v, m)) l = m+1;
            else r = m;
        }

        cout << --l << "\n";

    }

    return 0;
}