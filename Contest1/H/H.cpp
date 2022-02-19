#include <bits/stdc++.h>

using namespace std;

int main(){
    int S;
    cin >> S;

    while(S!=0){
        int B;
        cin >> B;

        int right[S+1], left[S+1];
        for(int i=1; i<=S; i++){
            right[i] = i+1;
            left[i] = i-1;
        }
        right[S] = 10;
        left[1] = 1;

        for(int i=0; i<B; i++){
            int l, r;
            cin >> l >> r;

            if(l-1>0 && r+1<=S){
                right[l-1] = right[r];
                left[r+1] = left[l];
            }
            else{
                right[l-1] = 0;
                left[r+1] = 0;
            }

            for(int j=l; j<r+1; j++){
                right[j] = right[r];
                left[j] = left[l];
            }

            if(left[r+1] == 0) cout << "* ";
            else cout << left[r+1] << " ";
            if(right[l-1] == 0) cout << "*\n";
            else cout << right[l-1] << "\n";
        }

        cout << "-\n";
        cin >> S;
    }


    return 0;
}