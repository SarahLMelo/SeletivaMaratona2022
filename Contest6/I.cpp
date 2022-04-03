#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, r = 0;
    cin >> n >> k;
    vector <int> v(n), sum(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];

    while(r < n && sum[0]+v[r] <= k){
        sum[0] += v[r];
        r++;
    }

    int ans = r;

    for(int i=1; i<n; i++){
        sum[i] = max(sum[i-1] - v[i-1], 0);
        r = max(r, i);

        while(r < n && sum[i]+v[r] <= k){
            sum[i] += v[r];
            r++;
        }

        ans = max(ans, r-i);
    }

    cout << ans << "\n";

    return 0;
}