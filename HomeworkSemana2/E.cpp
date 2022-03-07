#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool check(int n, ll int m, int k, ll int t){
    ll int qntdDireita = k-1, qntdEsquerda = n - k;
    m -= t;
    ll int sumDireita = 0, sumEsquerda = 0;
    if(qntdDireita>=t){
        sumDireita = (t-1)*t/2;
        sumDireita += (qntdDireita - (t-1));
    }
    else{
        sumDireita = ((2*t - 1 - qntdDireita)*qntdDireita)/2;
    }

    if(qntdEsquerda>=t){
        sumEsquerda = (t-1)*t/2;
        sumEsquerda += (qntdEsquerda - (t-1));
    }
    else{
        sumEsquerda = ((2*t - 1 - qntdEsquerda)*qntdEsquerda)/2;
    }
    m -= (sumDireita+sumEsquerda);

    return m>=0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long int n, m, k;
    cin >> n >> m >> k;

    int l = 1, r = m+1;
    while(l<r){
        long long int meio = (l+r)/2;
        if(check(n, m, k, meio) == true) l = meio+1;
        else r = meio;
    }

    cout << --l << "\n";
    return 0;
}