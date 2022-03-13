#include <bits/stdc++.h>

using namespace std;

bool solve(vector <int> &color, vector <vector <int>> &g, int pos, bool cor){
    if(color[pos] != -1){
        if(color[pos] != cor) return false;
        else return true;
    }
    color[pos] = cor;

    int ans = true;
    for(auto i:g[pos]){
        ans = ans & solve(color, g, i, !cor);
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int k=1; k<=t; k++){
        int n, m;
        cin >> n >> m;
        vector <int> color(n, -1);
        vector <vector <int>> g(n);

        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;

            --a;
            --b;

            g[a].push_back(b);
            g[b].push_back(a);
        }

        bool ans = true;
        for(int i= 0; i<n; i++){
            if(color[i] == -1){
                ans = ans & solve(color, g, i, 0);
            }
        }

        cout << "Scenario #" << k << ":\n";
        if(ans) cout << "No suspicious bugs found!\n";
        else cout << "Suspicious bugs found!\n";
    }

    return 0;
}