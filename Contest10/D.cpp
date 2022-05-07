#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int ab[n*n+1], cd[n*n+1];
    int a[n], b[n], c[n], d[n];

    for(int i= 0; i<n; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    int cnt = 0;

     for(int i = 0; i<n; i++){
         for(int j = 0; j<n; j++){
             ab[cnt] = a[i]+b[j];
             cd[cnt] = c[i]+d[j];

             cnt++;
         }
     }

    //sort(ab.begin(), ab.end());
    sort(cd, cd + cnt);

    int ans = 0;
    //for(int i=0; i<cnt; i++) cout << cd[i] << " ";
    //cout << endl;

    for(int i=0; i<cnt; i++){
        //cout << ab[i] << " ";
        ans += (upper_bound(cd, cd + cnt, -ab[i]) - lower_bound(cd, cd + cnt, -ab[i]));
    }
    cout << endl;

    cout << ans << "\n";

    return 0;
}