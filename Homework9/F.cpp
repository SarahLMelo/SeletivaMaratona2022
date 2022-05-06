#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int;

void solve(int pos, int parent, vector <vector <int>> &g, vector <vector <int>> &memo){
    memo[pos][pos] = 0;

    for(auto i:g[pos]){
        if(i == parent) continue;

        memo[pos][i] = 1;
        memo[i][pos] = 1;

        solve(i, pos, g, memo);
    }
}

__int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector <vector <int>> g(n);

    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    return 0;
}