#include <bits/stdc++.h>

using namespace std;

int dfs(vector <vector <int>> &g, vector <bool> &vis, int pos){
    int nLeafs = 0;
    stack <int> s;

    s.push(pos);
    while(!s.empty()){
        int temp = s.top();
        s.pop();

        if(vis[temp] == 1) continue;

        vis[temp] = 1;

        if(g[temp].size() == 1) nLeafs++;
        for(auto i:g[temp]) s.push(i);
    }

    return ceil(nLeafs/2.0);
}

int main(){
    int n;
    cin >> n;
    
    vector <vector <int>> g(n);
    vector <bool> vis(n, 0);

    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        if(vis[i] == 0) ans += dfs(g, vis, i);
    }

    std::cout << ans << "\n";

    return 0;
}