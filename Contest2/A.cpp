#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define ll long long


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n;
    vector <int> shops(n);

    for(int i=0; i<n; i++) cin >> shops[i];
    sort(shops.begin(), shops.end());

    cin >> q;
    while(q--){
        int l = 0, r = n, money;
        cin >> money;
        while(l<r){
            int m = (l+r)/2;
            if(shops[m]<=money) l = m+1;
            else r = m;
        }

        cout << l << "\n";
    }

    return 0;
}