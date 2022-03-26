#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n; 
        cin >> n;

        stack <int> sPar, sImpar;
        bool possible = true;

        for(int i=0; i<n; i++){
            int x;
            cin >> x;

            if(x%2){ //Se x for impar
                if(!sImpar.empty()){
                    if(x < sImpar.top()) possible = false;
                }
                sImpar.push(x);
            }  

            else{
                if(!sPar.empty()){
                    if(x < sPar.top()) possible = false;
                }
                sPar.push(x);
            } 
        }

        if(possible) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}