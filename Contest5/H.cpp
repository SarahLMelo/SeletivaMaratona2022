#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, w;
vector <ii> v;
vector <int> dp;

int bt(int value){
    if(value >= n*1000) return 0;

    int &ans = dp[value];
    if(ans != -1) return ans;

    int pega = 0, nPega = 0;
    

    ans = max(pega, nPega);
    
    return ans;
}

int main(){
    cin >> n >> w;
    dp.assign(n*1000, -1);
    v.assign(n, {0, 0});

    for(int i=0; i<n; i++){
        int x, y;
        cin >> v[i].first >> v[i].second;
    }

    cout << bt(0, w) << "\n";

    return 0;
}