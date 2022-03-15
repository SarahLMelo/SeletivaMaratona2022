#include <bits/stdc++.h>

using namespace std;

int solve(vector <vector <int>> &g, vector <int> &v, int m, int catAlready, int pos, vector <bool> &vis){
<<<<<<< Updated upstream
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

=======
    vis[pos] = true;
    if(catAlready>m) return 0;
    if(g[pos].empty()){
        catAlready += v[pos];
        //cout << "HERE: " << catAlready << " " << pos << "\n";
        if(catAlready>m) return 0;
        return 1;
    }

    int ans = 0;
    for(auto i:g[pos]){
        if(v[pos] == 1) ans += solve(g, v, m, catAlready+v[pos], i, vis);
        else ans += solve(g, v, m, 0, i, vis);
    }

>>>>>>> Stashed changes
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector <int> v(n);
<<<<<<< Updated upstream
    vector <bool> vis(n, 0);
=======
>>>>>>> Stashed changes
    vector <vector <int>> g(n);

    for(int i=0; i<n; i++) cin >> v[i];
    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
<<<<<<< Updated upstream
        g[y].push_back(x);
    }

    vis[0] = 1;
    cout << solve(g, v, m, v[0], 0, vis) << "\n";
=======
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        vector <bool> vis(n);
        int temp = solve(g, v, m, 0, i, vis);
        bool flag = true;
        for(int j =0; j<n && flag == true; j++){
            if(vis[j] == 0) flag = false;
        }
        if(flag == true) ans = max(temp, ans);
    }

    cout << ans << "\n";
>>>>>>> Stashed changes

    return 0;
}