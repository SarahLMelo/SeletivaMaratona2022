#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        long long int l, r, a;
        long long int ans;
        cin >> l >> r >> a;

        ans = floor((double)r/a) + r%a;

        long long int n = floor((double)((r - (r%a + 1))/a) + a-1);
        //cout << ans << " " << n << " " << r - (r%a + 1) << endl;
        if(l <= r - (r%a + 1)) ans = max(ans, n);

        cout << ans << "\n";
    }

    return 0;
}