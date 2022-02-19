#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, ans = 1;
        cin >> n;
        int moedas[n];
        
        for(int i=0; i<n; i++){
            cin >> moedas[i];
        }

        long long maiorPossivel = moedas[0];
        for(int i=1; i<n-1; i++){
            if(maiorPossivel + moedas[i]<moedas[i+1]){
                ans++;
                maiorPossivel += moedas[i];
            }
        }

        cout << ++ans << "\n";
    }

    return 0;
}