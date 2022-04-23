#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  if(n>=31) cout << m << "\n";
  else cout << (m % ((int)(pow(2, n)))) << "\n";

  return 0;
}