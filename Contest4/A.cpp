#include <bits/stdc++.h>

using namespace std;

int unionFind(vector <int> &ds, int x){
    if(ds[x] != x) ds[x] = unionFind(ds, ds[x]);
    return ds[x];
}

void unionUnion(vector <int> &ds, vector <int> &sz, int a, int b){
    a = unionFind(ds, ds[a]);
    b = unionFind(ds, ds[b]);

    if(sz[a] < sz[b]) swap(a, b);
    if(a!=b) sz[a] += sz[b];
    ds[b] = a;

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector <int> doces(n);
    vector <int> sz(n, 1);

    for(int i=0; i<n; i++) doces[i] = i; //UnionBuild

    for(int i=0; i<k; i++){
        int d1, d2;
        cin >> d1 >> d2;
        --d1;
        --d2;

        unionUnion(doces, sz, d1, d2);
    }

    set <int> s;
    int happyCows = 0;

    for(auto i:doces) s.insert(unionFind(doces, i));
    for (auto i:s){
        happyCows += (sz[i]-1);
        //cout << i << " " << sz[i] << " ";
    }
    //cout << endl;
    
    cout << k-happyCows << "\n";

    return 0;
}