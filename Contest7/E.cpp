#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    ll ans = 1e18;

    cin >> n >> k;

    vector <int> teams(k, 0);

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        teams[x-1]++;
    }

    if(n==1 || k==1){
        cout << teams[0] << "\n";
        return 0;
    }
    
    sort(teams.begin(), teams.end());

    ll lT = 0, rT = k-1, limit = 0;

    while(lT<=rT){
        if(teams[lT]+teams[rT] <= ceil(k/2.0) && lT!=rT) lT++;
        rT--;
        limit++;
    }


    for(int i=teams[k-1]; i<=teams[k-1]+teams[k-2]; i++){
        ll temp = 0, l = 0, r = k-1;

        while(l<=r){
            if(teams[l]+teams[r] <= i && l!=r) l++;
            r--;
            temp++;
        }

        ans = min(ans, i*temp);
        if(temp == limit) break;
    }

    cout << ans << "\n";

    return 0;
}