#include <bits/stdc++.h>

using namespace std;

void dfs(vector <vector <int>> &g, vector <int> &colors, bool color, int parent, int pos){
    if(colors[pos] != -1) return;
    colors[pos] = color;

    for(auto i:g[pos]){
        if(i==parent) continue;

        dfs(g, colors, !color, pos, i);
    }

    return;
}

int main(){
    int n;
    cin >> n;

    vector <vector <int>> g(n);
    vector <int> colors(n, -1);

    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(g, colors, 0, -1, 0);

    int n0, n1 = 0;
    for (auto i:colors) n1 += i;
    n0 = n-n1;

    cout << 1ll* n0*n1 - (n-1) << "\n";

    return 0;
}