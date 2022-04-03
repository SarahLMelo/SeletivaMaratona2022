#include <bits/stdc++.h>

using namespace std;

int phi[(int)1e6+1];

void init(){
    for(int i=1; i<=1e6; i++) phi[i] = i;
    for(int i=2; i<=1e6; i++){
        if(phi[i] == i){
            for(int j = i; j<=1e6+1; j+=i){
                phi[j] = (phi[j]/i)*(i-1);
            }
        }
    }

    return;
}

int main(){
    init();
    int t; 
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << phi[n] << "\n";
    }

    return 0;
}