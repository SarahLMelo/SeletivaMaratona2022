#include <bits/stdc++.h>

/*
DP [soma][usandoNElementos] -> Numero de Maneiras
*/

using namespace std;

#define ll long long

ll memo[105][105];
int N, K;

int dp(int soma, int elem){
    if(soma > 100) return 0;
    if(soma == 0) return 1;
    if(elem == 1) return 1;
    
    ll &ans = memo[soma][elem];
    if(ans != -1) return ans;

    ans = 0;
    for(int i=0; i<=soma; i++){
        ans += (dp(soma-i, elem-1)%1000000);
    }

    return ans;
}

int main(){
    cin >> N >> K;

    memset(memo, -1, sizeof(memo));
    while(N || K){
        cout << dp(N, K)%1000000 << "\n";

        cin >> N >> K;
    }

    return 0;
}