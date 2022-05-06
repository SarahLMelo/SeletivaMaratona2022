#include <bits/stdc++.h>

using namespace std;

int in[(int)(4 * 1e5 + 5)];
int out[(int)(4 * 1e5 + 5)];
int legenda[(int)(4 * 1e5 + 5)];
vector <int> roots;
vector <vector <int>> g;

bool cmp(int a, int b){
      return in[a] < in[b];
  }

class eulerTour{
  int t;

  void dfs(int i){
    in[i] = t++;
    legenda[in[i]] = i;

    for(auto x:g[i]){

      dfs(x);
    }

    out[i] = t;
  }

  public:
  eulerTour(int n){
    t = 0;
    
    for(auto i:roots)
      dfs(i);
  }

  

  int query(vector <int> &v){
    sort(v.begin(), v.end(), cmp);
    
    //for(auto i:v) cout << in[i] << " ";

    int max = 0, ans = 0;

    for(auto i:v){
        //cout << in[i] << " " << out[i] << " " << i << "\n";
        if(out[i] <= max) continue;
        
        ans += (out[i] - in[i]);
        max = out[i];
    }

    return ans;
  }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    g.assign(n, vector <int> {});
    
    for(int i=0; i<n; i++){
        int par;
        cin >> par;

        if(par) g[par-1].push_back(i);
        else roots.push_back(i);
    }

    eulerTour et(n);

    int q;
    cin >> q;

    while(q--){
        int x;
        cin >> x;

        vector <int> v(x);

        for(int i=0; i<x; i++){
            cin >> v[i];
            v[i]--;
        }

        cout << et.query(v) << "\n";
    }

    return 0;
}