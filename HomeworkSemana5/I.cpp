#include <bits/stdc++.h>

using namespace std;

#define ll long long

//pos sum

int soma(int pos, int sum, bool smaller, vector <vector <int>> &dp, vector <int> &n){
    if(pos == n.size()) return sum;
    if(dp[pos][sum] != -1) return dp[pos][sum];

    int ans = 0;
    int lim = (smaller) ? 9:n[pos];

    for(int i=0; i<=lim; i++){
        int newSmaller = smaller || (i<lim);
        int newSum = sum + i;

        ans = soma(pos, sum, smaller, dp, n);
    }

    return dp[pos][sum] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int l = 1; l<=t; l++){
        ll int a, b, k;
        vector <vector <int>> dp(12, vector <int> (12*9 + 5, -1));
        int cnt = 0;
        cin >> a >> b >> k;
        
        int i = a;
        while(i%k) i++;
        for(i; i<=b; i += k) if(!(sum(i)%k)) cnt++;

        cout << "Case " << l << ": " << cnt << "\n";

    }

    return 0;
}