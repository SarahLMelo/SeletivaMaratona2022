#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector <ll> cost(n);
    vector <ll> dp(n, -1);

    for(int i=0; i<n; i++) cin >> cost[i];

    dp[0] = 0;
    for(int i=1; i<n; i++){
        ll ans = 1e18;
        for(int j=1; j<=k && i-j>=0; j++){
            ans = min(ans, abs(cost[i] - cost[i-j]) + dp[i-j]);
        }
        dp[i] = ans;
    }


    cout << dp[n-1] << "\n";

    return 0;
}