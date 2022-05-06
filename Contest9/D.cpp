#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

void dfs(int x, int par, vector <int> &parents, vector <vector <int>> &g){
    parents[x] = par;

    for(auto i:g[x]){
        if(i==par) continue;
        dfs(i, x, parents, g);
    }

    return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); 

  int n;
  cin >> n;

  vector <int> parent(n);
  vector <vector <int>> g(n);

  for(int i=1; i<n; i++){
      int p;
      cin >> p;

      p--;

      g[p].push_back(i);
      g[i].push_back(p);
  }

  dfs(0, -1, parent, g);

  n--;

  vector <int> ans;

  while(n!=-1){
      ans.push_back(n+1);
      n = parent[n];
  }

  for(int i = ans.size()-1; i>=0; i--){
      if(i!= ans.size() - 1) cout << " ";
      cout << ans[i];
  }

  cout << "\n";

  return 0;
}