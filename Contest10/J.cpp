#include <bits/stdc++.h>

using namespace std;

int main(){
    int c, n;
    cin >> c >> n;

    while(c != 0){
        vector <int> prefixModSum(n, 0);
        for(int i=0; i<n; i++){
            int x;
            cin >> x;

            if(!i) prefixModSum[i] = x%c;
            else prefixModSum[i] = (prefixModSum[i-1]+x)%c;
        }

        int l = 0, r = 1;

        while(l<n){
            if(l>1){
                if(!((prefixModSum[r-1] - prefixModSum[l])%c)) break;
                else{
                 if(r < n && prefixModSum[r-1] - prefixModSum[l] <= c) r++;
                 else l++;
                }
            }
        }

        for(int i = l; i<r; i++){
            cout << i << " ";
        }
        cout << endl;

        cin >> c >> n;
    }

    return 0;
}