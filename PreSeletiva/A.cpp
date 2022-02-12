#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        bool valid = true;
        int n, m, k;
        cin >> n >> m >> k;
        int table[n][m];
        /* 0 -> Branca
           1 -> Preta
           2 -> Verde */
        int blackNotVisited = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char c;
                cin >> c;
                if(c == '*'){
                    table[i][j] = 1;
                    blackNotVisited++;
                }
                else table[i][j] = 0;
            }
            cin.ignore(1); //Ignorar o \n
        }

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<m; j++){
                if(table[i][j] != 0){
                    table[i][j] = 2;
                    if(table[i][j] == 1) blackNotVisited--;
                    k--;
                    if(i-1<0 || j-1<0) k++;
                    else if(table[i-1][j-1] == 0) k++;
                    else if(i-1<0  || j+1>=m) k++;
                    else if(table[i-1][j+1] == 0) k++;

                    int a = 1;
                    bool flag = 1;
                    while(i-a>=0 && flag && j-a>=0 && j+a<m){
                        if(table[i-a][j-a] != 0 && table[i-a][j+a] != 0){
                            if(table[i-a][j-a] == 1) blackNotVisited--;
                             if(table[i-a][j+a] == 1) blackNotVisited--;
                            table[i-a][j-a] = 2;
                            table[i-a][j+a] = 2;
                        }
                        else flag = false;

                        a++;
                    }
                }
            }
        }

        if(valid == false || blackNotVisited>0 || k>0) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}