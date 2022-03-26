#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
typedef pair <int, int> ii;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--){
        int n, k;
        cin >> n >> k;

        vector <ll> dpL (n, inf);
        vector <ll> dpR (n, inf);
        vector <int> pos(k);


        for(int i=0; i<k; i++){
            cin >> pos[i];
            pos[i]--;
        }

        for(int i=0; i<k; i++){
            cin >> dpL[pos[i]];
            dpR[pos[i]] = dpL[pos[i]];
        }

        for(int i=1; i<n; i++) dpR[i] = min(dpR[i], dpR[i-1]+1);
        for(int i=n-2; i>=0; i--) dpL[i] = min(dpL[i], dpL[i+1]+1);

        for(int i=0; i<n; i++){
            if(i != 0) cout << " ";
            cout << min(dpL[i], dpR[i]);
        }
        cout << endl;
    }

    return 0;
}

/*
6 2
2 5
14 16
*/