#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, k, ans;
        cin >> n >> k;
        k--;

        if(n%2){
            int nJump = k/(n/2);
            ans = (k+nJump)%n + 1;
            if(ans == 0) ans = n;
        }
        else{
            ans = k%n + 1;
            if(ans == 0) ans = n;
        }

        cout << ans << "\n";
    }

    return 0;
}