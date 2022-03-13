#include <bits/stdc++.h>

using namespace std;

int solve(vector <vector <int>> &g, vector <int> &v, int m, int catAlready, int pos, vector <bool> &vis){
    vis[pos] = 1;
    if(catAlready>m) return 0;
    int folha = true;

    int ans = 0;
    for(auto i:g[pos]){
        if(vis[i] == 1) continue;
        folha = false;
        if(v[i] == 1) ans += solve(g, v, m, catAlready+1, i, vis);
        else ans += solve(g, v, m, 0, i, vis);
    }


    if(folha == true){
        if(catAlready>m) return 0;
        return 1;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector <int> v(n);
    vector <bool> vis(n, 0);
    vector <vector <int>> g(n);

    for(int i=0; i<n; i++) cin >> v[i];
    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vis[0] = 1;
    cout << solve(g, v, m, v[0], 0, vis) << "\n";

    return 0;
}