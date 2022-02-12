#include <bits/stdc++.h>

using namespace std;

bool isSquare(string palavra, int n){
    if(n%2!=0) return 0;
    for(int i=0; i<n/2; i++){
        if(palavra[i]!=palavra[(n/2 + i)]) return 0;
    }

    return 1;
}

int main(){
    int n;
    cin >> n;

    while(n--){
        string palavra;
        cin >> palavra;
        if(isSquare(palavra, palavra.size()) == 0) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}