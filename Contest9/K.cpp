#include <bits/stdc++.h>

using namespace std;

typedef pair<int, vector <int>> iv;

int dp(int pos, int parPos, vector <iv> &g, vector <int> &memo){
    for(auto i:g[pos].second){
        if(i == parPos) continue;

        memo[pos] = max(memo[pos], g[pos].first + dp(i, pos, g, memo));
    }

    return memo[pos];
}

void dfs(int pos, int parPos, int parAns, vector <iv> &g, vector <int> &memo, vector <int> &ans){
    int max1 = 0, max2 = 0;

    for(auto i:g[pos].second){
        if(i == parPos) continue;
        int cur = g[pos].first + memo[i];

        if (max1 < cur) swap(max1, cur);
        if (max2 < cur) swap(max2, cur);
    }

    //cout << "here" << endl;

    ans[pos] = max(parAns, max1);

    for(auto i:g[pos].second){
        if(i == parPos) continue;
        int cur = g[pos].first + memo[i];

        int maxUp, temp;
        if(max1 == cur) temp = max2;
        else temp = max1;

        maxUp = max(parAns, temp);
        dfs(i, pos, g[pos].first + maxUp, g, memo, ans);
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    //cout << "here" << endl;

    vector <iv> g(n);
    vector <int> ans(n, 0);
    vector <int> memo(n, 0);

    //cout << "here" << endl;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        g[i].first = x;
        //cout << "here" << endl;
    }
    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        g[x].second.push_back(y);
        g[y].second.push_back(x);
    }

    dp(0, -1, g, memo);

    dfs(0, -1, 0, g, memo, ans);

    cout << *max_element(ans.begin(), ans.end());
    cout << endl;

  return 0;
}