#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n){
        vector<int> H(n);
        int ans = 0;

        for(int i=0; i<n; i++){
            cin >> H[i];
        }

        //Caso do primeiro
        if(H[n-1]<H[0] && H[1]<H[0]) ans++;
        else if(H[n-1]>H[0] && H[1]>H[0]) ans++;


        //Caso do último
        if(H[n-2]<H[n-1] && H[0]<H[n-1]) ans++;
        else if(H[n-2]>H[n-1] && H[0]>H[n-1]) ans++;

        for(int i=1; i<n-1; i++){
            if(H[i-1]<H[i] && H[i+1]<H[i]) ans++;
            else if(H[i-1]>H[i] && H[i+1]>H[i]) ans++;
        }

        cout << ans << "\n";
        cin >> n;
    }

    return 0;
}