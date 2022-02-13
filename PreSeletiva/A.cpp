#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

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
            for(int j = 0; j<m; j++){
                if(table[i][j] != 0){
                    int a = 0;
                    int toReduce = 0;
                    while(i-a>=0 && j+a<m && table[i-a][j+a]!=0 && table[i-a][j-a] !=0 && j-a >=0){
                        if(table[i-a][j+a] == 1){
                            table[i-a][j+a] = 3;
                            toReduce++;
                        }
                        if(table[i-a][j-a] == 1){
                            table[i-a][j-a] = 3;
                            toReduce++;
                        }

                        a++;
                    }

                    a--;
                    if(a>=k){
                        blackNotVisited -= toReduce;
                        a = 0;
                         while(i-a>=0 && j+a<m && table[i-a][j+a]!=0 && table[i-a][j-a] !=0 && j-a >=0){
                            if(table[i-a][j+a] == 3) table[i-a][j+a] = 2;

                            if(table[i-a][j-a] == 3) table[i-a][j-a] = 2;

                            a++;
                        }
                    }
                    
                    else{
                        a = 0;
                        while(i-a>=0 && j+a<m && table[i-a][j+a]!=0 && table[i-a][j-a] !=0 && j-a >=0){
                            if(table[i-a][j+a] == 3) table[i-a][j+a] = 1;

                            if(table[i-a][j-a] == 3) table[i-a][j-a] = 1;

                            a++;
                        }
                    }
                }
            }
        }
        if(blackNotVisited!=0) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}