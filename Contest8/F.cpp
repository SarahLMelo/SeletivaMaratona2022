#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    vector <ll> v(n);
    vector <ll> sortedV;

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    sortedV = v;

    sort(sortedV.begin(), sortedV.end());
    
    ll pos = n;
    ll find1 = sortedV[ceil(n/2.0) - 1], find2 = sortedV[n/2];

    for(int i=0; i<n && pos == n; i++){
        if(v[i] == find1 || v[i] == find2) pos = i;
    }

    cout << pos+ 1 << "\n";


  return 0;
}