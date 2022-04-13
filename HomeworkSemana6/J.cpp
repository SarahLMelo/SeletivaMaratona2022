#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
  while(b){
    a %= b;
    swap(a,b);
  }

  return a;
}

int main(){
  int n;
  cin >> n;
  vector <int> v(n);
  for(int i=0; i<n; i++) cin >> v[i];

  vector <int> memo(n, 1);
  vector <bool> vis;
  vector <int> pais(n, -1);

  for(int i = n-2; i>=0; i--){
    vis.assign(n, 0);
    for(int j=i+1; j<n; j++){
      if(pais[j] != -1 && vis[pais[j]] == 1){
        vis[j] = 1;
        continue;
      }
      if(gcd(v[i], v[j]) > 1){
        vis[j] = 1;
        pais[j] = i;
        memo[i] = max(memo[j]+1, memo[i]);
      }
    }
  }

  //for(auto i: memo) cout << i << " ";
  //cout << endl;

  cout << *max_element(memo.begin(), memo.end());

  return 0; 
}