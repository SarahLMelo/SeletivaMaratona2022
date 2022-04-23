#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
#define int long long
#define inf 1e9+7

int bt(vector <int> &v, int pos){
    if(*max_element(v.begin(), v.end()) == 0) return 0;
    if(pos+2 >= v.size()) return inf;

    int flip, notFlip;
    notFlip = bt(v, pos+1) + 1;

    v[pos] ^= v[pos];
    v[pos+1] ^= v[pos+1];
    v[pos+2] ^= v[pos+2];

    flip = bt(v, pos+1) + 1;

    if(notFlip < flip){
        v[pos] ^= v[pos];
        v[pos+1] ^= v[pos+1];
        v[pos+2] ^= v[pos+2];

        return notFlip;
    }

    return flip;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector <int> v(20);
    for(int i=0; i<20; i++) cin >> v[i];

    cout << bt(v, 0);

    return 0;
}