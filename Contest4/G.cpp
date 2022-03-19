#include <bits/stdc++.h>

using namespace std;

int unionFind(vector <int> &ds, int x){
    if(ds[x] != x) ds[x] = unionFind(ds, ds[x]);
    return ds[x];
}

void unionBuild(vector <int> &ds, vector <long long int> &sz, vector <long long int> &edges, int a, int b){
    a = unionFind(ds, a);
    b = unionFind(ds, b);

    if(sz[a]<sz[b]) swap(a, b);
    if(a!=b){
        sz[a] += sz[b];
        edges[a] += edges[b];
    }
    ds[b] = a;
    edges[a]++;

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector <int> ds(n);
    vector <long long int> sz(n, 1);
    vector <long long int> edges(n, 0);

    for(int i=0; i<n; i++) ds[i] = i; //UnionBuild

    while(m--){
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        //cout << x << " " << y << "\n";
        //for(auto i:ds)cout << i << " ";
        //cout << endl;
        unionBuild(ds, sz, edges, x, y);
        //cout << "HERE" << endl;
    }

    bool flag = true;
    set <int> s;

    for(auto i:ds) s.insert(i);

    for(auto i:s) if(edges[i] != (sz[i]*(sz[i]-1)/2)) flag = false;

    if(flag) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}