#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    bool firstTime = true;
    cin >> t;

    while(t--){
        int cnt = 0, n;
        vector <int> a, b, c, d;
        vector <ll int> sumAB, sumCD;
        
        cin >> n;
        for(int i=0; i<n; i++){
            int x, y, z, w;
            cin >> x >> y >> z >> w;
            
            a.push_back(x);
            b.push_back(y);
            c.push_back(z);
            d.push_back(w);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                sumAB.push_back(a[i]+b[j]);
                sumCD.push_back(c[i]+d[j]);
            }
        }

        sort(sumAB.begin(), sumAB.end());
        sort(sumCD.begin(), sumCD.end());

        for(auto i:sumAB){
            cnt += (upper_bound(sumCD.begin(), sumCD.end(), (-i)) - lower_bound(sumCD.begin(), sumCD.end(), (-i)));
        }

        if(firstTime == false) cout << "\n";
        cout << cnt << "\n";
        firstTime = false;
    }


    return 0;
}