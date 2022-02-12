#include <bits/stdc++.h>

using namespace std;

bool table[11][11];

int main(){
    bool valid = true;
    int N;
    cin >> N;

    while(N--){
        bool D;
        int L, R, C;
        cin >> D >> L >> R >> C;

        if(D==0){
            if(C+L-1>10) valid = false;
            else {
                for(int i=0; i<L; i++){
                    if(table[R][C+i] == 1) valid = false;
                    else table[R][C+i] = 1;
                }
            }
        }

        else{
            if(R+L-1>10) valid = false;
            else {
                for(int i=0; i<L; i++){
                    if(table[R+i][C] == 1) valid = false;
                    else table[R+i][C] = 1;
                }
            }

        }
    }

    if(valid == true) cout << "Y\n";
    else cout << "N\n";

    return 0;
}