#include <bits/stdc++.h>

using namespace std;

int resposta[8][8];

#define endl "\n";

bool isValidConfiguration(int (&table)[8][8]){
    bool ans = true;
    for(int i=0; i<8 && ans == true; i++){
        for(int j=0; j<8 && ans == true; j++){
            //Check Vertical e Horizontal
            for(int n = 0; n<8 && ans == true; n++){
                if(table[i][j] == table[n][j] && n!=i) ans = false;
                if(table[i][j] == table[i][n] && n!=j) ans = false;
            }

            int duplicates = 0;
            
            //Check Quadrante

            if(floor((double)i/4.0) == 0){
                if(floor((double)j/4.0) == 0){
                    for(int n=0; n<4 && ans == true; n++){
                        for(int m=0; m<4 && ans == true; m++){
                            if(i!=n && j!=m && table[i][j] == table[n][m]){
                                if(duplicates == 0) duplicates++;
                                else ans = false;
                            }
                        }
                    }
                }
                else{
                    for(int n=0; n<4 && ans == true; n++){
                        for(int m=4; m<8 && ans == true; m++){
                            if(i!=n && j!=m && table[i][j] == table[n][m]){
                                if(duplicates == 0) duplicates++;
                                else ans = false;
                            }
                        }
                    }
                }
            }

            if(floor((double)i/4.0) == 1){
                if(floor((double)j/4.0) == 0){
                    for(int n=4; n<8 && ans == true; n++){
                        for(int m=0; m<4 && ans == true; m++){
                            if(i!=n && j!=m && table[i][j] == table[n][m]){
                                if(duplicates == 0) duplicates++;
                                else ans = false;
                            }
                        }
                    }
                }
                if(floor((double)j/4.0) == 1){
                    for(int n=4; n<8 && ans == true; n++){
                        for(int m=4; m<8 && ans == true; m++){
                            if(i!=n && j!=m && table[i][j] == table[n][m]){
                                if(duplicates == 0) duplicates++;
                                else ans = false;
                            }
                        }
                    }
                }
            }

        }
    }

    if(ans == true){
        for(int i=0; i<8; i++) for(int j=0; j<8; j++) resposta[i][j] = table[i][j];
    }
    return ans;
}

bool bt(int posI, int posJ, int (&table)[8][8], vector <int> &freq){
    if(posI == 8) return isValidConfiguration(table);

    if(table[posI][posJ] == 0){
        bool possible = false;
        for(int i=1; i<=8 && possible == false; i++){
            if(freq[i]==8) continue;
            freq[i]++;
            table[posI][posJ] = i;
            if(posJ==7){
                possible = possible | bt(posI+1, 0, table, freq);
            }
            else possible = possible | bt(posI, posJ+1, table, freq);
            if(possible == false){
                table[posI][posJ] = 0;
                freq[i]--;
            }
        }
        //cout << posI << " " << posJ << endl;
        return possible;
    }
    else{
        if(posJ==7) return bt(posI+1, 0, table, freq);
        else return bt(posI, posJ+1, table, freq);
    }

}

int main(){
    int t;
    cin >> t;
    
    for(int k=1; k<=t; k++){
        int table[8][8];
        vector <int> freq(9, 0);

        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                cin >> table[i][j];
                freq[table[i][j]]++;
            }
        }

        cout << "Test case #" << k << ": ";

        bool ans = bt(0, 0, table, freq);

        if(ans == true)for(int i=0; i<8; i++){
            for(int j=0; j<8; j++) if(resposta[i][j] == 0) ans = false;
        }

        if(ans == true){
            cout << "YES\n";
            for(int i=0; i<8; i++){
                cout << resposta[i][0];
                for(int j=1; j<8; j++) cout << " " << resposta[i][j];
                cout << endl;
            }
        }
        else cout << "NO" << endl;
    }

    return 0;
}
