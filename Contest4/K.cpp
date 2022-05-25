#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        int table[n][m];

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char test;
                cin >> test;

                table[i][j] = test - '0' ;
            }
        }
        
        bool ans = true;
        for(int i=0; i<n-1 && ans; i++){
            for(int j=0; j<m-1 && ans; j++){
                if(table[i][j]+table[i+1][j]+table[i][j+1]+table[i+1][j+1] == 3) ans = false;
            }
        }

        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}