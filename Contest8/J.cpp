#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
#define ll long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    k++;
    vector <int> v(n);

    for(int i=0; i<n; i++) cin >> v[i];
    unsigned ll dp[12][n];

    for(int i=0; i<n; i++){
        dp[0][i] = 0;
        dp[1][i] = n-i;
    }

    for(int i=2; i<=k; i++){
        for(int j=n-1; j>=0; j--){
            //cout << n << " " << j << endl;
            if(n-j <= i) {
                //cout << "HERE" << endl;
                dp[i][j] = 0; //5 - 4 > 2 -> 1 > 2
            }

            else{
                dp[i][j] = dp[i][j+1];
                if(v[j] < v[j+1]) dp[i][j] += dp[i-1][j+1];
            } 
        }
    }

    for(int i=0; i<=k; i++){
        for(int j=0; j<n; j++) cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << dp[k][0] << "\n";

  return 0;
}