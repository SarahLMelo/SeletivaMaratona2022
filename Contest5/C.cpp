#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <double> v(n);
        for(int i=0; i<n; i++) cin >> v[i];

        int bestAns = 75;
        if(n==1) bestAns = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;

                //double raz = (v[j]-v[i])/(j-i);
                int ans = 0;

                for(int k = 0; k<n; k++){
                    if(v[i]*(j-i) + (v[j]-v[i])*(k-i) != v[k]*(j-i)){
                        ans++;
                        //cout << i << " " << k << " " << v[i] + raz*(k-i) << " " << v[k] << "\n";
                    }
                }

                bestAns = min(ans, bestAns);
            }
        }

        cout << bestAns << "\n";
    }

    return 0;
}