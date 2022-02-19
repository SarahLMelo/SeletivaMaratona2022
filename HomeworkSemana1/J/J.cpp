#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, k = 0, sizeOfK = 0;
        cin >> n;

        while(n!=0){
            n = n >> 1;
            sizeOfK += 1;
        }

        for(int i=0; i<sizeOfK; i++){
            k = k << 1;
            k += 1;
        }

        k = k >> 1;

        cout << k << "\n";

    }

    return 0;
}