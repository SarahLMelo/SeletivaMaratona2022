#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
#define int long long

int dp(int pos, int parPos, vector <vector <ii>> &g, vector <int> &memo){
    for(auto i:g[pos]){
        if(i.first == parPos) continue;

        memo[pos] = max(memo[pos], i.second + dp(i.first, pos, g, memo));
    }

    return memo[pos];
}

void dfs(int pos, int parPos, int parAns, vector <vector <ii>> &g, vector <int> &memo, vector <int> &ans){
    int max1 = 0, max2 = 0;

    for(auto i:g[pos]){
        if(i.first == parPos) continue; //É o pai
        int cur = i.second + memo[i.first];

        if (max1 < cur) swap(max1, cur); //Coloca o menor no cur
        if (max2 < cur) swap(max2, cur); //Coloca o menor no cur
    }

    ans[pos] = max(parAns, max1);

    for(auto i:g[pos]){
        if(i.first == parPos) continue;
        int cur = i.second + memo[i.first];

        int maxUp, temp;
        if(max1 == cur) temp = max2;
        else temp = max1;

        maxUp = max(parAns, temp);
        dfs(i.first, pos, i.second + maxUp, g, memo, ans);
    }

    return;
}

__int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--){
      int n;
      cin >> n;

      vector <vector <ii>> g(n);
      vector <int> ans(n, 0);
      vector <int> memo(n, 0);

      for(int i=0; i<n-1; i++){
          int x, y, w;
          cin >> x >> y >> w;

          x--;
          y--;

          g[x].push_back({y, w});
          g[y].push_back({x, w});
      }

      //Inicializando a dp
      dp(0, -1, g, memo);

      //Calculando para cada nó
      dfs(0, -1, 0, g, memo, ans);

      for(int i=0; i<n; i++){
          if(i) cout << " ";
          cout << ans[i];
      }

      cout << endl;
  } 

  return 0;
}