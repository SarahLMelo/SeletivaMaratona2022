#include <bits/stdc++.h>

using namespace std;

int unionFind(vector<int> &ds, int x){
    if(ds[x] != x) ds[x] = unionFind(ds, ds[x]);
    return ds[x];
}

void unionUnion(vector<int> &ds, vector<int> &sz, int x, int y){
    int a = unionFind(ds, ds[x]), b = unionFind(ds, ds[y]);
    if(sz[a] < sz[b]) swap(sz[a], sz[b]);
    if(a != b) sz[a] += sz[b];
    ds[b] = a;

    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector <int> ds(n+1);
    vector <int> sz(n+1, 1);

    for(int i=1; i<=n; i++){ //UnionBuild
        ds[i] = i;
    }

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        //for(auto i:sz) cout << i << " ";
        //cout << "\n";
        unionUnion(ds, sz, x, y);
    }

    //for(auto i:sz) cout << i << " ";
    //cout << "\n";
    set <int> s;
    for(int i=1; i<n+1; i++) s.insert(unionFind(ds, i));
    long long int ans = 1;

    for(int i=0; i< n - s.size(); i++) ans *=2;
    
    cout << ans << "\n";

}