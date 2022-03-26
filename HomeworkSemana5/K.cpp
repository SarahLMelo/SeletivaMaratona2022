#include <bits/stdc++.h>

using namespace std;

int solve(vector <vector <int>> &g, vector <int> &dp, int x){
    if(dp[x] != -1) return dp[x];
    int ans = 0;
    for(auto i:g[x]) ans = max(ans, solve(g, dp, i) + 1);

    return dp[x] = ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector <vector <int>> g(n);
    vector <int> dp(n, -1);

    while(m--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }

    int ans = 0;
    for(int i=0; i<n; i++) ans = max(solve(g, dp, i), ans);

    cout << ans << "\n";

    return 0;
}