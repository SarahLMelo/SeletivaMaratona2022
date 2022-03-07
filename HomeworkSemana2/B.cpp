#include <bits/stdc++.h>

using namespace std;

int check(vector <vector <int>> &table){
    int ans = 0;
    for(int i=0; i<10; i++) for(int j=0; j<10; j++) if(table[i][j] == 0) ans++;

    return ans;
}

int bt(int posX, int posY, vector <vector <int>> &table){
    if(posX<0 || posY<0 ||posX>=10 || posY>=10 || table[posX][posY] != 0) return check(table);

    //cout << posX  << " " << posY << endl;

    table[posX][posY] = 1;
    int ans = 1e9;
    if(posX-2>=0 && posY-1>=0 && table[posX-2][posY-1] == 0){
        ans = min(ans, bt(posX-2, posY-1, table));
        table[posX-2][posY-1] = 0;
    }
    else ans = min(ans, bt(posX-2, posY-1, table));

    if(posX-2>=0 && posY+1<10 && table[posX-2][posY+1] == 0){
        ans = min(ans, bt(posX-2, posY+1, table));
        table[posX-2][posY+1] = 0;
    }
    else ans = min(ans, bt(posX-2, posY+1, table));


    if(posX+2<10 && posY-1>=0 && table[posX+2][posY-1] == 0){
        ans = min(ans, bt(posX+2, posY-1, table));
        table[posX+2][posY-1] = 0;
    }
    else ans = min(ans, bt(posX+2, posY-1, table));

    if(posX+2<10 && posY+1<10 && table[posX+2][posY+1] == 0){
        ans = min(ans, bt(posX+2, posY+1, table));
        table[posX+2][posY+1] = 0;
    }
    else ans = min(ans, bt(posX+2, posY+1, table));


    if(posX-1>=0 && posY-2>=0 && table[posX-1][posY-2] == 0){
        ans = min(ans, bt(posX-1, posY-2, table));
        table[posX-1][posY-2] = 0;
    }
    else ans = min(ans, bt(posX-1, posY-2, table));

    if(posX-1>=0 && posY+2<10 && table[posX-1][posY+2] == 0){
        ans = min(ans, bt(posX-1, posY+2, table));
        table[posX-1][posY+2] = 0;
    }
    else ans = min(ans, bt(posX-2, posY+1, table));


    if(posX+1<10 && posY-2>=0 && table[posX+1][posY-2] == 0){
        ans = min(ans, bt(posX+1, posY-2, table));
        table[posX+1][posY-2] = 0;
    }
    else ans = min(ans, bt(posX+1, posY-2, table));
    
    if(posX+1<10 && posY+2<10 && table[posX+1][posY+2] == 0){
        ans = min(ans, bt(posX+1, posY+2, table));
        table[posX+1][posY+2] = 0;
    }
    else ans = min(ans, bt(posX+1, posY+2, table));

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, cnt = 0;;
    cin >> n;
    while(n!=0){
        cnt++;

        vector <vector <int>> table (10, vector <int> (10));
        for(int i=0; i<10; i++){
            int skipped = 10, in = 0;
            if(i<n) cin >> skipped >> in;
            for(int j=0; j<10; j++){
                if(skipped>0){
                    table[i][j] = -1;
                    skipped--;
                }
                else if(in>0){
                    table[i][j] = 0;
                    in--;
                }
                else table[i][j] = -1;
            }
        }


        cout << "Case " << cnt << ", " << bt(0, 0, table) << " squares can not be reached.\n";

        cin >> n;
    }

    return 0;
}