#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector <int> v(n);

        for(int i=0; i<n; i++) cin >> v[i];

        int ans = 0;
        for(int i=n-2; i>=0; i--){
            if(v[i] != v[n-1]){
                ans++;
                if(i - ((n-1)-(i)) >= 0) i -= (n-1)-(i);
                else{
                    bool nfound = true;
                    for(int j=i-1; j>=0 && nfound; j--) if(v[j] != v[n-1]){nfound = false; ans++;}
                    i = -1;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}