#include <bits/stdc++.h>

/*
    Peso
    Valor dos Itens
*/

#define ii std::pair<int, int> //(Peso, Valor)

int n, pMax;
std::vector <ii> itens;
std::vector <std::vector <int>> memo; //(Peso, Pos)

int dp(int peso, int pos){
    if(pos>=n) return 0;
    if(memo[peso][pos] != -1) return memo[peso][pos];

    int pega = 0, nPega = 0;
    if(peso + itens[pos].first <= pMax) pega = itens[pos].second + dp(peso+itens[pos].first, pos+1);
    nPega = dp(peso, pos+1);

    return memo[peso][pos] = std::max(pega, nPega);

}

int main(){
    int n;


    return 0;
}